// AtomLegacy1 property


#include "Project_ShootSphere/Game/DamagingTraps/DamagingSpikesClass.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Kismet/GameplayStatics.h"


ADamagingSpikesClass::ADamagingSpikesClass()
{
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::ApplyDamageByOverlap);
}

void ADamagingSpikesClass::ApplyDamageByOverlap(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::ApplyDamage(SweepResult.GetActor(),
		DamageToCause,GetInstigatorController(),this,UDamageType::StaticClass());
}
