
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Diccionario.h"

Diccionario::Diccionario( std::string ruta ): hojas( this->espacio ) {


    std::ifstream fe;
    std::string linea;


    fe.open( ruta );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                Palabra p ( linea );
                this->hojas.push_back( p );
            }
        }

        std::sort( this->hojas.begin(), this->hojas.end() );

        fe.close();



    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
}


Diccionario::Diccionario(const Diccionario &orig) : hojas ( orig.hojas ) {}


//BUSCA
long int Diccionario::busca ( const std::string &termino ) {

    Palabra p(termino);

    bool flag = true;

    long int pos, pos0 = 0, pos1 = this->hojas.size() - 1;

    while (flag) {

        pos = (pos0 + pos1) / 2;

        if (p == this->hojas[pos])
            return pos;

        else {

            if ((pos1 - pos0) <= 0)
                flag = false;

            else {

                if (p < this->hojas[pos]) {

                    pos1 = pos - 1;

                } else {

                    pos0 = pos + 1;
                }
            }
        }
    }
    return -1;
}



void Diccionario::insertar(std::string &termino) {


    Palabra p ( termino );


    if ( this->busca ( termino ) == -1 ) {
        this->hojas.push_back( p );

        if ( p < this->hojas [ this->hojas.size() - 2] )
            std::sort( this->hojas.begin(), this->hojas.end() );
    }

}


void Diccionario::entrena ( const std::string& frase ) {

    std::string palabra, predecesor = "";
    std::stringstream ss;
    long int pos = 0;
    ss << frase;	//enviamos la cadena al stream
    while (!ss.eof()) {
        ss >> palabra;	//leemos la siguiente palabra
        if (palabra!="") {

            pos = this->busca( palabra );
            if (  pos == -1 ) {
                Palabra termino ( palabra );
                this->hojas.push_back( termino );
                std::sort( this->hojas.begin(), this->hojas.end() );
                pos = this->busca(palabra);
            }
            if ( predecesor != "") {
                this->hojas[pos].nuevoSucesor( predecesor );
            }
        }
        predecesor = palabra;
    }

}

void Diccionario::usacorpus ( const std::string &nom_fich_corpus ) {

    std::ifstream fe;
    std::string linea;

    fe.open( nom_fich_corpus );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                this->entrena( linea );
            }
        }

        fe.close();

    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
    std::cout << "Fin de corpus" <<std::endl;

}

std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    auto pos = this->busca( p );

    if ( pos != -1 )
        return this->hojas [pos].sucesores();
    else
        throw std::string ( "La palabra no tiene sucesores porque no está en el diccionario" );
}


Diccionario::~Diccionario() {}