// AtomLegacy1 property


#include "Project_ShootSphere/Game/DamagingTraps/DamagingSpikesClass.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Kismet/GameplayStatics.h"

ADamagingSpikesClass::ADamagingSpikesClass()
{
	
	MovingSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MovingSpikesMesh"));
	MovingSpikesMesh->SetupAttachment(RootComp);
	SpikesOutCollision = CreateDefaultSubobject<UBoxComponent>(FName("SpikesOutCollision"));
	SpikesOutCollision->SetupAttachment(RootComp);
}

void ADamagingSpikesClass::BeginPlay()
{
	Super::BeginPlay();

	SpikesMovingRate = 1;
	RangeToOut = 85;
	FVector TempSpikesOutVector{0,0,RangeToOut};
	SpikesMovingVector={0,0,SpikesMovingRate};
	
	SpikesStartLocation = MovingSpikesMesh->GetComponentLocation();
	SpikesOutLocation = MovingSpikesMesh->GetComponentLocation() + TempSpikesOutVector;
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::StartApplyDamage);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this,&ThisClass::StopApplyDamage);

	SpikesOutCollision->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::MoveSpikesUp);
	SpikesOutCollision->OnComponentEndOverlap.AddDynamic(this,&ThisClass::MoveSpikesDown);
}

void ADamagingSpikesClass::StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		CharacterToDamage = OtherActor;
		ApplyDamageToActor();
		GetWorldTimerManager().SetTimer(THDamageApply,this,&ThisClass::ApplyDamageToActor,1.0f,true);
	}
}
void ADamagingSpikesClass::StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		GetWorldTimerManager().ClearTimer(THDamageApply);
	}
}
void ADamagingSpikesClass::ApplyDamageToActor()
{
	UGameplayStatics::ApplyDamage(CharacterToDamage,DamageToCause,GetInstigatorController(),
this,UDamageType::StaticClass());
}

void ADamagingSpikesClass::MoveSpikesUp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		isCharacterOverlap = true;
		GetWorldTimerManager().SetTimer(THSpikesMove,this,&ADamagingSpikesClass::MoveSpikes,0.001f,true);
	}
}
void ADamagingSpikesClass::MoveSpikesDown(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		isCharacterOverlap = false;
		GetWorldTimerManager().SetTimer(THSpikesMove,this,&ADamagingSpikesClass::MoveSpikes,0.001f,true);
	}
}
void ADamagingSpikesClass::MoveSpikes()
{
	if (isCharacterOverlap)
	{
		MovingSpikesMesh->SetWorldLocation(MovingSpikesMesh->GetComponentLocation()+SpikesMovingVector);
		if (MovingSpikesMesh->GetComponentLocation().Z>=SpikesOutLocation.Z)
		{
			GetWorldTimerManager().ClearTimer(THSpikesMove);
		}
	}
	else
	{
		MovingSpikesMesh->SetWorldLocation(MovingSpikesMesh->GetComponentLocation()-SpikesMovingVector);
		if (MovingSpikesMesh->GetComponentLocation().Z<=SpikesStartLocation.Z)
		{
			GetWorldTimerManager().ClearTimer(THSpikesMove);
		}
	}
}
