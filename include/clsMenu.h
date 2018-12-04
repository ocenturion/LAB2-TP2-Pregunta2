#ifndef CLSMENU_H
#define CLSMENU_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>


#include <clsPresentacion.h>
class clsMenu
{
      protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsFondo fondo;
        clsPresentacion presentacion;
    public:
        int iniciar(clsScreen*,clsEvent*);
        int run();
        int keyCommand(bool*,Uint16);
};

#endif // CLSMENU_H
