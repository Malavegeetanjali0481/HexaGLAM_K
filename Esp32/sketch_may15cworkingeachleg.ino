#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// =====================================================
// HEXAPOD ROBOT
// Arduino UNO + 2 PCA9685
// ALL 6 LEGS WALKING
// =====================================================

// PCA9685 Boards
Adafruit_PWMServoDriver pca1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pca2 = Adafruit_PWMServoDriver(0x41);

// =====================================================
// SERVO SETTINGS
// =====================================================

#define SERVOMIN 110
#define SERVOMAX 490

// =====================================================
// WALK CONTROL
// =====================================================

bool walking = false;

// =====================================================
// ANGLE TO PWM
// =====================================================

int angleToPulse(int ang)
{
  return map(ang, 0, 180, SERVOMIN, SERVOMAX);
}

// =====================================================
// MOVE SERVO
// =====================================================

void setServo(Adafruit_PWMServoDriver &pca, int channel, int angle)
{
  angle = constrain(angle, 30, 150);

  int pulse = angleToPulse(angle);

  pca.setPWM(channel, 0, pulse);
}

// =====================================================
// STAND POSITION
// =====================================================

void standPosition()
{
  // PCA1
  for (int ch = 0; ch <= 8; ch++)
  {
    setServo(pca1, ch, 90);
  }

  // PCA2
  for (int ch = 0; ch <= 8; ch++)
  {
    setServo(pca2, ch, 90);
  }

  delay(1000);
}

// =====================================================
// MOVE ONE LEG
// =====================================================

void moveLeg(
  Adafruit_PWMServoDriver &pca,
  int coxa,
  int femur,
  int tibia,
  int dir)
{
  // ===================================
  // LIFT LEG
  // ===================================

  for (int a = 90; a >= 65; a--)
  {
    setServo(pca, femur, a);

    delay(4);
  }

  // ===================================
  // FORWARD SWING
  // ===================================

  if (dir == 1)
  {
    for (int a = 70; a <= 120; a++)
    {
      setServo(pca, coxa, a);

      delay(4);
    }
  }
  else
  {
    for (int a = 120; a >= 70; a--)
    {
      setServo(pca, coxa, a);

      delay(4);
    }
  }

  // ===================================
  // LOWER LEG
  // ===================================

  for (int a = 65; a <= 90; a++)
  {
    setServo(pca, femur, a);

    delay(4);
  }

  // ===================================
  // PUSH BODY
  // ===================================

  if (dir == 1)
  {
    for (int a = 120; a >= 70; a--)
    {
      setServo(pca, coxa, a);

      delay(4);
    }
  }
  else
  {
    for (int a = 70; a <= 120; a++)
    {
      setServo(pca, coxa, a);

      delay(4);
    }
  }
}

// =====================================================
// TRIPOD GAIT WALK
// =====================================================

void tripodWalk()
{
  // ===================================
  // GROUP A
  // LEG 1,3,5
  // ===================================

  moveLeg(pca1, 0, 1, 2, 1); // LEG 1

  moveLeg(pca1, 6, 7, 8, 1); // LEG 3

  moveLeg(pca2, 3, 4, 5, 1); // LEG 5

  delay(20);

  // ===================================
  // GROUP B
  // LEG 2,4,6
  // ===================================

  moveLeg(pca1, 3, 4, 5, 0); // LEG 2

  moveLeg(pca2, 0, 1, 2, 0); // LEG 4

  moveLeg(pca2, 6, 7, 8, 0); // LEG 6

  delay(20);
}

// =====================================================
// WALK LONG DISTANCE
// =====================================================

void walkDistance()
{
  for (int i = 0; i < 80; i++)
  {
    tripodWalk();
  }
}

// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(9600);

  Serial.println("HEXAPOD STARTING");

  // PCA START
  pca1.begin();
  pca2.begin();

  pca1.setPWMFreq(50);
  pca2.setPWMFreq(50);

  delay(1000);

  // INITIAL POSITION
  standPosition();

  Serial.println("READY");

  Serial.println("Commands:");
  Serial.println("s = START WALK");
  Serial.println("x = STOP");
  Serial.println("w = WALK DISTANCE");
}

// =====================================================
// LOOP
// =====================================================

void loop()
{
  // ===================================
  // SERIAL COMMANDS
  // ===================================

  if (Serial.available())
  {
    char cmd = Serial.read();

    // START CONTINUOUS WALK
    if (cmd == 's')
    {
      walking = true;

      Serial.println("WALKING...");
    }

    // STOP
    else if (cmd == 'x')
    {
      walking = false;

      standPosition();

      Serial.println("STOPPED");
    }

    // WALK DISTANCE
    else if (cmd == 'w')
    {
      Serial.println("WALKING LONG DISTANCE");

      walkDistance();

      Serial.println("DONE");
    }
  }

  // CONTINUOUS WALK
  if (walking)
  {
    tripodWalk();
  }
}