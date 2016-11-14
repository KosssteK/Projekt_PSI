#include "Siec.h"
#include "Naglowki.h"
// =============================== NODE
Node::Node(){
	x = 2.0;
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
void Layer::stworzNeuron(int ileNeuronow, int ileNeuronow1)
{
	neurony = new Node[ileNeuronow];
	for (int i = 0; i < ileNeuronow; i++)
	{
		neurony[i].wagi = new double[ileNeuronow1];

		for (int j = 0; j < ileNeuronow1; j++)
		{
			neurony[i].wagi[j] = (rand() % 60) + 20;
			neurony[i].wagi[j] = neurony[i].wagi[j] / 100.0;
			//neurony[i].wagi[j] = 1;
		}




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
	for (int i = 0; i < ileWarstw - 1; i++)
	{
		warstwy[i].stworzNeuron(ileNeuronow[i], ileNeuronow[i + 1]);
	}
	warstwy[ileWarstw - 1].neurony = new Node[1];
	warstwy[ileWarstw - 1].neurony[0].wagi = new double[1];
	warstwy[ileWarstw - 1].neurony[0].wagi[0] = 0;
	std::cout << std::endl;
}
void Siec::dodajWszystkie(int ileWarstw, int * ileNeuronow)
{
	double suma = 0.0;
	double sumaZapis = 0.0;
	for (int i = 1; i < ileWarstw; i++)
	{
		for (int j = 0; j < ileNeuronow[i]; j++)
		{
			for (int k = 0; k < ileNeuronow[i - 1]; k++)
			{
				suma += warstwy[i - 1].neurony[k].x * warstwy[i - 1].neurony[k].wagi[j];
				sumaZapis = suma;



			}
			suma = tanh(suma);
			warstwy[i].neurony[j].suma = sumaZapis;
			warstwy[i].neurony[j].x = suma;

			suma = 0.0;
		}
	}
	/*std::cout << " Oczekiwana: " << warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc << " Ta co wyszla: " << warstwy[ileWarstw - 1].neurony[0].x << " wartosc x: " << warstwy[ileWarstw - 1].neurony[0].x << */ /*
																																																														<< std::endl;*/
}
double Siec::funcE(double suma)
{
	double e = 2.718;
	double alfa = 0.5;
	return (pow(e, suma) - pow(e, -suma)) / ((pow(e, suma) + pow(e, -suma)));
}
double Siec::pochodnaFuncE(double suma)
{
	double e = 2.718;
	double alfa = 0.5;

	return sinh(suma) / cosh(suma);
}
void Siec::zaladuj(std::string i, int ktory, int ileWejsciowych, int ileWarstw, int ostatniNeuron)
{
	std::string nazwa;
	if (ktory == 0)
	{
		nazwa = "daneO\\" + i + ".txt";
	}
	else
	{
		nazwa = "daneX\\" + i + ".txt";
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
		double wynik = 0;
		plik >> wynik;
		if (wynik == 1)
		{
			warstwy[ileWarstw - 1].neurony[ostatniNeuron - 1].oczekiwanaWartosc = -1;
		}
		else
		{
			warstwy[ileWarstw - 1].neurony[ostatniNeuron - 1].oczekiwanaWartosc = 1;
		}




	}
	else
	{
		//std::cout << "nie uda³o sie otworzyc"  << std::endl;
	}

	plik.close();


}
void Siec::wstecznaPropagacja(int ileWarstw, int * ileNeuronow, double &sumaDelta)
{
	int licznik = 1;

	while (licznik == 1)
	{

		double suma = 0.0;
		double sumaZapis = 0.0;
		for (int i = 1; i < ileWarstw; i++)
		{
			for (int j = 0; j < ileNeuronow[i]; j++)
			{
				for (int k = 0; k < ileNeuronow[i - 1]; k++)
				{
					suma += warstwy[i - 1].neurony[k].x * warstwy[i - 1].neurony[k].wagi[j];
					sumaZapis = suma;



				}
				suma = tanh(suma);
				warstwy[i].neurony[j].suma = sumaZapis;
				warstwy[i].neurony[j].x = suma;

				suma = 0.0;
			}
		}
		//std::cout << "Wartosc x: " << warstwy[ileWarstw - 1].neurony[0].x << std::endl;

		warstwy[ileWarstw - 1].neurony[0].delta = warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc - warstwy[ileWarstw - 1].neurony[0].x;
		/*std::cout << " Oczekiwana: " << warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc << " Ta co wyszla: " << warstwy[ileWarstw - 1].neurony[0].x << " wartosc x: " << warstwy[ileWarstw - 1].neurony[0].x << */	/*
																																																							<< std::endl;*/
		for (int i = ileWarstw - 1; i > 0; i--)
		{
			for (int j = 0; j < ileNeuronow[i - 1]; j++)
			{
				for (int k = 0; k < ileNeuronow[i]; k++)
				{
					warstwy[i - 1].neurony[j].delta += warstwy[i].neurony[k].delta * warstwy[i - 1].neurony[j].wagi[k];

				}
			}
		}
		double n = 0.6;
		double temp;
		for (int i = 0; i < ileWarstw - 1; i++)
		{
			for (int j = 0; j < ileNeuronow[i + 1]; j++)
			{
				for (int k = 0; k < ileNeuronow[i]; k++)
				{
					temp = 1 - tanh(warstwy[i + 1].neurony[j].x) * tanh(warstwy[i + 1].neurony[j].x);
					warstwy[i].neurony[k].wagi[j] = warstwy[i].neurony[k].wagi[j] + (n *  warstwy[i + 1].neurony[j].delta* temp *  warstwy[i].neurony[k].x);
				}
			}
		}
		sumaDelta += sqrt(pow(warstwy[ileWarstw - 1].neurony[0].delta, 2));
		licznik = 0;
		/*std::cout << " Oczekiwana: " << warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc << " Ta co wyszla: " << warstwy[ileWarstw - 1].neurony[0].x << " wartosc x: " << warstwy[ileWarstw - 1].neurony[0].x << */ /*funcTan(ileWarstw, ileNeuronow);*/	/*
																																																																<< std::endl;*/
	}
}
void Siec::zapiszWagi(int ileWarstw, int * ileNeuronow)
{
	std::fstream plik("wagi.txt", std::ios::in | std::ios::out);

	for (int i = 0; i < ileWarstw - 1; i++)
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
			std::cout << " X: " << warstwy[i].neurony[j].x << " ";
			std::cout << "Waga: ";
			for (int k = 0; k < ileNeuronow[i + 1]; k++)
			{
				std::cout << warstwy[i].neurony[j].wagi[k] << " ";
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
		if (i == ileWarstw - 2)
		{

			std::cout
				<< " Oczekiwana: " << warstwy[ileWarstw - 1].neurony[0].oczekiwanaWartosc
				<< " Wynikowa: " << warstwy[ileWarstw - 1].neurony[0].x
				<< std::endl;
		}
	}
}
void Siec::funcTan(int ileWarstw, int * ileNeuronow)
{
	
}