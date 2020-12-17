// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSpawner.h"
#include "WorldPoint.h"
#include "Math/RandomStream.h"

// Sets default values
ACubeSpawner::ACubeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UBlueprint> WorldPointBlueprint(TEXT("Blueprint'/Game/Blueprints/BP_WorldPoint.BP_WorldPoint'"));

	if (WorldPointBlueprint.Object){
		WorldPointBlueprintClass = (UClass*)WorldPointBlueprint.Object->GeneratedClass;
	}
}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("cube spawmer begin"));
	//get the reference to the blueprint class to spawn
	Super::BeginPlay();

	
	auto RandomString = FRandomStream();
	for(int i = 0; i < 50; i++)
	{
		
		int RandValueX = RandomString.RandRange(-200, 200);
		int RandValueY = RandomString.RandRange(-200, 200);
		int RandValueZ = RandomString.RandRange(-200, 200);
		
		/*AWorldPoint* MirroringPlane = GetWorld()->SpawnActor<AWorldPoint>(
        FVector(RandValueX, RandValueY, RandValueZ),
        FRotator::ZeroRotator,
        FActorSpawnParameters());
		*/

		AWorldPoint* DroppedItem = GetWorld()->SpawnActor<AWorldPoint>(
			WorldPointBlueprintClass,
			FVector(RandValueX, RandValueY, RandValueZ),
			FRotator::ZeroRotator,
			FActorSpawnParameters());

		//spawn object
		//save in a list
		//call the method update position from the blueprint in c++
	}
}

// Called every frame
void ACubeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

