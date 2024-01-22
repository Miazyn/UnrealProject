// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/Image.h"

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

	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemType)
	TEnumAsByte<EItemType> ItemType;
	
	FString ItemDescription;
	FString ItemId;

	UImage* ItemIcon;

	virtual void UseItem();
	
};
