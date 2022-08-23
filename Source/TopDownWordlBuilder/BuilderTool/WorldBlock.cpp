// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldBlock.h"

// Sets default values
AWorldBlock::AWorldBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Components
	mMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mMesh;
}

// Called when the game starts or when spawned
void AWorldBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

