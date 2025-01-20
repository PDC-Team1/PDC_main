#include <mcp_can.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10

const int SPI_CS_PIN = 9;
const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
const int buzzer = 10;
const unsigned int BAUD_RATE=115200;

#define ENCODER 3 //light detecting pin, connect D0 with 3
#define CIRCUMFERENCE 0.214 //enter in meter
#define PERIOD 0.1

volatile unsigned int counter = 0;
double rpm;

void count(){
  counter++;
}

/* Union that can devide 4byte data */
union DataUnion {
  struct {
    float speed_kmh;
    int distance_cm;
  };

  byte bytes[8];
} data;

MCP_CAN CAN0(SPI_CS_PIN);
int dis_start = 0;

void setup() {
  Serial.begin(115200);

  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) {
    Serial.println("MCP2515 Initialized Successfully!");
  }
  else {
    Serial.println("Error Initializing MCP2515...");
    };

  CAN0.setMode(MCP_NORMAL);

  //set pin status
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(ENCODER, INPUT);
  digitalWrite(ENCODER, HIGH);

  //interrupt to the PIN2, when rising edge count worksavrdude: ser_open(): can't open device "/dev/ttyACM0": No such file or directory
  int interrupt = (ENCODER == 2) ? 0 : 1;
  attachInterrupt(interrupt, count, RISING);
}

void loop() {
  if (dis_start >= 5) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN,  HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
    Serial.print("Duration");
    Serial.println(duration);

    int distance= duration/29/2;
    Serial.print("Distance");
    Serial.println(distance);
    static uint32_t previousMillis;
    
    if(distance<=15 && distance > 7){
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
      delay(100);        // 1 sec Pause
    }
    else{
      noTone(buzzer);
      delay(1000);
    }

    data.distance_cm = distance;

    if(duration==0){
    Serial.println("Warning: no pulse from sensor");
    }  
    else{}

    if (millis() - previousMillis >= 1000 *PERIOD){
      rpm = (counter / 20.0) * 60 / PERIOD;
      data.speed_kmh = rpm * CIRCUMFERENCE * 100 / 60;
          
      counter = 0;
      previousMillis += 1000 * PERIOD;
          
      Serial.print("RPM: ");
      Serial.println(data.speed_kmh);
    }                    // send data per 100ms

    byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, data.bytes);

    if(sndStat == CAN_OK){
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }
  }
  else {
    dis_start ++;
    Serial.println(dis_start);
    // delay(100);
  };
  
}
