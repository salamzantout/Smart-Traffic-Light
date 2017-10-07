import processing.serial.*;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
String input[];

void setup()
{
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match port
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
  println(val); //print it out in the console
  input = loadStrings("http://trafficcontroller.co.nf/?cars="+val);
  delay(10000);  //receive number of cars every 10 sec
}