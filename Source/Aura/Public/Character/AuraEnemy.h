// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interation/EnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
    GENERATED_BODY()

    // IEnemyInterface BEGIN
public:
    virtual void HighlightActor() override;
    virtual void UnHighlightActor() override;
    // IEnemyInterface END
    
public:
    AAuraEnemy();

protected:
    virtual void BeginPlay() override;
};
