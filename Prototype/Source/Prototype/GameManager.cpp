#include "GameManager.h"
#include "UIManager.h"

AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;

	IsGameActive = false;

	if (GetWorld())
	{
		AUIManager* UIManager = GetWorld()->SpawnActor<AUIManager>(AUIManager::StaticClass());
		if (UIManager)
		{
			Managers.Add(UIManager);
		}
	}
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

