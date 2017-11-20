
#include "Palabra.h"

Palabra::Palabra () : termino ( "" ), siguientes () {}

Palabra::Palabra ( const std::string &t ) : termino ( t ), siguientes () {}

Palabra::Palabra ( const Palabra &orig ) : termino ( orig.termino ), siguientes ( orig.siguientes ) {}

//OPERATOR ==
bool Palabra::operator == ( const Palabra &orig ) {

    if ( this->termino == orig.termino )
        return true;

    return false;
}

bool Palabra::operator < ( const Palabra &orig ) {

    if ( this->termino < orig.termino )
        return true;

    return false;
}

std::string Palabra::getPalabra () {
    return this->termino;
}

void Palabra::nuevoSucesor( const std::string& termino ) {

    bool encontrado = false;
    std::list < Sucesor >::iterator it = this->siguientes.begin();

    while ( (it != this->siguientes.end()) && !encontrado  ) {

        if ( (*it).getTermino() == termino ) {

            (*it).incrementar();
            encontrado = true;
        }

        ++it;
    }

    if ( !encontrado ) {
        Sucesor s ( termino );
        this->siguientes.push_back ( s );
    }
}

std::list < std::string > Palabra::sucesores() {

    std::list < std::string > lstr;

    std::list < Sucesor >::iterator it = this->siguientes.begin();

    while ( it != this->siguientes.end() ){
        lstr.push_back( (*it).getTermino() );
        ++it;
    }

    return lstr;
}


Palabra::~Palabra() {}