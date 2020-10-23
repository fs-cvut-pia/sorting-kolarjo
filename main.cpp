#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <exception>
#include <vector>

#include "trideni.h"

// Nacteni prvniho argumentu z prikazove radky
// Promenna argc obsahuje pocet argumentu programu (vcetne samotneho nazvu programu)
// Pole argv obsahuje jednotlive argumenty z prikazove radky
std::string nazev_z_prikazove_radky(int argc, char* argv[]) {
    if (argc < 2)
    	 std::cout<<"Musite zadat nazev vstupniho souboru"; 

    return std::string(argv[1]);
}


int main(int argc, char* argv[]) {

    std::string nazev_vstupniho_souboru = nazev_z_prikazove_radky(argc,argv);
    
    seznam_slov jmena;


    nacti(nazev_vstupniho_souboru, jmena);

    std::cout << "Nacteno " << jmena.size() << " slov." << std::endl;
    std::cout << "Serazuji slova ... " << std::endl;

    // Zacatek mereni CPU casu
    clock_t start = clock();

    serad(jmena);
    // Konec mereni CPU casu
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Hotovo. Serazeni trvalo " << seconds << " sekundy." << std::endl;

  
    if (zeptej_se_jestli_vypsat()) {
      
      vypis(jmena); 
    }

    return 0;
}
