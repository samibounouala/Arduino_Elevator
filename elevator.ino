bool c=false;
int f = 13;
int g = 12;
int e = 11;
int d = 10;
int k = 9;
int b = 8;
int a = 7;  //7 Segment pin


int de=500;  // delay time

int bouttonspins[] = { 22, 23, 24, 25, 26, 27, 28, 29};
int bouttonstate[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int dernierbouttonstate[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW , LOW};
int ledPins[] = { 30, 31, 32, 33, 34, 35, 36, 37};
int ledstate[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int dernierledstate[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int fc[]={44,45,46,47};
int ledetage[] = {38, 39, 40, 41};
int ledetagestate[] = { LOW, LOW, LOW, LOW};
int reading[] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
long tdd[] = { 5, 5, 5, 5};
long lastDebounceTime = 0; // the last time the output pin was toggled
long debounceDelay = 50; 
long t=0;
int speed=150;
int in1 =50;
int in2=51;

int monter=5;
int descendre=6 ;
int etage;
int etaged;
int distance;
int count =0;
void setup() {
 // put your setup code here, to run once:
for (int i = 0; i < 8; i++) {
 pinMode(bouttonspins[i], INPUT);
 pinMode(fc[i], INPUT);
 pinMode(ledPins[i], OUTPUT);
 pinMode(ledetage[i], OUTPUT);
 
 }
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(50,OUTPUT);
 pinMode(51,OUTPUT);
  pinMode(59,OUTPUT);
 
 pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(k, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
 
 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 
}
void loop() {
 for (int j=0;j<8;j++){
 {if (j<4){
ledetagestate[j]=digitalRead(fc[j]);

digitalWrite(ledetage[j],ledetagestate[j]);
if (digitalRead( fc[j])==HIGH and j<4){ etage=j;seven_segments(j);
}
 }}
 if (ledstate[j]==HIGH ){
 t=t+1;
 
 { if (j<4){etaged=j;}
 else if (j>3){etaged=j-4;} }
 
 }
debut: for (int j = 0; j < 8;j++){
 reading[j] = digitalRead(bouttonspins[j]);
{ if (reading[j] !=dernierbouttonstate[j]){
 lastDebounceTime = millis();
}
if ((millis() - lastDebounceTime) > debounceDelay) {
 if (reading[j] != bouttonstate[j]) {
bouttonstate[j] = reading[j];
if (bouttonstate[j] == HIGH) {
 ledstate[j] = !ledstate[j];
 }
 }
 }
 
} 
dernierbouttonstate[j] = reading[j];
digitalWrite(ledPins[j],ledstate[j]);
{if (ledstate[j]==HIGH){continue;}}
 
distance= etage-etaged; 
 continue;}
 
//if(t==0){goto debut;}
if (t>0){
 if (distance==0 and ledetagestate[etage]==HIGH){
 quickLight(ledetage[etage]);
 
 t=0;
 ledstate[etage]=LOW;
 ledstate[etage+4]=LOW;
 dernierledstate[etaged]=LOW; 
 dernierledstate[etage+4]=LOW;

 digitalWrite(descendre,LOW);
 digitalWrite(monter,LOW);
stop_();
 
 
 c=LOW;
 }
 else if (distance>0 and (c==false)){
 

 digitalWrite(descendre,HIGH);
 go_down();
 
 c=true;
 t=t-1;
 }
 else if (distance<0 and (c==false)){

 digitalWrite(monter,HIGH);
 go_up();
 c=true;
 t=t-1;
 }}}}
void go_up(){
  digitalWrite(in2, LOW);
 for(int motorValue = 0 ; motorValue <= 255; motorValue +=20){
  digitalWrite(in2, LOW);
 analogWrite(in1, motorValue); 
 delay(300);      
 }
 for(int motorValue = 255 ; motorValue >= 0; motorValue -=5){
  digitalWrite(in2, LOW);
 analogWrite(in1, motorValue); 
 delay(30);    
  digitalWrite(in2, LOW);
    
 }
  }
void go_down(){
  digitalWrite(in1, LOW);
  for(int motorValue = 0 ; motorValue <= 255; motorValue +=20){
    digitalWrite(in2, LOW);
 analogWrite(in1, motorValue); 
 delay(300);      
 }
 for(int motorValue = 255 ; motorValue >= 0; motorValue -=5){
  digitalWrite(in1, LOW);
 analogWrite(in2, motorValue); 
 delay(30);      
 }
  analogWrite(in1, 0);
  
  }
void stop_(){
  analogWrite(in1, 0);
  digitalWrite(in2, LOW);
  }

void quickLight(int pin) {/*fonction du clignotement*/
 digitalWrite(pin, LOW);
 delay(200);
 digitalWrite(pin, HIGH);
 delay(200);
}
void seven_segments(int segment){
  if(segment==0){
    digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(k,1);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,1);  
 digitalWrite(g,0);   // 0
  delay(de);
    }
  if (segment==1){
    digitalWrite(a,0); 
 digitalWrite(b,1);  
 digitalWrite(k,1);  
 digitalWrite(d,0);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,0);   // 1
  delay(de);
    }
  if(segment==2){
    digitalWrite(a,1);  
 digitalWrite(b,1);  
 digitalWrite(k,0);  
 digitalWrite(d,1);  
 digitalWrite(e,1);  
 digitalWrite(f,0);  
 digitalWrite(g,1);   // 2
 delay(de);
    }  
  if (segment==3){
    digitalWrite(a,1); 
 digitalWrite(b,1);  
 digitalWrite(k,1);  
 digitalWrite(d,1);  
 digitalWrite(e,0);  
 digitalWrite(f,0);  
 digitalWrite(g,1);   // 3
  delay(de);
    }
  }
void prio(){
 
}
