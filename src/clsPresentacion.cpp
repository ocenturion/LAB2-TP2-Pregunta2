#include "clsPresentacion.h"

int clsPresentacion::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);

    cout<<"ingrese a clspresentacion::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())
        return error.get();
    fondo.setPresentacion();
    return error.get();
}

int clsPresentacion::run()
{
    error.set(0);

    cout<<"ingrese a clspresentacion::run"<<endl;
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
int clsPresentacion::keyCommand(bool*salir,Uint16 key)
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
