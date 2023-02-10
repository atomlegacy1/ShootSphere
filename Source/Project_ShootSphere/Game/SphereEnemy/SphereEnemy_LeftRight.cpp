// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/SphereEnemy_LeftRight.h"

ASphereEnemy_LeftRight::ASphereEnemy_LeftRight()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASphereEnemy_LeftRight::BeginPlay()
{
	Super::BeginPlay();

	SphereSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	
}
void ASphereEnemy_LeftRight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MoveSphereUpDown();
}

void ASphereEnemy_LeftRight::MoveSphereUpDown()
{
	switch (isMovingUp)
	{
	case true:
		MoveSphereUp();
		break;
	case false:
		MoveSphereDown();
		break;
	}
}

void ASphereEnemy_LeftRight::MoveSphereUp()
{
	if (isMovingUp)
	{
		SetActorLocation(GetActorLocation()+SphereMovingRate);
	}
	if (GetActorLocation()==SphereSpawnLocation+MaxMovingDistanceUp)
	{
		isMovingUp = false;
	}
	
}

void ASphereEnemy_LeftRight::MoveSphereDown()
{
	if (!isMovingUp)
	{
		SetActorLocation(GetActorLocation()-SphereMovingRate);
	}
	if (GetActorLocation()==SphereSpawnLocation-MaxMovingDistanceUp)
	{
		isMovingUp = true;
	}
	
}

void ASphereEnemy_LeftRight::RandomDirectionSelect()
{
	int32 RandomDirection = FMath::RandRange(0,1);
	switch (RandomDirection)
	{
	case 1 :
		isMovingUp = true;
		break;
	case 0:
		isMovingUp = false;
		break;
	default:;
	}
}
