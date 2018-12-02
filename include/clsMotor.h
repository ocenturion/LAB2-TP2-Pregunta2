#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsFondo.h>

class clsMotor
{
    public:
        int init();
        int run();
        int keyCommand();
    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;
    private:
        clsFondo *fondo; //creo un objeto nuevo de la clase llamada
        bool salir=false;

};

#endif // CLSMOTOR_H
