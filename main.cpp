#include <iostream>
#include "Diccionario.h"

int main() {



    try {

        Diccionario d("/home/anonymous/Documents/eedd_practice/pr4_eedd/listado-sin-acentos_v2.txt");

        //d.usacorpus("/home/anonymous/Documents/eedd_practice/pr4_eedd/corpus_spanish.txt");

        std::string frase;
        std::string palabra = "el";

        std::getline(std::cin, frase);


        d.entrena(frase);

        std::list<std::string> l = d.sacaSucesoresDe(palabra);
        std::list<std::string>::iterator it = l.begin();

        while (it != l.end()) {
            std::cout << *it << std::endl;
            ++it;
        }

    }catch ( std::string &e){
    std::cerr << e << std::endl;
}

    return 0;
}