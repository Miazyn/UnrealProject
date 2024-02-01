// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemWidget.h"

#include "DragDrop.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealProject/MyCode/PlayerCharacter.h"
#include "UnrealProject/MyCode/UInventoryComponent.h"


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

	if(InventorySlotItem == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid DragOperation"));
		return;
	}
	
	UDragDrop* DragWidget = Cast<UDragDrop>(
		UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDrop::StaticClass())
		);
	this->SetVisibility(ESlateVisibility::HitTestInvisible);

	if(DragWidget){
		DragWidget->WidgetReference = this;
		DragWidget->Pivot = EDragPivot::MouseDown;
		DragWidget->DefaultDragVisual = this;
		DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

		OutOperation = DragWidget;
	}
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
}

bool UInventoryItemWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
                                        UDragDropOperation* InOperation)
{
	//When sth is dropped on top of The InventoryItemWidget
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	UE_LOG(LogTemp, Log, TEXT("Drop Item inside of InventoryItemWidget"));
	if(InOperation)
	{
		UDragDrop* DragDropOp = Cast<UDragDrop>(InOperation);
		if(DragDropOp)
		{
			UInventoryItemWidget* OtherWidget = Cast<UInventoryItemWidget>(DragDropOp->WidgetReference);
			if(OtherWidget)
			{
				//Logic of swap Items
			}
		}
	}
	return  true;
}

void UInventoryItemWidget::NativeConstruct()
{
	Super::NativeConstruct();
	OriginalPos = GetRenderTransform().Translation;
}


void UInventoryItemWidget::SwapItemWidgets(UInventoryItemWidget* OtherWidget)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	UItem* CurrentItem = this->InventorySlotItem;

	if(!CurrentItem)
	{
		UE_LOG(LogTemp, Error, TEXT("No Item found on current widget."));
		return;
	}
	if(!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Pawn found."));
		return;
	}
	APlayerCharacter* PlayerCharacter =
		Cast<APlayerCharacter>(PlayerPawn);

	if(!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot cast to PlayerCharacter!"));
		return;
	}
	UInventoryComponent* PlayerInventory = PlayerCharacter->PlayerInventory;
	if(!PlayerInventory)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find Player Inventory!"));
		return;
	}
	
	//If other slot contains other item
	if(OtherWidget->InventorySlotItem)
	{
		UItem* OtherItem = OtherWidget->InventorySlotItem;
		
	}//If other slot is empty
	else
	{
		
	}
}

