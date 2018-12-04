#include "clsMenu.h"

int clsMenu::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);
    cout<<"ingrese a clsMenu::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())
        return error.get();
    fondo.setMenu();
    return error.get();
}
int clsMenu::run()
{
    cout<<"ingrese a clsMenu::run"<<endl;
    error.set(0);
    bool salir=false;
    screen->clean(BLUE);
    fondo.paste(screen->getPtr());
    screen->refresh();
    while (!salir)
    {
        if (event->wasEvent())
        {
            if(event->getEventType()==KEY_PRESSED)
            {
                keyCommand(&salir,event->getKey());
            }
        }
    }
    return error.get();
}
int clsMenu::keyCommand(bool*salir,Uint16 key)
{
    cout<<"ingreso al clsMenu::keyCommand"<<endl;
    error.set(0);
    switch(key)
    {
    case KEY_j:
    case KEY_J:
    {
        *salir=true;
//        error.set(presentacion.iniciar(&screen,&event));
//        if(error.get()) return error.get();
    }
    break;
    case KEY_a:
    case KEY_A:
    {
        fondo.setI(3);
        fondo.paste(screen->getPtr());
        screen->refresh();
        bool salir2=false;
        while (!salir2)
        {
            if (event->wasEvent())
            {
                if(event->getEventType()==KEY_PRESSED)
                {
                    if(event->getKey()==KEY_s || event->getKey()==KEY_S)
                    {
                        fondo.setI(1);
                        fondo.paste(screen->getPtr());
                        screen->refresh();
                        salir2=true;
                    }
                }
            }
        }
    }
    break;
    }
    return error.get();
}

