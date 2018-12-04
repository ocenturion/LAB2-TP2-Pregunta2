#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>

class clsFondo : public clsSprite
{
public:
    int Iniciar();
    void setPresentacion();
    void setDespedida();
    void setMenu();
protected:
    void inherit() {};
private:
};

#endif // CLSFONDO_H
