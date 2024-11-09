// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UIManager.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> MainScreenClass;
};
