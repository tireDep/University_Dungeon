// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.h"
#include "GameModeMain.generated.h"

UCLASS()
class PROTOTYPE_API AGameModeMain : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameModeMain();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Managers") AGameManager* GameManager;
	
};
