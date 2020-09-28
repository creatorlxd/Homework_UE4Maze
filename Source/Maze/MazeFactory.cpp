// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeFactory.h"
#include "Maze.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "UObject/NameTypes.h"
#include "UObject/UObjectBase.h"
#include "Wall.h"

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

	m_pController = Cast<AMazePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

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

	int sx, sy;
	for (int i = 0; i < m_MazeMap.x; i++)
	{
		for (int j = 0; j < m_MazeMap.y; j++)
		{
			if (m_MazeMap.m_Content[i][j] == MazeType::Src)
			{
				sx = i;
				sy = j;
			}
			else if (m_MazeMap.m_Content[i][j] == MazeType::Dst)
			{
				m_DstX = i;
				m_DstY = j;
			}
		}
	}
	UE_LOG(LogMaze, Log, TEXT("start %d %d"), sx, sy);
	for (int i = 0; i < m_MazeMap.x; i++)
	{
		for (int j = 0; j < m_MazeMap.y; j++)
		{
			if (m_MazeMap.m_Content[i][j] == MazeType::Wall)
			{
				GetWorld()->SpawnActor<AWall>(AWall::StaticClass(), FVector((sx - i) * 100, (j - sy) * 100, 0), FRotator(0));
			}
		}
	}

	m_Floors.resize(m_MazeMap.x, std::vector<AFloor*>(m_MazeMap.y, nullptr));
	m_Flag.resize(m_MazeMap.x, std::vector<bool>(m_MazeMap.y, false));

	for (int i = 0; i < m_MazeMap.x; i++)
	{
		for (int j = 0; j < m_MazeMap.y; j++)
		{
			auto pfloor = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), FVector((sx - i) * 100, (j - sy) * 100, -100), FRotator(0));
			if (m_MazeMap.m_Content[i][j] == MazeType::Dst)
				pfloor->SetColorBlue();
			m_Floors[i][j] = pfloor;
		}
	}

	m_PositionStack.Push(std::make_pair(sx, sy));
	m_Flag[sx][sy] = true;
	m_Floors[sx][sy]->SetColorGreen();

	m_StartX = sx;
	m_StartY = sy;
}

// Called every frame
void AMazeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	static const float Duration = 0.5;
	static float TimeCount = 0;
	TimeCount += DeltaTime;
	if (TimeCount >= Duration)
	{
		TimeCount = 0;
		if (m_PositionStack.Top().first == m_DstX && m_PositionStack.Top().second == m_DstY)
		{
			//todo : win
		}
		else
		{
			int nx = m_PositionStack.Top().first;
			int ny = m_PositionStack.Top().second;

		}
	}
}

