void talck()
{
  myGLCD.setBackColor(0, 0, 255);
  drawButtons();  
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("BANK SECURITY SISTEM", CENTER, 270);
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.print("UPI YPTK PADANG", CENTER, 295);
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

  Serial.print("X = ");
  Serial.print(x);
  Serial.print("   ");
  Serial.print("Y = ");
  Serial.println(y);

      
      if ((x>=20) && (x<=70))  // Upper row
      {
        if ((y>=170) && (y<=210))  // Button: 1
        {
          waitForIt(10, 10, 60, 60);
          updateStr('1');
        }
        if ((y>=211) && (y<=230))  // Button: 6
        {
         waitForIt(10, 70, 60, 120);
         updateStr('6');
        }
      }

      if ((x>=80) && (x<=105))  // Upper row
      {
        if ((y>=180) && (y<=210))  // Button: 2
        {
         waitForIt(70, 10, 120, 60);
         updateStr('2');
        }
        if ((y>=210) && (y<=230))  // Button: 7
        {
         waitForIt(70, 70, 120, 120);
         updateStr('7');
        }
      }

      if ((x>=115) && (x<=150))  // Upper row
      {
        if ((y>=200) && (y<=227))  // Button: 3
        {
          waitForIt(130, 10, 180, 60);
          updateStr('3');
        }
        if ((y>=230) && (y<=240))  // Button: 8
        {
          waitForIt(130, 70, 180, 120);
          updateStr('8');
        }
      }

      if ((x>=180) && (x<=220))  // Upper row
      {
        if ((y>=230) && (y<=240))  // Button: 4
        {
          waitForIt(190, 10, 240, 60);
          updateStr('4');
        }
        if ((y>=246) && (y<=260))  // Button: 9
        {
          waitForIt(190, 70, 240, 120);
          updateStr('9');
        }
      }

       if ((x>=231) && (x<=270))  // Upper row
      {
        if ((y>=250) && (y<=260))  // Button: 5
        {
          waitForIt(250, 10, 300, 60);
          updateStr('5');
        }
        if ((y>=261) && (y<=270))  // Button: 0
        {
          waitForIt(250, 70, 300, 120);
          updateStr('0');
        }
      }

    if ((x>=320) && (x<=410))  // Upper row
      {
        if ((y>=260) && (y<=270))  // Button: Clear
        {
          waitForIt(330, 10, 470, 60);
          stCurrent[0]='\0';
          stCurrentLen=0;
          stLast[x] = '\0';
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect(50, 180, 400, 250);
          password.reset();
        }
       if ((y>=272) && (y<=290))  // Button: Enter
        {
          waitForIt(330, 80, 470, 130);
          if (stCurrentLen>0)
          {
           for (x=0; x<stCurrentLen+1; x++)
           {
             password.append(stCurrent[x]);
             password1.append(stCurrent[x]);
            stLast[x]=stCurrent[x];
            delay(10);
            }
            stCurrent[0]='\0';
            stCurrentLen=0;
            delay(10);
           myGLCD.setColor(VGA_BLACK);
         myGLCD.fillRect(0, 0, 479, 319);
            Login();
          }
          else
          {
            myGLCD.setColor(255, 0, 0);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            delay(500);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            myGLCD.setColor(0, 255, 0);
            
          }
        }
      }
    }
  }
}
