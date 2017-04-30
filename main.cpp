#include "Towar.h"
#include <iostream>
#include <list>
#include <cstring>
#include <windows.h>
#include "Zamowienie.h"
#include <cstdlib>
#include <time.h>



//--------------------------------------------------------------------
//INFORMACJA DLA PROWADZACEGO
//Niestety nie dodano ustawienia priorytetow
//--------------------------------------------------------------------
using namespace std;
list <int> lista; //utworzenie listy przechowywujacej zamowienia
int wybor;
Zamowienie gruszki(0);
Zamowienie pomarancze(0);    // utworznie obiektow do stworzenia listy zamowien
Zamowienie winogrono(0);
Zamowienie wisnie(0);
int uruch_zam=0;




//---------------------

void wyswietl()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"HISTORIA ZAMOWIEN: "<<endl;
    cout<<"---------------------------"<<endl;

    for(list<int>::iterator i=lista.begin(); i!= lista.end(); ++i)
       cout<<*i<<" ";

       cout<<endl<<endl<<"ilosc zamowionych gruszek na liscie to: "<<gruszki.lacznie<<endl;
       cout<<"ilosc zamowionych wisni na liscie to: "<<wisnie.lacznie<<endl;
       cout<<"ilosc zamowionych pomaranczy na liscie to: "<<pomarancze.lacznie<<endl;
       cout<<"ilosc zamowionych winogrona na liscie to: "<<winogrono.lacznie<<endl;
       cout<<"ilosc zamowien na liscie "<< lista.size()<<endl;

       cout <<"--------------------------------------------"<<endl;
       cout <<"STAN MAGAZYNU";


    cout<<endl;
    cout<<"---------------------------"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

//-------- 1 ------------

void push_front()
{

    cout<<"Podaj liczbe gruszek do zamowienia(priorytet 1) ";
    cin >> gruszki.poj_zam;
    gruszki.lacznie+=gruszki.poj_zam;
    lista.push_front(gruszki.poj_zam);
    uruch_zam++;


}

//--------- 2 -----------

void push_front1()
{

    cout<<"Podaj liczbe wisni do zamowienia(priorytet 2) ";
    cin >> wisnie.poj_zam;
    wisnie.lacznie+=wisnie.poj_zam;
    lista.push_front(wisnie.poj_zam);
    uruch_zam++;


}
//---------- 3 ---------

void push_front2()
{

    cout<<"Podaj liczbe pomaranczy do zamowienia(priorytet 3) ";
    cin >> pomarancze.poj_zam;
    pomarancze.lacznie+=pomarancze.poj_zam;
    lista.push_front(pomarancze.poj_zam);
    uruch_zam++;


}
//---------- 4 ---------

void push_front3()
{

    cout<<"Podaj liczbe pomaranczy do zamowienia(priorytet 4) ";
    cin >> winogrono.poj_zam;
    winogrono.lacznie+=winogrono.poj_zam;
    lista.push_front(winogrono.poj_zam);
    uruch_zam++;


}

//---------- 5 ----------

void size()
{
    cout<<"Jest: "<<lista.size()<<"zamowien na liscie";
    Sleep(2000);
}



//---------- 6 ----------

void empty()
{
    cout<<"Czy lista pusta? -> ";
    if (lista.empty()==1) cout<<"TRUE"; else cout<<"FALSE";
    Sleep(2000);
}

//---------- 7 ----------

void pop_front()
{
    cout<<"Nastapi usuniecie liczby z poczatku listy";
    Sleep(2000);
    lista.pop_front();

    uruch_zam--;        // zmnieszy liczbe zamowien wiec realizacja nastapi pozniej
}

//---------- 8 ----------

void sort()
{
    cout<<"Nastapi posortowanie listy! ";
    lista.sort();
    Sleep(2000);
}



//---------- 9 ----------

void exit()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Koniec programu!";
    Sleep(2000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
//------------------------


int main()
{

srand(time(NULL)); //

//   int wyb;
    Towar p[4];

    for(int i=0;i<=3;i++)   //TABLICA OBIEKTOW
    {
        p[i].ile=i+1;
        p[i].wczytaj();
        p[i].wyswietl();
    }


do
{

wyswietl();

cout <<"ilosc gruszek w magazynie: "<<p[0].ilosc<<endl;
cout <<"ilosc wisni w magazynie: "<<p[1].ilosc<<endl;         // Wyswietla aktualny stan magazynu
cout <<"ilosc pomaranczy w magazynie: "<<p[2].ilosc<<endl;
cout <<"ilosc winogrona w magazynie: "<<p[3].ilosc<<endl<<endl;

if(uruch_zam%3==0&&lista.size()!=0) // Petla odpowiadajaca za realizacje zamowien

{
if(p[0].ilosc >gruszki.lacznie) // zmniejsza ilosc towaru na magazynie
  {
    p[0].ilosc-=gruszki.lacznie;
    gruszki.lacznie-=gruszki.lacznie;
   }
   else
    {
      cout<<"Brak dostepnosci - zbyt malo gruszek"<<endl;
      Sleep(2000);
    }
if(p[1].ilosc >wisnie.lacznie)
  {
    p[1].ilosc-=wisnie.lacznie;
    wisnie.lacznie-=wisnie.lacznie;
   }
   else
    {
      cout<<"Brak dostepnosci - zbyt malo zbyt malo wisni"<<endl;
      Sleep(2000);
    }
if(p[2].ilosc >pomarancze.lacznie)
  {
    p[2].ilosc-=pomarancze.lacznie;
    pomarancze.lacznie-=pomarancze.lacznie;
   }
   else
    {
      cout<<"Brak dostepnosci - zbyt malo pomaranczy"<<endl;
      Sleep(2000);
    }
if(p[3].ilosc >winogrono.lacznie)
  {
    p[3].ilosc-=winogrono.lacznie;
    winogrono.lacznie-=winogrono.lacznie;
   }
   else
    {
      cout<<"Brak dostepnosci - zbyt malo gruszek"<<endl;
      Sleep(2000);
    }


uruch_zam++;
}

if(uruch_zam%5==0&&lista.size()!=0&&uruch_zam%3!=0)
{
   int wybor_tow;
   wybor_tow=rand()%3;


    int dostawa;
    dostawa=rand()%200+101;
    p[wybor_tow].ilosc+=dostawa;

    uruch_zam++;
}


else

{



cout << " MENU GLOWNE LISTY:"<<endl;
cout << "---------------------------"<<endl;
cout << "1.  Zamow gruszki    (priorytet 1)"<<endl;
cout << "2.  Zamow wisnie     (priorytet 2)"<<endl;
cout << "3.  Zamow pomarancze (priorytet 3)"<<endl;
cout << "4.  Zamow winogrono  (priorytet 4)"<<endl;
cout << "5.  Ilosc zamowien na liscie:"<<endl;
cout << "6.  Czy lista zamowien jest pusta?"<<endl;
cout << "7.  Usuwa ostatnio zlozozne zamowienie z listy"<<endl;
cout << "8.  Porzadkuje recznie liste wedlug priorytetow"<<endl;
cout << "9.  exit"<<endl;
cout << "---------------------------"<<endl;
cout << "Wybor: ";
cin >> wybor;

	switch (wybor)
	{
        case 1:  push_front(); break;
        case 2:  push_front1();  break;
        case 3:  push_front2();  break;
        case 4:  push_front3();   break;
        case 5:  size();       break;
        case 6:  empty();      break;
        case 7:  pop_front();     break;
        case 8:  sort();       break;
        case 9:  exit();       break;


        default:
        cout<<"POMYLKA!";
        Sleep(2000);
        break;
	}

}
}
while(wybor!=9);




	return 0;
}
