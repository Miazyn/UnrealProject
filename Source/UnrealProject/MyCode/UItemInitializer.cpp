// Fill out your copyright notice in the Description page of Project Settings.


#include "UItemInitializer.h"

//#include "NavigationSystemTypes.h"

UItem* UUItemInitializer::CreateItemInstance(UObject* Outer, FString ItemName)
{
	UItem* NewItem = NewObject<UItem>(Outer, UItem::StaticClass());
	if (NewItem)
	{
		NewItem->ItemName = ItemName;

		NewItem->AddToRoot();  
	}

	return NewItem;
}

void UUItemInitializer::CreateBasicItems()
{
	//UItem* Strawberry = CreateItemInstance(this, FString(TEXT("Strawberry")));
	//UItem* Blueberry = CreateItemInstance(this,FString(TEXT("Blueberry")));
}
