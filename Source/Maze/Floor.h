// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Floor.generated.h"

UCLASS()
class MAZE_API AFloor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetColorBlue();
	void SetColorRed();
	void SetColorGreen();
private:
	UMaterial* m_pBaseMaterial, * m_pRedMaterial, * m_pGreenMaterial, * m_pBlueMaterial;
};
