#include <TFT_eSPI.h>
#include "mario.h"
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int size=11;
int frame=0;

int bA=18;
int bB=21;
int bC=22;
int bD=23;
int red, blue=0;

unsigned short colBlue[7]={TFT_BLUE,TFT_RED,TFT_GREEN,TFT_PURPLE,TFT_YELLOW,TFT_PINK,TFT_BLACK};
unsigned short colRed[7]={0xF800,TFT_BLUE,TFT_GREEN,TFT_PURPLE,TFT_YELLOW,TFT_PINK,TFT_BLACK};

void setup() {
  pinMode(bA,INPUT_PULLUP);
  pinMode(bB,INPUT_PULLUP);
  pinMode(bC,INPUT_PULLUP);
  pinMode(bD,INPUT_PULLUP);

  tft.init();
  tft. fillScreen(TFT_WHITE);
  sprite.createSprite(230,230);
}

void drawSprite(){
  sprite.fillSprite(TFT_WHITE);
   int pok=0;
 for(int i=0;i<21;i++)
 for(int j=0;j<21;j++)
 { 
       
if(mario[frame][pok]==TFT_RED)
  sprite.fillRect(j*size,i*size,size,size,colRed[red]);
 else if(mario[frame][pok]==0x13F) 
  sprite.fillRect(j*size,i*size,size,size,colBlue[blue]);  
   else
  sprite.fillRect(j*size,i*size,size,size,mario[frame][pok]);
  pok++;
 }
  sprite.pushSprite(10,10);
}

void loop() {
  drawSprite();

  red=map(analogRead(25),0,4065,0,7);
  blue=map(analogRead(33),0,4065,0,7);
  size=map(analogRead(26),0,4065,1,12);
 
  if(digitalRead(bA)==0)
  frame=1;

  if(digitalRead(bB)==0)
  frame=2;

  if(digitalRead(bC)==0)
  frame=3;

  if(digitalRead(bD)==0)
  frame=4;
}
