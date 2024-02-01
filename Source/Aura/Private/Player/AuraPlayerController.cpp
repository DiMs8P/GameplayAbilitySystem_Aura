// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "Interation/EnemyInterface.h"

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    // TODO experiment
    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::CursorTrace()
{
    FHitResult CursorHit;
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if (!CursorHit.bBlockingHit)
    {
        return;
    }

    PreviousActor = CurrentActor;
    CurrentActor = Cast<IEnemyInterface>(CursorHit.GetActor());

    /**
     * Line trace from cursor. There are several scenarios:
     *  A. LastActor is null && ThisActor is null
     *		- Do nothing
     *	B. LastActor is null && ThisActor is valid
     *		- Highlight ThisActor
     *	C. LastActor is valid && ThisActor is null
     *		- UnHighlight LastActor
     *	D. Both actors are valid, but LastActor != ThisActor
     *		- UnHighlight LastActor, and Highlight ThisActor
     *	E. Both actors are valid, and are the same actor
     *		- Do nothing
     */

    if (PreviousActor == nullptr && CurrentActor != nullptr) {
        // Case B
        CurrentActor->HighlightActor();
    }
    else if (PreviousActor != nullptr && CurrentActor == nullptr) {
        // Case C
        PreviousActor->UnHighlightActor();
    }
    else if (PreviousActor != nullptr && PreviousActor != CurrentActor) {
        // Case D
        PreviousActor->UnHighlightActor();
        CurrentActor->HighlightActor();
    }
}
