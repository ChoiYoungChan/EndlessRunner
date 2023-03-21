// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere) class UCameraComponent* m_sideViewCamera;

public:
	// Sets default values for this character's properties
	ARunnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float _move_value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ReStartLevel();

	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* _overlappedComponent,
		AActor* _other_actor,
		UPrimitiveComponent* _other_component,
		int32 _otherBodyIndex, bool _bFrom_sweep, const FHitResult& _sweep_result);

public:
	class UCameraComponent* GetSideViewCameraComponent() const
	{
		return m_sideViewCamera;
	}

private:
	float m_zPosition;
	FVector m_tempPos = FVector();
	bool m_b_canMove;

};
