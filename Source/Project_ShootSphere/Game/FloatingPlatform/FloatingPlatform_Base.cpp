// AtomLegacy1 property


#include "Project_ShootSphere/Game/FloatingPlatform/FloatingPlatform_Base.h"


AFloatingPlatform_Base::AFloatingPlatform_Base()
{
	
	PrimaryActorTick.bCanEverTick = false;

	PlatformRoot = CreateDefaultSubobject<USceneComponent>(FName("PlatformRoot"));
	SetRootComponent(PlatformRoot);
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlatformMesh"));
	PlatformMesh->SetupAttachment(PlatformRoot);

}

