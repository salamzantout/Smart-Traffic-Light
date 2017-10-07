import processing.serial.*;
Serial ComPort;
String input[];
int current =0;
boolean sent;
void setup(){
  String portName = Serial.list()[0];
  ComPort = new Serial(this, portName, 9600);
  ComPort.bufferUntil('\n');
}
void draw(){
  sent=false;
  input = loadStrings("http://trafficcontroller.co.nf/TrafficController.txt");
  if(input != null){
    if(input.length != 0){
      String s_last = input[0];
      int last = Integer.parseInt(s_last);
      delay(1000);
      //println("last="+last);
      if((current != last)&& (!sent)){
        println("sending to Arduino, update time of green");
        ComPort.write(last);
        sent=true;
        //ComPort.write(last);
      }
      input = loadStrings("http://trafficcontroller.co.nf/TrafficController.txt");
      if (input.length != 0){
      String s_current = input[0];
      current = Integer.parseInt(s_current);
      //println("current="+current);
      if((current != last) && (!sent)){
        println("sending to Arduino, update time of green");
        ComPort.write(current);
        sent=true;
        //ComPort.write(last);
      }
     }
    }
  }
  delay(1000);   
}