#include "Konts.h"
#include <iostream>
#include "Admiin.h"
#include "Lietotajs.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>

Konts::Kontss(string  kontaNumurs,string personalID){//konstruktors prieks konta
	this->setKontaNumurs(kontaNumurs,personalID);
}


void Konts::pievienot_Kontu(string kontaNumurs,string personalID ){//konta pievienosana
string nosaukums;
int izvele;
    nosaukums=personalID+"-Konts.txt";
    ifstream file(nosaukums);
        if (file.peek() == ifstream::traits_type::eof()){
            cout<<"Konts vel netika izveidots!Vai jus gribat aiziet uz konta izveidosanu?(1-ja, 0-ne)"<<endl;
        }else{
            cout<<"Konts ir jau izveidots. Vai jus gribat turpinat, jo jas saksiet ievadit datus, tad jusu pasreizejais konts tiks parrakstits(1-ja, 0-ne)"<<endl;
        }
    cin>>izvele;
    if(izvele==0){
        cout<<"Konts netika izveidots!"<<endl;
    }else{
        int  ID=rand() % 100000;
        stringstream ss;
        ss << ID;
        kontaNumurs = ss.str();
        setKontaNumurs(kontaNumurs, personalID);
        cout<<"Konts tika izveidots!"<<endl;
    }
}

void Konts::setKontaNumurs(string kontaNumurs, string personalID){//dodam konta parametru
    int a;
    string k;
    string f;
    long random(void);
    f=personalID;
    k="-Konts.txt";
	ofstream file(string(string(f)+k).c_str());
    cout<<"Ievadiet naudas daudzumu sava konta"<<endl;
    cin>>a;
	file<<kontaNumurs<<","<<a<<" eiro"<<endl;
	file.close();
}

void Konts::paradit_Kontu(string personalID){//paradit kontu
    Lietotajs l;
    string nosaukums;
    nosaukums=personalID+"-Konts.txt";
    l.paraditSarakstu(nosaukums);
}
