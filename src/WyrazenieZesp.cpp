#include "WyrazenieZesp.hh"

std::istream & operator >> (std::istream & strm, WyrazenieZesp & WZ)
{
  strm >> WZ.Arg1 >> WZ.Op >> WZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream & strm, Operator & Op)
{
  char znak;
  strm >> znak;
  switch(znak)
  {
    case '+':
    {
    Op = Op_Dodaj;
    break;
    }

    case '-':
    {
    Op = Op_Odejmij;
    break;
    }

    case '*':
    {
    Op = Op_Mnoz;
    break;
    }

    case '/':
    {
    Op = Op_Dziel;
    break;
    }
  }
  return strm;
}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WZ)
{
  strm << WZ.Arg1 << WZ.Op << WZ.Arg2;
  return strm;
}

std::ostream & operator << (std::ostream & strm, const Operator & Op)
{
  switch(Op)
  {
    case Op_Dodaj:
    {
    strm << '+';
    break;
    }

    case Op_Odejmij:
    {
    strm << '-';
    break;
    }

    case Op_Mnoz:
    {
    strm << '*';
    break;
    }

    case Op_Dziel:
    {
    strm << '/';
    break;
    }
  }
  return strm;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch(WyrZ.Op)
  {

    case Op_Dodaj:
    {
    Wynik=WyrZ.Arg1+WyrZ.Arg2;
    break;
    }

    case Op_Odejmij:
    {
    Wynik=WyrZ.Arg1-WyrZ.Arg2;
    break;
    }

    case Op_Mnoz:
    {
    Wynik=WyrZ.Arg1*WyrZ.Arg2;
    break;
    }

    case Op_Dziel:
    {
    Wynik=WyrZ.Arg1/WyrZ.Arg2;
    break;
    }
  }
  return Wynik;
}

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
