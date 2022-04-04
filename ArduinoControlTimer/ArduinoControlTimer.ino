int GoPin = 11;  //active low
int SetPin = 13;  // active high
int DirectionPin = 12;  //high = up,  low = down

void setup() {
  // put your setup code here, to run once:
  pinMode(GoPin, OUTPUT);
  pinMode(SetPin, OUTPUT);
  pinMode(DirectionPin, OUTPUT);
  digitalWrite(DirectionPin, HIGH);
  digitalWrite(SetPin, LOW);
  digitalWrite(GoPin, HIGH);
  Serial.begin(9600);
}

void pulseGo()
{
  digitalWrite(GoPin, LOW);
  delay(100);
  digitalWrite(GoPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
  
    String received = Serial.readString();
    if(received == "Go") pulseGo();
    if(received == "Set") digitalWrite(SetPin, HIGH);
    if(received == "Stop") digitalWrite(SetPin, LOW);
    if(received == "Up") digitalWrite(DirectionPin, HIGH);
    if(received == "Down") digitalWrite(DirectionPin, LOW);
  }
  delay(100);
}
