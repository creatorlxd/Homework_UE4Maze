// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Maze.h"

// Sets default values
AFloor::AFloor()
{
	ConstructorHelpers::FObjectFinder<UMaterial> BaseMaterial(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	ConstructorHelpers::FObjectFinder<UMaterial> RedMaterial(TEXT("Material'/Game/Material/RedMaterial.RedMaterial'"));
	ConstructorHelpers::FObjectFinder<UMaterial> GreenMaterial(TEXT("Material'/Game/Material/GreenMaterial.GreenMaterial'"));
	ConstructorHelpers::FObjectFinder<UMaterial> BlueMaterial(TEXT("Material'/Game/Material/BlueMaterial.BlueMaterial'"));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if ((!BaseMaterial.Succeeded()) || (!RedMaterial.Succeeded()) || (!GreenMaterial.Succeeded()) || (!BlueMaterial.Succeeded()))
	{
		UE_LOG(LogMaze, Error, TEXT("load material failed"));
	}
	else
	{
		m_pBaseMaterial = BaseMaterial.Object;
		m_pRedMaterial = RedMaterial.Object;
		m_pGreenMaterial = GreenMaterial.Object;
		m_pBlueMaterial = BlueMaterial.Object;
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeAsset.Succeeded())
	{
		UE_LOG(LogMaze, Log, TEXT("cube load success"));
		this->GetStaticMeshComponent()->SetStaticMesh(CubeAsset.Object);
		this->GetStaticMeshComponent()->SetMaterial(0, BaseMaterial.Object);
	}
	else
	{
		UE_LOG(LogMaze, Error, TEXT("cube load fail"));
	}
}
// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloor::SetColorBlue()
{
	GetStaticMeshComponent()->SetMaterial(0, m_pBlueMaterial);
}

void AFloor::SetColorRed()
{
	GetStaticMeshComponent()->SetMaterial(0, m_pRedMaterial);
}

void AFloor::SetColorGreen()
{
	GetStaticMeshComponent()->SetMaterial(0, m_pGreenMaterial);
}

