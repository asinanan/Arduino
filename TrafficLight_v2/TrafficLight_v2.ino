//Traffic Light
int carRed = 11;
int carYellow = 12;
int carGreen = 13;

//Pedestrian Button
int button = 7;
int crossTime = 5000;
long changeTime;
int pedRed = 3;
int pedGreen = 2;

//Timer

unsigned long action = 0;
boolean rLed = true;
boolean yLed = false;
boolean gLed = false;

void setup() {

  Serial.begin(9600);
  
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(button, INPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);

  digitalWrite(carRed, HIGH);
  digitalWrite(pedRed, HIGH);

  Serial.println("Setup Completed");
}

// the loop function runs over and over again forever
void loop() {

  int state = digitalRead(button); //Current State of Button
  unsigned long upTime = millis();
  
  if (state == HIGH && (millis() - changeTime) > 5000) {
    Serial.println("Button Pressed");
    changeLight();
  }
  
  //YELLOW ON after 5secs
  if ((rLed == true && yLed == false && gLed == false ) && (upTime - action >= 5000)){
      digitalWrite(carRed, LOW);
      digitalWrite(carYellow, HIGH);
      yLed = true;
      action = upTime;
      Serial.println("Turn Yellow ON");
      Serial.println((String)"Action at: "+action);
    }
  //GREEN ON after 5sec 
  if ((rLed == true && yLed == true && gLed == false ) && (upTime - action >= 5000)){
      digitalWrite(carYellow, LOW);
      digitalWrite(carGreen, HIGH);
      gLed = true;
      action = upTime;
      Serial.println("Turn Green ON");
      Serial.println((String)"Action at: "+action);
    }
  //ALL OFF after 5sec
  if ((rLed == true && yLed == true && gLed == true) && (upTime - action >= 5000)){
    digitalWrite(carGreen, LOW);
    digitalWrite(carRed, HIGH);
    action = upTime;
    gLed = false;
    yLed = false;
    Serial.println("ALL OFF");
    Serial.println((String)"Action at: "+action);
  }
}
void changeLight() {

  Serial.println("Change Sequence Started");
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(2000);

  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);

  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crossTime);

  for (int a = 1; a < 10; a++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, HIGH);
  delay(1000);

  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, HIGH);

  changeTime = millis();
  Serial.println("Change Sequence Ended");
  Serial.println((String)"Sequence Ended: "+changeTime);
}
