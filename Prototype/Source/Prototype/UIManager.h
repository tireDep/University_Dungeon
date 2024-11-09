#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "UIType.h"
#include "UIManager.generated.h"

UCLASS()
class PROTOTYPE_API UUIManager : public UBaseManager
{
	GENERATED_BODY()

public:
	UUIManager();
	
	virtual void InitializeManager() override;
	virtual void ShutDownManager() override;

	UUserWidget* GetWidget(EUIType UIType);
	void CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool bHide = true);
	void RemoveWidget(EUIType UIType);
	void SetHideWidget(EUIType UIType, bool bHide);

private:
	UPROPERTY()
	TMap<EUIType, UUserWidget*> UIWidgets;
};
