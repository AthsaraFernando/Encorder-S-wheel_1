 #define A 1
 #define D 2

 uint8_t buf[8] = {
  0
 }; //Keyboard buffer bit rate

 #define outputA 6
 #define outputB 7

int counter = 0;
int aState;
int aLastState;

void setup() {
  Serial.begin (9600);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  pinMode (A,INPUT);
  pinMode (D,INPUT);

  aLastState = digitalRead(outputA);

  digitalWrite(A, 1);
  digitalWrite(D, 1);

  delay(200);

}

void loop() {
  aState = digitalRead(outputA);
  if (aState != aLastState){
    if (digitalRead(outputB) != aState) {
      counter ++;
    } else {
      counter --;
    }
    Serial.print("Position: ");
    Serial.println(counter);
  }
  aLastState = aState;

  if (counter > 5) {
    buf[0] = A;   // A
    buf[2] = 4;    // Letter a
    // buf[2] = 124;    // Copy key: Less portable
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  if (counter < -5) {
    buf[0] = D;   // D
    buf[2] = 7;    // Letter d
    // buf[2] = 124;    // Copy key: Less portable
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  delay(200);
}
