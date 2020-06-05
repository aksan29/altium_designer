

float v;
void setup() {
Serial.begin(9600);
}
void loop() {
int sensorValue = analogRead(A1);
  float v = sensorValue * (5.0 / 1023.0);
  v = v - 1.8958;
  v = v / 0.0018;
  Serial.print(v);
  delay (500);

}
