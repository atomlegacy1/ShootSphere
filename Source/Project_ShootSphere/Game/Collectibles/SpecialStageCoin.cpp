// AtomLegacy1 property


#include "Project_ShootSphere/Game/Collectibles/SpecialStageCoin.h"

#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"

ASpecialStageCoin::ASpecialStageCoin()
{
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ASpecialStageCoin::GiveSpecialCoinByOverlap);
	
}

void ASpecialStageCoin::GiveSpecialCoinByOverlap(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AShootSpherePlayerCharacter_Base* PlayerCharacter = Cast<AShootSpherePlayerCharacter_Base>(OtherActor);
	if (OtherActor==PlayerCharacter)
	{
		PlayerCharacter->SpecialStageCoinCollected++;
		Destroy();
	}
	
}
