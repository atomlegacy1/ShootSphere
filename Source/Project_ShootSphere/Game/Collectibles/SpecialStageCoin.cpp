// AtomLegacy1 property


#include "Project_ShootSphere/Game/Collectibles/SpecialStageCoin.h"

ASpecialStageCoin::ASpecialStageCoin()
{
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::OverlapBegin);
	
}


void ASpecialStageCoin::OverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}
