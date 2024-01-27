// Fill out your copyright notice in the Description page of Project Settings.


#include "UItemDataAsset.h"

#include "UItem.h"

FString UUItemDataAsset::GetItemName()
{
	const TMap<FName, uint8*>& RowMap = this->ItemDataTable->GetRowMap();

	if (RowMap.Num() > 0)
	{
		auto Iterator = RowMap.CreateConstIterator();

		if (Iterator)
		{
			const TPair<FName, uint8*>& FirstEntry = *Iterator;

			FItemData* ItemData = reinterpret_cast<FItemData*>(FirstEntry.Value);

			FString ItemName = ItemData->ItemName;

			return ItemName;
		}
	}

	return "NameNotFound";
}
