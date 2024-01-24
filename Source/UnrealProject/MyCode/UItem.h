// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
//#include "Components/Image.h"

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
	
	//TODO: Later maybe add images as possibility for now use standardized one
	//UImage* ItemIcon;

	virtual void UseItem();
	
};
