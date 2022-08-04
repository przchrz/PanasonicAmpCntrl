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
byte CenterByte = 0x0;
byte SubByte = 0x0;

int Byte01 = 19;    //0x13
int Byte02 = 14;    //0x0E
int Byte03 = 1;     //0x01
int Byte04 = 16;    //0x10 or 0x20 (dec 32)
int Byte05 = 0;     //0x00 (Volume 0)
int Byte06 = 128;   //0x80 (Bass 0)
int Byte07 = 128;   //0x80 (Treble 0)
int Byte08 = 128;   //0x80 (Balance 0)
int Byte09 = 128;   //0x80 (Fader 0)
int Byte10 = 0;     //0x00 (Speed 0)
byte Byte11_1 = 0x0;   //0x0 (Center 0)
byte Byte11_2 = 0x0;   //0x0 (Sub 0)
int Byte11 = 0;     //0x00 (Center 0, Sub 0)
int Byte12 = 0;     //0x00
int Byte13 = 0;     //0x00 (Beep: 0x21, 0x22, 0x23)
int Byte14 = 0;     //0x00
int Byte15 = 0;     //0x00
int Byte16 = 206;   //0xCE (CRC)

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
            Byte05 = VolumeInt;
        }
        else if(command.equals("Bass")){
            Bass = Serial.readStringUntil('\n');

             //float count = (float)256/12;
             //count = count * (-1+6);
             //int BassInt = (int)(count + .5);

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
             Byte06 = BassInt;
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
             Byte07 = TrebleInt;
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
             Byte08 = BalanceInt;
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
             Byte09 = FaderInt;
        }
        else if(command.equals("Center")){
            Center = Serial.readStringUntil('\n');

            switch (Center.toInt()) {
              case -6:
                CenterByte = 0xA;
                break;
              case -5:
                CenterByte = 0xB;
                break;
              case -4:
                CenterByte = 0xC;
                break;
              case -3:
                CenterByte = 0xD;
                break;
              case -2:
                CenterByte = 0xE;
                break;
              case -1:
                CenterByte = 0xF;
                break;
              case 0:
                CenterByte = 0x0;
                break;
              case 1:
                CenterByte = 0x1;
                break;
              case 2:
                CenterByte = 0x2;
                break;
              case 3:
                CenterByte = 0x3;
                break;
              case 4:
                CenterByte = 0x4;
                break;
              case 5:
                CenterByte = 0x5;
                break;
              case 6:
                CenterByte = 0x6;
                break;
              default:
                CenterByte = 0x0;
             }
             Byte11_1 = CenterByte;
             byte Byte11Byte = Byte11_1 << 4 | Byte11_2;
             Byte11 = int(Byte11Byte);
        }
        else if(command.equals("Sub")){
            Sub = Serial.readStringUntil('\n');

            switch (Sub.toInt()) {
              case -6:
                SubByte = 0xA;
                break;
              case -5:
                SubByte = 0xB;
                break;
              case -4:
                SubByte = 0xC;
                break;
              case -3:
                SubByte = 0xD;
                break;
              case -2:
                SubByte = 0xE;
                break;
              case -1:
                SubByte = 0xF;
                break;
              case 0:
                SubByte = 0x0;
                break;
              case 1:
                SubByte = 0x1;
                break;
              case 2:
                SubByte = 0x2;
                break;
              case 3:
                SubByte = 0x3;
                break;
              case 4:
                SubByte = 0x4;
                break;
              case 5:
                SubByte = 0x5;
                break;
              case 6:
                SubByte = 0x6;
                break;
              default:
                SubByte = 0x0;
             }
             Byte11_2 = SubByte;
             byte Byte11Byte = Byte11_1 << 4 | Byte11_2;
             Byte11 = int(Byte11Byte);
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
            Byte10 = SpeedInt;
        }
        else{
            Serial.println("Invalid command");
        }
    }

  int MessageToAmpWoCrc[15] = {Byte01, Byte02, Byte03, Byte04, Byte05, Byte06, Byte07, Byte08, Byte09, Byte10, Byte11, Byte12, Byte13, Byte14, Byte15};

  //Serial.print("CRC: ");
  //Serial.println(getCRC(MessageToAmpWoCrc,14));

  Byte16 = getCRC(MessageToAmpWoCrc,14);
  
  int MessageToAmpWithCrc[16] = {Byte01, Byte02, Byte03, Byte04, Byte05, Byte06, Byte07, Byte08, Byte09, Byte10, Byte11, Byte12, Byte13, Byte14, Byte15, Byte16};

  //const int message[] = {19, 14, 1, 16, 80, 128, 128, 128, 2, 0, 0, 0, 0, 0, 0, 252};

  for (int i=0; i <= 15; i++){
    RS485.write(MessageToAmpWithCrc[i]);
    Serial.print(MessageToAmpWithCrc[i], HEX);
    Serial.print(" ");
  }
  Serial.println(" ");
  
  Serial.print("Volume: ");
  Serial.print(VolumeInt);
  Serial.print(", Bass: ");
  Serial.print(BassInt);
  Serial.print(", Treble: ");
  Serial.print(TrebleInt);
  Serial.print(", Balance: ");
  Serial.print(BalanceInt);
  Serial.print(", Fader: ");
  Serial.print(FaderInt);
  Serial.print(", Center : ");
  Serial.print(CenterByte);
  Serial.print(", Sub : ");
  Serial.println(SubByte);
  
  if (RS485.available()) 
  {
  //  RX = RS485.read();   // Read the byte 
  //  
    Serial.println(RS485.read());
  //  //Serial.write(RX);   
  //  }
  //else {Serial.println("Oops!!!");  // print this if serial is not available
  }
  delay(100);
}

int getCRC(int message[], int length)
{
  int i, j, crc = 0;

  for (i = 0; i < length; i++)
  {
    crc = crc + message[i];
  }

  crc = crc % 256;

  crc = 256 - crc;

  return crc;
}
