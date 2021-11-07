// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankyPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    Initialize();
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!TankyPawn)
        Initialize();

    if (!TankyPawn)
        return;

    TankyPawn->MoveForward(1);
    float rotationValue = GetRotationgValue();
    TankyPawn->RotateRight(rotationValue);

    Targeting();
}

bool ATankAIController::IsPlayerSeen()
{
    if (!PlayerPawn)
        Initialize();

    FVector playerPos = PlayerPawn->GetActorLocation();
    FVector eyesPos = TankyPawn->GetEyesPosition();
}

void ATankAIController::Initialize()
{
    TankyPawn = Cast<ATankyPawn>(GetPawn());
    if (TankyPawn)
    {
        PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
        FVector pawnLocation = TankPawn->GetActorLocation();
        MovementAccurency = TankPawn->GetMovementAccurency();
        TArray<FVector> points = TankPawn->GetPatrollingPoints();
        for (FVector point : points)
        {
            PatrollingPoints.Add(point);
        }
        CurrentPatrolPointIndex = 0;
    }
}




