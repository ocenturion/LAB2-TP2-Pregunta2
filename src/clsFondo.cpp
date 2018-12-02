#include "clsFondo.h"

// creacion de vector constante para fondos
const char * const SpriteFondos[13]=
{
    "recursos/pantallas/Fondos/1.png",
    "recursos/pantallas/Fondos/2.png",
    "recursos/pantallas/Fondos/3.png",
    "recursos/pantallas/Fondos/4.png",
    "recursos/pantallas/Fondos/5.png",
    "recursos/pantallas/Fondos/6.png",
    "recursos/pantallas/Fondos/7.png",
    "recursos/pantallas/Fondos/8.png",
    "recursos/pantallas/Fondos/9.png",
    "recursos/pantallas/Fondos/10.png",
    "recursos/pantallas/Fondos/11.png",
    "recursos/pantallas/Fondos/12.png",
    "recursos/pantallas/Fondos/13.png"
};
clsFondo::Iniciar(clsScreen * pantalla)
{
    error.set(0); // seteo el error
    setItems(12);
    for(int i=0;i<13;i++)
    {
        setI(i);
        error.set(load(SpriteFondos[i]));
        cout<<"carga SpriteFondos "<<i<<endl;
        if (error.get()){return error.get();}
    }
    //setI(0); //posicion inicial de mis Sprite
    setX(0); //eje x desde donde se cargan las imagenes
    setY(0); //eje y desde donde se cargan las imagenes
}
