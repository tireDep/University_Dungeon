#include "GameManager.h"

AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;

	IsGameActive = false;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	StartGame();
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsGameActive == true)
	{

	}	
}

void AGameManager::StartGame()
{
	IsGameActive = true;
	UE_LOG(LogTemp, Warning, TEXT("Game Started!"));
}

void AGameManager::EndGame()
{
	IsGameActive = false;
	UE_LOG(LogTemp, Warning, TEXT("Game Over!"));
}

