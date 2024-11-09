#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIType.h"
#include "UIManagerSubsystem.generated.h"

UCLASS()
class PROTOTYPE_API UUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintCallable, Category = "UI")
    UUserWidget* GetWidget(EUIType UIType);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool Visibility = true);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void RemoveWidget(EUIType UIType);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetWidgetVisibility(EUIType UIType, bool bVisibility);

private:
    UPROPERTY()
    TMap<EUIType, UUserWidget*> UIWidgets;
};
