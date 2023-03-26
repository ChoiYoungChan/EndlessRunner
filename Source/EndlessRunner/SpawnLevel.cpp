// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnLevel.h"
#include "BaseLevel.h"
#include "Engine.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpawnLevel::ASpawnLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION() void ASpawnLevel::SpawnLevel(bool _isFirst)
{
	
}

UFUNCTION() void ASpawnLevel::OnOverlapBegin(UPrimitiveComponent* _overlappedComponent, AActor* _other_actor, UPrimitiveComponent* _other_component, int32 _otherBodyIndex, bool _bFrom_sweep, const FHitResult& _sweep_result)
{
	
}

