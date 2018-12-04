#include "clsMotor.h"
int clsMotor::init()
{
    cout<<"ingreso al init"<<endl;
    error.set(0);
    error.set(mode.init(350,600,32));
    if(error.get())return error.get();
    error.set(screen.init(350,600,32,ENABLED,RESIZABLE));
    if(error.get()) return error.get();

    error.set(presentacion.iniciar(&screen,&event));
    if(error.get()) return error.get();

    error.set(menu.iniciar(&screen,&event));
    if(error.get()) return error.get();

    error.set(juego.iniciar(&screen,&event));
    if(error.get()) return error.get();

    error.set(despedida.iniciar(&screen,&event));
    if(error.get()) return error.get();

    return error.get();
}

int clsMotor::run()
{
    error.set(0);


    cout<<"ingreso al run"<<endl;

    error.set(presentacion.run());
    if(error.get()) return error.get();

    error.set(menu.run());
    if(error.get()) return error.get();
    if (menu.ingresoJuego)
        {
            error.set(juego.run());
            if(error.get()) return error.get();
        }
    error.set(despedida.run());
    if(error.get()) return error.get();
    return error.get();

    cout<<"salgo del run"<<endl;
}

