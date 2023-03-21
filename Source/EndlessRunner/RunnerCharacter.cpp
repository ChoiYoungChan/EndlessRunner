// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	// 
	// 
	GetCapsuleComponent()->SetCollisionResponseToChannel
	(ECC_GameTraceChannel1, ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	m_sideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Cam"));
	// make block rotation of side cam
	m_sideViewCamera->bUsePawnControlRotation = false;



}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARunnerCharacter::MoveRight(float _move_value)
{
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARunnerCharacter::ReStartLevel()
{
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* _overlappedComponent,
	AActor* _other_actor, UPrimitiveComponent* _other_component, int32 _otherBodyIndex,
	bool _bFrom_sweep, const FHitResult& _sweep_result)
{
	return UFUNCTION() void();
}

