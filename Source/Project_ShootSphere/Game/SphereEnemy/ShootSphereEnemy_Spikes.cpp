// AtomLegacy1 property


#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Spikes.h"


AShootSphereEnemy_Spikes::AShootSphereEnemy_Spikes()
{
	LeftSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("SphereLeftSpikes"));
	LeftSpikesMesh->SetupAttachment(SphereRootComponent);
	RightSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("SphereRightSpikes"));
	RightSpikesMesh->SetupAttachment(SphereRootComponent);
	PlayerFinderColl = CreateDefaultSubobject<USphereComponent>(FName("SpherePlayerTrigger"));
	PlayerFinderColl->SetupAttachment(SphereStaticMesh);
}

void AShootSphereEnemy_Spikes::BeginPlay()
{
	Super::BeginPlay();

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
