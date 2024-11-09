// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeMain.h"

AGameModeMain::AGameModeMain()
{

}

void AGameModeMain::BeginPlay()
{
	Super::BeginPlay();

	CreateManager();
}

void AGameModeMain::CreateManager()
{
//	if (GameManager == nullptr)
//	{
//		GameManager = GetWorld()->SpawnActor<AGameManager>(AGameManager::StaticClass());
//	}
//
//	if (GameManager != nullptr)
//	{
//		GameManager->StartGame();
//	}
//
//	if (UIManager == nullptr)
//	{
//		UIManager = GetWorld()->SpawnActor<AUIManager>(AUIManager::StaticClass());
//	}
//
//	if (UIManager != nullptr)
//	{
//		UIManager->Initialize();
//	}
}