// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryItemWidget.h"

void UInventoryWidget::InitializeInventory(int32 NumSlots)
{
	InventorySlots.Empty();

	for (int32 i = 0; i < NumSlots; ++i)
	{
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(GetWorld(), ItemWidgetClass);
		InventorySlots.Add(ItemWidget);
	}
}

void UInventoryWidget::AddItemToInventory(const FString& ItemName, int32 SlotIndex)
{
	if (InventorySlots.IsValidIndex(SlotIndex))
	{
		UInventoryItemWidget* ItemWidget = InventorySlots[SlotIndex];
		if (ItemWidget)
		{
			ItemWidget->ItemName = ItemName;
			// Set other properties or handle item data as needed.
		}
	}
}
