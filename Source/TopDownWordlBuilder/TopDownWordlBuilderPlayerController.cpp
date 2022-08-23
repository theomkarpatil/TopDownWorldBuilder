// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownWordlBuilderPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "TopDownWordlBuilderCharacter.h"
#include "Engine/World.h"

#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ATopDownWordlBuilderPlayerController::ATopDownWordlBuilderPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATopDownWordlBuilderPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ATopDownWordlBuilderPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATopDownWordlBuilderPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATopDownWordlBuilderPlayerController::OnSetDestinationReleased);


	// setting up movement
	InputComponent->BindAxis("Look Around", this, &ATopDownWordlBuilderPlayerController::TurnAround);
	InputComponent->BindAxis("Move Forward / Backwards", this, &ATopDownWordlBuilderPlayerController::MoveForward);
	InputComponent->BindAxis("Move Sideways", this, &ATopDownWordlBuilderPlayerController::MoveSideways);

}

void ATopDownWordlBuilderPlayerController::MoveForward(float aValue)
{
	if (aValue != 0.0f)
	{
		const FVector direction = GetCharacter()->GetActorForwardVector();
		GetCharacter()->AddMovementInput(direction, aValue);
	}
}

void ATopDownWordlBuilderPlayerController::MoveSideways(float aValue)
{
	if (aValue != 0.0f)
	{
		const FVector direction = GetCharacter()->GetActorRightVector();
		GetCharacter()->AddMovementInput(direction, aValue);
	}
}

void ATopDownWordlBuilderPlayerController::OnSetDestinationPressed()
{
	// We flag that the input is being pressed
	bInputPressed = true;
	// Just in case the character was moving because of a previous short press we stop it
	StopMovement();
}

void ATopDownWordlBuilderPlayerController::OnSetDestinationReleased()
{
	// Player is no longer pressing the input
	bInputPressed = false;

	// If it was a short press
	if(FollowTime <= ShortPressThreshold)
	{
		// We look for the location in the world where the player has pressed the input
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		HitLocation = Hit.Location;

		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, HitLocation, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
}
