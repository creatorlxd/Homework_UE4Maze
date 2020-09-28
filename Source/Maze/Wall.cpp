// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "UObject/ConstructorHelpers.h"
#include "Maze.h"

// Sets default values
AWall::AWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeAsset.Succeeded())
	{
		UE_LOG(LogMaze, Log, TEXT("cube load success"));
		this->GetStaticMeshComponent()->SetStaticMesh(CubeAsset.Object);

		static ConstructorHelpers::FObjectFinder<UMaterial>	Material(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'"));

		if (Material.Succeeded())
		{
			UE_LOG(LogMaze, Log, TEXT("material load success"));
			this->GetStaticMeshComponent()->SetMaterial(0, Material.Object);
		}
		else
		{
			UE_LOG(LogMaze, Error, TEXT("material load fail"));
		}
	}
	else
	{
		UE_LOG(LogMaze, Error, TEXT("cube load fail"));
	}

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

