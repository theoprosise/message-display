#ifndef _BitmapDisplay_H_
#define _BitmapDisplay_H_

#include "messageMain.ino"

class BitmapDisplay
{
  private:
    GxEPD2_GFX& display;
  public:
    BitmapDisplay(GxEPD2_GFX& _display) : display(_display) {};
    void drawBitmaps();
  private:
    void drawBitmaps200x200();
    void drawBitmaps104x212();
    void drawBitmaps128x250();
    void drawBitmaps128x296();
    void drawBitmaps152x296();
    void drawBitmaps176x264();
    void drawBitmaps240x416();
    void drawBitmaps400x300();
    void drawBitmaps640x384();
    void drawBitmaps800x480();
    void drawBitmaps800x600();
    void drawBitmaps3c200x200();
    void drawBitmaps3c104x212();
    void drawBitmaps3c128x296();
    void drawBitmaps3c176x264();
    void drawBitmaps3c400x300();
    void drawBitmaps3c800x480();
};

#endif