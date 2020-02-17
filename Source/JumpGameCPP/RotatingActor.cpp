// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotatingActor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingActor"));
	RotatingActor->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator NewRotation = GetActorRotation();
	float Rotation = DeltaTime * 20.0f;
	NewRotation.Yaw += Rotation;
	SetActorRotation(NewRotation);
}

