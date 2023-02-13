// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/PlayerWeapon/WeaponProjectile/SpherePlayerWeapon_Projectile.h"


ASpherePlayerWeapon_Projectile::ASpherePlayerWeapon_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileRoot = CreateDefaultSubobject<USceneComponent>(FName("Projectile root component"));
	SetRootComponent(ProjectileRoot);
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Projectile StaticMesh"));
	ProjectileMesh->SetupAttachment(ProjectileRoot);
	ProjectileCollision = CreateDefaultSubobject<USphereComponent>(FName("Projectile Collision"));
	ProjectileCollision->SetupAttachment(ProjectileRoot);
	ProjectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));

}

