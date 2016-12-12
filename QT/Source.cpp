
#include "Siec.h"
#include "Naglowki.h"


int main()
{
	srand(time(NULL));
	


	std::cout << "Poczatek" << std::endl;

	int ileWarstw = 4;
	int * ileNeuronow = new int[ileWarstw];
	ileNeuronow[0] = 10;
	ileNeuronow[1] = 3;
	ileNeuronow[2] = 3;
	ileNeuronow[3] = 1;
	//ileNeuronow[4] = 1;
	Siec siec(ileWarstw, ileNeuronow);



	//siec.dodajWszystkie(ileWarstw, ileNeuronow);

	//siec.wypiszDane(ileWarstw, ileNeuronow);

	//siec.wczytajWagi(ileWarstw, ileNeuronow);


	std::cout << std::endl;
	int liczbaEpok = 30;
	int ileDanych = 5000;
	int ktoryWygral = 0;
	double sumaDelta = 0.0;
	for (int j = 0; j < liczbaEpok; j++)
	{
		sumaDelta = 0.0;
		for (int i = 0; i < ileDanych; i++)
		{
			//if (j % 2 == 0)
			//{
			//	ktoryWygral = 1;
			//}
			//else
			//{
			//	ktoryWygral = 0;
			//}
			//if (i == 0)
			//{
			//	//std::cout << j << std::endl;
			//}
			std::string nazwa = std::to_string(i);
			siec.zaladuj(nazwa, ktoryWygral, ileNeuronow[0], ileWarstw, ileNeuronow[ileWarstw - 1]);

			siec.wstecznaPropagacja(ileWarstw, ileNeuronow, sumaDelta);
			//siec.zapiszWagi(ileWarstw, ileNeuronow);

		}
		//siec.wypiszDane(ileWarstw, ileNeuronow);
		//std::cout << "Delta: " << sumaDelta << std::endl;
	}

	ktoryWygral = 1;
	//siec.wypiszDane(ileWarstw, ileNeuronow);


	std::string nazwa = std::to_string(0);
	siec.zaladuj(nazwa, ktoryWygral, ileNeuronow[0], ileWarstw, ileNeuronow[ileWarstw - 1]);

	siec.dodajWszystkie(ileWarstw, ileNeuronow);
	
	std::cout << " Oczekiwana ->> " << siec.warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc<< "         Wynik ->> " << siec.warstwy[ileWarstw - 1].neurony[0].x << std::endl;

	ktoryWygral = 0;
	//siec.wypiszDane(ileWarstw, ileNeuronow);


	nazwa = std::to_string(0);
	siec.zaladuj(nazwa, ktoryWygral, ileNeuronow[0], ileWarstw, ileNeuronow[ileWarstw - 1]);

	siec.dodajWszystkie(ileWarstw, ileNeuronow);
	
	std::cout << " Oczekiwana ->> " << siec.warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc << "         Wynik ->> " << siec.warstwy[ileWarstw - 1].neurony[0].x << std::endl;

	system("pause");
	//return a.exec();
	return 0;
}

