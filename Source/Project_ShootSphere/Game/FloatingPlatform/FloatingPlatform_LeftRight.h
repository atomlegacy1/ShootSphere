// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/FloatingPlatform/FloatingPlatform_Base.h"
#include "FloatingPlatform_LeftRight.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AFloatingPlatform_LeftRight : public AFloatingPlatform_Base
{
	GENERATED_BODY()
#pragma region Action
public:
	UFUNCTION()
	void MovePlatformLeftRight();
	UFUNCTION()
	void MovePlatformLeft();
	UFUNCTION()
	void MovePlatformRight();
	UFUNCTION()
	void RandomDirectionSelect();
	UFUNCTION()
	void PlatformMovingSlowDown();

	AFloatingPlatform_LeftRight();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Variables
private:
	UPROPERTY()
	FVector MaxMovingDistanceVector{0,0,0};
	UPROPERTY()
	FVector PlatformMovingRateVector{0,0,0};
	UPROPERTY()
	FVector PlatformSpawnLocation{0,0,0};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformMovingRate{2};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float MaxMovingDistance{200};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformSlowingDownSpeed{0.25};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformSlowingDownLimit{1};
	UPROPERTY()
	bool isMovingLeft{false};

#pragma endregion
};
