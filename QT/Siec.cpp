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
