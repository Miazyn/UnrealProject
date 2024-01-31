// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemWidget.h"

#include "DragDrop.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/SlateBlueprintLibrary.h"


FReply UInventoryItemWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	
	FEventReply ReplyResult = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);
	return ReplyResult.NativeReply;
}

void UInventoryItemWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	UDragDrop* DragWidget = Cast<UDragDrop>(
		UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDrop::StaticClass())
		);
	this->SetVisibility(ESlateVisibility::HitTestInvisible);

	DragWidget->WidgetReference = this;
	DragWidget->Pivot = EDragPivot::MouseDown;
	DragWidget->DefaultDragVisual = this;
	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

	OutOperation = DragWidget;
}

bool UInventoryItemWidget::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	UE_LOG(LogTemp, Log, TEXT("Drag is over area"));
	return Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);
}


void UInventoryItemWidget::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);

	UE_LOG(LogTemp, Log, TEXT("Exit area"));
	RemoveFromParent();
}

bool UInventoryItemWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
                                        UDragDropOperation* InOperation)
{
	//When sth is dropped ontop of The InventoryItemWidget
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}


void UInventoryItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}
