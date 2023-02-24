// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Components/ArrowComponent.h"
#include "Debug/ReporterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Project_ShootSphere/Project_ShootSphereCharacter.h"

AShootSpherePlayerCharacter_Base::AShootSpherePlayerCharacter_Base()
{
	PrimaryActorTick.bCanEverTick = true;

	CharacterSpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("Camera spring arm"));
	CharacterCameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("Character following camera"));
	CharacterCameraComponent->SetupAttachment(CharacterSpringArm);
	CharacterSpringArm->SetupAttachment(GetMesh());
	WeaponDirection = CreateDefaultSubobject<UArrowComponent>(FName("WeaponDirection arrow component"));
	
}

void AShootSpherePlayerCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	WeaponCurrentAmmo = WeaponMaxAmmo;
	WeaponDirection->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,FName("WeaponAttach"));
	SpawnWeapon();
}

void AShootSpherePlayerCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShootSpherePlayerCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AShootSpherePlayerCharacter_Base::CharacterMoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AShootSpherePlayerCharacter_Base::CharacterMoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"),this,&AShootSpherePlayerCharacter_Base::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"),this,&AShootSpherePlayerCharacter_Base::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&AShootSpherePlayerCharacter_Base::CharacterJump);
	PlayerInputComponent->BindAction(TEXT("Dash"),IE_Pressed,this,&AShootSpherePlayerCharacter_Base::CharacterDash);
	PlayerInputComponent->BindAction(TEXT("Reload"),IE_Pressed,this,&AShootSpherePlayerCharacter_Base::CharacterWeaponReload);
	PlayerInputComponent->BindAction(TEXT("WeaponShoot"),IE_Pressed,this,&AShootSpherePlayerCharacter_Base::CharacterWeaponShoot);
	
}

void AShootSpherePlayerCharacter_Base::CharacterMoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AShootSpherePlayerCharacter_Base::CharacterMoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AShootSpherePlayerCharacter_Base::CharacterJump()
{
	Jump();
}

void AShootSpherePlayerCharacter_Base::CharacterDash()
{
	if (GetMovementComponent()->Velocity.Size()==0) return;
	if (DashAmount>0)
	{
		FTimerHandle TimerHandleTemp;
		if (GetCharacterMovement()->IsFalling())
		{
			GetCharacterMovement()->GravityScale = 0;
			LaunchCharacter(GetActorForwardVector() * DashRange,true,true);
			GetWorldTimerManager().SetTimer(TimerHandleTemp,this,&AShootSpherePlayerCharacter_Base::DashStop,1.0f,false,0.1);
			DashAmount--;

		}
		else
		{
			LaunchCharacter(GetActorForwardVector() * DashRange,true,true);
			GetWorldTimerManager().SetTimer(TimerHandleTemp,this,&AShootSpherePlayerCharacter_Base::DashStop,1.0f,false,0.1);
			DashAmount--;

		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("DashAmount: %i "),DashAmount));
}

void AShootSpherePlayerCharacter_Base::DashStop()
{
	GetCharacterMovement()->GravityScale = 1;
	GetCharacterMovement()->StopMovementImmediately();
}

void AShootSpherePlayerCharacter_Base::CharacterWeaponReload()
{
	if (WeaponCurrentAmmo<WeaponMaxAmmo)
	{
		//Нужна анимация
		WeaponCurrentAmmo = WeaponMaxAmmo;
	}
}

void AShootSpherePlayerCharacter_Base::CharacterWeaponShoot()
{
	if (WeaponCurrentAmmo!=0)
	{
		WeaponCurrentAmmo--;
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ASpherePlayerWeapon_Projectile>(WeaponProjectile,WeaponDirection->GetComponentTransform(),SpawnParams);
	}
}

void AShootSpherePlayerCharacter_Base::SpawnWeapon()
{
	FActorSpawnParameters ActorSpawnParams;
	FTransform SocketLocation = GetMesh()->GetSocketTransform("WeaponAttach");
	GetWorld()->SpawnActor<ASpherePlayerWeapon>(WeaponToSpawn,SocketLocation,ActorSpawnParams)
	->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,FName("WeaponAttach"));
}

