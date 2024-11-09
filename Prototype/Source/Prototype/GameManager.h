// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

UCLASS()
class PROTOTYPE_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:	
	AGameManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	void StartGame();
	void EndGame();

private:
	bool IsGameActive;
};
