// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UItem.h"

#include "UItemInitializer.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UUItemInitializer : public UObject
{
	GENERATED_BODY()

	public:
		// Your CreateItemInstance function
		UItem* CreateItemInstance(UObject* Outer, FString ItemName);

	void CreateBasicItems();
};

