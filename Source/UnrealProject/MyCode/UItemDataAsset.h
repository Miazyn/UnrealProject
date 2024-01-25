// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UUItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FString ItemDescription;
};
