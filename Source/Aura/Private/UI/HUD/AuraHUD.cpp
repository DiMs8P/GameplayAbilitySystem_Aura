// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AAuraHUD::BeginPlay()
{
    Super::BeginPlay();
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (OverlayWidgetController)
    {
        return OverlayWidgetController;
    }

    OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
    OverlayWidgetController->SetWidgetControllerParams(WCParams);

    return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(const FWidgetControllerParams& WCParams)
{
    checkf(OverlayWidgetClass, TEXT("Overlay widget class unitialized, set it in BP_AuraHUD"));
    checkf(OverlayWidgetControllerClass, TEXT("Overlay widget controller class unitialized, set it in BP_AuraHUD"));
    
    UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
    OverlayWidget = Cast<UAuraUserWidget>(Widget);

    UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WCParams);
    OverlayWidget->SetWidgetController(WidgetController);
    
    Widget->AddToViewport();
}
