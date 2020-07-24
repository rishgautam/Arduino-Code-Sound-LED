#define red 11
#define green 10
#define blue 9
int c=38;
float sensorvalue = 0, filteredSignal = 0, filteredSignalValues[] = {508+c, 510+c, 512+c, 514+c, 516+c, 518+c, 520+c, 522+c, 524+c};
#define delay 3
#define sensor A0

      

void setup () {

  Serial.begin (9600);
}

void loop () {

  MainFunction();
}

void MainFunction() {

  sensorvalue = analogRead(sensor);

  FilterSignal(sensorvalue);

  CompareSignalFiltered(filteredSignal);
}

void FilterSignal(float sensorSignal) {

  filteredSignal = (0.950 * filteredSignal) + (0.055 * sensorSignal);
}

void CompareSignalFiltered(float filteredSignal) {

  if (filteredSignal < filteredSignalValues[0]) {
    RGBColor(255, 255, 255);
    //Serial.println("Blue");
  } else if (filteredSignal >= filteredSignalValues[0] && filteredSignal < filteredSignalValues[1]) {
    //Serial.println("Azure");
    RGBColor(170, 50, 255);
  } else if (filteredSignal >= filteredSignalValues[1] && filteredSignal < filteredSignalValues[2]) {
    RGBColor(100, 30, 0);
    //Serial.println("Cyan");
  } else if (filteredSignal >= filteredSignalValues[2] && filteredSignal < filteredSignalValues[3]) {
    RGBColor(50, 50, 255);
    //Serial.println("Aqua marine");
  } else if (filteredSignal >= filteredSignalValues[3] && filteredSignal < filteredSignalValues[4]) {
    RGBColor(0, 0, 255);
    //Serial.println("Green");
  } else if (filteredSignal >= filteredSignalValues[4] && filteredSignal < filteredSignalValues[5]) {
    RGBColor(127, 255, 0);
    //Serial.println("Chartreuse");
  } else if (filteredSignal >= filteredSignalValues[5] && filteredSignal < filteredSignalValues[6]) {
    RGBColor(255, 255, 0);
    //Serial.println("Yellow");
  } else if (filteredSignal >= filteredSignalValues[6] && filteredSignal < filteredSignalValues[7]) {
    RGBColor(255, 0, 127);
    //Serial.println("Magenta");
  } else if (filteredSignal >= filteredSignalValues[7] && filteredSignal < filteredSignalValues[8]) {
    RGBColor(255, 0, 0);
    //Serial.println("Rose");
  } else if (filteredSignal >= filteredSignalValues[8] && filteredSignal < filteredSignalValues[9]) {
    RGBColor(255, 127, 0);
    //Serial.println("Orange");
  } else if (filteredSignal >= filteredSignalValues[9]) {
    RGBColor(0, 255, 0);
    //Serial.println("Red");
  } else {
    RGBColor(0, 0, 255);
    //Serial.println("Default: Blue");
  }
}

void RGBColor(int Rcolor, int Gcolor, int Bcolor) {

  analogWrite(red, Rcolor);
  analogWrite(green, Gcolor);
  analogWrite(blue, Bcolor);

  delay(delay);

  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}
