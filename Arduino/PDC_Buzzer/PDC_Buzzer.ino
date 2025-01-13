const int buzzer = 9;

void setup(){
  pinMode(buzzer, OUTPUT);
}

void loop(){
  tone(buzzer, 1000); // Sende 1KHz Tonsignal
  delay(1000);        // 1 sec Pause
  noTone(buzzer);     // Ton stoppen
  delay(1000);        // 1 sec Pause
}

//const int buzzer = 9;
