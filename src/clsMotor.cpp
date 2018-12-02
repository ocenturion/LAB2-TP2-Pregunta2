#include "clsMotor.h"

int clsMotor::init()
{
    cout<<"ingreso al init"<<endl;
    error.set(0);
    error.set(mode.init(350,600,32));
    if(error.get())
        {
            mode.crashPrevent();
            error.show(true);
            return error.get();
        }

    error.set(screen.init(350,
                          600,
                          32,
                          ENABLED,
                          DISABLED
                          ));
    if(error.get()) {return error.get();}
    error.set(fondo->Iniciar(&screen));
    if(error.get()) {return error.get();}

    cout<<"salio del init"<<endl;
    return error.get();
}

int clsMotor::run()
{
    error.set(0);
    bool salir=false;
    screen.clean(BLUE);
    fondo->setI(0);
    fondo->paste(screen.getPtr());
    screen.refresh();
    while (!salir)
    {
        cout<<"ingreso al juego"<<endl;
        if (event.wasEvent())
        {
            switch (event.getEventType())
            {
            case KEY_PRESSED:
                {
                    if (event.getKey()==KEY_ENTER)
                    {
                        salir=true;
                    }
                }break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    return error.get();
}

int clsMotor::keyCommand()
{
    error.set(0);
    switch(event.getKey())
    {
    case KEY_ESCAPE:
        {
            salir=true;
        }break;
    }
    return error.get();
}
