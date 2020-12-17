// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldPoint.generated.h"

UCLASS()
class TESTPROJECT_API AWorldPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldPoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Cube;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateActorPosition(float Time);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
