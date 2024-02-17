// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"


AAuraEffectActor::AAuraEffectActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
    Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
    if (const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target))
    {
        UAbilitySystemComponent* TargetASC = ASCInterface->GetAbilitySystemComponent();

        check(GameplayEffectClass)
        FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
        EffectContextHandle.AddSourceObject(this);

        const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);
        TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
    }
}


