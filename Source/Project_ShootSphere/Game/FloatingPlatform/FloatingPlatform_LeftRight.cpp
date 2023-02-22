// AtomLegacy1 property


#include "Project_ShootSphere/Game/FloatingPlatform/FloatingPlatform_LeftRight.h"

AFloatingPlatform_LeftRight::AFloatingPlatform_LeftRight()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFloatingPlatform_LeftRight::BeginPlay()
{
	Super::BeginPlay();
	
	MaxMovingDistanceVector.Y=MaxMovingDistance;
	PlatformMovingRateVector.Y=PlatformMovingRate;

	PlatformSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	
}
void AFloatingPlatform_LeftRight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	PlatformMovingSlowDown();
	MovePlatformLeftRight();
}

void AFloatingPlatform_LeftRight::MovePlatformLeftRight()
{
	switch (isMovingLeft)
	{
	case true:
		MovePlatformLeft();
		break;
	case false:
		MovePlatformRight();
		break;
	}
}

void AFloatingPlatform_LeftRight::MovePlatformLeft()
{
	if (isMovingLeft)
	{
		SetActorLocation(GetActorLocation()+PlatformMovingRateVector);
	}
	if (GetActorLocation().Y>=PlatformSpawnLocation.Y+MaxMovingDistanceVector.Y)
	{
		PlatformMovingRateVector.Y = PlatformMovingRate;
		isMovingLeft = false;
	}
	
}

void AFloatingPlatform_LeftRight::MovePlatformRight()
{
	if (!isMovingLeft)
	{
		SetActorLocation(GetActorLocation()-PlatformMovingRateVector);
	}
	if (GetActorLocation().Y<=PlatformSpawnLocation.Y-MaxMovingDistanceVector.Y)
	{
		PlatformMovingRateVector.Y = PlatformMovingRate;
		isMovingLeft = true;
	}
	
}

void AFloatingPlatform_LeftRight::RandomDirectionSelect()
{
	int32 RandomDirection = FMath::RandRange(0,1);
	switch (RandomDirection)
	{
	case 1 :
		isMovingLeft = true;
		break;
	case 0:
		isMovingLeft = false;
		break;
	default:;
	}
}
 void AFloatingPlatform_LeftRight::PlatformMovingSlowDown()
 {
	 switch (isMovingLeft)
	 {
	 case true:
		 if (GetActorLocation().Y>=PlatformSpawnLocation.Y+MaxMovingDistanceVector.Y/2)
		 {
			 if (PlatformMovingRateVector.Y >= PlatformSlowingDownLimit)
			 {
				 PlatformMovingRateVector.Y=PlatformMovingRateVector.Y - PlatformSlowingDownSpeed;
			 }
		 }
	 	break;
	 	
	 case false:
		 if (GetActorLocation().Y<=PlatformSpawnLocation.Y-MaxMovingDistanceVector.Y/2)
		 {
		 	if (PlatformMovingRateVector.Y >= PlatformSlowingDownLimit)
		 	{
		 		PlatformMovingRateVector.Y=PlatformMovingRateVector.Y - PlatformSlowingDownSpeed;
		 	}
		 }
	 		break;
	 }
}