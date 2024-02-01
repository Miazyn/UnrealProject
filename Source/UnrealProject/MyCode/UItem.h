// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UUItemDataAsset;

#include "CoreMinimal.h"

//#include "UObject/NoExportTypes.h"
#include "UItem.generated.h"


UENUM()
enum EItemType
{
	General   UMETA(DisplayName = "General"),
	Material     UMETA(DisplayName = "Material"),
	Consumable      UMETA(DisplayName = "Consumable"),
};

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemType)
	TEnumAsByte<EItemType> ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString ItemDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Item")
	UTexture2D* ItemImage;

	UPROPERTY()
	UUItemDataAsset* ItemDataAsset;

	virtual void UseItem();
};
