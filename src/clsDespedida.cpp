#include "clsDespedida.h"

int clsDespedida::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);
    cout<<"ingrese a clsdespedida::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())
        return error.get();
    fondo.setDespedida();
    return error.get();
}
int clsDespedida::run()
{
    cout<<"ingrese a clsdespedida::run"<<endl;
    error.set(0);
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
                if (event->getKey()==KEY_ESCAPE)
                {
                    keyCommand(&salir,event->getKey());
                    salir=true;
                }
            }
            break;
            }
        }
    }
    return error.get();
}
int clsDespedida::keyCommand(bool*salir,Uint16 key)
{
    cout<<"ingreso al clsdespedida::keyCommand"<<endl;
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:
    {
        *salir=true;
    }
    break;
    }
    return error.get();
}
