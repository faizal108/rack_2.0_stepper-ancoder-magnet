#include <AccelStepper.h>

//drivers pins
#define dirPin1 22 //driver 1
#define stepPin1 23
#define dirPin2 24 //driver 2
#define stepPin2 25
#define dirPin3 26 //driver 3
#define stepPin3 27


//encoder pins
#define CLK1 2 //intrupt pins
#define DT1 3 //intrupt pins
#define BTN1 4 //button

#define BTN2 16 //button
#define CLK2 18 //intrupt pins
#define DT2 19 //intrupt pins

#define BTN3 17 //button
#define CLK3 20 //intrupt pins
#define DT3 21 //intrupt pins


//if you dont want to use this library then you can simply delete this below
//line and setup custom pin for driver direction and steps dir and step[pulse]
AccelStepper stepper = AccelStepper(1, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(1, stepPin2, dirPin2);
AccelStepper stepper3 = AccelStepper(1, stepPin3, dirPin3);

//Encoder button state
int BTN1State = 0;
int BTN2State = 0;
int BTN3State = 0;

//motor steps counter
int m1_steps = 0;
int m2_steps = 0;
int m3_steps = 0;

//one encoder equal to increments motor steps [1 = 20 motor steps]
int increment1 = 20;
int increment2 = 20;
int increment3 = 20;

int m1_currentPos = 0;
int m2_currentPos = 0;
int m3_currentPos = 0;

int m1_prevDist = 0;
int m2_prevDist = 0;
int m3_prevDist = 0;

int magnet_prevState = 0;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;


//encoders initialization
int currentStateCLK1;
int lastStateCLK1;
int currentStateCLK2;
int lastStateCLK2;
int currentStateCLK3;
int lastStateCLK3;

//Recording button
const int recordBtnPin = 50;
const int recordLedPin =  51;
int recordBtnState = 0;

//Play button
const int playBtnPin = 52;
const int playLedPin =  53;
int playBtnState = 0;

//Magnet button
const int magnetBtnPin = 44;
const int magnetLedPin = 45;
int magnetBtnState = 0;
int magnetState = 0;

//pause button
const int pauseBtnPin = 46;
const int pauseLedPin = 47;
int pauseBtnState = 0;

//motor memory
int m1_memory[250];
int m2_memory[250];
int m3_memory[250];
int m1_index = 0;
int m2_index = 0;
int m3_index = 0;

//magnet memory
int magnet_memory[20];
int magnet_index = 0;

//Sequence counter
int seq_pointer[750];
int seq_index = 0;

void setup() {
  //  stepper.setMaxSpeed(4000);
  //  stepper.setAcceleration(4000);
  //  stepper.setSpeed(4000);

  // Set encoder pins as inputs
  pinMode(CLK1, INPUT);
  pinMode(DT1, INPUT);
  pinMode(BTN1, INPUT);

  pinMode(CLK2, INPUT);
  pinMode(DT2, INPUT);
  pinMode(BTN2, INPUT);

  pinMode(CLK3, INPUT);
  pinMode(DT3, INPUT);
  pinMode(BTN3, INPUT);

  // Setup Serial Monitor
  Serial.begin(115200);

  // Read the initial state of CLK1
  lastStateCLK1 = digitalRead(CLK1);
  lastStateCLK2 = digitalRead(CLK2);
  lastStateCLK3 = digitalRead(CLK3);

  // Call freeMove() when any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(digitalPinToInterrupt(2), freeMove, CHANGE);
  attachInterrupt(digitalPinToInterrupt(18), freeMove, CHANGE);
  attachInterrupt(digitalPinToInterrupt(20), freeMove, CHANGE);

  //  Record button & Led configuration
  pinMode(recordBtnPin, INPUT);
  digitalWrite(recordBtnPin, LOW);
  pinMode(recordLedPin, OUTPUT);
  digitalWrite(recordLedPin, LOW);

  //  Play button & Led configuration
  pinMode(playBtnPin, INPUT);
  digitalWrite(playBtnPin, LOW);
  pinMode(playLedPin, OUTPUT);
  digitalWrite(playLedPin, LOW);

  //Magnet button & led configuration
  pinMode(magnetBtnPin, INPUT);
  digitalWrite(magnetBtnPin, LOW);
  pinMode(magnetLedPin, OUTPUT);
  digitalWrite(magnetLedPin, LOW);

  //Pause button & led configuration
  pinMode(pauseBtnPin, INPUT);
  digitalWrite(pauseBtnPin, LOW);
  pinMode(pauseLedPin, OUTPUT);
  digitalWrite(pauseLedPin, LOW);
}


void freeMove()
{
  if (playBtnState != HIGH)
  {
    currentStateCLK1 = digitalRead(CLK1);
    currentStateCLK2 = digitalRead(CLK2);
    currentStateCLK3 = digitalRead(CLK3);

    if (currentStateCLK1 != lastStateCLK1 && currentStateCLK1 == 1)
    {

      if (digitalRead(DT1) != currentStateCLK1)
      {
        counter1 = counter1 - increment1;
      }
      else
      {
        counter1 = counter1 + increment1;
      }

      Serial.print("Counter1: ");
      Serial.print(counter1);
      Serial.print("\t");
    }

    if (currentStateCLK2 != lastStateCLK2 && currentStateCLK2 == 1)
    {

      if (digitalRead(DT2) != currentStateCLK2)
      {
        counter2 = counter2 - increment2;
      }
      else
      {
        counter2 = counter2 + increment2;
      }

      Serial.print("Counter2: ");
      Serial.print(counter2);
      Serial.print("\t");
    }

    if (currentStateCLK3 != lastStateCLK3 && currentStateCLK3 == 1)
    {

      if (digitalRead(DT3) != currentStateCLK3)
      {
        counter3 = counter3 - increment3;
      }
      else
      {
        counter3 = counter3 + increment3;
      }

      Serial.print("Counter3: ");
      Serial.print(counter3);
      Serial.print("\t");
    }

    lastStateCLK1 = currentStateCLK1;
    lastStateCLK2 = currentStateCLK2;
    lastStateCLK3 = currentStateCLK3;
  }

}
void loop() {

  recordBtnState = digitalRead(recordBtnPin); //record button
  playBtnState = digitalRead(playBtnPin); //play button
  magnetBtnState = digitalRead(magnetBtnPin); // magnet button
//  pauseBtnState = digitalRead(pauseBtnPin); // pause button
  BTN1State = digitalRead(BTN1);
  BTN2State = digitalRead(BTN2);
  BTN3State = digitalRead(BTN3);

  if (m1_currentPos != counter1) {
    gotoPosition(counter1, 1, stepPin1, dirPin1);
  }
  if (m2_currentPos != counter2) {
    gotoPosition(counter2, 2, stepPin2, dirPin2);
  }
  if (m3_currentPos != counter3) {
    gotoPosition(counter3, 3, stepPin3, dirPin3);
  }

  checkMagnet();
  
  //for recording
  if (recordBtnState == HIGH) {
    digitalWrite(recordLedPin, HIGH);
    //    Serial.println("Recording your moves.......");
    startRecording();
  } else {
    digitalWrite(recordLedPin, LOW);
  }

  //for playing a record
  if (playBtnState == HIGH) {
    digitalWrite(playLedPin, HIGH);
    startPlaying();
  } else {
    digitalWrite(playLedPin, LOW);
  }

  //  encoder button
  //  if (BTN1State == LOW && counter1 != 0) {
  //    gotoPosition(0, 1, stepPin1, dirPin1);
  //    counter1 = 0;
  //  }
  //  if (BTN2State == LOW && counter2 != 0) {
  //    gotoPosition(0, 2, stepPin2, dirPin2);
  //    counter2 = 0;
  //  }
  if (BTN3State == LOW && counter3 != 0) {
    gotoPosition(0, 3, stepPin3, dirPin3);
    counter3 = 0;
  }

}
