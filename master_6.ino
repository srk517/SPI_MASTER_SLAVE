#include <SPI.h>
char f[5]="Jake\n";
String a;
int str_len;
void setup (void)
{
  Serial.begin(115200);
  digitalWrite(SS, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);

}  // end of setup


void loop (void)
{

  char c;
  char j [30];
  str_len=30;

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10
  while (Serial.available())
  {
    a = Serial.readString();
   // str_len=a.length();
  // char j [str_len];
    a.toCharArray(j,str_len);

  // send test string
  for ( char * p = j ; c = *p; p++)
    SPI.transfer (c);
  // disable Slave Select
  
  digitalWrite(SS, HIGH);
  delay (500);  
  }// 1 seconds delay
}  // end of loop
