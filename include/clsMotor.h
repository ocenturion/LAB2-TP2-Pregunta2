#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>

class clsMotor
{
    public:
        int init();//inicializa los objetos basicos
        int run();//ejecucion del programa
        int keyCommand(bool*,Uint16);
    protected:
        clsEvent event; //objeto evento
        clsError error; //objeto para el manejo de errores
        clsMode mode;   //objeto para modo grafico
        clsScreen screen; //objeto de pantalla
    private:
};

#endif // CLSMOTOR_H
