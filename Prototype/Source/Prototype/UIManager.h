#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "UIType.h"
#include "UIManager.generated.h"

UCLASS()
class PROTOTYPE_API AUIManager : public ABaseManager
{
	GENERATED_BODY()

public:
	AUIManager();

protected:
	virtual void BeginPlay() override;

public:
	// virtual void Tick(float DeltaTime) override;
	virtual void Initialize() override;
	virtual void ShutDown() override;
	
	UUserWidget* GetWidget(EUIType UIType);
	void CreateNewWidget(EUIType UIType, TSubclassOf<UUserWidget> WidgetClass, bool bHide = true);
	void RemoveWidget(EUIType UIType);
	void SetHideWidget(EUIType UIType, bool bHide);

private:
	UPROPERTY()
	TMap<EUIType, UUserWidget*> UIWidgets;
};
