// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UInventorySlot.h"
#include "Components/ActorComponent.h"
#include "UItem.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	FString InventoryName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	int InventorySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	int ItemCap;
	
	TArray<UInventorySlot> InventorySlots;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool AddItem(UItem* AddedItem, int AddedAmount);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool RemoveItem(UItem* RemoveItem, int RemovedAmount);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int GetTotalItemCount(UItem* QueryItem);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int GetSlotNum(UItem* QueryItem);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	UItem* NewItem;

};
