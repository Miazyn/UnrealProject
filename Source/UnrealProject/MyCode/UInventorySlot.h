// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UItem.h"
#include "UInventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UInventorySlot : public UObject
{
	GENERATED_BODY()

public:
	
	struct FInventorySlot
	{
		UItem* Item;
		int Amount;
		int SlotNumber;

		void AddAmount(int AddedAmount)
		{
			Amount += AddedAmount;
		};
	};
};
