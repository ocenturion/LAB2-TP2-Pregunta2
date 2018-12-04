#include "clsFondo.h"

int clsFondo::Iniciar()
{
    error.set(0); // seteo el error

    setItems(4);
    setI(0);
    error.set(load("recursos/pantallas/Fondos/1.png"));
    if (error.get())return error.get();
    setI(1);
    error.set(load("recursos/pantallas/Fondos/2.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
//    setI(3);
//    error.set(load("recursos/pantallas/Fondos/3.png"));
//    cout<<"carga SpriteFondos "<<endl;
//    if (error.get())return error.get();
//    setI(4);
//    error.set(load("recursos/pantallas/Fondos/4.png"));
//    cout<<"carga SpriteFondos "<<endl;
//    if (error.get())return error.get();
//    setI(1);
//    error.set(load("recursos/pantallas/Fondos/5.png"));
//    cout<<"carga SpriteFondos "<<endl;
//    if (error.get())return error.get();
    setI(2);
    error.set(load("recursos/pantallas/Fondos/6.jpeg"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
    setI(3);
    error.set(load("recursos/pantallas/Fondos/7.png"));
    cout<<"carga SpriteFondos "<<endl;
    if (error.get())return error.get();
//    const char * const SpriteFondos[6]=
//{
//    "recursos/pantallas/Fondos/1.png",
//    "recursos/pantallas/Fondos/2.png",
//    "recursos/pantallas/Fondos/3.png",
//    "recursos/pantallas/Fondos/4.png",
//    "recursos/pantallas/Fondos/5.png",
//    "recursos/pantallas/Fondos/6.png" // faltan imagenes...
//};
//
//    setItems(6);
//    for(int i=0;i<6;i++)
//    {
//        setI(i);
//        error.set(load(SpriteFondos[i]));
//        cout<<"carga SpriteFondos "<<i<<endl;
//        if (error.get())return error.get();
//    }
    cout<<"estoy casi afuera"<<endl;
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
void clsFondo::setDespedida()
{
    setI(2);
}
