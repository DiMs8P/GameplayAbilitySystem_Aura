// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraWidgetController.h"
#include "AbilitySystemComponent.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    AbilitySystemComponent = WCParams.AbilitySystemComponent;
    AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
    UE_LOG(LogTemp, Fatal, TEXT("Method must be implemented"))
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
    UE_LOG(LogTemp, Fatal, TEXT("Method must be implemented"))
}
