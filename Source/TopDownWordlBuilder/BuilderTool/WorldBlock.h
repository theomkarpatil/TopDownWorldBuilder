// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldBlock.generated.h"

UCLASS()
class TOPDOWNWORDLBUILDER_API AWorldBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldBlock();

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* mMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Variables")
	int32 mBlockIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Variables")
	FVector mGridSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Variables")
	bool mHasPrereqs;
};
