// Motor A

int enA = 9;
int in1 = 8;
int in2 = 7;

// Joystick Input

int joyVert = A0; // Vertical  

// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;

// Joystick Values - Start at 512 (middle position)

int joyposVert = 512;


void setup()

{

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   
  // Start with motors disabled and direction forward
  
  // Motor A
  
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
}

void loop() {

  // Read the Joystick X positions

  joyposVert = analogRead(joyVert); 

  // Determine if this is a forward or backward motion
  // Do this by reading the Verticle Value
  // Apply results to MotorSpeed and to Direction

  if (joyposVert < 460)
  {
    // This is Backward

    // Set Motor A backward

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //Determine Motor Speeds

    // As we are going backwards we need to reverse readings

    joyposVert = joyposVert - 460; // This produces a negative number
    joyposVert = joyposVert * -1;  // Make the number positive

    MotorSpeed1 = map(joyposVert, 0, 460, 0, 255);

  }
  else if (joyposVert > 564)
  {
    // This is Forward

    // Set Motor A forward

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //Determine Motor Speeds

    MotorSpeed1 = map(joyposVert, 564, 1023, 0, 255);
  }
  else
  {
    // This is Stopped

    MotorSpeed1 = 0;

  }

  // Set the motor speeds

  analogWrite(enA, MotorSpeed1);
  
}
