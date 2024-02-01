// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemWidget.h"
#include "Blueprint/UserWidget.h"
#include "DropZone.generated.h"


/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UDropZone : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

public:

	void DropItem(UInventoryItemWidget* Widget);
	void SpawnPickUp(UItem* DroppedItem, FVector SpawnLocation);
	
	float SpawnOffsetDistance = 300.f;
};
