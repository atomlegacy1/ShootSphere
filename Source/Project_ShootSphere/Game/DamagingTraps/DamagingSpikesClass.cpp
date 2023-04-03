// AtomLegacy1 property


#include "Project_ShootSphere/Game/DamagingTraps/DamagingSpikesClass.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Kismet/GameplayStatics.h"


void ADamagingSpikesClass::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::StartApplyDamage);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this,&ThisClass::StopApplyDamage);
}


void ADamagingSpikesClass::StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		CharacterToDamage = OtherActor;
		GetWorldTimerManager().SetTimer(THDamageApply,this,&ThisClass::ApplyDamageToActor,2.5f,true);
	}
}

void ADamagingSpikesClass::StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		GetWorldTimerManager().ClearTimer(THDamageApply);
	}
}

void ADamagingSpikesClass::ApplyDamageToActor()
{
	UGameplayStatics::ApplyDamage(CharacterToDamage,DamageToCause,GetInstigatorController(),
this,UDamageType::StaticClass());
}