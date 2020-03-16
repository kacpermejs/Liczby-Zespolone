#include "LZespolona.hh"


/*!
 * Tworzy nowa liczbe zespolona z podanych liczb.
 *
 *
 */

LZespolona utworz(int rzeczywista, int urojona)
{
  LZespolona nowa;
  nowa.re=rzeczywista;
  nowa.im=urojona;
  return nowa;
}

void WyswietlZespolona(LZespolona Z)
{
  std::cout<<'('<< Z.re << std::showpos << Z.im << std::noshowpos << "i)";
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;

  return Wynik;
}

/*!
 * Reszta funkcji to analogiczne funkcje przeciazajace operatory.
 */

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;

  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re - Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im + Skl1.im * Skl2.re);

  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik=Skl1*sprz(Skl2)/pow(mod(Skl2), 2);

  return Wynik;
}
//!Funkcja zwraca sprzezenie LZespolonej
LZespolona sprz(LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = (-1)*Skl1.im;

  return Wynik;
}
//!Funkcja zwraca modul LZespolonej
double mod(LZespolona Skl1)
{
  double Wynik;
  Wynik=sqrt(pow(Skl1.re, 2)+pow(Skl1.im, 2));
  return Wynik;
}
/*!
 * Ponizsze funkcje to operacje matematyczne ale ze skladnikiem rzeczywistym typu double
 */
LZespolona operator + (LZespolona zesp, double rzeczywista)
{
  LZespolona  Wynik;

  Wynik.re = zesp.re+rzeczywista;
  Wynik.im = zesp.im;

  return Wynik;
}

LZespolona operator - (LZespolona zesp, double rzeczywista)
{
  LZespolona  Wynik;

  Wynik.re = zesp.re-rzeczywista;
  Wynik.im = zesp.im;

  return Wynik;
}

LZespolona operator * (LZespolona zesp, double rzeczywista)
{
  LZespolona  Wynik;

  Wynik.re = zesp.re*rzeczywista;
  Wynik.im = zesp.im*rzeczywista;

  return Wynik;
}

LZespolona operator / (LZespolona zesp, double rzeczywista)
{
  LZespolona  Wynik;

  Wynik.re = zesp.re/rzeczywista;
  Wynik.im = zesp.im/rzeczywista;

  return Wynik;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else
    return false;
}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re != Skl2.re && Skl1.im != Skl2.im)
    return true;
  else
    return false;
}
