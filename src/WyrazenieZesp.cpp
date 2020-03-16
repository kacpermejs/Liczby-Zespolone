#include "WyrazenieZesp.hh"

void WyswietlWyrarzenie(WyrazenieZesp  WyrZ)
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
    default:
    std::cout << "nie zdefiniowano dzialania" <<std::endl;
    break;
  }
  return Wynik;
}

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
