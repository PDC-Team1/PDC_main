const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
const int buzzer = 9;
const  unsigned int BAUD_RATE=9600;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(BAUD_RATE);
}

void loop()  {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,  HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  int distance= duration/29/2;

  if(distance<=10 && distance > 7){
    tone(buzzer, 1000); // Sende 1KHz Tonsignal
    delay(200);        // 1 sec Pause
    noTone(buzzer);     // Ton stoppen
    delay(200);        // 1 sec Pause
  }
  else if(distance <=7 && distance > 4){
    tone(buzzer, 1000); // Sende 1KHz Tonsignal
    delay(100);        // 1 sec Pause
    noTone(buzzer);     // Ton stoppen
    delay(100);        // 1 sec Pause
  }
  else if(distance <= 4){
    tone(buzzer, 1000); // Sende 1KHz Tonsignal
    delay(1000);        // 1 sec Pause
  }
  else{
    noTone(buzzer);
    delay(1000);
  }

  if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   }  
  else{
      //Serial.print("distance to nearest object:");
      //Serial.println(distance);
      //Serial.println(" cm");
  }
 //delay(300);
 }