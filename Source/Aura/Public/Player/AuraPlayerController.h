// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void PlayerTick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    void CursorTrace();

private:
    TObjectPtr<IEnemyInterface> PreviousActor;
    TObjectPtr<IEnemyInterface> CurrentActor;
};
