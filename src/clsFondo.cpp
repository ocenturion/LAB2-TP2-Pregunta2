#include "clsFondo.h"

int clsFondo::Iniciar()
{
    error.set(0); // seteo el error

    setItems(10);// verificar siempre la cantidad de imagenes
    setI(0);
    error.set(load("recursos/pantallas/Fondos/1.png"));
    if (error.get())return error.get();
    setI(1);
    error.set(load("recursos/pantallas/Fondos/2.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(2);
    error.set(load("recursos/pantallas/Fondos/3.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(3);
    error.set(load("recursos/pantallas/Fondos/4.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(4);
    error.set(load("recursos/pantallas/Fondos/5.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(5);
    error.set(load("recursos/pantallas/Fondos/6.jpeg"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(6);
    error.set(load("recursos/pantallas/Fondos/7.png"));//ayuda
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(7);
    error.set(load("recursos/pantallas/Fondos/8.png"));//ranking
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(8);
    error.set(load("recursos/pantallas/Fondos/9.png"));//ranking
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(9);
    error.set(load("recursos/pantallas/Fondos/10.png"));//ranking
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setX(0); //eje x desde donde se cargan las imagenes
    setY(0); //eje y desde donde se cargan las imagenes

    return error.get();
}
void clsFondo::setPresentacion()
{
    setI(0);
}
void clsFondo::setMenu()
{
    setI(1);
}
void clsFondo::setJuego()
{
    setI(2);
}
void clsFondo::setDespedida()
{
    setI(5);
}
