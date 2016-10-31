#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int czyWygrana(int ** tab, int n, int m);
int ** wypelnianieTablicy(int **tab1, int n, int m, int &wynik);

int main()
{
	std::cout << "Poczatek" << endl;
	srand(time(NULL));
	const int n = 3, m = 3;
	int ** tab = new int *[n];
	int wynik;
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[m];
	}

	int ileTestow = 100000;
	int zmienna1 = 0;
	int zmienna2 = 0;
	int zmienna3 = 0;
	for (int k = 0; k < ileTestow; k++)
	{

		wynik = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tab[i][j] = 2;
			}
		}

		tab = wypelnianieTablicy(tab, n, m, wynik);
		
		if (wynik == 1)
		{
			string nazwa = to_string(zmienna1);
			fstream plik("dane1\\" + nazwa + ".txt", ios::out | ios::in | ios::app);


			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					plik << tab[i][j];
					if (j == m - 1)
					{
						plik << "\n";
					}
					else
					{
						plik << " ";
					}
				}
			}

			plik << wynik;
			plik << "\n";
			zmienna1++;
			plik.close();
		}
		else if (wynik == 0)
		{
			string nazwa = to_string(zmienna2);
			fstream plik("dane2\\" + nazwa + ".txt", ios::out | ios::in | ios::app);


			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					plik << tab[i][j];
					if (j == m - 1)
					{
						plik << "\n";
					}
					else
					{
						plik << " ";
					}
				}
			}

			plik << wynik;
			plik << "\n";
			zmienna2++;
			plik.close();
		}
		else
		{
			string nazwa = to_string(zmienna3);
			fstream plik("dane3\\" + nazwa + ".txt", ios::out | ios::in | ios::app);


			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					plik << tab[i][j];
					if (j == m - 1)
					{
						plik << "\n";
					}
					else
					{
						plik << " ";
					}
				}
			}

			plik << wynik;
			plik << "\n";
			zmienna3++;
			plik.close();
		}
		
		
	}
	std::cout << "Koniec" << endl;
	std::system("pause");
}
int czyWygrana(int ** tab, int n, int m)
{
	int a = -1, b = 1;
	if (tab[0][0] == a && tab[1][1] == a && tab[2][2] == a)
	{
		return a;
	}
	else if (tab[0][0] == a && tab[0][1] == a && tab[0][2] == a)
	{
		return a;
	}
	else if (tab[0][0] == a && tab[1][0] == a && tab[2][0] == a)
	{
		return a;
	}
	else if (tab[1][0] == a && tab[1][1] == a && tab[1][2] == a)
	{
		return a;
	}
	else if (tab[0][1] == a && tab[1][1] == a && tab[2][1] == a)
	{
		return a;
	}
	else if (tab[2][0] == a && tab[2][1] == a && tab[2][2] == a)
	{
		return a;
	}
	else if (tab[0][2] == a && tab[1][2] == a && tab[2][2] == a)
	{
		return a;
	}
	else if (tab[2][0] == a && tab[1][1] == a && tab[0][2] == a)
	{
		return a;
	}else



	//----------------  B
	if (tab[0][0] == b && tab[1][1] == b && tab[2][2] == b)
	{
		return b;
	}
	else if (tab[0][0] == b && tab[0][1] == b && tab[0][2] == b)
	{
		return b;
	}
	else if (tab[0][0] == b && tab[1][0] == b && tab[2][0] == b)
	{
		return b;
	}
	else if (tab[1][0] == b && tab[1][1] == b && tab[1][2] == b)
	{
		return b;
	}
	else if (tab[0][1] == b && tab[1][1] == b && tab[2][1] == b)
	{
		return b;
	}
	else if (tab[2][0] == b && tab[2][1] == b && tab[2][2] == b)
	{
		return b;
	}
	else if (tab[0][2] == b && tab[1][2] == b && tab[2][2] == b)
	{
		return b;
	}
	else if (tab[2][0] == b && tab[1][1] == b && tab[0][2] == b)
	{
		return b;
	}
	else
	{
		return 2;
	}

}
int ** wypelnianieTablicy(int **tab1, int n, int m, int &wynik)
{
	int x = 0, y = 0;
	bool przelacznikOX = true;
	int ileMaBycStrzalow = 9;
	//ileMaBycStrzalow = rand() % 5 + 5;
	
	przelacznikOX = rand() % 2;

	int ** tab = new int *[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			tab[i][j] = 2;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (tab[x][y] == 2)
		{
			if (przelacznikOX)
			{
				tab[x][y] = 1;
				przelacznikOX = false;
			}
			else
			{
				tab[x][y] = 0;
				przelacznikOX = true;
			}
		}
		else
		{
			i--;
		}
		if (i > 4)
		{
			if (czyWygrana(tab, n, m) == 0 || czyWygrana(tab, n, m) == 1)
			{
				wynik = czyWygrana(tab, n, m);
				break;
			}
		}
		if (i == 8 && (czyWygrana(tab, n, m) != 0 || czyWygrana(tab, n, m) != 1))
		{
			wynik = 2;
		}
	}
	return tab;
}