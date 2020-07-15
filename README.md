# DemoCPPGame
## Игровой проект-прототип.
* **https://drive.google.com/drive/folders/1CCrruDhSKaIfxCE8MB7S0Lf64xuwjveQ?usp=sharing** - ссылка на скачивание всего проекта.
* **https://www.youtube.com/watch?v=NR8mOqcHu3E** - ссылка на прохождение уровня.
* **https://github.com/dead0designer/DemoCPPGame** - в файлах репозитория содержится папка Source с исходным С++ кодом. 
### Описание
* Проект написан с помощью C++ и Blueprint в движке Unreal Engine 4.24.1
* Были реализованы простые основные механики Unreal Engine 4: бег, поворот, прыжок, движение акторов, триггеры.
* Цель проекта - демонстрация навыков.

### Игровая механика | С++ Classes
 
1. *Действия*
  * Бег
  
 ---
 
	void AMyBaseCharacter::MoveForward(float Value)
	{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
	}

	void AMyBaseCharacter::MoveRight(float Value)
	{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value); >
  
---

  * Так же были использованы built-in повороты, прыжок и камера. 

2. *Сущности*
  * FlyingCloud
---

	#include "FlyingCloud.h"
	#include "Components/StaticMeshComponent.h"
	
	// Sets default values
	AFlyingCloud::AFlyingCloud()
	{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Called when the game starts or when spawned
	void AFlyingCloud::BeginPlay()
	{
	Super::BeginPlay();
	}

	// Called every frame
	void AFlyingCloud::Tick(float DeltaTime)
	{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 160.0f;
	SetActorLocation(NewLocation);
	}

---

 * RotatingActor 
 
       #include "RotatingActor.h"
       #include "Components/StaticMeshComponent.h"

        // Sets default values
        ARotatingActor::ARotatingActor()
        {
 		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
		RotatingActor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingActor"));
		RotatingActor->SetupAttachment(RootComponent);
        }

        // Called when the game starts or when spawned
        void ARotatingActor::BeginPlay()
        {
		Super::BeginPlay();
        } 

        // Called every frame
        void ARotatingActor::Tick(float DeltaTime)
        {
		Super::Tick(DeltaTime);
		FRotator NewRotation = GetActorRotation();
		float Rotation = DeltaTime * 20.0f;
		NewRotation.Yaw += Rotation;
		SetActorRotation(NewRotation);
        }

---

 * MyBaseCharacter
 
        #include "MyBaseCharacter.h"
        #include "Components/InputComponent.h"
        #include "GameFramework/Pawn.h"
        #include "GameFramework/Controller.h"
        #include "Engine/Engine.h"

        // Sets default values
        AMyBaseCharacter::AMyBaseCharacter()
        {
 		// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
        }

        // Called when the game starts or when spawned
        void AMyBaseCharacter::BeginPlay()
        {
		Super::BeginPlay();
		if (GEngine)
		{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("using MyBaseCharacter"));
		}
        }

        // Called every frame
        void AMyBaseCharacter::Tick(float DeltaTime)
        {
		Super::Tick(DeltaTime);
		const FVector ActorLocation = GetActorLocation();
		if ((ActorLocation.Z == KillZ) || (ActorLocation.Z < KillZ))
		{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Critical Z-value! Move to start!"));
		SetActorLocation(FVector(0.0f, 0.0f, 112.0f));
		}
        }

        // Called to bind functionality to input
        void AMyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
        {
		Super::SetupPlayerInputComponent(PlayerInputComponent);
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyBaseCharacter::Jump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyBaseCharacter::StopJumping);

		PlayerInputComponent->BindAxis("MoveForward", this, &AMyBaseCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AMyBaseCharacter::MoveRight);

		PlayerInputComponent->BindAxis("Turn", this, &AMyBaseCharacter::AddControllerYawInput);
		PlayerInputComponent->BindAxis("LookUp", this, &AMyBaseCharacter::AddControllerPitchInput);
        }

		void AMyBaseCharacter::MoveForward(float Value)
		{
			if ((Controller) && (Value != 0.0f))
		{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		}
		}

		void AMyBaseCharacter::MoveRight(float Value)
		{
		if ((Controller) && (Value != 0.0f))
		{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
		}
		}

 
 3. *Прочее*
 
 * MyTriggerBox
 
        #include "MyTriggerBox.h"
        #include "Engine/Engine.h"
        #include "GameFramework/Character.h"
        #include "GameFramework/Actor.h"
        #include "Kismet/KismetSystemLibrary.h"

        AMyTriggerBox::AMyTriggerBox()
        {
		OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
		OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
        }

        void AMyTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
        {
		if (const auto Char = Cast<ACharacter>(OtherActor))
		{
						GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("It's finish! You win!"));
		}
        }

        void AMyTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
        {
	    if (const auto Char = Cast<ACharacter>(OtherActor))
		{
        	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Press ESC to close the game!"));
		}
        	}

 
 ---
 
 * Также были созданы и использованы С++ классы, формирующие правила игры, точку старта уровня.
 
### Демонстрация
* Прохождение проекта в редакторе, доступ по ссылке.

  **https://www.youtube.com/watch?v=NR8mOqcHu3E**

---

* Сообщения в левом верхнем углу экрана показывают о выполнении условий игры (использование определенных классов, условие пройгрыша - падение, условие выйгрыша - попадание в триггер).
* UPD:  
Перенес код из фото в readme.
* UPD2: 
Собственно зачем оно было сделано?
Это была первая проба плюсов в контексте UE4. Прочитал книжку по с++ - построил уровень. Закрепил. 
* UPD3:
Постарался сделать код настолько читаемым насколько это возможно.
