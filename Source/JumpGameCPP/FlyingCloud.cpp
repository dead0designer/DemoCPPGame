// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingCloud.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFlyingCloud::AFlyingCloud()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void AFlyingCloud::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyingCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 160.0f;
	SetActorLocation(NewLocation);
}

