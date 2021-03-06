#ifndef CLSDESPEDIDA_H
#define CLSDESPEDIDA_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>

class clsDespedida
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsFondo fondo;
    public:
        int iniciar(clsScreen*,clsEvent*);
        int run();
        int keyCommand(bool*,Uint16);
};

#endif // CLSDESPEDIDA_H
