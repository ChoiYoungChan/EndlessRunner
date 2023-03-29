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

	mLevel.Reserve(10);

	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnLevel::SpawnLevel(bool _isFirst)
{
	mspawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	mspawnRotation = FRotator(0.0f, 90.0f, 0.0f);

	if (!_isFirst)
	{
		ABaseLevel* lastLevel = mlevelList.Last();
		mspawnLocation = lastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}
	mrandomLevel = FMath::RandRange(1,10);
	ABaseLevel* newLevel = nullptr;

	if (mrandomLevel == 1) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(mLevel[mrandomLevel - 1], mspawnLocation,
			mspawnRotation, mspawnInfo);
	}

	if (newLevel)
	{
		if (newLevel->GetTrigger())
		{
			newLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawnLevel::OnOverlapBegin);
		}
	}
	mlevelList.Add(newLevel);
	if (mlevelList.Num() > 5)
	{
		mlevelList.RemoveAt(0);
	}

}

void ASpawnLevel::OnOverlapBegin(UPrimitiveComponent* _overlappedComponent, AActor* _other_actor, 
							     UPrimitiveComponent* _other_component, int32 _otherBodyIndex, bool _bFrom_sweep, 
							     const FHitResult& _sweep_result)
{
	SpawnLevel(false);
}

