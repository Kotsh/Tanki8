// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankyPawn.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "TankFactory.generated.h"

UCLASS()
class AMapLoader;
class TANKI_API ATankFactory : public AActor, public IDamageTaker
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn tanks params")
	class AMapLoader* LinkedMapLoader;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* BuildingMesh;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* TankSpawnPoint;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* HitCollider;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UHealthComponent* HealthComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn tanks params")
		TSubclassOf<ATankyPawn> SpawnTankClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawn tanks params")
		float SpawnTankRate = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn tanks params")
		TArray<ATargetPoint*> TankWayPoints;

public:
	// Sets default values for this actor's properties
	ATankFactory();
	UFUNCTION()
		void TakeDamage(FDamageData DamageData);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnNewTank();

	UFUNCTION()
		void Die();

	UFUNCTION()
		void DamageTaked(float DamageValue);

};



