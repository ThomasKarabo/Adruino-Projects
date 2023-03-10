// C++ code
//
int Temperature = 0;
int temp = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
void loop()
{
  Temperature = 33;
  
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  Serial.print(temp);
  Serial.println(" C, ");
 
  if (temp < Temperature) {
    digitalWrite(9, LOW);
  	digitalWrite(10, LOW);
  	digitalWrite(11, HIGH);
    
  }
  if (temp >= Temperature && temp < Temperature + 5) {
   	digitalWrite(9, LOW);
  	digitalWrite(10, HIGH);
  	digitalWrite(11, LOW);
    
  }
  if (temp >= Temperature + 5) {
    digitalWrite(9, HIGH);
  	digitalWrite(10, LOW);
  	digitalWrite(11, LOW);
    
  }
  delay(1000); 
}