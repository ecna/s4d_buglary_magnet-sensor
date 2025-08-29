void setup() {
  Serial.begin(115200);
  pinMode(A2, INPUT);
}

void loop() {
  Serial.print("Analog: ");
  Serial.println(analogRead(A2));
  delay(100);
}
