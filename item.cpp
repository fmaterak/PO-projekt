#include "item.h"
using namespace std;


// MENU OD PRZEDMIOTOW WSZYSTKICH
void menu_ekwipunek()
{
	cout << "[1] - Przedmioty zalozone." << endl;
	cout << "[2] - Przedmioty w plecaku." << endl;
	cout << "[3] - Sklep." << endl;
	cout << "[4] - Chce zdjac przedmiot." << endl;
	cout << "[5] - Chce zalozyc przedmiot." << endl;
	cout << "Posiadasz: "<<gold<<"zlota" << endl;

	int menu_nr=-1;
	Item* katalog = new Item;
	int l = -1;

	switch (menu_nr)
	{
	case 1:
	{
		katalog = wczytaj_zalozone(&l);
		wypis_wszystkich(l, katalog);
		system("PAUSE");
		system("cls");
		break;
	}
	case 2:
	{
		katalog = wczytaj_w_plecaku(&l);
		wypis_wszystkich(l, katalog);
		system("PAUSE");
		system("cls");
		break;
	}
	case 3:
	{
		int tmp = -1;
		cout << "[1] - Lista dostepnych przedmiotow." << endl;
		cout << "[2] - Kup przedmiot." << endl;
		cout << "Wypieram pozycje nr: ";
		cin >> tmp;
		switch (tmp)
		{
		case 1:
		{
			katalog = wczytaj_sklep(&l);
			wypis_wszystkich(l, katalog);
			system("PAUSE");
			system("cls");
			break;
		}
		case 2:
		{
			

			cout << "Chce kupic przedmiot o nr: ";
			cin >> tmp1;
			katalog = wczytaj_sklep(&l);
			if (tmp1 >= l)
			{
				cout << "Nie ma przedmiotu o takim numerze!" << endl;
			}
			else
			{
				nameT = katalog[tmp1].name;
				priceT = katalog[tmp1].price;
				defenceT = katalog[tmp1].defence;
				damageT = katalog[tmp1].damage;
				agilityT = katalog[tmp1].agility;

				if (gold >= katalog[tmp1].price)
				{
					gold = gold - katalog[tmp1].price;
					katalog = zmniejsz(&l, katalog);

					katalog = wczytaj_w_plecaku(&l);
					katalog = dodaj(&l, katalog);
				}
				else
				{
					cout << "Nie masz wystarczajaco pieniedzy!" << endl;
				}
			}


			system("PAUSE");
			system("cls");
			break;
		}
		}
	}
	case 4:
	{
		int tmp2;

		cout << "Chce kupic przedmiot o nr: ";
		cin >> tmp2;
		katalog = wczytaj_zalozone(&l);
		if (tmp1 >= l)
		{
			cout << "Nie ma przedmiotu o takim numerze!" << endl;
		}
		else
		{
			nameT = katalog[tmp2].name;
			priceT = katalog[tmp2].price;
			defenceT = katalog[tmp2].defence;
			damageT = katalog[tmp2].damage;
			agilityT = katalog[tmp2].agility;
			
			katalog = zmniejsz(&l, katalog);

			katalog = wczytaj_w_plecaku(&l);
			katalog = dodaj(&l, katalog);
		}
	}
	case 5:
	{
		int tmp3;

		cout << "Chce kupic przedmiot o nr: ";
		cin >> tmp3;
		katalog = wczytaj_w_plecaku(&l);
		if (tmp1 >= l)
		{
			cout << "Nie ma przedmiotu o takim numerze!" << endl;
		}
		else
		{
			nameT = katalog[tmp3].name;
			priceT = katalog[tmp3].price;
			defenceT = katalog[tmp3].defence;
			damageT = katalog[tmp3].damage;
			agilityT = katalog[tmp3].agility;

			katalog = zmniejsz(&l, katalog);

			katalog = wczytaj_zalozone(&l);
			katalog = dodaj(&l, katalog);
		}
	}
	}
}

void wypis_wszystkich(int i, Item kat[])
{
	for (int j = 0; i > j; j++)
	{
		cout << "nr: " << j << endl;
		cout << "Nazwa: " << kat[j].name << endl;
		cout << "Cena: " << kat[j].price << endl;
		cout << "Obrona: " << kat[j].defence << endl;
		cout << "Atak: " << kat[j].damage << endl;
		cout << "Zrecznosc: " << kat[j].agility << endl;
	}
}
Item* wczytaj_zalozone(int* i)
{
	fstream plik;
	plik.open("przedmioty.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad otwarcia pliku." << endl;
		exit(-1);
	}
	plik >> *i; //pobranie ilości zalozonych przedmiotow
	Item* kat = new Item[*i];
	for (int j = 0; j < *i; j++)
	{
		plik >> kat[j].name;
		plik >> kat[j].price;
		plik >> kat[j].defence;
		plik >> kat[j].damage;
		plik >> kat[j].agility;
	}
	plik.close();
	return kat;
}
Item* wczytaj_w_plecaku(int* i)
{
	fstream plik;
	plik.open("zdjete.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad otwarcia pliku." << endl;
		exit(-1);
	}
	plik >> *i; //pobranie ilości posiadanych, ale nie zalozonych przedmiotow
	Item* kat = new Item[*i];
	for (int j = 0; j < *i; j++)
	{
		plik >> kat[j].name;
		plik >> kat[j].price;
		plik >> kat[j].defence;
		plik >> kat[j].damage;
		plik >> kat[j].agility;
	}
	plik.close();
	return kat;
}
Item* wczytaj_sklep(int* i)
{
	fstream plik;
	plik.open("sklep.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad otwarcia pliku." << endl;
		exit(-1);
	}
	plik >> *i; //pobranie ilości przedmiotow w sklepie
	Item* kat = new Item[*i];
	for (int j = 0; j < *i; j++)
	{
		plik >> kat[j].name;
		plik >> kat[j].price;
		plik >> kat[j].defence;
		plik >> kat[j].damage;
		plik >> kat[j].agility;
	}
	plik.close();
	return kat;
}
Item* usun(int* i, Item kat[])
{
	Item* nowa = new Item[*i - 1];
	for (int j = 0; j < *i - 1; j++)
	{
		if (tmp1 > j)
		{
			nowa[j].name = kat[j].name;
			nowa[j].price = kat[j].price;
			nowa[j].defence = kat[j].defence;
			nowa[j].damage = kat[j].damage;
			nowa[j].agility = kat[j].agility;
		}
		else
		{
			nowa[j].name = kat[j+1].name;
			nowa[j].price = kat[j+1].price;
			nowa[j].defence = kat[j+1].defence;
			nowa[j].damage = kat[j+1].damage;
			nowa[j].agility = kat[j+1].agility;
		}
	}
	delete[]kat;
	return nowa;
}
Item* zmniejsz(int* i, Item kat[])
{
	Item* nowa = usun(i, kat);
	*i = *i - 1;
	return nowa;
}
Item* powieksz(int i, Item kat[])
{
	Item* nowa = new Item[i + 1];
	for (int j = 0; j < i; j++)
	{
		nowa[j].name = kat[j].name;
		nowa[j].price = kat[j].price;
		nowa[j].defence = kat[j].defence;
		nowa[j].damage = kat[j].damage;
		nowa[j].agility = kat[j].agility;
	}
	delete[]kat;
	return nowa;
}
Item* dodaj(int* i, Item kat[])
{
	Item* nowa = powieksz(*i, kat);
	nowa[*i].name = nameT;
	nowa[*i].price = priceT;
	nowa[*i].defence = defenceT;
	nowa[*i].damage = damageT;
	nowa[*i].agility = agilityT;
	*i = *i + 1;
	return nowa;
}
