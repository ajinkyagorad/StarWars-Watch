#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <SPI.h>
//#include <SD.h>
//#include <TMRpcm.h>
//#include <pcmConfig.h>  
//#include <utility/m2ghu8g.h>
#include <M2tk.h>
#include <U8glib.h>
#include <utility/mas.h>

#include <SharpIR.h>

#define ir A1
#define model 1080
boolean done=false;
int dis;
SharpIR sharp(ir, 25, 93, model);

//#define u8g_logo_width 38
//#define u8g_logo_height 24
// SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
U8GLIB_SSD1306_128X64 u8g(A2,A3,U8G_PIN_NONE,8,6);  
//GPSClass gps;
//position pos;
int  img=0;

void draw(){
  
//  switch(img%2)
//  {
//    case 0 : u8g.drawBitmapP( 0, 0, 16,64, electrified);  break;

//    case 1 : u8g.drawBitmapP( 0, 0, 16,64, stab); break;
//    while(1); img++;
//  }
 
  
  //u8g.setPrintPos(0,20);
  //u8g.print(pos.lat);
  u8g.setPrintPos(0,50);
  u8g.print(String(dis));
}
void setup()
{
  u8g.begin();  
  u8g.setColorIndex(1);   
  u8g.setFont(u8g_font_osb18);
  pinMode (ir, INPUT);
}

void loop()
{
  /*gps.getLatLon(pos,500);
  pos.lat="lat "+pos.lat;
  pos.lon="lon "+pos.lon;
  
  
  */
 dis=sharp.distance();  // this returns the distance to the object you're measuring
  u8g.firstPage();
  do {
    
    draw();
  } while( u8g.nextPage() );
   
  


}
