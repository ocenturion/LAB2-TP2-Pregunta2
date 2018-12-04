#include "clsMenu.h"

int clsMenu::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);
    cout<<"ingrese a clsMenu::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())return error.get();
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
    error.set(0); // seteo el error
    switch(key)
    {
    case KEY_s:
    case KEY_S:
    {
        *salir=true;
    }
    break;
    case KEY_a:
    case KEY_A:
    {
        fondo.setI(6);
        fondo.paste(screen->getPtr());
        screen->refresh();
        bool salirAyuda=false;
        while (!salirAyuda)
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
                        salirAyuda=true;
                    }
                }
            }
        }
    }
    break;
    case KEY_R:
    case KEY_r:
    {
        fondo.setI(7);
        fondo.paste(screen->getPtr());
        screen->refresh();
        bool salirRanking=false;
        while (!salirRanking)
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
                        salirRanking=true;
                    }
                }
            }
        }
    }
    break;
    case KEY_J:
    case KEY_j:
        {
             ingresoJuego=true;
        }
        break;
    }
    return error.get();
    cout<<"-salgo del clsMenu::keyCommand"<<endl;
}

