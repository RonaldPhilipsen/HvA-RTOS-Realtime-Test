
int i = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(3)){
     i = 0;
  }

  while(i <= 1000){
    digitalWrite(2, 255);
    delay(1);
    digitalWrite(2, 0);
    delay(1);
    i++;
  }
  
}
