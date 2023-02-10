// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/SphereEnemy_UpDown.h"

ASphereEnemy_UpDown::ASphereEnemy_UpDown()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void ASphereEnemy_UpDown::BeginPlay()
{
	Super::BeginPlay();

	SphereSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	
}
void ASphereEnemy_UpDown::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MoveSphereUpDown();
}

void ASphereEnemy_UpDown::MoveSphereUpDown()
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

void ASphereEnemy_UpDown::MoveSphereUp()
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

void ASphereEnemy_UpDown::MoveSphereDown()
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

void ASphereEnemy_UpDown::RandomDirectionSelect()
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
