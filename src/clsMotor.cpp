#include "clsMotor.h"

int clsMotor::init()
{
    error.set(0);
    error.set(mode.init(DEFAULT));
    if(error.get()) return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE
                          ));
    if(error.get()) return error.get();
    return error.get();
}
int clsMotor::run()
{
    error.set(0);
    bool salir=false;
    screen.clean(BLUE);
    screen.refresh();
    while (!salir)
    {
        if (event.wasEvent())
        {
            if (event.getEventType()==KEY_PRESSED)
            {
                error.set(keyCommand(&salir,event.getKey()));
                if(error.get()) return error.get();
            }
        }
    }
    return error.get();
}
int clsMotor::keyCommand(bool*salir,Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:
        {
            *salir=true;
        }break;
    }
    return error.get();
}
