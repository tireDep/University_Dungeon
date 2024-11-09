// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "Blueprint/UserWidget.h"


AUIManager::AUIManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
}

void AUIManager::Initialize()
{
	Super::Initialize();
}

void AUIManager::ShutDown()
{
	Super::ShutDown();

	for (auto& content : UIWidgets)
	{
		if (content.Value)
		{
			content.Value->RemoveFromViewport();
			content.Value = nullptr;
		}
	}

	UIWidgets.Empty();
}

UUserWidget* AUIManager::GetWidget(EUIType UIType)
{
	if( UIWidgets.Contains(UIType) )
	{
		return UIWidgets[UIType];
	}

	return nullptr;
}

void AUIManager::CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool bHide/* = true*/)
{
	if (WidgetClass == nullptr)
	{
		// error
		return;
	}

	if (UIWidgets.Contains(UIType) == true)
	{
		// warning
		return;
	}

	UUserWidget* Widget = CreateWidget<UUserWidget>(GWorld->GetGameInstance(), WidgetClass);
	if (Widget == nullptr)
	{
		// error
		return;
	}

	UIWidgets.Add(UIType, Widget);
	Widget->AddToViewport();

	if (bHide == true)
	{
		Widget->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		Widget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AUIManager::RemoveWidget(EUIType UIType)
{
	if (UIWidgets.Contains(UIType) == false )
	{
		return;
	}

	if (UIWidgets[UIType])
	{
		UIWidgets[UIType]->RemoveFromViewport();
		UIWidgets[UIType] = nullptr;
	}

	UIWidgets.Remove(UIType);
}

void AUIManager::SetHideWidget(EUIType UIType, bool bHide)
{
	if (UIWidgets.Contains(UIType) == true)
	{
		// warning
		return;
	}

	UUserWidget* Widget = UIWidgets[UIType];
	if (Widget == nullptr)
	{
		return;
	}

	if (bHide == true)
	{
		Widget->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		Widget->SetVisibility(ESlateVisibility::Visible);
	}
}

