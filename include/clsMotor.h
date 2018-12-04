#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsPresentacion.h>
#include <clsDespedida.h>
#include <clsMenu.h>
class clsMotor
{
public:
    int init();
    int run();
    int keyCommand(bool*,Uint16);
protected:
    clsEvent event;
    clsError error;
    clsMode mode;
    clsScreen screen;
    clsPresentacion presentacion;
    clsMenu menu;
    clsDespedida despedida;
};

#endif // CLSMOTOR_H
