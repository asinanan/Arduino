
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

int wait = 1;
unsigned long upTime;

void setup() {

  Serial.begin(9600);
  
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(button, INPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);

  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);

  Serial.println("Setup Completed");
}

// the loop function runs over and over again forever
void loop() {

  
  int state = digitalRead(button); //Current State of Button
  if (state == HIGH && (millis() - changeTime) > 5000) {
    Serial.println("Button Pressed");
    changeLight();
  }
 upTime = millis();
 Serial.println(upTime);
 delay(1000); 
 /*
    digitalWrite(carGreen, HIGH);
    delay(5000);
    digitalWrite(carGreen, LOW);
    digitalWrite(carYellow, HIGH);
    delay(2000);

    digitalWrite(carYellow, LOW);
    digitalWrite(carRed, HIGH);
    delay(1000);
    digitalWrite(carRed, LOW);
*/

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
