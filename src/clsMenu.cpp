#include "clsMenu.h"
struct ranking
{
    int id;
    char nombre[10];
    int puntaje;
};
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
    error.set(texto.init());
    if(error.get())
        return error.get();
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
        volveralMenu=false;
        ingresoJuego=false;
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
        //ingreso al ranking.
        fondo.setI(7);
        fondo.paste(screen->getPtr());
        ranquin();
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
        *salir=true;
    }
    break;
    }
    return error.get();
    cout<<"-salgo del clsMenu::keyCommand"<<endl;
}
int clsMenu::ranquin()
{
    error.set(0);
    ranking ranki;
    int i=1,posY=110,vueltas=0;;
    char inttochar[3],cadenaPuntaje[3];
    FILE *archivo;
    archivo=fopen("./RANKING.DAT","rb");
    error.set(texto.loadFont("FONTS/FreeSans.ttf",30));
    if(error.get())
        return error.get();

    if (archivo !=NULL)
    {
        while(fread(&ranki,sizeof(ranking),1,archivo)==1)
        {
            cout<<"----------------------------------"<<endl;
            cout<<"ranki.puntaje: "<<ranki.puntaje<<endl;
//            for(int a=0; a<4; a++)
//            {
//                inttochar[a]='\0';
//                cadenaPuntaje[a]='\0';
//            }
            intToStr(ranki.puntaje,inttochar);
            while (inttochar[vueltas]!='\0')
            {
                cadenaPuntaje[vueltas]=inttochar[vueltas];
                vueltas++;
            }
            cadenaPuntaje[vueltas]='\0';
            cout<<"pasado a char: "<<inttochar<<endl;
            cout<<"-puesto"<<i<<": "<<ranki.nombre<<endl;
            texto.write(ranki.nombre,40,posY,screen->getPtr());
            texto.write(cadenaPuntaje,250,posY,screen->getPtr());
            i++;
            posY=posY+30;
//            vueltas=0;
            cout<<"----------------------------------\n\n"<<endl;
        }
    }
    fclose(archivo);
    return error.get();
}
void clsMenu::intToStr(int nroConvertir, char *cDestino)
{
    cout<<"puntaje a convertir: "<<nroConvertir<<endl;
    int d=1,resto=0,cociente=0;
    int aux=nroConvertir;
    while (aux>=10)
    {
        aux=aux/10;
        d=d*10;

    }

    resto = nroConvertir;
    int i = 0;
    cDestino[3];
    while(resto!=0)
    {
        cociente = 0;
        cociente = resto / d;
        resto = nroConvertir % d;
        d=d/10;
        cDestino[i] = (cociente + '0');
        i++;
    }
    cDestino[i]='\0';
    cout<<"ahora es char: "<<cDestino<<endl;
}
