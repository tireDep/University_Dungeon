// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseManager.generated.h"

UCLASS()
class PROTOTYPE_API ABaseManager : public AActor
{
	GENERATED_BODY()

public:
	ABaseManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Initialize() {};
	virtual void ShutDown() {};
};
