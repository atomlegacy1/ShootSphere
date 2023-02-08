// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootSphereEnemy_Base.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Base : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	AShootSphereEnemy_Base();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

#pragma endregion



};
