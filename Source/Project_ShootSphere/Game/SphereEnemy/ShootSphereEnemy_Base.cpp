// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "Project_ShootSphere/Core/GameMode/ShootSphereGameMode.h"

AShootSphereEnemy_Base::AShootSphereEnemy_Base()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereRootComponent = CreateDefaultSubobject<USceneComponent>(FName("Sphere root Component"));
	SetRootComponent(SphereRootComponent);
	SphereStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Sphere Static Mesh"));
	SphereStaticMesh->SetupAttachment(SphereRootComponent);
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collision Component"));
	SphereCollisionComponent->SetupAttachment(SphereRootComponent);
	SphereCollisionComponent->SetCollisionProfileName("Trigger");

}

void AShootSphereEnemy_Base::BeginPlay()
{
	Super::BeginPlay();

	SphereCollisionComponent->OnComponentBeginOverlap.AddDynamic
	(this,&ThisClass::AShootSphereEnemy_Base::GetScoreByOverlapAndDestroy);
}


void AShootSphereEnemy_Base::GetScoreByOverlapAndDestroy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Projectile"))
	{
		auto LevelGamemode = Cast<AShootSphereGameMode>(GetWorld()->GetAuthGameMode());
		LevelGamemode->TotalPlayerPoints += SphereScore;
		Destroy();
	}
}