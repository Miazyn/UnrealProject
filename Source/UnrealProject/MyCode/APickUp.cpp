// Fill out your copyright notice in the Description page of Project Settings.


#include "APickUp.h"
#include "Components/SphereComponent.h"

// Sets default values
AAPickUp::AAPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	RootComponent = SphereComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment((RootComponent));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere"));
	if (MeshAsset.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("Found Basic Mesh"));
		BaseMesh->SetStaticMesh(MeshAsset.Object);
	}

	SphereComp->SetWorldScale3D(FVector(SphereScale, SphereScale, SphereScale));
	BaseMesh->SetWorldScale3D(FVector(BaseMeshScale, BaseMeshScale, BaseMeshScale));
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

