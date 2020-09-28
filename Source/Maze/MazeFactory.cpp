// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeFactory.h"
#include "Maze.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework\PlayerStart.h"

// Sets default values
AMazeFactory::AMazeFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeFactory::BeginPlay()
{
	Super::BeginPlay();
	auto filename = FPaths::ProjectContentDir() / FString("MazeMap") / FileName;
	/*TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), Actors);

	for (AActor* Actor : Actors)
	{
		UE_LOG(LogMaze, Log, TEXT("get"));
		(Cast<APlayerStart>(Actor))->SetActorLocation(FVector(0, 0, 0));
	}*/
	//TODO: dynamic spwan playerstart
	std::ifstream ifile(filename.GetCharArray().GetData());
	ifile >> m_MazeMap;
	UE_LOG(LogMaze, Log, TEXT("%d %d"), m_MazeMap.x, m_MazeMap.y);
}

// Called every frame
void AMazeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

