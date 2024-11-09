#include "UIManagerSubsystem.h"
#include "Blueprint/UserWidget.h"

void UUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

UUserWidget* UUIManagerSubsystem::GetWidget(EUIType UIType)
{
    if (UIWidgets.Contains(UIType))
    {
        return UIWidgets[UIType];
    }
    return nullptr;
}

void UUIManagerSubsystem::CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool bVisibility/* = true*/)
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
    
    UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
    if (NewWidget == nullptr)
    {
        return;
    }
    
    NewWidget->AddToViewport();
    UIWidgets.Add(UIType, NewWidget);
    if (bVisibility == false)
    {
        NewWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UUIManagerSubsystem::RemoveWidget(EUIType UIType)
{
    if (UIWidgets.Contains(UIType) == false)
    {
        return;
    }

    UUserWidget* WidgetToRemove = UIWidgets[UIType];
    if (WidgetToRemove == nullptr)
    {
        return;
    }
    
    WidgetToRemove->RemoveFromParent();
    UIWidgets.Remove(UIType);
}

void UUIManagerSubsystem::SetWidgetVisibility(EUIType UIType, bool bVisibility)
{
    UUserWidget* Widget = GetWidget(UIType);
    if (Widget == nullptr)
    {
        return;
    }

    if (bVisibility == true)
    {
        Widget->SetVisibility(ESlateVisibility::Visible);
    }
    else
    {
        Widget->SetVisibility(ESlateVisibility::Hidden);
    }
}