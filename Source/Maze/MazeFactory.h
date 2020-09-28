// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMaze.h"
#include "MazeFactory.generated.h"

UCLASS()
class MAZE_API AMazeFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMazeFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "Maze")
		FString FileName;

private:
	typename MazeMap m_MazeMap;
};
