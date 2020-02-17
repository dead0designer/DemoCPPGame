// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Engine/Engine.h"

// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("using MyBaseCharacter"));
	}

}

// Called every frame
void AMyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector ActorLocation = GetActorLocation();
	if ((ActorLocation.Z == KillZ) || (ActorLocation.Z < KillZ))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Critical Z-value! Move to start!"));
		SetActorLocation(FVector(0.0f, 0.0f, 112.0f));
	}
}

// Called to bind functionality to input
void AMyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyBaseCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyBaseCharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyBaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyBaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyBaseCharacter::AddControllerPitchInput);
}

void AMyBaseCharacter::MoveForward(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMyBaseCharacter::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

