// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UInventorySlot.h"
#include "Components/ActorComponent.h"
#include "UInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	
	struct FInventory
	{
		FString InventoryName;
		int InventorySize;
		int ItemCap;
		
		TArray<UInventorySlot::FInventorySlot> InventorySlots;

		bool AddItem(UItem* AddedItem, int AddedAmount);

		bool RemoveItem(UItem* RemoveItem, int RemovedAmount);

		int GetTotalItemCount(UItem* QueryItem);
	};
};
