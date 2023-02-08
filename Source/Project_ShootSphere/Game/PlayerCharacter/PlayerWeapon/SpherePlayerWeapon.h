// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpherePlayerWeapon.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASpherePlayerWeapon : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	ASpherePlayerWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

#pragma endregion

};
