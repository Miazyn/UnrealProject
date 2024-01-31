// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryItemWidget.h"
#include "Components/UniformGridPanel.h"


TArray<UInventoryItemWidget*> UInventoryWidget::InitializeInventory(int32 NumSlots, UUniformGridPanel* GridPanel)
{
	InventorySlots.Empty();

	if(!GridPanel)
	{
		UE_LOG(LogTemp, Error, TEXT("Missing GridPanel Reference."));
		InventorySlots.Empty();
		return InventorySlots;
	}
	
	for (int32 i = 0; i < NumSlots; ++i)
	{
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(GetWorld(), ItemWidgetClass);
		InventorySlots.Add(ItemWidget);

		GridPanel->AddChildToUniformGrid(ItemWidget, 0, i);
	}
	UE_LOG(LogTemp, Log, TEXT("Inventory Initialized with: %d"), NumSlots);
	return InventorySlots;
}

void UInventoryWidget::AddItemToInventory(UItem* Item, int32 SlotIndex, TArray<UInventoryItemWidget*> RefArray)
{
	
	if (RefArray.IsValidIndex(SlotIndex))
	{
		RefArray[SlotIndex]->InventorySlotItem = Item;
		UE_LOG(LogTemp, Log, TEXT("Inventory added item: %s"), *Item->ItemName);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Invalid Inventory Slot %d Array Size %d"), SlotIndex, RefArray.Num());
	}
	
}


