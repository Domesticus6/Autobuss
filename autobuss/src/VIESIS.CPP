#include "Viesis.h"
#include "../menu.h"
#include "Lietotajs.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
Viesis::Viesis()
{
    //ctor
}

Viesis::~Viesis()
{
    //dtor
}

void Viesis::viesis(){//viesu menu
int izvele;
string nosaukums;
    viesisMenu();
    cin >> izvele;
    switch(izvele){
        case 1:{//ieks latvias saraksta izvade
            nosaukums="sarakstslv.txt";
            paraditSarakstu(nosaukums);
            system ("pause");
            system("cls");
			break;
        }
        case 2:{//starptaitiska saraksta izvade
            nosaukums="starptsaraksts.txt";
            paraditSarakstu(nosaukums);
            system ("pause");
            system("cls");
			break;
        }
        case 3:{
            system("cls");
            break;
        }
        case 4:{//informacija par iznemumu izvade
            nosaukums="uznemums.txt";
            paraditSarakstu(nosaukums);
            system ("pause");
            system("cls");
            break;
        }
        case 5:{//atsauksmju par uznemumu izvade
            nosaukums="atsauksmes.txt";
            paraditSarakstu(nosaukums);
            system ("pause");
            system("cls");
            break;
        }
        default:
            cout<<"Kluda!"<<endl;
    }
}
