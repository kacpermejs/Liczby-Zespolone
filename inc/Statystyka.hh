#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "BazaTestu.hh"

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

std::ostream & operator << (std::ostream & strm, Statystyka stat);

void Punktacja(Statystyka &stat, LZespolona Odpowiedz, WyrazenieZesp Wynik);

#endif // STATYSTYKA_HH
