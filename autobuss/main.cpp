#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "../menu.h"
#include "include\Lietotajs.h"
#include "include\Viesis.h"
#include "include\Admiin.h"
#include "include\Klients.h"
#include <time.h>
using namespace std;
int main(){
Viesis v;
Klients k;
Admiin a;
int izvele;
int atkartot;
do{
izvele==0;
    const int NotUsed = system( "color 2F" );//prieks krasaina pazinojuma izvadisanas uz ekrana
    char word[] = "Ecolines";
    for (int i = 0, j = 2; word[i] != '\0'; i++, j++){
       setColor(j);
       cout << word[i];
    }
    cout<<endl;
    time_t rawtime;
    struct tm *timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"Current local time and date: "<<asctime (timeinfo)<<endl;;
    setColor(15);
    printMenu();
    cin>>izvele;
    switch (izvele){//galvena menu izvelne
        case 1:
            system("cls");
            a.admin();
            break;
        case 2:
            system("cls");
            k.lietotajs_menu();
            break;
        case 3:
            system("cls");
            v.viesis();
            break;
        case 4:
            k.registresana();
            break;
        case 5:
            cout<<"Ata!!"<<endl;
            break;

        default:
        cout<<"Kluda"<<endl;
        system("cls");
    }
}while(izvele!=5);
return 0;
}
