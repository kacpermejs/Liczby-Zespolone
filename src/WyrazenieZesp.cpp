#include "WyrazenieZesp.hh"


/*void WyswietlWyrarzenie(WyrazenieZesp  WyrZ)
{
  WyswietlZespolona(WyrZ.Arg1);

  switch(WyrZ.Op)
  {
    case Op_Dodaj:
    {
    std::cout << '+';
    break;
    }

    case Op_Odejmij:
    {
    std::cout << '-';
    break;
    }

    case Op_Mnoz:
    {
    std::cout << '*';
    break;
    }

    case Op_Dziel:
    {
    std::cout << '/';
    break;
    }
    default:
    std::cout << "nie zdefiniowano dzialania" <<std::endl;
    break;
  }

  WyswietlZespolona(WyrZ.Arg2);
}
*/

std::istream & operator >> (std::istream & strm,WyrazenieZesp & WZ)
{
  strm >> WZ.Arg1 >> WZ.Op >> WZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream & strm,Operator & Op)
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

std::ostream & operator << (std::ostream & strm, WyrazenieZesp & WZ)
{
  strm << WZ.Arg1 << WZ.Op << WZ.Arg2;
  return strm;
}

std::ostream & operator << (std::ostream & strm,Operator & Op)
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
