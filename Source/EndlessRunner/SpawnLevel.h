// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnLevel.generated.h"

class ABaseLevel;

UCLASS()
class ENDLESSRUNNER_API ASpawnLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION() void SpawnLevel(bool _isFirst);

	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* _overlappedComponent,
		AActor* _other_actor,
		UPrimitiveComponent* _other_component,
		int32 _otherBodyIndex, bool _bFrom_sweep, const FHitResult& _sweep_result);

protected:
	APawn* m_player;

	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level01;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level02;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level03;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level04;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level05;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level06;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level07;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level08;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level09;
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseLevel>  m_level10;

	TArray<ABaseLevel*> m_levelList;

public:
	int m_randomLevel;
	FVector m_spawnLocation = FVector();
	FRotator m_spawnRotation = FRotator();
	FActorSpawnParameters m_spawnInfo = FActorSpawnParameters();

};
