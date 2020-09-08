#ifndef REDEHEADERDEF
#define REDEHEADERDEF

#include "Matriz.h++"
#include "Vector.h++"

class Rede {
    private:

    public:

    Rede addCamadaOculta() const;
    Rede addDropout(double porcentagem=0.2) const;
};

#endif