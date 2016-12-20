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
#include "GPS_NMEA.h"
#include "image.h"
#define u8g_logo_width 38
#define u8g_logo_height 24
// SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
U8GLIB_SSD1306_128X64 u8g(A2,A3,U8G_PIN_NONE,8,6);	
GPSClass gps;
position pos;
int  img=0;
void draw(){
	//u8g.setFont(u8g_font_unifont);
	switch(img%1)
	{
		case 0 : u8g.drawBitmapP( 0, 0, 16,64, starWars);	break;
		//case 1 : u8g.drawBitmapP( 0, 0, 16,64, stab);	break;
		while(1);
	}
	
	//u8g.setPrintPos(0,20);
	//u8g.print(pos.lat);
//	u8g.setPrintPos(0,50);
//	u8g.print("Happy Birthday");
}
void setup()
{
	u8g.begin();	
	u8g.setColorIndex(1);   
	
}

void loop()
{
	/*gps.getLatLon(pos,500);
	pos.lat="lat "+pos.lat;
	pos.lon="lon "+pos.lon;
	
	
	*/
	
	u8g.firstPage();
	do {
		draw();
	} while( u8g.nextPage() );
	// delay(500);
	 img++;


}
