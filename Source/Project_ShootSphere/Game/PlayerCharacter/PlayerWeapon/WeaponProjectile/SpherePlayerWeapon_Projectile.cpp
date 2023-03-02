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
	ProjectileCollision->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::DestroyOnOverlap);
	
}
void ASpherePlayerWeapon_Projectile::DestroyOnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}
