// AtomLegacy1 property

#include "Project_ShootSphere/Game/FloatingPlatform/FloatingPlatform_UpDown.h"

AFloatingPlatform_UpDown::AFloatingPlatform_UpDown()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AFloatingPlatform_UpDown::BeginPlay()
{
	Super::BeginPlay();
	
	MaxMovingDistanceVector.Z=MaxMovingDistance;
	SphereMovingRateVector.Z=PlatformMovingRate;

	PlatformSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	
}
void AFloatingPlatform_UpDown::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	PlatformMovingSlowDown();
	MovePlatformUpDown();
}

void AFloatingPlatform_UpDown::MovePlatformUpDown()
{
	switch (isMovingUp)
	{
	case true:
		MovePlatformUp();
		break;
	case false:
		MovePlatformDown();
		break;
	}
}

void AFloatingPlatform_UpDown::MovePlatformUp()
{
	if (isMovingUp)
	{
		SetActorLocation(GetActorLocation()+SphereMovingRateVector);
	}
	if (GetActorLocation().Z>=PlatformSpawnLocation.Z+MaxMovingDistanceVector.Z)
	{
		SphereMovingRateVector.Z = PlatformMovingRate;
		isMovingUp = false;
	}
	
}

void AFloatingPlatform_UpDown::MovePlatformDown()
{
	if (!isMovingUp)
	{
		SetActorLocation(GetActorLocation()-SphereMovingRateVector);
	}
	if (GetActorLocation().Z<=PlatformSpawnLocation.Z-MaxMovingDistanceVector.Z)
	{
		SphereMovingRateVector.Z = PlatformMovingRate;
		isMovingUp = true;
	}
	
}

void AFloatingPlatform_UpDown::RandomDirectionSelect()
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
 void AFloatingPlatform_UpDown::PlatformMovingSlowDown()
 {
	 switch (isMovingUp)
	 {
	 case true:
		 if (GetActorLocation().Z>=PlatformSpawnLocation.Z+MaxMovingDistanceVector.Z/2)
		 {
			 if (SphereMovingRateVector.Z >= PlatformSlowingDownLimit)
			 {
				 SphereMovingRateVector.Z=SphereMovingRateVector.Z - PlatformSlowingDownSpeed;
			 }
		 }
	 	break;
	 	
	 case false:
		 if (GetActorLocation().Z<=PlatformSpawnLocation.Z-MaxMovingDistanceVector.Z/2)
		 {
		 	if (SphereMovingRateVector.Z >= PlatformSlowingDownLimit)
		 	{
		 		SphereMovingRateVector.Z=SphereMovingRateVector.Z - PlatformSlowingDownSpeed;
		 	}
		 }
	 		break;
	 }
 }