// Fill out your copyright notice in the Description page of Project Settings.


#include "UItem.h"

void UItem::UseItem()
{
	if(ItemName != "" && ItemType == EItemType::Consumable)
	{
		UE_LOG(LogTemp, Log, TEXT("Using Item: %s"), *FString(ItemName));
	}
}
