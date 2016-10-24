#include "Plik.h"
#include "Naglowki.h"


// =======================  DANE
Dane::Dane(){

}
void Dane::zaladuj(std::string i, int ktory)
{
	std::string nazwa = "dane/" + i + ".txt";

	std::fstream plik(nazwa);

	
	plik.close();


}