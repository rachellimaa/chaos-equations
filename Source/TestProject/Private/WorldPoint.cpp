// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPoint.h"

// Sets default values
AWorldPoint::AWorldPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh "));

	const auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	
	Cube->SetStaticMesh(MeshAsset.Object);
	
	UE_LOG(LogTemp, Warning, TEXT("End of constructor"));
}

// Called when the game starts or when spawned
void AWorldPoint::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Begin play"));
}


