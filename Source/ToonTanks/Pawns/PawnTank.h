// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

/**
 * 
 */
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

	public:
		APawnTank();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	private:
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess))
		float MoveSpeed = 100.0f;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess))
		float RotateSpeed = 100.0f;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess))
		float SprintModifier = 1.75f;


		FVector MoveDirection;
		FQuat RotationDirection;

		APlayerController* PlayerControllerRef;

		void CalculateMoveInput(float Value);
		void CalculateRotateInput(float Value);

		void Move();
		void Rotate();

		void StartSprint();
		void EndSprint();
	

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		virtual void HandleDestruction() override;

};
