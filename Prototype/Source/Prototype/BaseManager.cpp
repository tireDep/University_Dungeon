// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseManager.h"

ABaseManager::ABaseManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseManager::BeginPlay()
{
	Super::BeginPlay();	
}

void ABaseManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

