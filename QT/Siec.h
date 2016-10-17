#ifndef SIEC_H
#define SIEC_H
#include "Naglowki.h"
class Node
{
public:

	double x=0;
	double waga=0;
	double oczekiwanaWartosc = 0;
	double delta = 0;
	Node();
	double sumuj();



};
class Layer
{
public:
	Node * neurony;
	Layer();

	
	void stworzNeuron(int ileNeuronow);
	
};
class Siec
{
public:
	Layer * warstwy;

	Siec(int ileWarstw, int * ileNeuronow);
	double funcE(double suma);
	double pochodnaFuncE(double suma);
	void stworzSiec(int ileWarstw, int * ileNeuronow);
	void dodajWszystkie(int ileWarstw, int * ileNeuronow);
void zaladuj(std::string i, int ktory, int ileWejsciowych, int ileWarstw, int ostatniNeuron);
};




#endif // SIEC_H