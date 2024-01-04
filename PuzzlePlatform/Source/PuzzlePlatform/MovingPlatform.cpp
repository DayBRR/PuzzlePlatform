// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Point 1. Must Replicate in client
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);	
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	/*
	Method HasAuthority() return:
	 - True if I am the server
	 - False if I am the client
	*/	
	/*
	FVector Location = GetActorLocation();
	Location += FVector(Speed * DeltaTime, 0, 0);
	SetActorLocation(Location);
	*/
	// This code move only in server if not have config point 1
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		Location += FVector(5 * DeltaTime, 0, 0);
		SetActorLocation(Location);
	}

	// This code move only in client
	/*
	if (!HasAuthority()) // Not on server == client
	{
		FVector Location = GetActorLocation();
		Location += FVector(5 * DeltaTime, 0, 0);
		SetActorLocation(Location);
	}
	*/
}