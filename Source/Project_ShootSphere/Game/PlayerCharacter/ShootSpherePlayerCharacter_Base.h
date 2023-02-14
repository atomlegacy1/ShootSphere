// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "ShootSpherePlayerCharacter_Base.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSpherePlayerCharacter_Base : public ACharacter
{
	GENERATED_BODY()

#pragma region Default
	
public:
	AShootSpherePlayerCharacter_Base();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Components
	
private:
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* CharacterSpringArm;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CharacterCameraComponent;

#pragma endregion

#pragma region Action
	
public:
	UFUNCTION()
	void CharacterMoveForward(float Value);
	UFUNCTION()
	void CharacterMoveRight(float Value);
	
	UFUNCTION()
	void CharacterJump();
	UFUNCTION()
	void CharacterDash();

#pragma endregion 
	
};
