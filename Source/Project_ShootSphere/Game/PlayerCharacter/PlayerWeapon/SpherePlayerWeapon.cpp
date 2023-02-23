// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/PlayerWeapon/SpherePlayerWeapon.h"

ASpherePlayerWeapon::ASpherePlayerWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("PlayerWeapon Root Component"));
	SetRootComponent(WeaponSceneRoot);
	
	WeaponBase = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Base component"));
	WeaponBase->SetupAttachment(WeaponSceneRoot);

	WeaponLanterns = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Lights component"));
	WeaponLanterns->SetupAttachment(WeaponSceneRoot);

	WeaponDirection = CreateDefaultSubobject<UArrowComponent>(FName("WeaponDirection arrow component"));
	WeaponDirection->SetupAttachment(WeaponSceneRoot);

	WeaponLeftLight = CreateDefaultSubobject<UStaticMeshComponent>(FName("Left light Mesh"));
	WeaponLeftLight->SetupAttachment(WeaponSceneRoot);
	WeaponRightLight = CreateDefaultSubobject<UStaticMeshComponent>(FName("Right light mesh"));
	WeaponRightLight->SetupAttachment(WeaponSceneRoot);

}
