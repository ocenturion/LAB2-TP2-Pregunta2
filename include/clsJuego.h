#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsText.h>

class clsJuego
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsFondo fondo;
        clsText texto;
    public:
        int iniciar(clsScreen*,clsEvent*);
        int run();
        int keyCommand(bool*,Uint16, int,int,bool*);
        int listarPreguntas(int i,int puntaje);
        int gane(int);
        int perdi(int);
        void intToStr(int nroConvertir,char *inttochar);
        int winner(int puntaje);
        int ranquin();
};

#endif // CLSJUEGO_H
