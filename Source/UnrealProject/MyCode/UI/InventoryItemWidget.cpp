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

void UInventoryItemWidget::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);

	RemoveFromParent();
}

void UInventoryItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}
