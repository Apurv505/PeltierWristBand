int MetalThermistorPin = A0;
int PeltierThermistorPin = A1;
int BatteryPin = A2;
int Vo;
float V;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {

  Vo = analogRead(MetalThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  T = T - 273.15;
  //  T = (T * 9.0)/ 5.0 + 32.0;

  Serial.println("MetalTemperature: ");
  Serial.print(T);
  Serial.println(" C");



  Vo = analogRead(PeltierThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  T = T - 273.15;
  //  T = (T * 9.0)/ 5.0 + 32.0;

  Serial.println("PeltierTemperature: ");
  Serial.print(T);
  Serial.println(" C");

  V = analogRead(BatteryPin);
  V=V/1023.0*4.7;
  Serial.println("BatteryVoltage: ");
  Serial.print(V);
  Serial.println(" V");
  
  digitalWrite(2, HIGH);
  delay(4000);
  digitalWrite(2, LOW);
  delay(4000);
}
