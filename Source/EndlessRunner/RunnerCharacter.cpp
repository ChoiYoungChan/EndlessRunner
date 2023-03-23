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

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	// set gravity scale
	GetCharacterMovement()->GravityScale = 2.0f;
	// set the flight time
	GetCharacterMovement()->AirControl = 0.8f;
	// set how far and hight can jump
	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	m_tempPos = GetActorLocation();
	m_zPosition = m_tempPos.Z + 300.0f;

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_b_canMove = true;
}

void ARunnerCharacter::MoveRight(float _move_value)
{
	if (m_b_canMove)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), _move_value);
	}
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_tempPos = GetActorLocation();
	m_tempPos.X -= 850.0f;
	m_tempPos.Z = m_zPosition;
	m_sideViewCamera->SetWorldLocation(m_tempPos);
}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ARunnerCharacter::MoveRight);



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

