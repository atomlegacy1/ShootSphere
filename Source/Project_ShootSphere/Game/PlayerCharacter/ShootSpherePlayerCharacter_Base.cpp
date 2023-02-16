// AtomLegacy1 property


#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"

#include "Debug/ReporterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

AShootSpherePlayerCharacter_Base::AShootSpherePlayerCharacter_Base()
{
	PrimaryActorTick.bCanEverTick = true;

	CharacterSpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("Camera spring arm"));
	CharacterCameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("Character following camera"));
	CharacterCameraComponent ->SetupAttachment(CharacterSpringArm);
}

void AShootSpherePlayerCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
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
		switch (GetMovementComponent()->IsFalling())
		{
		case true:
			GetCharacterMovement()->GravityScale = 0;
			FTimerHandle TimerHandleTemp;
			GetWorldTimerManager().SetTimer(TimerHandleTemp,this,&AShootSpherePlayerCharacter_Base::Dash,0.2f,false,0.0);
			//таймер блять
			break;
		case false:
			Dash();
			break;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("DashAmount: %i "),DashAmount));
}

void AShootSpherePlayerCharacter_Base::CharacterWeaponReload()
{
	//Нужна анимация
	
}
void AShootSpherePlayerCharacter_Base::Dash()
{
	LaunchCharacter(GetActorForwardVector() * DashRange,true,true);
	DashAmount--;
}
