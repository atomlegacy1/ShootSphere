// AtomLegacy1 property

#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Character.h"

#include "Components/CapsuleComponent.h"
#include "Project_ShootSphere/Core/GameMode/ShootSphereGameMode.h"

AShootSphereEnemy_Character::AShootSphereEnemy_Character()
{
	PrimaryActorTick.bCanEverTick = false;

	PlayerFinderCollision = CreateDefaultSubobject<USphereComponent>(FName("PlayerCollisionFinder"));

}

void AShootSphereEnemy_Character::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic
	(this,&ThisClass::AShootSphereEnemy_Character::GetScoreByOverlapAndDestroy);
}

void AShootSphereEnemy_Character::GetScoreByOverlapAndDestroy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Projectile"))
	{
		auto LevelGamemode = Cast<AShootSphereGameMode>(GetWorld()->GetAuthGameMode());
		LevelGamemode->TotalPlayerPoints += SphereScore;
		Destroy();
	}
}