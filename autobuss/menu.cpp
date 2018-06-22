using namespace std;
#include <iostream>
#include "menu.h"
#include <windows.h>

void printMenu(){
   cout<<"-----------------------------------------------------"<<endl;
   cout<<"Menu:"<<endl;
   cout<<"1)Admin"<<endl;
   cout<<"2)User"<<endl;
   cout<<"3)Paskatities sev  vajadzigo informaciju(par so uznemumu vai par autobusu marsrutiem "<<endl;
   cout<<"4)Lietotaja registresana"<<endl;
   cout<<"5)Iziet no programmas"<<endl;
   cout<<"-----------------------------------------------------"<<endl;
}

void setColor(int text){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD) text);
}
void viesisMenu(){
    cout <<"Jus iegajat ka viesis, Ecolines aplikacija:" << endl;
    cout<<"1)Paradit sarakstu(ieksvalsts)"<<endl;
    cout<<"2)Paradit Sarakstu Starptautiskiem vilcieniem"<<endl;
    cout<<"3)Iziet no Viesu menu"<<endl;
    cout<<"4)Paradit informaciju par uznemumu"<<endl;
    cout<<"5)Paskatities atsauksmes par so uznemumu"<<endl;
}
void adminMenu(){
    cout<<"Jus iegajat ka Admin, Ecolines aplikacija:"<<endl;
    cout<<"1)Marsrutu(sarakstu) redigesana un pievienosana"<<endl;
    cout<<"2)Darbibas ar klientiem(profilu redigesana un apskate)"<<endl;
    cout<<"3)Uznemuma informacijas redigesana un pievienosana"<<endl;
    cout<<"4)Statistikas apskate(lietotaju var marsrutu)"<<endl;
    cout<<"5)Atlaizu pievienosana(redigesana un dzesana)"<<endl;
    cout<<"6)Iziet no AdminMenu"<<endl;
    cout<<"7)Darbibas ar bilesu pirkumu vesturi"<<endl;
    cout<<"8)Darbibas ar atsauksmem"<<endl;
}

void adminUznemumsMenu(){
    cout<<"1)Paskatities informaciju par so uznemumu"<<endl;
    cout<<"2)Aiziet uz informacijas labosanu"<<endl;
    cout<<"3)Pievienot informaciju par uznemumu"<<endl;
    cout<<"4)Iziesana atpakal uz AdminMenu galveno logu"<<endl;
}

void printMenuAdminlabosana(){//Izvelamies vienu no menu darbibam
    cout<<"1)Rediget vardu "<<endl;
    cout<<"2)Dzest viss kas ir faila"<<endl;
    cout<<"3)Dzest rindu"<<endl;
    cout<<"4)Iziet no labosanas"<<endl;
}

void adminMenuProfili(){
    cout<<"1)Paskatitities visus profilus(klientus)"<<endl;
    cout<<"2)Aiziet uz profilu labosanu"<<endl;
    cout<<"3)Profilu blokesana"<<endl;
    cout<<"4)Iziesana atpakal uz AdminMenu galveno logu"<<endl;
    cout<<"5)Nonemt profila blokesanu"<<endl;
}
void adminMenuVesture(){
    cout<<"1)Paskatities bilesu vesturi"<<endl;
    cout<<"2)Dzest vesturi"<<endl;
    cout<<"3)Iziesana atpakal uz AdminMenu galveno logu"<<endl;
}

void adminMenuSaraksti(){
    cout<<"1)Aiziet uz latvijas  sarakstu darbibam(skatisana, labosana)"<<endl;
    cout<<"2)Aiziet uz starptautisko sarakstu darbibam(skatisana, labosana)"<<endl;
    cout<<"3)Iziesana uz AdminMenu galveno logu"<<endl;
}

void adminMenuSarakstilv(){
    cout<<"1)Paskatities sarakstu"<<endl;
    cout<<"2)Aiziet uz to labosanu"<<endl;
    cout<<"3)Iziesana uz AdminMenu galveno logu"<<endl;
    cout<<"4)Pievienot sarakstu"<<endl;
}
void adminMenuSarakstistarp(){
    cout<<"1)Paskatities sarakstu"<<endl;
    cout<<"2)Aiziet uz to labosanu"<<endl;
    cout<<"3)Iziesana uz AdminMenu galveno logu"<<endl;
    cout<<"4)Pievienot sarakstu"<<endl;
}

void adminMenuAtlaides(){
    cout<<"1)Izdzest visas atlaides"<<endl;
    cout<<"2)Pievienot atlaides katrai cilveka grupai(berniem, invalidiem, pensionariem un studentiem)."<<endl;
    cout<<"3)Iziesana uz AdminMenu galveno logu"<<endl;
}

void adminStatistika(){
    cout<<"1)Paskatities  statistiku prieks lietotajiem"<<endl;
    cout<<"2)Paskatities statistiku prieks marsrutiem(ieks latvijas un starptautiskus"<<endl;
    cout<<"3)Iziesana atpakal uz AdminMenu galveno logu"<<endl;
}

void klientsMenu(){
    cout << "1)Paradit vietejo sarakstu" << endl;
	cout << "2)Paradit sarakstu Starptautiskiem vilcieniem" << endl;
	cout << "3)Paradit savu biletes rezervaciju(rezervacijas)" << endl;
	cout << "4)Paradit informaciju par sevi" << endl;
	cout << "5)Pievienot kontu" << endl;
	cout << "6)Nopirkt bileti(vispirms atrast sev vajadzigo marsrutu, izmantojot meklesanas nosacijumus)" << endl;
	cout << "7)Mainit paroli" << endl;
	cout <<"8)Paradit savu kontu" << endl;
	cout<<"9)Iziet no jusu kabineta"<<endl;
}
void klientsMenumeklesana(){
    cout<<"Meklesanas nosacijumi:"<<endl;
    cout<<"1)Meklet pec Autobusa numura"<<endl;
    cout<<"2)Meklesana pec marsruta"<<endl;
    cout<<"3)Meklesana pec Brauciena cenas"<<endl;
}
void klientsMenuMarsruti(){
    cout<<"1)Meklet pec vilciena numura"<<endl;
    cout<<"2)Meklet pec vilciena atiesanas laika"<<endl;
}
void adminMenuatsauksmes(){
    cout<<"1)Paskatities atsauksmes par uznemumu"<<endl;
    cout<<"2)Dzest vesturi"<<endl;
    cout<<"3)Iziesana atpakal uz AdminMenu galveno logu"<<endl;
}
