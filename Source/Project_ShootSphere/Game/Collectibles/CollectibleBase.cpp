// AtomLegacy1 property


#include "Project_ShootSphere/Game/Collectibles/CollectibleBase.h"

ACollectibleBase::ACollectibleBase()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComp = CreateDefaultSubobject<USceneComponent>(FName("Collectible root"));
	SetRootComponent(RootComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collectible mesh"));
	StaticMeshComp->SetupAttachment(RootComp);
	CollisionComp = CreateDefaultSubobject<USphereComponent>(FName("Collectible collision"));
	CollisionComp->SetupAttachment(RootComp);

}

