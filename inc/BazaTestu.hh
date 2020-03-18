#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};


/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );

/*
 * Czesc odpowiedzialna za sprawdzanie poprawnosci odpowiedzi
 * i statystyke.
*/

bool SprawdzPoprawnosc(LZespolona Odpowiedz, WyrazenieZesp Wynik);

struct Statystyka {
  int l_pop;
  int l_pytan;
};

void InicjujStatystyke(Statystyka &stat, BazaTestu baza);

int ZwrocPoprawne(Statystyka stat);
int ZwrocLiczbePytan(Statystyka stat);
float ZwrocProcent(Statystyka stat);

void DodajDobra(Statystyka &stat);

void WyswietlPodsumowanie(Statystyka stat);

void Punktacja(Statystyka &stat, LZespolona Odpowiedz, WyrazenieZesp Wynik);


#endif
