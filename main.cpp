#include <iostream>
#include "Diccionario.h"

int main() {




    Diccionario d ( "/home/anonymous/Documents/eedd_practice/pr4_eedd/listado-sin-acentos_v2.txt");

   d.usacorpus( "/home/anonymous/Documents/eedd_practice/pr4_eedd/corpus_spanish.txt");

    std::string frase;
    std::string palabra = "el";

    std::getline (std::cin,frase);



    d.entrena( frase );

    ListaEnlazada < std::string > l = d.sacaSucesoresDe( palabra );
    ListaEnlazada < std::string >::Iterador it = l.iterador();

    while ( !it.fin() ) {
        std::cout << it.dato() << std::endl;
        it.siguiente();
    }

    return 0;
}