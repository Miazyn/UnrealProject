// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "DragDrop.h"
#include "InventoryItemWidget.h"
#include "InventorySlotWidget.h"
#include "IPropertyTableColumn.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"


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
		UInventorySlotWidget* SlotWidget = CreateWidget<UInventorySlotWidget>(GetWorld(), ItemSlotClass);
		
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(GetWorld(), ItemWidgetClass);
		InventorySlots.Add(ItemWidget);

		ItemWidget->SlotNumber = i;
		ItemWidget->SetAlignmentInViewport(FVector2D(0.5f, 0.5f));
		ItemWidget->SetRenderScale(FVector2D(1.0f, 1.0f));

		SlotWidget->SetAlignmentInViewport(FVector2D(0.5f, 0.5f));
		SlotWidget->SetRenderScale(FVector2D(1.0f, 1.0f));

		UUniformGridSlot* SlotWidgetGrid = Cast<UUniformGridSlot>(GridPanel->AddChildToUniformGrid(SlotWidget, 0, i));
		UUniformGridSlot* ItemWidgetGrid = Cast<UUniformGridSlot>(GridPanel->AddChildToUniformGrid(ItemWidget, 0, i));
		
		//GridPanel->AddChildToUniformGrid(SlotWidget, 0, i);
		//GridPanel->AddChildToUniformGrid(ItemWidget, 0, i);

		if(SlotWidgetGrid)
		{
			SlotWidgetGrid->SetHorizontalAlignment(HAlign_Fill);
			SlotWidgetGrid->SetVerticalAlignment(VAlign_Fill);
		}
		if(ItemWidgetGrid)
		{
			ItemWidgetGrid->SetHorizontalAlignment(HAlign_Fill);
			ItemWidgetGrid->SetVerticalAlignment(VAlign_Fill);
		}
		
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


