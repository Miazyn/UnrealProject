// Fill out your copyright notice in the Description page of Project Settings.


#include "DropZone.h"

bool UDropZone::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	UE_LOG(LogTemp, Log, TEXT("Dropped on DropZone"));
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}
