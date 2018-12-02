#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>
#include <clsScreen.h>

class clsFondo : public clsSprite
{
    public:
        int Iniciar(clsScreen *);
        void inherit(){};
    protected:
        clsScreen *pantalla;
    private:
};

#endif // CLSFONDO_H
