#include<SoftwareSerial.h>

int RX;
SoftwareSerial RS485(8,9);

String command;

String Volume;
String Bass;
String Treble;
String Balance;
String Fader;
String Center;
String Sub;
String Speed;

int VolumeInt = 0;
int BassInt = 128;
int TrebleInt = 128;
int BalanceInt = 128;
int FaderInt = 128;
int SpeedInt = 0;
String CenterString = "0";
String SubString = "0";

String Byte01 = String(19, HEX);  //0x13
String Byte02 = String(14, HEX);  //0x0E
String Byte03 = String(1, HEX);   //0x01
String Byte04 = String(16, HEX);  //0x10 or 0x20 (dec 32)
String Byte05 = String(0, HEX);   //0x00 (Volume 0)
String Byte06 = String(128, HEX); //0x80 (Bass 0)
String Byte07 = String(128, HEX); //0x80 (Treble 0)
String Byte08 = String(128, HEX); //0x80 (Balance 0)
String Byte09 = String(128, HEX); //0x80 (Fader 0)
String Byte10 = String(0, HEX);   //0x00 (Speed 0)
String Byte11_1 = String("0");     //0x0 (Center 0)
String Byte11_2 = String("0");     //0x0 (Sub 0)
String Byte11 = String("00");     //0x00 (Center 0, Sub 0)
String Byte12 = String(0, HEX);   //0x00
String Byte13 = String(0, HEX);   //0x00 (Beep: 0x21, 0x22, 0x23)
String Byte14 = String(0, HEX);   //0x00
String Byte15 = String(0, HEX);   //0x00
String Byte16 = String(206, HEX); //0xCE (CRC)

String MessageToAmpWoCrc[15];
String MessageToAmpWithCrc[16];


void setup() {
  
  Serial.begin(9600);
  Serial.println("configuring serial:\n");
  RS485.begin(9600);
  Serial.println("configuring RS485" );
  Serial.println("set up done!!");
}

void loop() {

  if(Serial.available()){
        command = Serial.readStringUntil(':');
         
        if(command.equals("Volume")){
            Volume = Serial.readStringUntil('\n');

            VolumeInt = Volume.toInt();
            if(VolumeInt < 0){
              VolumeInt = 0;
            }
            else if(VolumeInt > 255){
              VolumeInt = 255;
            }
            Byte05 = String(VolumeInt, HEX);
        }
        else if(command.equals("Bass")){
            Bass = Serial.readStringUntil('\n');

            switch (Bass.toInt()) {
              case -6:
                BassInt = 0;
                break;
              case -5:
                BassInt = 21;
                break;
              case -4:
                BassInt = 42;
                break;
              case -3:
                BassInt = 63;
                break;
              case -2:
                BassInt = 85;
                break;
              case -1:
                BassInt = 106;
                break;
              case 0:
                BassInt = 128;
                break;
              case 1:
                BassInt = 148;
                break;
              case 2:
                BassInt = 170;
                break;
              case 3:
                BassInt = 191;
                break;
              case 4:
                BassInt = 212;
                break;
              case 5:
                BassInt = 233;
                break;
              case 6:
                BassInt = 255;
                break;
              default:
                BassInt = 128;
             }
             Byte06 = String(BassInt, HEX);
        }
        else if(command.equals("Treble")){
            Treble = Serial.readStringUntil('\n');

            switch (Treble.toInt()) {
              case -6:
                TrebleInt = 0;
                break;
              case -5:
                TrebleInt = 21;
                break;
              case -4:
                TrebleInt = 42;
                break;
              case -3:
                TrebleInt = 63;
                break;
              case -2:
                TrebleInt = 85;
                break;
              case -1:
                TrebleInt = 106;
                break;
              case 0:
                TrebleInt = 128;
                break;
              case 1:
                TrebleInt = 148;
                break;
              case 2:
                TrebleInt = 170;
                break;
              case 3:
                TrebleInt = 191;
                break;
              case 4:
                TrebleInt = 212;
                break;
              case 5:
                TrebleInt = 233;
                break;
              case 6:
                TrebleInt = 255;
                break;
              default:
                TrebleInt = 128;
             }
             Byte07 = String(TrebleInt, HEX);
        }
        else if(command.equals("Balance")){
            Balance = Serial.readStringUntil('\n');

            switch (Balance.toInt()) {
              case -9:
                BalanceInt = 0;
                break;
              case -8:
                BalanceInt = 14;
                break;
              case -7:
                BalanceInt = 28;
                break;
              case -6:
                BalanceInt = 42;
                break;
              case -5:
                BalanceInt = 56;
                break;
              case -4:
                BalanceInt = 70;
                break;
              case -3:
                BalanceInt = 85;
                break;
              case -2:
                BalanceInt = 99;
                break;
              case -1:
                BalanceInt = 113;
                break;
              case 0:
                BalanceInt = 128;
                break;
              case 1:
                BalanceInt = 141;
                break;
              case 2:
                BalanceInt = 155;
                break;
              case 3:
                BalanceInt = 170;
                break;
              case 4:
                BalanceInt = 184;
                break;
              case 5:
                BalanceInt = 198;
                break;
              case 6:
                BalanceInt = 212;
                break;
              case 7:
                BalanceInt = 226;
                break;
              case 8:
                BalanceInt = 240;
                break;
              case 9:
                BalanceInt = 255;
                break;
              default:
                BalanceInt = 128;
             }
             Byte08 = String(BalanceInt, HEX);
        }
        else if(command.equals("Fader")){
            Fader = Serial.readStringUntil('\n');

            switch (Fader.toInt()) {
              case -9:
                FaderInt = 0;
                break;
              case -8:
                FaderInt = 14;
                break;
              case -7:
                FaderInt = 28;
                break;
              case -6:
                FaderInt = 42;
                break;
              case -5:
                FaderInt = 56;
                break;
              case -4:
                FaderInt = 70;
                break;
              case -3:
                FaderInt = 85;
                break;
              case -2:
                FaderInt = 99;
                break;
              case -1:
                FaderInt = 113;
                break;
              case 0:
                FaderInt = 128;
                break;
              case 1:
                FaderInt = 141;
                break;
              case 2:
                FaderInt = 155;
                break;
              case 3:
                FaderInt = 170;
                break;
              case 4:
                FaderInt = 184;
                break;
              case 5:
                FaderInt = 198;
                break;
              case 6:
                FaderInt = 212;
                break;
              case 7:
                FaderInt = 226;
                break;
              case 8:
                FaderInt = 240;
                break;
              case 9:
                FaderInt = 255;
                break;
              default:
                FaderInt = 128;
             }
             Byte09 = String(FaderInt, HEX);
        }
        else if(command.equals("Center")){
            Center = Serial.readStringUntil('\n');

            switch (Center.toInt()) {
              case -6:
                CenterString = "A";
                break;
              case -5:
                CenterString = "B";
                break;
              case -4:
                CenterString = "C";
                break;
              case -3:
                CenterString = "D";
                break;
              case -2:
                CenterString = "E";
                break;
              case -1:
                CenterString = "F";
                break;
              case 0:
                CenterString = "0";
                break;
              case 1:
                CenterString = "1";
                break;
              case 2:
                CenterString = "2";
                break;
              case 3:
                CenterString = "3";
                break;
              case 4:
                CenterString = "4";
                break;
              case 5:
                CenterString = "5";
                break;
              case 6:
                CenterString = "6";
                break;
              default:
                CenterString = "0";
             }
             Byte11_1 = CenterString;
             Byte11 = Byte11_1 + Byte11_2;
        }
        else if(command.equals("Sub")){
            Sub = Serial.readStringUntil('\n');

            switch (Sub.toInt()) {
              case -6:
                SubString = "A";
                break;
              case -5:
                SubString = "B";
                break;
              case -4:
                SubString = "C";
                break;
              case -3:
                SubString = "D";
                break;
              case -2:
                SubString = "E";
                break;
              case -1:
                SubString = "F";
                break;
              case 0:
                SubString = "0";
                break;
              case 1:
                SubString = "1";
                break;
              case 2:
                SubString = "2";
                break;
              case 3:
                SubString = "3";
                break;
              case 4:
                SubString = "4";
                break;
              case 5:
                SubString = "5";
                break;
              case 6:
                SubString = "6";
                break;
              default:
                SubString = "0";
             }
             Byte11_2 = SubString;
             Byte11 = Byte11_1 + Byte11_2;
        }
        else if(command.equals("Speed")){
            Speed = Serial.readStringUntil('\n');

            SpeedInt = Speed.toInt();
            if(SpeedInt < 0){
              SpeedInt = 0;
            }
            else if(SpeedInt > 255){
              SpeedInt = 255;
            }
            Byte10 = String(SpeedInt, HEX);
        }
        else{
            Serial.println("Invalid command");
        }
    }

  MessageToAmpWoCrc = {Byte01, Byte02, Byte03, Byte04, Byte05, Byte06, Byte07, Byte08, Byte09, Byte10, Byte11, Byte12, Byte13, Byte14, Byte15};
  Byte16 = String(getCRC(MessageToAmpWoCrc,14), HEX);
  MessageToAmpWithCrc = {Byte01, Byte02, Byte03, Byte04, Byte05, Byte06, Byte07, Byte08, Byte09, Byte10, Byte11, Byte12, Byte13, Byte14, Byte15, Byte16};

  
  if (RS485.available()) 
  {
    RX = RS485.read();   // Read the byte 
    
    Serial.println(RX, HEX);
    //Serial.write(RX);   
    }
  else {Serial.println("Oops!!!");  // print this if serial is not available
  delay(1000);}
}

unsigned char getCRC(unsigned char message[], unsigned char length)
{
  unsigned char i, j, crc = 0;

  for (i = 0; i < length; i++)
  {
    crc = crc + message[i];
  }

  while(crc > 255)
    crc = crc << 1;

  crc = 256 - crc;

  return crc;
}
