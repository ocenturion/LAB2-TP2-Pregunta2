#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsText.h>
#include <clsRandom.h>
class clsJuego
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsFondo fondo;
        clsText texto;
        clsRandom random;
    public:
        int iniciar(clsScreen*,clsEvent*);
        int run();
        int keyCommand(bool*,Uint16, int,int);
        int listarPreguntas(int i,int puntaje);
        int gane(int);
        int perdi(int);
        void intToStr(int nroConvertir,char *inttochar);
        int winner(int puntaje);
};

#endif // CLSJUEGO_H
