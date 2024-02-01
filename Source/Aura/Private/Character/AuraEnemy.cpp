// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "Game/AuraUtilityMacros.h"

void AAuraEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
}

void AAuraEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
}

AAuraEnemy::AAuraEnemy()
{
    PrimaryActorTick.bCanEverTick = false;

    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();
}
