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
	APawn* mplayer;
	UPROPERTY(EditAnywhere) TArray<TSubclassOf<ABaseLevel>> mLevel;
	TArray<ABaseLevel*> mlevelList;

public:
	int mrandomLevel;
	FVector mspawnLocation = FVector();
	FRotator mspawnRotation = FRotator();
	FActorSpawnParameters mspawnInfo = FActorSpawnParameters();

};
