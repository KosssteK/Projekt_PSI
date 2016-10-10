#include "qt.h"
#include "Siec.h"
#include "Naglowki.h"
#include "Plik.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	QApplication a(argc, argv);
	QT w;
	w.show();


	std::cout << "Poczatek" << std::endl;

	int ileWarstw = 4;
	int * ileNeuronow = new int[ileWarstw];
	ileNeuronow[0] = 10;
	ileNeuronow[1] = 2;
	ileNeuronow[2] = 2;
	ileNeuronow[3] = 1;

	Siec siec(ileWarstw, ileNeuronow);
	

	
	//siec.dodajWszystkie(ileWarstw, ileNeuronow);
	


	siec.wczytajWagi(ileWarstw, ileNeuronow);

	
	std::cout << std::endl;
	int liczbaEpok = 3;
	int ileDanych = 2;
	int ktoryWygral = 1;
	
	for (int i = 0; i < liczbaEpok; i++)
	{
		for (int i = 0; i < ileDanych; i++)
		{
			std::string nazwa = std::to_string(i);
			siec.zaladuj(nazwa, ktoryWygral, ileNeuronow[0], ileWarstw, ileNeuronow[ileWarstw - 1]);

			siec.wstecznaPropagacja(ileWarstw, ileNeuronow);
			siec.zapiszWagi(ileWarstw, ileNeuronow);
		}
	}


	siec.wypiszDane(ileWarstw, ileNeuronow);



	return a.exec();
}
