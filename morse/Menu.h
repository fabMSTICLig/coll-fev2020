#ifndef MENU_BOITE
#define MENU_BOITE

#include "WString.h"
#include <Bounce2.h>
#include <rgb_lcd.h>
#include "functionnalities.h"
#include "encoder.h"
#include "define.h"

typedef bool (*cbmenuopt_t)(int enc, bool but);
typedef void (*cbmenuaff_t)();

///***Class definition for LCD browse system ***///
class SubMenuItem
{
    public:
        bool autoRun = false;
        const char* name;
        cbmenuopt_t cbopt;
        cbmenuaff_t cbaff;
};

class MenuItem
{
    public:
        const char* name;
        SubMenuItem submenus[5];
        byte numItem=0;
};

class Menu
{
  public:
    MenuItem menuitems[5];
    byte numItem=0;
    void loop();
  private:
    byte layer1=0;
    bool layer1In=false;
    byte layer2=0;
    bool layer2In=false;
};
///*********************************************///

Menu setupmenu();

///*** Definition of "menu" used functions ***///
//Interacive functions
bool confDit(int enc, bool but);
bool conflettre(int enc, bool but);
bool inputButt(int enc, bool but);
bool inputLight(int enc, bool but);
bool readReceivedMessage(int enc, bool but);
bool sendInput(int enc, bool but);
bool sendErase(int enc, bool but);
bool sendLum(int enc, bool but);

//Printing functions
void confDitAff();
void conflettreAff();
void inputButtAff();
void inputLightAff();
void readReceivedMessageAff();
void sendInputAff();
void sendEraseAff();
void sendLumAff();
///*****************************************///

#endif
