// Fill out your copyright notice in the Description page of Project Settings.


#include "UItemDataAsset.h"

#include "UItem.h"
#include "Net/RepLayout.h"

FItemStruct UUItemDataAsset::GetItemInfo()
{
		FItemStruct ItemStruct;
	
		const TMap<FName, uint8*>& RowMap = this->ItemDataTable->GetRowMap();

		if (RowMap.Num() > 0)
		{
			auto Iterator = RowMap.CreateConstIterator();

			if (Iterator)
			{
				const TPair<FName, uint8*>& FirstEntry = *Iterator;

				FItemData* ItemData = reinterpret_cast<FItemData*>(FirstEntry.Value);

				ItemStruct.ItemName = ItemData->ItemName;
				ItemStruct.ItemDescription = ItemData->ItemDescription;
				ItemStruct.ItemId = ItemData->ItemId;
				ItemStruct.ItemIcon = ItemData->ItemIcon;
				ItemStruct.ItemType = ItemData->ItemType;
			
				return ItemStruct;
			}
		}
	

	ItemStruct.ItemName = "None";
	ItemStruct.ItemDescription = "None";
	ItemStruct.ItemId = "Error";
	ItemStruct.ItemIcon = nullptr;
	ItemStruct.ItemType = EItemType::General;
	
	return ItemStruct;
}
