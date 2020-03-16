#include <iostream>
#include "BazaTestu.hh"
#include <cmath>
#include <cstdlib>

using namespace std;


int main(int argc, char **argv)
{
  LZespolona Odpowiedz;

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  system("clear");

  BazaTestu BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  Statystyka stat = {0, 0};

  InicjujStatystyke(stat, BazaT);

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << endl;
    cout << " Oblicz nastepujace dzialanie: ";
    WyswietlWyrarzenie(WyrZ_PytanieTestowe);
    cout << '.' << endl;

    for(int i=1;i<=3;i++)
    {
      if(!PobierzOdpowiedz(Odpowiedz))
        cout << "Bledny format danych. Proba " << i << " na 3"<<  endl;
      else break;
    }//for

    Punktacja(stat, Odpowiedz, WyrZ_PytanieTestowe);
    cout << " Aby przejsc do nastepnego pytania, nacisnij ENTER!" << endl;
    getchar();
    system("clear");

  }//while

  WyswietlPodsumowanie(stat);

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
