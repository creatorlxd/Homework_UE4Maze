// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMaze.h"
#include "Stack.h"
#include <utility>
#include <vector>
#include "Floor.h"
#include "MazePlayerController.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> WinHUDAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> LoseHUDAsset;

	UFUNCTION(BlueprintCallable)
		void LoadMazeFile(const FString& FileName);

private:
	FVector TransformLocationFromBlockLocation(int sx, int sy, int x, int y, float fz);
private:
	typename MazeMap m_MazeMap;
	Stack<std::pair<int, int>> m_PositionStack;
	std::vector<std::vector<AFloor*> > m_Floors;
	std::vector<std::vector<bool> > m_Flag;
	AMazePlayerController* m_pController;
	int m_StartX, m_StartY;
	int m_DstX, m_DstY;
};
