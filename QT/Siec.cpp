#include "Siec.h"
#include "Naglowki.h"
// =============================== NODE
Node::Node(){
	x = 1.0;
	waga = 0.0;
	oczekiwanaWartosc = 0.0;
	delta = 0.0;
};

double  Node::sumuj()
{
	double wynik = 0;
	return wynik;
}
// =============================== LAYER
Layer::Layer(){};
void Layer::stworzNeuron(int ileNeuronow)
{
	neurony = new Node[ileNeuronow];
	for (int i = 0; i < ileNeuronow; i++)
	{
		neurony[i].waga = (rand() % 100) + 1.0;
		neurony[i].waga = neurony[i].waga / 100;
	}
}

//  ================================= SIEC
Siec::Siec(int ileWarstw, int * ileNeuronow)
{
	stworzSiec(ileWarstw, ileNeuronow);
}
void Siec::stworzSiec(int ileWarstw, int * ileNeuronow)
{
	warstwy = new Layer[ileWarstw];
	for (int i = 0; i < ileWarstw; i++)
	{
		warstwy[i].stworzNeuron(ileNeuronow[i]);
	}
	std::cout << std::endl;
}
void Siec::dodajWszystkie(int ileWarstw, int * ileNeuronow)
{
	double suma = 0.0;
	for (int i = 1; i < ileWarstw; i++)
	{
		for (int j = 0; j < ileNeuronow[i]; j++)
		{
			for (int k = 0; k < ileNeuronow[i - 1]; k++)
			{
				suma += warstwy[i - 1].neurony[k].x * warstwy[i - 1].neurony[k].waga;
				suma = funcE(suma);
			}
			warstwy[i].neurony[j].x = suma;
			suma = 0.0;
		}
	}
}
double Siec::funcE(double suma)
{
	double e = 2.718;
	double alfa = 0.5;
	return 1.0 / (1.0 + pow(e, alfa*suma));
}
double Siec::pochodnaFuncE(double suma)
{
	double e = 2.718;
	double alfa = 0.5;
	
	return (-alfa*pow(e,alfa*suma)) / (pow(1.0 + pow(e, alfa*suma),2));
}
void Siec::zaladuj(std::string i, int ktory, int ileWejsciowych, int ileWarstw, int ostatniNeuron)
{
	std::string nazwa;
	if (ktory == 0)
	{
		nazwa = "C:\\Users\\Wojciech\\Documents\\Visual Studio 2013\\Projects\\Przygotowanie danych do psi\\Przygotowanie danych do psi\\dane3\\" + i + ".txt";
	}
	else
	{
		nazwa = "C:\\Users\\Wojciech\\Documents\\Visual Studio 2013\\Projects\\Przygotowanie danych do psi\\Przygotowanie danych do psi\\dane" + std::to_string(ktory) + "\\" + i + ".txt";
	}

	std::fstream plik(nazwa);
	if (plik.is_open())
	{
		
		
		for (int i = 0; i < ileWejsciowych; i++)
		{
			if (i != ileWejsciowych - 1)
			{
				plik >> warstwy[0].neurony[i].x;
				
			}
			else
			{
				warstwy[0].neurony[i].x = 1;
				
			}
		}
		plik >> warstwy[ileWarstw - 1].neurony[ostatniNeuron - 1].oczekiwanaWartosc;
		

		
	}
	else
	{
		//std::cout << "nie uda³o sie otworzyc"  << std::endl;
	}

	plik.close();


}
void Siec::wstecznaPropagacja(int ileWarstw, int * ileNeuronow)
{
	int licznik = 1;
	
	while (licznik ==1)
	{

		double suma = 0.0;
		for (int i = 1; i < ileWarstw; i++)
		{
			for (int j = 0; j < ileNeuronow[i]; j++)
			{
				for (int k = 0; k < ileNeuronow[i - 1]; k++)
				{
					suma += warstwy[i - 1].neurony[k].x * warstwy[i - 1].neurony[k].waga;
					suma = funcE(suma);
				}
				warstwy[i].neurony[j].x = suma;
				suma = 0.0;
			}
		}
		
		warstwy[ileWarstw - 1].neurony[0].delta = warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc - warstwy[ileWarstw - 1].neurony[0].x;
		for (int i = ileWarstw-1; i > 0; i--)
		{
			for (int j = 0; j < ileNeuronow[i]; j++)
			{
				for (int k = 0; k < ileNeuronow[i - 1]; k++)
				{
					warstwy[i - 1].neurony[j].delta = warstwy[i].neurony[j].delta * warstwy[i - 1].neurony[j].waga;

					
				}
				
			}
		}
		double n = 0.03;
		double e = 2.718;
		for (int i = 1; i < ileWarstw; i++)
		{
			for (int j = 0; j < ileNeuronow[i]; j++)
			{
				for (int k = 0; k < ileNeuronow[i - 1]; k++)
				{
					warstwy[i - 1].neurony[k].waga = warstwy[i - 1].neurony[k].waga + n*pochodnaFuncE(e)*warstwy[i - 1].neurony[k].x;
				}
				
			}
		}

		licznik = 0;
	}
}
void Siec::zapiszWagi(int ileWarstw, int * ileNeuronow)
{
	std::fstream plik("wagi.txt", std::ios::in | std::ios::out);
	
	for (int i = 0; i < ileWarstw-1; i++)
	{
		for (int j = 0; j < ileNeuronow[i]; j++)
		{
			plik << warstwy[i].neurony[j].waga;
			plik << "\n";
		}
		plik << "\n";
	}

	plik.close();
}
void Siec::wczytajWagi(int ileWarstw, int * ileNeuronow)
{
	std::fstream plik("wagi.txt", std::ios::in | std::ios::out);
	
	for (int i = 0; i < ileWarstw - 1; i++)
	{
		for (int j = 0; j < ileNeuronow[i]; j++)
		{
			plik >> warstwy[i].neurony[j].waga;
			
		}
		
	}

	plik.close();
}
void Siec::wypiszDane(int ileWarstw, int * ileNeuronow)
{
	for (int i = 0; i < ileWarstw - 1; i++)
	{
		for (int j = 0; j < ileNeuronow[i]; j++)
		{
			std::cout << "Waga: " << warstwy[i].neurony[j].waga <<
				" X: " << warstwy[i].neurony[j].x
				  << std::endl;
		}

	}
}