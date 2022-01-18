byte A = 2;
byte B = 3;

int baud1= 4;
int baud2= 5;
int baud3= 6;
//const byte baud4= 7;

int buttonstate1=0;
int buttonstate2=0;
int buttonstate3=0;
//byte buttonstate4=0;

int baudrate;

unsigned long prevByteMillis = 0;
unsigned long curMillis;

void setup() {
  // put your setup code here, to run once:

//  Serial.begin(9600);
  pinMode( A, OUTPUT);
  pinMode( B, OUTPUT);
  pinMode( baud1, INPUT);
  pinMode( baud2, INPUT);
  pinMode( baud3, INPUT);
  //pinMode( baud4, INPUT);
  buttonstate1= digitalRead(baud1);
  buttonstate2= digitalRead(baud2);
  buttonstate3= digitalRead(baud3);
 // buttonstate4= digitalRead(baud4);
  if( buttonstate1 == HIGH &&  buttonstate2 == LOW && buttonstate3==LOW){
    baudrate=19200; 
  }
  else if ( buttonstate1 == LOW &&  buttonstate2 == HIGH && buttonstate3==LOW){
    baudrate=9600;
  }
  else if (buttonstate1 == LOW &&  buttonstate2 == LOW && buttonstate3==HIGH ){
    baudrate=4800;
  }
  Serial.begin(baudrate);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:

    curMillis = millis();
    if(Serial.available()>0) {
       char dataku = (char)Serial.read();
       Serial.print(dataku); 
       digitalWrite(A,HIGH);
       digitalWrite(B,LOW);
       prevByteMillis = curMillis;     
    }
    if (curMillis - prevByteMillis >=2000) {
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
    }

}
