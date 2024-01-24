// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerPawn.h"

AAPlayerPawn::AAPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	
}
