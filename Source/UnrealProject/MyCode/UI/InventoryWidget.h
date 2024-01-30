// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventory(int32 NumSlots);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemToInventory(const FString& ItemName, int32 SlotIndex);

};
