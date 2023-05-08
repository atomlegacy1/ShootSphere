// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Spikes.h"
#include "Kismet/GameplayStatics.h"


AShootSphereEnemy_Spikes::AShootSphereEnemy_Spikes()
{
	LeftSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("SphereLeftSpikes"));
	LeftSpikesMesh->SetupAttachment(GetMesh());
	RightSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("SphereRightSpikes"));
	RightSpikesMesh->SetupAttachment(GetMesh());
	PlayerDamageCollision = CreateDefaultSubobject<USphereComponent>(FName("SphereDamageCollision"));
	PlayerDamageCollision->SetupAttachment(GetMesh());
	PlayerFinderCollision->SetupAttachment(GetMesh());
}

void AShootSphereEnemy_Spikes::BeginPlay()
{
	Super::BeginPlay();

	PlayerDamageCollision->OnComponentBeginOverlap.AddDynamic
	(this,&ThisClass::AShootSphereEnemy_Spikes::StartApplyDamage);
	PlayerDamageCollision->OnComponentEndOverlap.AddDynamic
	(this,&ThisClass::AShootSphereEnemy_Spikes::StopApplyDamage);

	NewSpikesRotation={0,0,SpikesRotationRate};
	StartSpikesRotation();
	
}

void AShootSphereEnemy_Spikes::StartSpikesRotation()
{
	GetWorldTimerManager().SetTimer(THSpikesRotation,this,&AShootSphereEnemy_Spikes::SpikesRotation,0.01f,true);
}
void AShootSphereEnemy_Spikes::SpikesRotation()
{
	LeftSpikesMesh->SetWorldRotation(LeftSpikesMesh->GetComponentRotation()+NewSpikesRotation);
	RightSpikesMesh->SetWorldRotation(RightSpikesMesh->GetComponentRotation()+NewSpikesRotation);
}

void AShootSphereEnemy_Spikes::StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("PlayerCharacter"))
	{
		CharacterToDamage = OtherActor;
		ApplyDamageToActor();
		GetWorldTimerManager().SetTimer(THDamageCharacter,this,&ThisClass::ApplyDamageToActor,0.5f,true);
	}
}
void AShootSphereEnemy_Spikes::StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("PlayerCharacter"))
	{
		GetWorldTimerManager().ClearTimer(THDamageCharacter);
	}
}
void AShootSphereEnemy_Spikes::ApplyDamageToActor()
{
	UGameplayStatics::ApplyDamage(CharacterToDamage,DamageWhenOverlap,GetInstigatorController(),
this,UDamageType::StaticClass());
}