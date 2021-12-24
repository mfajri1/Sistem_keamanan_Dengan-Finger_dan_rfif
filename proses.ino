
/// lcd
void Login()
{
 if (password.evaluate())
 {
 Serial.println("Password BENAR");
 Serial.write(254);
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("PASWORD DITERIMA", CENTER, 180);
 myGLCD.print("                ", CENTER, 195);
rid();
 }

else if (password1.evaluate())
 {
 Serial.println("Password BENAR");
 Serial.write(254);
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("PASWORD DITERIMA", CENTER, 180);
 myGLCD.print("                ", CENTER, 195);
 }
 else if (hitung >3){
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("KESALAHAN PASWORD", CENTER, 180);
 myGLCD.print("SUDAH MELEBIHI BATAS", CENTER, 205);
 //hitung = 0;
 rid();
 }

// jika password tidak benar atau salah
 else
 {
  hitung++;
 Serial.println("Password SALAH ... !!!");
 Serial.write(254);
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("PASWORD SALAH", CENTER, 180);
 myGLCD.print("             ", CENTER, 195);
 delay(500);
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("             ", CENTER, 180);
 myGLCD.print("             ", CENTER, 195);
 delay(500);
 myGLCD.print("PASWORD SALAH", CENTER, 180);
 myGLCD.print("             ", CENTER, 195);
 delay(500);
 myGLCD.setColor(255, 0, 0);
 myGLCD.print("             ", CENTER, 180);
 myGLCD.print("             ", CENTER, 195);
 delay(500);
 myGLCD.print("PASWORD SALAH", CENTER, 180);
 myGLCD.print("             ", CENTER, 195);
  delay(500);
 waitForIt(330, 10, 470, 60);
 stCurrent[0]='\0';
 stCurrentLen=0;
 stLast[x] = '\0';
 myGLCD.setColor(0, 0, 0);
 myGLCD.fillRect(50, 180, 400, 250);
 password.reset();
 Serial.print(hitung);
 }
}


