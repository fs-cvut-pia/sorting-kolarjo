#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

#include "trideni.h"



void nacti(std::string nazev, seznam_slov & jmena){
   std::ifstream vstupni_soubor;
   vstupni_soubor.open(nazev.c_str());

   std::string radek;

   while (std::getline(vstupni_soubor,radek)){
    jmena.push_back(radek);
   }
   vstupni_soubor.close();
}

void serad(seznam_slov & jmena){
    std::string tmp;
    bool bylo_prohozeno;

    do {
        bylo_prohozeno = false;
        for (int i = 0; i < jmena.size(); ++i)
        {
           if (jmena[i].compare(jmena[i-1]) < 0){
              tmp = jmena[i];
              jmena[i] = jmena[i-1];
              jmena[i-1] = tmp;
              bylo_prohozeno=true;  
           }
        }
    }
    while(bylo_prohozeno);
}

void vypis(seznam_slov const& jmena){
    for (int i = 0; i < jmena.size(); ++i)
    {
      std::cout << jmena[i] << std::endl;
    }
}

bool zeptej_se_jestli_vypsat(){
   char vypsat;
   while (true) {
    std::cout << "Chces to vypsat serazeny (A/N)???? " << std::endl;
    std::cin >> vypsat;
    if (vypsat == 'A' || vypsat == 'a') return true;
    else if (vypsat == 'N' || vypsat == 'n') return false;
    else std::cout << "Kolego, vyber si A nebo N a nevymýšlej ";
   }
}

