// AtomLegacy1 property

#include "Project_ShootSphere/Game/Collectibles/SpecialStageCoin.h"

ASpecialStageCoin::ASpecialStageCoin()
{
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ASpecialStageCoin::GiveSpecialCoinByOverlap);
	
}

void ASpecialStageCoin::GiveSpecialCoinByOverlap(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
 {
		auto PlayerCharacterRef = Cast<AShootSpherePlayerCharacter_Base>(OtherActor);
		PlayerCharacterRef->SpecialCoinsCollected++;
		Destroy();
}
