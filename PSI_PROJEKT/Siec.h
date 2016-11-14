#ifndef SIEC_H
#define SIEC_H
#include "Naglowki.h"
class Node
{
public:

	double x = 0;
	double waga = 0;
	double oczekiwanaWartosc = 0;
	double delta = 0;
	double suma = 0;
	double *wagi;
	Node();
	double sumuj();




};
class Layer
{
public:
	Node * neurony;
	Layer();


	void stworzNeuron(int ileNeuronow, int ileNeuronow1);

};
class Siec
{
public:
	Layer * warstwy;

	Siec(int ileWarstw, int * ileNeuronow);
	double funcE(double suma);
	void funcTan(int ileWarstw, int * ileNeuronow);
	double pochodnaFuncE(double suma);
	void stworzSiec(int ileWarstw, int * ileNeuronow);
	void dodajWszystkie(int ileWarstw, int * ileNeuronow);
	void zaladuj(std::string i, int ktory, int ileWejsciowych, int ileWarstw, int ostatniNeuron);
	void wstecznaPropagacja(int ileWarstw, int * ileNeuronow, double &sumaDelta);
	void zapiszWagi(int ileWarstw, int * ileNeuronow);
	void wczytajWagi(int ileWarstw, int * ileNeuronow);
	void wypiszDane(int ileWarstw, int * ileNeuronow);

};




#endif // SIEC_H