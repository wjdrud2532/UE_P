// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"



#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyint = 30;

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 5;

	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt = 10;

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 400.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	//																				private 항목에 있어도 블루프린트에서 접근 가능하도록 함
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Super Duper Variables" , meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditAnywhereInt = 22;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
