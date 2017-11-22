//----------------------------------------------
//--- Author         : Ahmet Ozlu
//--- Mail           : ahmetozlu93@gmail.com
//--- Date           : 26th October 2017
//----------------------------------------------

/*declaration of variables*/
int sensorValue;
int sensorValue2;

float voltage;
float voltage2;

float p1;
float p2;
float p3;
float p4;

float meanPower;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*FIRST MEASUREMENT*/
  sensorValue = analogRead(A0); /* Voltage difference of A0 */
  voltage = ((float)5/1023)*sensorValue; 
  sensorValue2 = analogRead(A1); /* Voltage difference of A1 */
  voltage2 = ((float)5/1023)*sensorValue2; 
  /*5 volt = 1023  and sensorValue2 was multiplied with this fraction to get voltage value*/
  p1=((voltage-voltage2)*15)*voltage2;
  delay(25);

  /*SECOND MEASUREMENT*/
  sensorValue = analogRead(A0); /* Voltage difference of A0 */
  voltage = ((float)5/1023)*sensorValue; 
  sensorValue2 = analogRead(A1); /* Voltage difference of A1 */
  voltage2 = ((float)5/1023)*sensorValue2; 
  /*5 volt = 1023  and sensorValue2 was multiplied with this fraction to get voltage value*/
  p2=((voltage-voltage2)*15)*voltage2;
  delay(25);

  /*THIRD MEASUREMENT*/
  sensorValue = analogRead(A0); /* Voltage difference of A0 */
  voltage = ((float)5/1023)*sensorValue; 
  sensorValue2 = analogRead(A1); /* Voltage difference of A1 */
  voltage2 = ((float)5/1023)*sensorValue2; 
  /*5 volt = 1023  and sensorValue2 was multiplied with this fraction to get voltage value*/
  delay(25);

  /*FOURTH MEASUREMENT*/
  sensorValue = analogRead(A0); /* Voltage difference of A0 */
  voltage = ((float)5/1023)*sensorValue; 
  sensorValue2 = analogRead(A1); /* Voltage difference of A1 */
  voltage2 = ((float)5/1023)*sensorValue2; 
  /*5 volt = 1023  and sensorValue2 was multiplied with this fraction to get voltage value*/
  p4=((voltage-voltage2)*15)*voltage2;
  delay(25);

  /*AVERAGE MEASUREMENT*/
  meanPower=(p1+p2+p3+p4)/4;
  
  Serial.print(meanPower);/* Sent voltage value to the computer via serial communication   */
  Serial.println("");
}
