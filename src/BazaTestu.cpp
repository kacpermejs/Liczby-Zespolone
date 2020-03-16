#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/*!
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };

/*
 * Analogicznie zdefiniuj test "trudne"
 *
 */





/*!
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}




/*!
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  /*
   * Analogicznie zrob inicjalizacje dla testu trudne
   */

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}
/*!
 * Funkcja pobiera i sprawdza poprawnosc formatu odpowiedzi uzyskanej od uzytkownika
 * Parametry:
 *       L - referencja do LZespolona
 *
 * Warunki wstepne:
 *      - Brak
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie (uzytkownik wprowadzi liczbe
 *              zespolona w postaci (a+bi)
 *       false - w przypadku przeciwnym.
 */
bool PobierzOdpowiedz(LZespolona &L)
{

  char znak; //zmienna do przechowywania znaków "(, i, )" z określonego formatu liczby zespolonej

  cin >> znak;    //sprawdzanie pierwszego nawiasu
  if(znak == '(') //******************************
  {
    cin >> L.re >>L.im; //sprawdzanie liczb
    if(cin.good())      //*****************
    {
      cin >> znak;    //sprawdzanie "i"
      if(znak == 'i') //***************
      {
        cin >> znak;    //sprawdzanie zamykajacego nawiasu
        if(znak == ')') //********************************
        {
          cin.clear();
          cin.ignore(10000, '\n');
          return true;
        }
      }
    }
  }
  cin.clear();
  cin.ignore(10000, '\n');
  return false;
}
/*!
 * Funkcja porownuje liczbe zespolona z wynikiem wprowadzonego wyrazenia.
 * Parametry:
 *       Odpowiedz - LZespolona wprowadzona jako dana do porownania
 *       Wynik - WyrazenieZesp ktorego wynik funkcja ma porownac z Odpowiedz
 * Warunki wstepne:
 *      - Brak
 *
 * Zwraca:
 *       true - gdy odpowiedz i obliczony wynik sa takie same
 *       false - w przypadku przeciwnym.
 */
bool SprawdzPoprawnosc(LZespolona Odpowiedz, WyrazenieZesp Wynik)
{
  if(Odpowiedz==Oblicz(Wynik))
    return true;
  else
    return false;
}
/*!
 * Funkcja konfiguruje strukture Statystyka laczac ja z parametrem struktury BazaTestu.
 * Parametry:
 *       stat - referencja do struktury Statystyka
 *       baza - struktura zawiarajaca dane o tescie
 *
 * Warunki wstepne:
 *      - obie struktury musza byc wczesniej utworzone
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie (uzytkownik wprowadzi liczbe
 *              zespolona w postaci (a+bi))
 *       false - w przypadku przeciwnym.
 */
void InicjujStatystyke(Statystyka &stat, BazaTestu baza)
{
  stat.l_pytan=baza.IloscPytan;
}

//!Funkcja zwraca liczbe poprawnych odpowiedzi.
int ZwrocPoprawne(Statystyka stat)
{
  return stat.l_pop;
}

//!Funkcja zwraca liczbe pytan w tescie.
int ZwrocLiczbePytan(Statystyka stat)
{
  return stat.l_pytan;
}

//!Funkcja zwraca procent poprawnych odpowiedzi.
float ZwrocProcent(Statystyka stat)
{
  float procent;
  procent = ((float)stat.l_pop/(float)stat.l_pytan)*100;
  return procent;
}

//!Funkcja doadaje punkt do statystyki.
void DodajDobra(Statystyka &stat)
{
  ++stat.l_pop;
}

//!Funkcja wyswietla uzytkownikowi dane ze struktury Statystyka.
void WyswietlPodsumowanie(Statystyka stat)
{
  cout << "Uzyskano " << ZwrocPoprawne(stat) << " poprawnych odpowiedzi na " << ZwrocLiczbePytan(stat) << " mozliwych" <<endl;
  cout << "Co daje wynik " << ZwrocProcent(stat) << "%." << endl;
}

/*!
 * Funkcja zajmujaca sie badaniem poprawnosci odpowiedzi.
 * Parametry:
 *       stat - referencja do struktury Statystyka
 *       Odpowiedz - LZespolona wprowadzona jako dana do porownania
 *       Wynik - WyrazenieZesp ktorego wynik funkcja ma porownac z Odpowiedz
 *
 * Warunki wstepne:
 *      - struktura Statystyka musi byc wczesniej utworzona
 *
 */
void Punktacja(Statystyka &stat, LZespolona Odpowiedz, WyrazenieZesp Wynik)
{
  if(SprawdzPoprawnosc(Odpowiedz, Wynik))
    DodajDobra(stat);
  else
  {
    cout << endl;
    cout << "Zla odpowiedz, poprawny wynik to:";
    WyswietlZespolona(Oblicz(Wynik));
    cout << endl;
  }
}
