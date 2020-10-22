#include "trideni.h"

void nacti(std::string nazev, seznam_slov & jmena){

}

void insertion_sort(int array[], int size) {

	for (int i = 0; i < size - 1; i++) {
		int j = i + 1;
		int tmp = array[j];
		while (j > 0 && tmp > array[j-1]) {
		array[j] = array[j-1];
		j--;
	}

	array[j] = tmp;

	}

}

void vypis()....