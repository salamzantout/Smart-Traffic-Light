int greenPin = 10;                // Green LED connected to digital pin 10
int redPin = 12;                  // Red LED connected to digital pin 12
int yellowPin = 11;               // Yellow LED connected to digital pin 11
int greenOn = 1000;               // 1 seconds default green time
int key;                          //variable to indicate increase or decrease
void setup()                      // run once, when the sketch starts
{
  Serial.begin(9600);             // set up serial input
  pinMode(redPin, OUTPUT);        // sets the digital pin as output
  pinMode(yellowPin, OUTPUT);     // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
}

void loop()                       // run over and over again
{
  if(Serial.available()>0) {
    key = Serial.read();
    Serial.print(key);
    Serial.println();
    if(key == 1){                 //decrease green time
        greenOn=greenOn - 1000;
        digitalWrite(greenPin, HIGH);   // sets the Green LED on
        delay(greenOn);                   // waits for ten seconds
        digitalWrite(yellowPin, HIGH);  // sets the Yellow LED on
        delay(500);
        digitalWrite(greenPin, LOW);    // sets the Green LED off
        digitalWrite(yellowPin, LOW);   // sets the Yellow LED off
        delay(500);                     // waits for half a second 
        
        digitalWrite(redPin, HIGH);     // sets the Red LED on
        delay(5000);                   // waits for ten seconds
        digitalWrite(redPin, LOW);      // sets the Red LED off
    }else if(key == 2){         //increase green time
        greenOn=greenOn + 1000;
        digitalWrite(greenPin, HIGH);   // sets the Green LED on
        delay(greenOn);                   // waits for ten seconds
        digitalWrite(yellowPin, HIGH);  // sets the Yellow LED on
        delay(500);
        digitalWrite(greenPin, LOW);    // sets the Green LED off
        digitalWrite(yellowPin, LOW);   // sets the Yellow LED off
        delay(500);                     // waits for half a second 
        
        digitalWrite(redPin, HIGH);     // sets the Red LED on
        delay(5000);                   // waits for ten seconds
        digitalWrite(redPin, LOW);      // sets the Red LED off
    }
  }
}
