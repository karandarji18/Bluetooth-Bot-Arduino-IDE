int LmotorUp = 10; //initialising Arduino port 10 be be called as LmotorUp
int LmotorDn = 11; //initialising Arduino port 11 be be called as LmotorDn
int RmotorUp = 6;  //initialising Arduino port 6 be be called as RmotorUp
int RmotorDn = 9;  //initialising Arduino port 9 be be called as RmotorDn

void setup()
{
  Serial.begin(9600);
  pinMode(LmotorUp,OUTPUT);//Setting ports as OUTPUTS as they 
  pinMode(LmotorDn,OUTPUT);//supply signal values to motor driver
  pinMode(RmotorUp,OUTPUT);
  pinMode(RmotorDn,OUTPUT);

  
  Serial.println("Team ONYX Welcomes you"); //begining statement because i can :P
  delay(1000);
} 
  

void loop()
{
  if(Serial.available()>0)//Checking is Serial data available
  {
    int input = Serial.read(); //Storing value of read data into variable assigned
    switch(input)
    {
     case 'e' : MoveSlow(); //Move slow in forward direction
     break;
     case 'w' : MoveF(); //Calling respective functions if mathced with case label 
     break;
     case 's' : MoveB(); // here is it important to use '' as that stores the ASCII value is the letter in the variable
     break;
     case 'a' : MoveL(); // and hence we can use the int keyword
     break;
     case 'd' : MoveR();
     break;
     case 'x' : Stop();
     break;
     default : break;
    }
  } 
  delay(1);
}

void MoveF()
{
  Serial.println("Team ONYX Forward");
  digitalWrite(LmotorUp,HIGH); //We are writing a Digital HIGH to the upper left pin of the motor driver
  digitalWrite(LmotorDn,LOW); //We are writing a Digital LOW to the lower left pin of the motor driver
  digitalWrite(RmotorUp,HIGH); //We are writing a Digital HIGH to the upper right pin of the motor driver
  digitalWrite(RmotorDn,LOW); //We are writing a Digital LOW to the lower right pin of the motor driver
   // As a result the robot will move forward
}

void MoveB()
{
  Serial.println("Team ONYX Backward");
  digitalWrite(LmotorUp,LOW); //Reverse logic of above
  digitalWrite(LmotorDn,HIGH);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,HIGH);
}

void MoveL()
{
  Serial.println("Team ONYX Left");
  digitalWrite(LmotorUp,LOW); 
  analogWrite(LmotorDn,190); //this will cause the robot to move left
  digitalWrite(RmotorUp,HIGH);
  digitalWrite(RmotorDn,LOW);
}

void MoveR()
{
  Serial.println("Team ONYX Right");
  digitalWrite(LmotorUp,HIGH);
  digitalWrite(LmotorDn,LOW);//this will cause the robot to move right
  digitalWrite(RmotorUp,LOW);
  analogWrite(RmotorDn,190);
}

void Stop()
{
  Serial.println("Team ONYX Stop");
  digitalWrite(LmotorUp,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(LmotorDn,LOW);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
}
 void MoveSlow()
{
  Serial.println("Team ONYX Stop");
  analogWrite(LmotorUp,190);
  digitalWrite(LmotorDn,LOW); 
  analogWrite(RmotorUp,190);
  digitalWrite(RmotorDn,LOW);
}