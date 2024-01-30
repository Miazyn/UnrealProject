// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UnrealProject/MyCode/UInventorySlot.h"

#include "InventoryItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UInventoryItemWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UInventorySlot* InventorySlot;
};
