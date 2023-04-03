 // AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/SphereEnemy_UpDown.h"
#include "Project_ShootSphere/Core/GameMode/ShootSphereGameMode.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"

 ASphereEnemy_UpDown::ASphereEnemy_UpDown()
{
	PrimaryActorTick.bCanEverTick = true;
 	SphereCollisionComponent->SetSphereRadius(100);
}

void ASphereEnemy_UpDown::BeginPlay()
{
	Super::BeginPlay();

 	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this,
	&ThisClass::GivePointsByOverlap);
	
	MaxMovingDistanceVector.Z=MaxMovingDistance;
	SphereMovingRateVector.Z=SphereMovingRate;

	SphereSpawnLocation = GetActorLocation();
	RandomDirectionSelect();
	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic(this,
	&ThisClass::GivePointsByOverlap);
	
}
void ASphereEnemy_UpDown::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SphereMovingSlowDown();
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
		SetActorLocation(GetActorLocation()+SphereMovingRateVector);
	}
	if (GetActorLocation().Z>=SphereSpawnLocation.Z+MaxMovingDistanceVector.Z)
	{
		SphereMovingRateVector.Z = SphereMovingRate;
		isMovingUp = false;
	}
	
}
void ASphereEnemy_UpDown::MoveSphereDown()
{
	if (!isMovingUp)
	{
		SetActorLocation(GetActorLocation()-SphereMovingRateVector);
	}
	if (GetActorLocation().Z<=SphereSpawnLocation.Z-MaxMovingDistanceVector.Z)
	{
		SphereMovingRateVector.Z = SphereMovingRate;
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
void ASphereEnemy_UpDown::SphereMovingSlowDown()
 {
	 switch (isMovingUp)
	 {
	 case true:
		 if (GetActorLocation().Z>=SphereSpawnLocation.Z+MaxMovingDistanceVector.Z/2)
		 {
			 if (SphereMovingRateVector.Z >= SphereSlowingDownLimit)
			 {
				 SphereMovingRateVector.Z=SphereMovingRateVector.Z - SphereSlowingDownSpeed;
			 }
		 }
	 	break;
	 	
	 case false:
		 if (GetActorLocation().Z<=SphereSpawnLocation.Z-MaxMovingDistanceVector.Z/2)
		 {
		 	if (SphereMovingRateVector.Z >= SphereSlowingDownLimit)
		 	{
		 		SphereMovingRateVector.Z=SphereMovingRateVector.Z - SphereSlowingDownSpeed;
		 	}
		 }
	 		break;
	 }
 }

void ASphereEnemy_UpDown::GivePointsByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor==Cast<ASpherePlayerWeapon_Projectile>(OtherActor))
	{
		Destroy();
		auto LevelGamemode = Cast<AShootSphereGameMode>(GetWorld()->GetAuthGameMode());
		LevelGamemode->TotalPlayerPoints= LevelGamemode->TotalPlayerPoints + SpherePoints;
	}
}