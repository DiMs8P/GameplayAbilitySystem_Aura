// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

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
