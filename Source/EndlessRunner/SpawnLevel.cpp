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
	m_spawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	m_spawnRotation = FRotator(0.0f, 90.0f, 0.0f);

	if (!_isFirst)
	{
		ABaseLevel* lastLevel = m_levelList.Last();
		m_spawnLocation = lastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}
	m_randomLevel = FMath::RandRange(1,10);
	ABaseLevel* newLevel = nullptr;

	if (m_randomLevel == 1) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level01, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 2) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level02, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 3) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level03, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 4) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level04, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 5) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level05, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 6) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level06, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 7) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level07, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 8) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level08, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 9) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level09, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	} else if (m_randomLevel == 10) {
		newLevel = GetWorld()->SpawnActor<ABaseLevel>(m_level10, m_spawnLocation,
			m_spawnRotation, m_spawnInfo);
	}

	if (newLevel)
	{
		if (newLevel->GetTrigger())
		{
			newLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawnLevel::OnOverlapBegin);
		}
	}
	m_levelList.Add(newLevel);
	if (m_levelList.Num() > 5)
	{
		m_levelList.RemoveAt(0);
	}

}

void ASpawnLevel::OnOverlapBegin(UPrimitiveComponent* _overlappedComponent, AActor* _other_actor, 
							     UPrimitiveComponent* _other_component, int32 _otherBodyIndex, bool _bFrom_sweep, 
							     const FHitResult& _sweep_result)
{
	SpawnLevel(false);
}

