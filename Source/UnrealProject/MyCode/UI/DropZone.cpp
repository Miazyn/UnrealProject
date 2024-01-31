// Fill out your copyright notice in the Description page of Project Settings.


#include "DropZone.h"

#include "DragDrop.h"
#include "InventoryItemWidget.h"
#include "InventoryWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

bool UDropZone::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
                             UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
	
	UE_LOG(LogTemp, Log, TEXT("Dropped on DropZone"));
	
	if (InOperation)
	{
		UE_LOG(LogTemp, Log, TEXT("Dropped 1on DropZone"));
		
			
			UDragDrop* DragDropOp = Cast<UDragDrop>(InOperation);

			if(DragDropOp)
			{
				UE_LOG(LogTemp, Log, TEXT("Dropped3 on DropZone"));
				UInventoryItemWidget* Widget = Cast<UInventoryItemWidget>(DragDropOp->WidgetReference);
				if(Widget){
					UE_LOG(LogTemp,Log, TEXT("Dropped %s"), *Widget->InventorySlotItem->ItemName);
				}
			}
		
	}
	
	return true;
}
