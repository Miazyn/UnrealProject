// Fill out your copyright notice in the Description page of Project Settings.


#include "APickUp.h"

// Sets default values
AAPickUp::AAPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAPickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

