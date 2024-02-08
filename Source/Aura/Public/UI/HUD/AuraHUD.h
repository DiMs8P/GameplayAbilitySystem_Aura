// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UOverlayWidgetController;
class UAuraUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
    UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

    void InitOverlay(const FWidgetControllerParams& WCParams);
    
protected:
    virtual void BeginPlay() override;
    
protected:
    UPROPERTY()
    TObjectPtr<UAuraUserWidget> OverlayWidget;

    UPROPERTY()
    TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
