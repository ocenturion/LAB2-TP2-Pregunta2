#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>

class clsMotor
{
    public:
        int init();
        int run();
        int keyCommand(bool*,Uint16);
    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;
    private:
};

#endif // CLSMOTOR_H
