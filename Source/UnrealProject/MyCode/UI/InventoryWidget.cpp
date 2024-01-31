// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryItemWidget.h"
#include "Components/UniformGridPanel.h"

void UInventoryWidget::InitializeInventory(int32 NumSlots, UUniformGridPanel* GridPanel)
{
	InventorySlots.Empty();

	if(!GridPanel)
	{
		UE_LOG(LogTemp, Error, TEXT("Missing GridPanel Reference."));
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("Inventory Initialized with: %d"), NumSlots);

	
	for (int32 i = 0; i < NumSlots; ++i)
	{
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(GetWorld(), ItemWidgetClass);
		InventorySlots.Add(ItemWidget);

		GridPanel->AddChildToUniformGrid(ItemWidget, 0, i);
	}
	
}

void UInventoryWidget::AddItemToInventory(UItem* Item, int32 SlotIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Inventory added item: %s"), *Item->ItemName);
	
	
	if (InventorySlots.IsValidIndex(SlotIndex))
	{
		InventorySlots[SlotIndex]->InventorySlotItem = Item;
	}
	
}


