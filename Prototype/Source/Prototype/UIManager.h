// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API AUIManager : public ABaseManager
{
	GENERATED_BODY()

public:
	AUIManager();

protected:
	virtual void BeginPlay() override;

public:
	// virtual void Tick(float DeltaTime) override;

	virtual void Initialize() override;
	virtual void ShutDown() override;
	
};
