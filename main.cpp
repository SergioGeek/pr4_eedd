#include <iostream>
#include "Diccionario.h"

int main() {



    try {

        Diccionario d("/home/anonymous/Documents/eedd_practice/pr4_eedd/listado-sin-acentos_v2.txt");

        d.usacorpus("/home/anonymous/Documents/eedd_practice/pr4_eedd/corpus_spanish.txt");

        std::string frase;
        std::string palabra;

        std::cout << "Introduzca una frase para entrenar: " << std::endl;
        std::getline(std::cin, frase);
        std::cout << "Introduzca la palabra de la que quiere saber sus sucesores: " << std::endl;
        std::cin >> palabra;

        d.entrena(frase);

        std::cout << "Lista de sucesores: " << std::endl;
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