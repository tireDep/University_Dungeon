#include "UIManager.h"
#include "Blueprint/UserWidget.h"

UUIManager::UUIManager()
{

}

void UUIManager::InitializeManager()
{
	Super::InitializeManager();
}

void UUIManager::ShutDownManager()
{
	Super::ShutDownManager();

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

UUserWidget* UUIManager::GetWidget(EUIType UIType)
{
	if (UIWidgets.Contains(UIType))
	{
		return UIWidgets[UIType];
	}

	return nullptr;
}

void UUIManager::CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool bHide/* = true*/)
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

void UUIManager::RemoveWidget(EUIType UIType)
{
	if (UIWidgets.Contains(UIType) == false)
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

void UUIManager::SetHideWidget(EUIType UIType, bool bHide)
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
