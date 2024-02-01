// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "DragDrop.h"
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

		ItemWidget->SlotNumber = i;
		
		GridPanel->AddChildToUniformGrid(ItemWidget, 0, i);
	}
	UE_LOG(LogTemp, Log, TEXT("Inventory Initialized with: %d"), NumSlots);
	return InventorySlots;
}

TArray<UInventoryItemWidget*> UInventoryWidget::AddItemToInventory(UItem* Item, int32 SlotIndex, TArray<UInventoryItemWidget*> RefArray)
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

	return  RefArray;
}

bool UInventoryWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	UDragDrop* DragWidgetResult = Cast<UDragDrop>(InOperation);

	if(!IsValid(DragWidgetResult))
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid DragDrop Widget"));
		return false;
	}

	const FVector2D DragWindowOffset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
	const FVector2D DragWindowOffsetResult = DragWindowOffset - DragWidgetResult->DragOffset;

	DragWidgetResult->WidgetReference->AddToViewport();
	DragWidgetResult->WidgetReference->SetVisibility(ESlateVisibility::Visible);
	DragWidgetResult->WidgetReference->SetPositionInViewport(DragWindowOffsetResult, false);

	return true;
}


