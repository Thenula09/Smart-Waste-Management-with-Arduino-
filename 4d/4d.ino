#define enA 13//Enable1 L298 Pin enA 
#define in1 12 //Motor1  L298 Pin in1 
#define in2 9 //Motor1  L298 Pin in1 
#define in3 10 //Motor2  L298 Pin in1 
#define in4 9//Motor2  L298 Pin in1 
#define enB 8 //Enable2 L298 Pin enB 

#define R_S A0 
#define L_S A1 
// Adjustable Speeds
int baseSpeed = 60;
int turningSpeed = 100;
int speedDifference = 40;
void setup(){ 

pinMode(R_S, INPUT);
pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 

analogWrite(enA, baseSpeed); // Motor1 speed
analogWrite(enB, baseSpeed); // Motor2 speed 
delay(1000);
}
void loop(){  
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forword();}  

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();}  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} 
}

void forword(){  //forword
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);  
digitalWrite(in4, HIGH); 
}

void turnRight(){ //turnRight
digitalWrite(in1, LOW);  
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW);  
digitalWrite(in4, HIGH); 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);  
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);  
}

void Stop(){ //stop
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW); 
}