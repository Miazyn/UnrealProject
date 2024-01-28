// Fill out your copyright notice in the Description page of Project Settings.


#include "UInventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	InventorySlots.SetNumUninitialized(InventorySize);
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
			//TODO: Item changed callback
			return true;
			
		}
	}

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

