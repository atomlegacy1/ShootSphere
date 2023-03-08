// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "SphereEnemy_LeftRight.generated.h"

UCLASS(HideCategories = ("Rendering","Replication","Collision","Advanced","HLOD","Physics",
"Networking","WorldPartition","Input","Actor","Cooking","DataLayers"))
class PROJECT_SHOOTSPHERE_API ASphereEnemy_LeftRight : public AShootSphereEnemy_Base
{
	GENERATED_BODY()

#pragma region Action
public:
	UFUNCTION()
	void MoveSphereLeftRight();
	UFUNCTION()
	void MoveSphereLeft();
	UFUNCTION()
	void MoveSphereRight();
	UFUNCTION()
	void RandomDirectionSelect();
	UFUNCTION()
	void SphereMovingSlowDown();

	ASphereEnemy_LeftRight();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void GivePointsByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

#pragma endregion

#pragma region Variables
private:
	UPROPERTY()
	FVector MaxMovingDistanceVector{0,0,0};
	UPROPERTY()
	FVector SphereMovingRateVector{0,0,0};
	UPROPERTY()
	FVector SphereSpawnLocation{0,0,0};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float SphereMovingRate{2};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float MaxMovingDistance{200};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float SphereSlowingDownSpeed{0.25};
	UPROPERTY(EditAnywhere,Category = "SphereMoving Settings")
	float SphereSlowingDownLimit{1};
	UPROPERTY()
	bool isMovingLeft{false};

	UPROPERTY(EditDefaultsOnly,Category = "Sphere Settings")
	int32 SpherePoints {3};

#pragma endregion
	
};
