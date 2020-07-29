// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay() 
{
    // Get references and game win/lose conditions

    // call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
    
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of actor died, if turret, tally, if player go to lose condition
    UE_LOG(LogTemp, Warning, TEXT("A pawn died."));
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // Init the start countdown turret acitiation, pawn check
    // call bp gamestart
}

void ATankGameModeBase::HandleGameStart() 
{
    // see if player killed all turrets show win
    // else if turret killed player show lose
    // call bp gameover
}
