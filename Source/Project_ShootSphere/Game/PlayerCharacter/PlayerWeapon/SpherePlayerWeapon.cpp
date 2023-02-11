// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/PlayerWeapon/SpherePlayerWeapon.h"

ASpherePlayerWeapon::ASpherePlayerWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("PlayerWeapon Root Component"));
	SetRootComponent(WeaponSceneRoot);
	
	WeaponBase = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Base component"));
	WeaponBase->SetupAttachment(WeaponSceneRoot);

	WeaponLights = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Lights component"));
	WeaponLights->SetupAttachment(WeaponBase);

	WeaponDirection = CreateDefaultSubobject<UArrowComponent>(FName("WeaponDirection arrow component"));

}

void ASpherePlayerWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePlayerWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

