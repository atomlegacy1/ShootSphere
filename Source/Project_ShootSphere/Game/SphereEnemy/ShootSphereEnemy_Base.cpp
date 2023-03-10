// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"

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