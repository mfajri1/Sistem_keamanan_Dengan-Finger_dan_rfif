// rfid

void rid()
{ 
 t_rfid();  
  if(rfid.isCard()){
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.println(rfid.serNum[3]);
       if (rfid.serNum[0] == 176){
        myGLCD.setColor(VGA_BLACK);
         myGLCD.fillRect(0, 0, 479, 319);
        t_akses();
         t_nama1();
         delay(1000);
         digitalWrite(selenoid1, LOW);
         delay(5000);
         digitalWrite(selenoid1, HIGH); 
         myGLCD.setColor(VGA_BLACK);
         myGLCD.fillRect(0, 0, 479, 319);
          }

           else if (rfid.serNum[0] ==117){
            myGLCD.setColor(VGA_BLACK);
           myGLCD.fillRect(0, 0, 479, 319);
            t_akses();
            t_nama2();
           delay(1000);
         digitalWrite(selenoid1, LOW);
         delay(5000);
         digitalWrite(selenoid1, HIGH); 
         myGLCD.setColor(VGA_BLACK);
         myGLCD.fillRect(0, 0, 479, 319);
          }
          else {
            t_nama3();
            delay(3000);
            myGLCD.setColor(VGA_BLACK);
             myGLCD.fillRect(0, 0, 479, 319);
          }
        }
  }
  rid();
}
