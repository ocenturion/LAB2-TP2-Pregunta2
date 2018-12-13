#ifndef CLSMENU_H
#define CLSMENU_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsText.h>
#include <clsPresentacion.h>
class clsMenu
{
      protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsFondo fondo;
        clsText texto;
    public:
        int iniciar(clsScreen*,clsEvent*);
        int run();
        int keyCommand(bool*,Uint16);
        bool ingresoJuego=false;
        bool volveralMenu=true;
        void intToStr(int nroConvertir,char *inttochar);
        int ranquin();
};

#endif // CLSMENU_H
