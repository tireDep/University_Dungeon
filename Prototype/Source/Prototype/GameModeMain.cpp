// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeMain.h"

AGameModeMain::AGameModeMain()
{

}

void AGameModeMain::BeginPlay()
{
	Super::BeginPlay();

	if (GameManager == nullptr)
	{
		GameManager = GetWorld()->SpawnActor<AGameManager>(AGameManager::StaticClass());
	}

	if (GameManager != nullptr)
	{
		GameManager->StartGame();
	}
}
