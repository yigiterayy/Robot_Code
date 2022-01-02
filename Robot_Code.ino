const int Enable_A = 10;
const int Enable_B = 5;
const int inputA1 = 9;
const int inputA2 = 8;
const int inputB1 = 7;
const int inputB2 = 6;
const int sol_sensor = 11;
#define orta_sensor 3
const int sag_sensor = 12;
const int arka_sensor = 4;
#define pompa 13

int sol_deger = 0;
int sag_deger = 0;
int orta_deger = 0;
int arka_deger = 0;
int i = 0;

boolean fire = false;


void setup() {
  Serial.begin(9600);
 pinMode(Enable_A, OUTPUT);
pinMode(Enable_B, OUTPUT);
pinMode(inputA1, OUTPUT);
pinMode(inputA2, OUTPUT);
pinMode(inputB1, OUTPUT);
pinMode(inputB2, OUTPUT);
pinMode(sol_sensor, INPUT);
pinMode(orta_sensor, INPUT);
pinMode(sag_sensor, INPUT);
pinMode(arka_sensor, INPUT);
pinMode(pompa, OUTPUT);
pinMode(2, OUTPUT);

}



void loop() {
  sol_deger=digitalRead(sol_sensor);
  sag_deger=digitalRead(sag_sensor);
  arka_deger=digitalRead(arka_sensor);
  orta_deger=digitalRead(orta_sensor);
  Serial.print("Sag:");
  Serial.println(sag_deger);
  Serial.print("Sol:");
  Serial.println(sol_deger);
    Serial.print("Orta:");
  Serial.println(orta_deger);
  if(sol_deger == 0 && sag_deger==1){
    analogWrite(Enable_A, 150);
    analogWrite(Enable_B, 150);
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, HIGH);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    digitalWrite(pompa, LOW);
    delay(100);
  }
    if(sol_deger==1 && sag_deger==1 ){
         digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, LOW);
    
    
      Serial.println("--------------------------------------------");
      delay(200);
    }

   if(sol_deger == 1 && sag_deger==0){
    analogWrite(Enable_A, 150);
    analogWrite(Enable_B, 150);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 ,LOW);
    digitalWrite(inputB2, HIGH);
    digitalWrite(pompa, LOW);
    delay(100);
  }
     if(arka_deger == 0){
    analogWrite(Enable_A, 200);
    analogWrite(Enable_B, 200);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, HIGH);
    digitalWrite(pompa, LOW);
    delay(1750);
  }
    if(orta_deger==0 && sag_deger == 1 && sol_deger == 1 ){
      Serial.println("***************duz*********************");
    analogWrite(Enable_A, 125);
    analogWrite(Enable_B, 125);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    digitalWrite(pompa, HIGH);
    for(i=700;i<800;i++){
  tone(2,i);
  delay(1);
  }
  for(i=800;i>700;i--){
  tone(2,i);
  delay(1);
  }

    
 
    
  }
      else{
     digitalWrite(pompa, LOW);
     noTone(2);
      }
}
