#include "clsJuego.h"

int clsJuego::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);

    cout<<"ingrese a clsJuego::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())return error.get();
    fondo.setJuego();

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    cout<<"ingrese a clsJuego::run"<<endl;
    bool salir=false;
    screen->clean(BLUE);
    fondo.paste(screen->getPtr());
    screen->refresh();
    while (!salir)
    {
        if (event->wasEvent())
        {
            switch (event->getEventType())
            {
            case KEY_PRESSED:
            {
                if (event->getKey()==KEY_ENTER)
                {
                    keyCommand(&salir,event->getKey());
                }
            }
            break;
            }
        }
    }
    return error.get();
}

int clsJuego::keyCommand(bool*salir,Uint16 key)
{
    cout<<"ingreso al keyCommand"<<endl;
    error.set(0);
    switch(key)
    {
    case KEY_ENTER:
    {
        *salir=true;
    }
    break;
    }
    return error.get();
}
