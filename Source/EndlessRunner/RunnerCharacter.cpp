// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Spikes.h"
#include "WallSpikes.h"

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

	msideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Cam"));
	// make block rotation of side cam
	msideViewCamera->bUsePawnControlRotation = false;

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

	mtempPos = GetActorLocation();
	mzPosition = mtempPos.Z + 300.0f;

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// collision determination
	// when collision determin with other collision and this capsule component activate OnOverlapBegin
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ARunnerCharacter::OnOverlapBegin);

	mbcanMove = true;
}

void ARunnerCharacter::MoveRight(float _move_value)
{
	if (mbcanMove)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), _move_value);
	}
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mtempPos = GetActorLocation();
	mtempPos.X -= 850.0f;
	mtempPos.Z = mzPosition;
	msideViewCamera->SetWorldLocation(mtempPos);
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
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* _overlappedComponent,
	AActor* _other_actor, UPrimitiveComponent* _other_component, int32 _otherBodyIndex,
	bool _bFrom_sweep, const FHitResult& _sweep_result)
{
	if (_other_actor != nullptr)
	{
		ASpikes* wallSpike = Cast<AWallSpikes>(_other_actor);
		ASpikes* spike = Cast<ASpikes>(_other_actor);

		if (wallSpike || spike)
		{
			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);

			mbcanMove = false;

			FTimerHandle unusedHandle;
			GetWorldTimerManager().SetTimer(unusedHandle, this, &ARunnerCharacter::ReStartLevel, 2.0f, false);
		}
	}
}

