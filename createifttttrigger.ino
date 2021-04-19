
int analogvalue1 = 0;
int analogvalue2 = 0;

void setup()
{
  Particle.variable("Sunny indoor:100--1000", &analogvalue1, INT);
  Particle.variable("cloudy indoor:5--50", &analogvalue2, INT);

  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop()
{
  // Read the analog value of the sensor (TMP36)
  analogvalue1 = analogRead(A2);
  analogvalue2 = analogRead(A3);

  Particle.publish("Sunny indoor:100--1000", String(analogvalue1));
  Particle.publish("cloudy indoor:5--50", String(analogvalue2));
  delay(200);
}