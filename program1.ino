#include <SPI.h>
#include <RFID.h>
#define SS_PIN 53
#define RST_PIN 49
#include <UTFT.h>
#include <UTouch.h>
#include <Password.h>

UTFT    myGLCD(31,38,39,40,41);
UTouch  myTouch( 6, 5, 4, 3, 2);
extern uint8_t SmallFont[];
extern uint8_t BigFont[];

RFID rfid(SS_PIN,RST_PIN);

int x, y;
char stCurrent[5]="";
int stCurrentLen=0;
char stLast[5]="";
int data ;
Password password = Password( "1234" );
Password password1 = Password( "1122" );

int hitung =0;
int getar = A0;
int selenoid1 = A1;
int selenoid2 = A2;

int color = 0;
word colorlist[] = {VGA_WHITE, VGA_BLACK, VGA_RED, VGA_BLUE, VGA_GREEN, VGA_FUCHSIA, VGA_YELLOW, VGA_AQUA};
int  bsize = 4;

void drawButtons()
{
// Draw the upper row of buttons
  for (x=0; x<5; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10+(x*60), 10, 60+(x*60), 60);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10+(x*60), 10, 60+(x*60), 60);
    myGLCD.printNumI(x+1, 27+(x*60), 27);
  }
// Draw the center row of buttons
  for (x=0; x<5; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10+(x*60), 70, 60+(x*60), 120);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10+(x*60), 70, 60+(x*60), 120);
    if (x<4)
      myGLCD.printNumI(x+6, 27+(x*60), 87);
  }
  myGLCD.print("0", 267, 87);
// Draw the lower row of buttons
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (330, 10, 470, 60);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (330, 10, 470, 60);
  myGLCD.print("Clear", 360, 26);
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (330, 80, 470, 130);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (330, 80, 470, 130);
  myGLCD.print("Enter", 360, 93);
  myGLCD.setBackColor (0, 0, 0);

}

void updateStr(int val)
{
  if (stCurrentLen<4)
  {
    stCurrent[stCurrentLen]=val;
    stCurrent[stCurrentLen+1]='\0';
    stCurrentLen++;
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(stCurrent, CENTER, 195);
    
  }
  else
  {
     waitForIt(330, 10, 470, 60);
     stCurrent[0]='\0';
     stCurrentLen=0;
     stLast[x] = '\0';
     myGLCD.setColor(0, 0, 0);
     myGLCD.fillRect(50, 180, 400, 250);
     password.reset();
  }
}

// Draw a red frame while a button is touched
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
  myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

/*************************
**  Required functions  **
*************************/

void setup()
{
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 0, 0);

  pinMode(selenoid1, OUTPUT);
  pinMode(selenoid2, OUTPUT);
  digitalWrite(selenoid1, HIGH);  
  digitalWrite(selenoid2, HIGH);  
}

void loop()
{
  //t_rfid();
  //t_nama1();
  //judul();
 // rid();
  talck();
}

// tampilan lcd
void judul()
{
myGLCD.setColor(VGA_RED);
myGLCD.print("SISTEM KEAMANAN BRANGKAS", CENTER, 20);
myGLCD.print("PADA SEBUAH BANK", CENTER, 45);
myGLCD.setColor(VGA_GREEN);
myGLCD.print("TUGAS AKHIR PERKULIAN", CENTER, 90);
myGLCD.print("DISUSUN OLEH :", CENTER, 115);
myGLCD.setColor(VGA_FUCHSIA);
myGLCD.print("NAMA : RAFLI ", CENTER, 155);
myGLCD.print("NO Bp: 13-000", CENTER, 180);
myGLCD.setColor(VGA_YELLOW);
myGLCD.print("UPI YPTK PADANG", CENTER, 255);
myGLCD.setColor(VGA_WHITE);
myGLCD.print("#2019 GANTI PRESIDEN", CENTER, 285);
}

void t_rfid()
{
//myGLCD.setColor(VGA_BLACK);
//myGLCD.fillRect(0, 0, 479, 319);
myGLCD.setColor(VGA_RED);
myGLCD.print("SILAHKAN PERKENALKAN", CENTER, 20);
myGLCD.print("CARD ID ANDA", CENTER, 45);
myGLCD.setColor(VGA_BLUE);
myGLCD.print("BANK SECURITY SISTEM", CENTER, 255);
myGLCD.setColor(VGA_YELLOW);
myGLCD.print("UPI YPTK PADANG", CENTER, 285);
delay(500);
myGLCD.print("            ", CENTER, 45);
delay(500);
}

void t_akses(){
myGLCD.setColor(VGA_RED);
myGLCD.print("SISTEM DIAKTIFKAN", CENTER, 20);
myGLCD.setColor(VGA_RED);
myGLCD.print("WELCOM", CENTER, 160);
myGLCD.print("SILAHKAN MASUK", CENTER, 185);
myGLCD.setColor(VGA_BLUE);
myGLCD.print("BANK SECURITY SISTEM", CENTER, 255);
myGLCD.setColor(VGA_YELLOW);
myGLCD.print("UPI YPTK PADANG", CENTER, 285);
delay(300);
myGLCD.print("      ", CENTER, 160);
delay(300);
myGLCD.setColor(VGA_GREEN);
myGLCD.print("WELCOM", CENTER, 160);
delay(300);
myGLCD.print("      ", CENTER, 160);
delay(300);
myGLCD.setColor(VGA_FUCHSIA);
myGLCD.print("WELCOM", CENTER, 160);
delay(300);
myGLCD.print("      ", CENTER, 160);
delay(300);
}

void t_nama1()
{
myGLCD.setColor(VGA_WHITE);
myGLCD.print("AKSES DITERIMA", CENTER, 70);
myGLCD.print("NAMA : RAFLI", CENTER, 95);
myGLCD.setColor(VGA_GREEN);
myGLCD.print("PINTU DEPAN DIBUKA", CENTER, 160);
}

void t_nama2()
{
myGLCD.setColor(VGA_WHITE);
myGLCD.print("AKSES DITERIMA", CENTER, 70);
myGLCD.print("NAMA : PRABOWO", CENTER, 95);
}

void t_nama3()
{
myGLCD.setColor(VGA_WHITE);
myGLCD.print("AKSES DITOLAK", CENTER, 100);
myGLCD.print("CARD ID TIDAK TERDAFTAR", CENTER, 125);
}

