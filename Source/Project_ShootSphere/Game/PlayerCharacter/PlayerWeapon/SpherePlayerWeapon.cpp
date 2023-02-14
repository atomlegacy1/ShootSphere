// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/PlayerWeapon/SpherePlayerWeapon.h"

ASpherePlayerWeapon::ASpherePlayerWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("PlayerWeapon Root Component"));
	SetRootComponent(WeaponSceneRoot);
	
	WeaponBase = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Base component"));
	WeaponBase->SetupAttachment(WeaponSceneRoot);

	WeaponLights = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlayerWeapon Lights component"));
	WeaponLights->SetupAttachment(WeaponSceneRoot);

	WeaponDirection = CreateDefaultSubobject<UArrowComponent>(FName("WeaponDirection arrow component"));
	WeaponDirection->SetupAttachment(WeaponSceneRoot);

}

void ASpherePlayerWeapon::BeginPlay()
{
	Super::BeginPlay();
	WeaponShoot();
}

void ASpherePlayerWeapon::WeaponShoot()
{
	if (GetOwner())
	{
		FActorSpawnParameters ActorSpawnParams;
		GetWorld()->SpawnActor<ASpherePlayerWeapon_Projectile>(ProjectileToSpawn,WeaponDirection->GetComponentLocation(),
		WeaponDirection->GetComponentRotation(),ActorSpawnParams);
	}
}

void ASpherePlayerWeapon::WeaponReload()
{
	if (WeaponCurrentAmmo<WeaponMaxAmmo)
	{
		//Нужно добавить анимацию перезарядки как-то вот сюда 
		WeaponCurrentAmmo = WeaponMaxAmmo;
	}
}
