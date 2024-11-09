// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseManager.generated.h"

UCLASS(Abstract)
class PROTOTYPE_API UBaseManager : public UObject
{
	GENERATED_BODY()

public:
	virtual void InitializeManager() PURE_VIRTUAL(UBaseManager::InitializeManager);
	virtual void ShutDownManager() PURE_VIRTUAL(UBaseManager::ShutDownManager);
};
