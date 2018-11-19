int PinSuhu = A0 ;
float suhu, data ;
void setup() {
Serial.begin(9600) ;//BOUDRATE
pinMode(PinSuhu, INPUT) ;
}
void loop() {
data = analogRead(PinSuhu) ;
suhu = data * 500 / 1024 ;
Serial.print("data : ") ;
Serial.print(data ) ;
Serial.print(" Suhu : ");
Serial.print(suhu) ;
Serial.print(" C") ;
Serial.println();
delay(1000) ;
}
