// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/FloatingPlatform/FloatingPlatform_Base.h"
#include "FloatingPlatform_UpDown.generated.h"


UCLASS(HideCategories = ("Rendering","Replication","Collision","Advanced","HLOD","Physics",
"Networking","WorldPartition","Input","Actor","Cooking","DataLayers"))
class PROJECT_SHOOTSPHERE_API AFloatingPlatform_UpDown : public AFloatingPlatform_Base
{
	GENERATED_BODY()

#pragma region Action
public:
	UFUNCTION()
	void MovePlatformUpDown();
	UFUNCTION()
	void MovePlatformUp();
	UFUNCTION()
	void MovePlatformDown();
	UFUNCTION()
	void RandomDirectionSelect();
	UFUNCTION()
	void PlatformMovingSlowDown();

	AFloatingPlatform_UpDown();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Variables
protected:
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformMovingRate{2};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float MaxMovingDistance{200};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformSlowingDownSpeed{0.25};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float PlatformSlowingDownLimit{1};
private:
	UPROPERTY()
	FVector MaxMovingDistanceVector{0,0,0};
	UPROPERTY()
	FVector SphereMovingRateVector{0,0,0};
	UPROPERTY()
	FVector PlatformSpawnLocation{0,0,0};
	UPROPERTY()
	bool isMovingUp{false};

#pragma endregion
};
