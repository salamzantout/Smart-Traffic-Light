#define trigPin 8
#define echoPin 7

unsigned long currentMillis;
// use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time out of range was read

// constants won't change :
const long interval = 1472;           // interval at which out of range needs to be read consecutively

bool firstOOR = true;
bool timeCond = false;

unsigned long carCount=0;

void setup() {
  // put your setup code here, to run once:
  
  //initialize serial communications at a 9600 baud rate
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.4;
  if (distance >= 250 || distance <= 0)     //out of range
  {        
    if(firstOOR)                       //the first time an OOR is read
    {
      timeCond = false;
      previousMillis = millis();  //set the previous millis to current time
      firstOOR = false;
    }
    else                            //not the first OOR
    {
      //need minimum 1.472 seconds of out of range between two consecutive cars

      // check to see if 1.472 seconds have passed; that is, if the
      // difference between the current time and last time of out of range
      // consecutively is bigger than 1.472 seconds
      currentMillis = millis();
    
      if (currentMillis - previousMillis >= interval) {
        timeCond = true;
        // save the last time out of range was read
        //previousMillis = currentMillis;
      }
    }
  }
  else   //sensor actually reading an acceptable (within range) value
  {                                 
    firstOOR = true;     //not consecutive OOR reading anymore, start over!

    if(timeCond)    //sensor read OOR for 1.472 seconds minimum before this
    {
      if (distance >= 100)    //this is the minimum distance measured by the sensor to count a car
      {
        carCount++;           //all the conditions are satisfied --> increase counter, a car has indeed passed
        Serial.println(carCount);    //send number of cars whenever it is updated
 
      }
    }
      
  }
  delay(500);

}
