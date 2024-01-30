// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "UItemDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	FItemData(): ItemType(EItemType::General), ItemIcon(nullptr)
	{
	}

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EItemType> ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* ItemIcon;
};

struct FItemStruct
{
	FString ItemName;
	FString ItemDescription;
	EItemType ItemType;
	FString ItemId;
	UTexture2D* ItemIcon;
};

UCLASS()
class UNREALPROJECT_API UUItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	UDataTable* ItemDataTable;

	FItemStruct GetItemInfo();

	
	
};
