// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "UnrealProject/MyCode/UItem.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TSubclassOf<class UInventoryItemWidget> ItemWidgetClass;
       
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TArray<UInventoryItemWidget*> InventorySlots;
	
public:

	UFUNCTION(BlueprintCallable,  Category = "Inventory")
	TArray<UInventoryItemWidget*> InitializeInventory(int32 NumSlots, UUniformGridPanel* GridPanel);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<UInventoryItemWidget*> AddItemToInventory(UItem* Item, int32 SlotIndex, TArray<UInventoryItemWidget*> RefArray);


	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

};
