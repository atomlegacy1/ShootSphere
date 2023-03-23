// AtomLegacy1 property

#include "Project_ShootSphere/Game/DamagingTraps/DamagingTrapsBase.h"


ADamagingTrapsBase::ADamagingTrapsBase()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComp = CreateDefaultSubobject<USceneComponent>(FName("SceneRootComponent"));
	SetRootComponent(RootComp);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshComponent"));
	MeshComp->SetupAttachment(RootComp);
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollisionComponent"));
	CollisionComp->SetupAttachment(RootComp);
}


