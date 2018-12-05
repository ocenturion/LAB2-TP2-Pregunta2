#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsText.h>
class clsJuego
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
};

#endif // CLSJUEGO_H
