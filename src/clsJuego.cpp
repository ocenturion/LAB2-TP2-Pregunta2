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
    error.set(texto.init());
    if(error.get())return error.get();

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
                if (event->getKey())
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
    cout<<"ingreso al clsJuego::keyCommand"<<endl;
    error.set(0);

    error.set(texto.loadFont("FONTS/FreeMono.ttf",30));
    if(error.get())return error.get();
    texto.setFontColor(RED);
    texto.write("hola como va?",10,10,screen->getPtr());
    screen->refresh();

    cout<<"-pase el testo"<<endl;
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
