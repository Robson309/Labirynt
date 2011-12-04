// labirynt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void show_table(char tab[10][10])
{
	system("cls");
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	//aktualnie na tebeli10x10
	char tab[10][10];
	int metax=10;
	int metay=10;
	int pozx=0;
	int pozy=0;
	//wypelnienie tablicy #
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			tab[i][j]=35;//35 w ACII to #
			cout << tab[i][j];
		}
		cout << endl;
	}
	//ustawienie przeszkod
	tab[5][0]=64;
	tab[5][5]=64; //64 w ASCII to @
	//symulacja gry
	do{
		if (pozx<9 && pozx<metax && tab[pozx+1][pozy]!=64)
		{
			tab[pozx][pozy]=35;
			pozx+=1;
			tab[pozx][pozy]=42; //42 w ASCII to *
		}
		else if (pozy<9 && pozy<metay && tab[pozx][pozy+1]!=64)
		{
			tab[pozx][pozy]=35;
			pozy+=1;
			tab[pozx][pozy]=42; //42 w ASCII to *
		}
		show_table(tab);
		cout << endl << metax << endl << pozx << endl << metay << endl << pozy << endl;
		Sleep(50);
	}while((metax-1)!=pozx || (metay-1)!=pozy);
	cout << "koniec gry" << endl;
	getchar();
	return 0;
}

