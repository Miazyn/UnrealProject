// Fill out your copyright notice in the Description page of Project Settings.


#include "UInventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent(): InventorySize(32), ItemCap(99), NewItem(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UInventoryComponent::AddItem(UItem* AddedItem, int AddedAmount)
{
	if(!AddedItem)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Item while adding to Inventory!"));
		return  false;
	}
	if(AddedAmount <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Amount while adding to Inventory!"));
		return  false;
	}

	if(InventorySlots.IsEmpty())
	{
		return false;
	}
	
	for(int i = 0; i < InventorySlots.Num(); i++)
	{
		if(InventorySlots[i].Item == AddedItem)
		{
			if(InventorySlots[i].Amount < ItemCap)
			{
				InventorySlots[i].AddAmount(AddedAmount);
				return true;
			}
		}
	}
	

	for (int i = 0; i < InventorySlots.Num(); i++)
	{
		if(InventorySlots[i].Item == nullptr)
		{
			InventorySlots[i].Item = AddedItem;

			if(ItemCap < AddedAmount)
			{
				InventorySlots[i].AddAmount(ItemCap);

				AddItem(AddedItem, AddedAmount - ItemCap);

				break;
			}
			InventorySlots[i].AddAmount(AddedAmount);
			return true;
			
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Inventory full"));
	//Inventory is full
	return false;
}

bool UInventoryComponent::RemoveItem(UItem* RemoveItem, int RemovedAmount)
{

	if(GetTotalItemCount(RemoveItem) <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot remove UItem as it is not existant inside of the FInventory."));
		return false;
	}

	for(int i = 0; i < InventorySlots.Num(); i++)
	{
		if(InventorySlots[i].Item == RemoveItem)
		{
			if(InventorySlots[i].Amount - RemovedAmount <= 0)
			{
				RemovedAmount -= InventorySlots[i].Amount;

				InventorySlots[i].Amount = 0;
				InventorySlots[i].Item = nullptr;
			}
			else
			{
				InventorySlots[i].Amount -= RemovedAmount;
			}
		}
	}

	if(RemovedAmount > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Invalid Remove Number found, End here."));
		return  false;
	}
	

	UE_LOG(LogTemp, Log, TEXT("All Items have been properly removed."));
	return true;
}

int UInventoryComponent::GetTotalItemCount(UItem* QueryItem)
{
	int Counter = 0;

	 for(int i = 0; i < InventorySlots.Num(); i++)
	 {
	 	if(InventorySlots[i].Item == QueryItem)
	 	{
	 		Counter += InventorySlots[i].Amount;
		}
	 }
	
	return Counter;
}

int UInventoryComponent::GetSlotNum(UItem* QueryItem)
{
	for(int i = 0; i < InventorySlots.Num(); i++)
	{
		if(InventorySlots[i].Item == QueryItem)
		{
			return  i;
		}
	}

	return 0;
}

void UInventoryComponent::SwapItemSlots(UItem* OriginalItem, int OriginalSlot, UItem* ItemSwap, int SwapSlot)
{
	UE_LOG(LogTemp, Log, TEXT("Swap Item Slots in Inventory here."));

	if(InventorySlots.IsValidIndex(OriginalSlot) && InventorySlots.IsValidIndex(SwapSlot))
	{
		if(InventorySlots[OriginalSlot].Item != OriginalItem || InventorySlots[SwapSlot].Item != ItemSwap)
		{
			UE_LOG(LogTemp, Error, TEXT("Cannot swap because Index is not same Item as Widget Index!!!"))
			return;
		}
		int OgAmount = InventorySlots[OriginalSlot].Amount;
		int OgNum = InventorySlots[OriginalSlot].SlotNumber;

		int SwapAmount = InventorySlots[SwapSlot].Amount;
		int SwapNum = InventorySlots[SwapSlot].SlotNumber;

		InventorySlots[OriginalSlot].Item = ItemSwap;
		InventorySlots[OriginalSlot].Amount = SwapAmount;
		InventorySlots[OriginalSlot].SlotNumber = SwapNum;

		InventorySlots[SwapSlot].Item = OriginalItem;
		InventorySlots[SwapSlot].Amount = OgAmount;
		InventorySlots[SwapSlot].SlotNumber = OgNum;
	}
	UE_LOG(LogTemp, Log, TEXT("Successful swapped inventory Slots."));
}

void UInventoryComponent::ReassignItemSlot(UItem* Item, int OriginalSlot, int NewSlot)
{
	if(InventorySlots.IsValidIndex(OriginalSlot) && InventorySlots.IsValidIndex(NewSlot))
	{
		if(InventorySlots[OriginalSlot].Item != Item)
		{
			UE_LOG(LogTemp, Error, TEXT("Cannot reassign because Index is not same Item as Widget Index!!!"))
			return;
		}
		int ItemAmount = InventorySlots[OriginalSlot].Amount;
		int SlotNum = InventorySlots[OriginalSlot].SlotNumber;
		
		InventorySlots[OriginalSlot].Item = nullptr;
		
		InventorySlots[NewSlot].Item = Item;
		InventorySlots[NewSlot].Amount = ItemAmount;
		InventorySlots[NewSlot].SlotNumber = SlotNum;

		UE_LOG(LogTemp, Log, TEXT("Successful reassigning of inventory Slot"));
	}
}




