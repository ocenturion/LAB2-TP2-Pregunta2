#include "clsJuego.h"

const char * const FILE_PREG_RESP[]= {"./PREGyRESP.DAT"};
const char * const FILE_RANKING[]= {"./RANKING.DAT"};
struct pregyresp
{
    int id;
    char preg[100];
    char respA[50];
    char respB[50];
    char respC[50];
    char respD[50];
    char respCorrecta[2];
};
struct ranking
{
    int id;
    char nombre[10];
    int puntaje;
};
int clsJuego::iniciar(clsScreen*scr,clsEvent* ev)
{
    error.set(0);

    cout<<"ingrese a clsJuego::iniciar"<<endl;
    this->screen=scr;
    this->event=ev;
    error.set(fondo.Iniciar());
    if(error.get())
        return error.get();
    fondo.setJuego();
    error.set(texto.init());
    if(error.get())
        return error.get();
    random.init();

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    cout<<"ingrese a clsJuego::run"<<endl;
    screen->clean(BLUE);
    fondo.paste(screen->getPtr());
    screen->refresh();
    bool salir=false;
    int i=0,a,devuelve,puntaje=0;
    while (!salir)
    {
        if (event->wasEvent() && !salir)
        {
            fondo.paste(screen->getPtr());
            devuelve=listarPreguntas(i,puntaje);
            screen->refresh();
            switch (event->getEventType())
            {
            case KEY_PRESSED:
            {
                cout<<"aprete: "<<event->getKey()<<endl;
                if (event->getKey())
                {

                    if(keyCommand(&salir,event->getKey(),devuelve,puntaje)==1)
                    {
                        puntaje++;
                    }
                    i++;
                    cout<<"proximo numero random: "<<i<<endl;
                }
            }
            break;
            default:
            {
                cout<<"----------------------------no aprete ninguna tecla!"<<endl;
            }
            break;
            }
        }
        if (i==19)
        {
            //eres el campeon! termina el juego y te pide agregar tu nombre para el ranking
            salir=true;
            winner(puntaje);
        }
    }
    cout<<"-Esto seria lo ganado: "<<puntaje<<endl;
    return error.get();
}

int clsJuego::keyCommand(bool*salir,Uint16 key, int devuelve,int puntaje)
{
    cout<<"ingreso al clsJuego::keyCommand"<<endl;
    error.set(0);

    bool gano=false;
    switch(key)
    {
    case KEY_A:
    case KEY_a:
    {
        cout<<"precione a : "<<KEY_a+0<<endl;
        if (devuelve== 97)
        {
            cout<<"**********GANE!!**********"<<endl;
            gano=true;
            if (gane(puntaje)==1)
            {
                *salir=true;
            }
        }
        else
        {
            cout<<"opcion incorrecta, perdiste!!"<<endl;
            if (perdi(puntaje)==1)
            {
                *salir=true;
            }
        }
    }
    break;
    case KEY_B:
    case KEY_b:
    {
        cout<<"precione b : "<<KEY_b+0<<endl;
        if (devuelve== 98)
        {
            cout<<"**********GANE!!**********"<<endl;
            gano=true;
            if (gane(puntaje)==1)
            {
                *salir=true;
            }
        }
        else
        {
            cout<<"opcion incorrecta, perdiste!!"<<endl;
            if (perdi(puntaje)==1)
            {
                *salir=true;
            }
        }
    }
    break;
    case KEY_C:
    case KEY_c:
    {
        cout<<"precione c : "<<KEY_c+0<<endl;
        if (devuelve== 99)
        {
            cout<<"**********GANE!!**********"<<endl;
            gano=true;
            if (gane(puntaje)==1)
            {
                *salir=true;
            }
        }
        else
        {
            cout<<"opcion incorrecta, perdiste!!"<<endl;
            if (perdi(puntaje)==1)
            {
                *salir=true;
            }
        }
    }
    break;
    case KEY_D:
    case KEY_d:
    {
        cout<<"precione d : "<<KEY_d+0<<endl;
        if (devuelve== 100)
        {
            cout<<"**********GANE!!**********"<<endl;
            gano=true;
            if (gane(puntaje)==1)
            {
                *salir=true;
            }
        }
        else
        {
            cout<<"opcion incorrecta, perdiste!!"<<endl;
            if (perdi(puntaje)==1)
            {
                *salir=true;
            }
        }
    }
    break;
    }
    return gano;

    if(error.get())
        return error.get();
}

int clsJuego::listarPreguntas(int i,int puntaje)
{
    pregyresp preg;
    char pregParte1[50],pregParte2[50];
    char inttochar[3];
    FILE *archivo;
    archivo = fopen("./PREGyRESP.DAT","rb");
    error.set(texto.loadFont("FONTS/FreeSans.ttf",15));
    if(error.get())
    {
        return error.get();
    }
    int num;
    if(archivo!=NULL)
    {
        while(fread(&preg,sizeof(pregyresp),1,archivo)==1)
        {
            if(preg.id==i)
            {
                texto.write("PUNTAJE: ",25,25,screen->getPtr());
                if(puntaje==10)
                {
                    texto.write("10",100,25,screen->getPtr());
                }
                else if (puntaje==0)
                {
                    texto.write("0",100,25,screen->getPtr());
                }
                else
                {
                    intToStr(puntaje,inttochar);
                    texto.write(inttochar,100,25,screen->getPtr());
                }
                cout << " _______inicio pregunta_____________" << endl;
                cout<<" _ID: "<<preg.id<<endl;
                cout<<" _pregunta   : "<<preg.preg<<endl;
                texto.write(preg.preg,15,170,screen->getPtr());
                cout<<" _respuesta-a: "<<preg.respA<<endl;
                texto.write(preg.respA,30,345,screen->getPtr());
                cout<<" _respuesta-b: "<<preg.respB<<endl;
                texto.write(preg.respB,30,405,screen->getPtr());
                cout<<" _respuesta-c: "<<preg.respC<<endl;
                texto.write(preg.respC,30,465,screen->getPtr());
                cout<<" _respuesta-d: "<<preg.respD<<endl;
                texto.write(preg.respD,30,525,screen->getPtr());
                cout<<" _respuesta correcta: "<<preg.respCorrecta[0]+0<<endl;
                num=preg.respCorrecta[0]+0;
                cout << " _______fin pregunta________________" << endl;
            }
        }

        fclose(archivo);
    }
    return num;
}

void clsJuego::intToStr(int nroConvertir, char *cDestino)
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


int clsJuego::gane(int puntaje)
{
    error.set(0);
    fondo.setI(3);
    fondo.paste(screen->getPtr());
    screen->refresh();

    bool salirGanaste=false,salir=false;
    while(!salirGanaste)
    {
        if (event->wasEvent())
        {
            if(event->getEventType()==KEY_PRESSED)
            {
                if(event->getKey()==KEY_r || event->getKey()==KEY_R)
                {
                    salirGanaste=true;
                    salir=true;
                    winner(puntaje);
                }
                else if(event->getKey()==KEY_s || event->getKey()==KEY_S)
                {
                    fondo.setJuego();
                    salirGanaste=true;
                    salir=false;
                }
            }
        }
    }
    return salir;
    if(error.get())
        return error.get();
}
int clsJuego::perdi(int puntaje)
{
    error.set(0);
    fondo.setI(8);
    fondo.paste(screen->getPtr());
    screen->refresh();
    bool salirGanaste=false,salir=false;
    while(!salirGanaste)
    {
        if (event->wasEvent())
        {
            if(event->getEventType()==KEY_PRESSED)
            {
                if(event->getKey()==KEY_r || event->getKey()==KEY_R)
                {
                    salirGanaste=true;
                    salir=true;
                    winner(puntaje);
                }
                else if(event->getKey()==KEY_s || event->getKey()==KEY_S)
                {
                    fondo.setJuego();
                    salirGanaste=true;
                }
            }
        }
    }
    return salir;
    if(error.get())
        return error.get();
}
int clsJuego::winner(int puntaje)
{
    error.set(0);

    ranking ranki;
    char nvoNombre[10],nombre[10];

    int i=0,x=30,a=0;
    bool salir=false,Esc=false;
    FILE *archivo;
    archivo=fopen("./RANKING.DAT","rb+");
    error.set(texto.loadFont("FONTS/FreeSans.ttf",30));
    if(error.get())return error.get();
    if(archivo!=NULL)
    {
        while(fread(&ranki,sizeof(ranking),1,archivo)==1 && !salir)
        {
            if (puntaje>=ranki.puntaje)
            {
                fondo.setI(9);
                fondo.paste(screen->getPtr());
                screen->refresh();
                while(!Esc)
                {
                    if(event->wasEvent())
                    {
                        switch (event->getEventType())
                        {
                        case KEY_PRESSED:
                        {
                            cout<<"aprete: "<<event->getKey()<<endl;
                            if (event->getKey()==KEY_ESCAPE)
                            {
                                Esc=true;
                                salir=true;
                            }else if(event->getKey()==KEY_ENTER)
                            {
                                ranki.puntaje=puntaje;
                                fseek(archivo,sizeof(ranking)*(-1),1);
                                fwrite(&ranki,sizeof(ranking),1,archivo);
                                salir=true;
                                Esc=true;
//                            }else if(event->getKey()==KEY_BACKSPACE)
//                            {
//                                i--;
//                                nvoNombre[i];
                            }else
                            {
                                x=x+15;
                                nvoNombre[i]=event->getKey();
                                texto.write(nvoNombre,x,413,screen->getPtr());
                                screen->refresh();
                                cout<<"nvoNombre: "<<nvoNombre<<endl;
                            }
                        }
                        break;
                        default:
                        {
                            cout<<"----------------------------no aprete ninguna tecla!"<<endl;
                        }
                        break;
                        }
                    }
                }
            }
        }
        cout<<"nvoNombre: "<<nvoNombre<<endl;
        cout<<"id: "<<ranki.id<<endl;
        cout<<"nombre: "<<ranki.nombre<<endl;
        cout<<"puntaje: "<<ranki.puntaje<<endl;
    fclose(archivo);
}
return error.get();
}
//hacer otra funcion para mostrar los ganadores
