// Fill out your copyright notice in the Description page of Project Settings.


#include "UInventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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


bool UInventoryComponent::FInventory::AddItem(UItem* AddedItem, int AddedAmount)
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
	
	for(int i = 0; i < InventorySlots.Num(); i++)
	{
		if(InventorySlots[i].Item == AddedItem)
		{
			if(InventorySlots[i].Amount < ItemCap)
			{
				InventorySlots[i].AddAmount(AddedAmount);
				//TODO: Item Changed Callback
				return true;
			}
		}
	}
	
	//TODO: Add completely new item to empty slot.

	for (int i = 0; i < InventorySlots.Num(); i++)
	{
		if(!InventorySlots[i].Item)
		{
			InventorySlots[i].Item = AddedItem;

			if(ItemCap < AddedAmount)
			{
				InventorySlots[i].AddAmount(ItemCap);

				AddItem(AddedItem, AddedAmount - ItemCap);

				break;
			}
			else
			{
				InventorySlots[i].AddAmount(AddedAmount);
				//TODO: Item changed callback
				return true;
			}
		}
	}

	//Inventory is full
	return false;
}

bool UInventoryComponent::FInventory::RemoveItem(UItem* RemoveItem, int RemovedAmount)
{

	for(int i = 0; i < InventorySlots.Num(); i++)
	{
		
	}
	
	return true;
}

int UInventoryComponent::FInventory::GetTotalItemCount(UItem* QueryItem)
{
	return 0;
}

