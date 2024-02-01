// Fill out your copyright notice in the Description page of Project Settings.


#include "DropZone.h"

#include "DragDrop.h"
#include "InventoryItemWidget.h"
#include "InventoryWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealProject/MyCode/APickUp.h"
#include "UnrealProject/MyCode/PlayerCharacter.h"

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
					
					UE_LOG(LogTemp, Log, TEXT("Set back to original pos."));
					Widget->SetPositionInViewport(Widget->OriginalPos);

					Widget->SetVisibility(ESlateVisibility::Visible);
					
					//Spawn Items in / Drop from Inventory UI & PlayerChar
					DropItem(Widget);
				}
			}
		
	}
	
	return true;
}

void UDropZone::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);

	UE_LOG(LogTemp, Log, TEXT("Leave on DropZone"));
}

void UDropZone::DropItem(UInventoryItemWidget* Widget)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UItem* DroppedItem = Widget->InventorySlotItem;

	if(!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Pawn found!"));
		return;
	}
	if(!DroppedItem)
	{
		UE_LOG(LogTemp, Error, TEXT("No item reference found!"));
		return;
	}
	
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerPawn);

	if(!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot cast to PlayerCharacter."));
		return;
	}
	
	PlayerCharacter->PlayerInventory->RemoveItem(DroppedItem, 1);
	
	FVector SpawnLocation = PlayerCharacter->GetActorLocation() + PlayerCharacter->GetActorForwardVector() * SpawnOffsetDistance;

	Widget->InventorySlotItem = nullptr;

	//TODO: Spawn In new Item here
	SpawnPickUp(DroppedItem, SpawnLocation);
}

void UDropZone::SpawnPickUp(UItem* DroppedItem, FVector SpawnLocation)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning Actor"));
	AAPickUp* NewPickUp =
		GetWorld()->SpawnActor<AAPickUp>(AAPickUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	NewPickUp->ItemDataAsset = DroppedItem->ItemDataAsset;
	
}
