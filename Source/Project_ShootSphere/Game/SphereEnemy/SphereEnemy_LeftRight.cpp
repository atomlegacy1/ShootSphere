// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/SphereEnemy_LeftRight.h"
#include "Project_ShootSphere/Core/GameMode/ShootSphereGameMode.h"

ASphereEnemy_LeftRight::ASphereEnemy_LeftRight()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereCollisionComponent->SetSphereRadius(100);
	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this,
		&ThisClass::GivePointsByOverlap);
}

void ASphereEnemy_LeftRight::BeginPlay()
{
	Super::BeginPlay();
	
	MaxMovingDistanceVector.Y=MaxMovingDistance;
	SphereMovingRateVector.Y=SphereMovingRate;

	SphereSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	
}
void ASphereEnemy_LeftRight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SphereMovingSlowDown();
	MoveSphereLeftRight();
}
void ASphereEnemy_LeftRight::MoveSphereLeftRight()
{
	switch (isMovingLeft)
	{
	case true:
		MoveSphereLeft();
		break;
	case false:
		MoveSphereRight();
		break;
	}
}
void ASphereEnemy_LeftRight::MoveSphereLeft()
{
	if (isMovingLeft)
	{
		SetActorLocation(GetActorLocation()+SphereMovingRateVector);
	}
	if (GetActorLocation().Y>=SphereSpawnLocation.Y+MaxMovingDistanceVector.Y)
	{
		SphereMovingRateVector.Y = SphereMovingRate;
		isMovingLeft = false;
	}
	
}
void ASphereEnemy_LeftRight::MoveSphereRight()
{
	if (!isMovingLeft)
	{
		SetActorLocation(GetActorLocation()-SphereMovingRateVector);
	}
	if (GetActorLocation().Y<=SphereSpawnLocation.Y-MaxMovingDistanceVector.Y)
	{
		SphereMovingRateVector.Y = SphereMovingRate;
		isMovingLeft = true;
	}
	
}
void ASphereEnemy_LeftRight::RandomDirectionSelect()
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
void ASphereEnemy_LeftRight::SphereMovingSlowDown()
 {
	 switch (isMovingLeft)
	 {
	 case true:
		 if (GetActorLocation().Y>=SphereSpawnLocation.Y+MaxMovingDistanceVector.Y/2)
		 {
			 if (SphereMovingRateVector.Y >= SphereSlowingDownLimit)
			 {
				 SphereMovingRateVector.Y=SphereMovingRateVector.Y - SphereSlowingDownSpeed;
			 }
		 }
	 	break;
	 	
	 case false:
		 if (GetActorLocation().Y<=SphereSpawnLocation.Y-MaxMovingDistanceVector.Y/2)
		 {
		 	if (SphereMovingRateVector.Y >= SphereSlowingDownLimit)
		 	{
		 		SphereMovingRateVector.Y=SphereMovingRateVector.Y - SphereSlowingDownSpeed;
		 	}
		 }
	 		break;
	 }
}

void ASphereEnemy_LeftRight::GivePointsByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor==Cast<ASpherePlayerWeapon_Projectile>(OtherActor))
	{
		Destroy();
		auto LevelGamemode = Cast<AShootSphereGameMode>(GetWorld()->GetAuthGameMode());
		LevelGamemode->TotalPlayerPoints= LevelGamemode->TotalPlayerPoints + SpherePoints;
	}
}
