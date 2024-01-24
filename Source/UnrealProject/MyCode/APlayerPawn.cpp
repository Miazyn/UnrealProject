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

	Move();
	Rotate();
}

void AAPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAPlayerPawn::CalculateMovementInput);
	PlayerInputComponent->BindAxis("Turn", this, &AAPlayerPawn::CalculateRotationInput);
}


void AAPlayerPawn::CalculateMovementInput(float Value)
{
	MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds,0,0);
}

void AAPlayerPawn::CalculateRotationInput(float Value)
{
	float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotator = FRotator(0,RotateAmount,0);
	RotationDirection =FQuat(Rotator);
}

void AAPlayerPawn::Move()
{
	AddActorLocalOffset(MoveDirection, true);
}

void AAPlayerPawn::Rotate()
{
	AddActorLocalRotation(RotationDirection, true);
}




