const int RED_PIN = 10;
const int BLUE_PIN = 11;
const int GREEN_PIN = 12;

const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

long duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delay(2);
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * (0.034/2);

  Serial.print(distance);
  Serial.println("cm");

  if (distance >= 0 && distance <= 20) {
    digitalWrite(RED_PIN, HIGH);
    
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  }

  if (distance > 20 && distance <= 40) {
    digitalWrite(BLUE_PIN, HIGH);
    
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  }

  if (distance > 40) {
    digitalWrite(GREEN_PIN, HIGH);
    
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }

  delay(500);
}
















