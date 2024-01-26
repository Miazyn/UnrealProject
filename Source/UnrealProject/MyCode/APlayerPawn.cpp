// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerPawn.h"

AAPlayerPawn::AAPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
}

void AAPlayerPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AAPlayerPawn::MoveForward(float AxisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Found AxisValue"));
	AddMovementInput(GetActorForwardVector() + AxisValue);
}


void AAPlayerPawn::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AAPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAPlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("LookUp", this, &AAPlayerPawn::LookUp);
}





