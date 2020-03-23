#include "Statystyka.hh"


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
std::ostream & operator << (std::ostream & strm, Statystyka stat)
{
  strm << "Uzyskano " << ZwrocPoprawne(stat) << " poprawnych odpowiedzi na " << ZwrocLiczbePytan(stat) << " mozliwych" << std::endl;
  strm << "Co daje wynik " << ZwrocProcent(stat) << "%." << std::endl;
  return strm;
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
    LZespolona Poprawny = Oblicz(Wynik);
    std::cout << std::endl;
    std::cout << "Zla odpowiedz, poprawny wynik to: ";
    std::cout << Poprawny;
    std::cout << std::endl;
  }
}
