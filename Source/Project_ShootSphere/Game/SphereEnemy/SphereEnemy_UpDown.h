// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "SphereEnemy_UpDown.generated.h"

UCLASS(HideCategories = ("Rendering","Replication","Collision","Advanced","HLOD","Physics",
"Networking","WorldPartition","Input","Actor","Cooking","DataLayers"))
class PROJECT_SHOOTSPHERE_API ASphereEnemy_UpDown : public AShootSphereEnemy_Base
{
	GENERATED_BODY()

#pragma region Action
public:
	UFUNCTION()
	void MoveSphereUpDown();
	UFUNCTION()
	void MoveSphereUp();
	UFUNCTION()
	void MoveSphereDown();
	UFUNCTION()
	void RandomDirectionSelect();
	UFUNCTION()
	void SphereMovingSlowDown();
	UFUNCTION()
	void GivePointsByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	ASphereEnemy_UpDown();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;



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
	bool isMovingUp{false};

	UPROPERTY(EditDefaultsOnly,Category = "Sphere Settings")
	int32 SpherePoints {3};
#pragma endregion
	
};
