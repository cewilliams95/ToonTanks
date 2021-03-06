// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true, false);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange) {
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::HandleDestruction() 
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::CheckFireCondition()
{
    // If Player is null or is dead then stop
	if(!PlayerPawn) 
	{
		return;
	}

    // If Player is within range fire
	if(ReturnDistanceToPlayer() <= FireRange)
	{
		// Fire
		Fire();

	}

}

float APawnTurret::ReturnDistanceToPlayer()
{
	if(!PlayerPawn) 
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
	
}