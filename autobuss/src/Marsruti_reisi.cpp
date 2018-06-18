#include "Marsruti_reisi.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
Marsruti_reisi::Marsruti_reisi()
{
    //ctor
}

Marsruti_reisi::~Marsruti_reisi()
{
    //dtor
}
void Marsruti_reisi::pievienot(string nosaukums){//marsrutu pievienosana
    string vilcienaNumurs, marsruts, laiks, cena, skaits;
    int cena2, skaits2, error=0;
	cout<<"Ievadi autobusa numuru: ";
	cin>> autobusaNumurs;
	cout<<"Ievadi marsrutu: ";
	cin>> marsruts;
	cout<<"Ievadi laiku: ";
	cin>>laiks;
	do{
        error=0;
        cout<<"Ievadi cenu(parasta): ";
        cin>> cena2;
        if(cena2>0){
            stringstream ss;
            ss << cena2;
            cena = ss.str();
        }else{
            cout<<"Tada brauciena cenas nevar but!"<<endl;
            error=1;
        }
	}while(error==1);

	do{
	    error=0;
    	cout<<"Ievadi bilesu skaitu: "<<endl;
        cin>>skaits2;
        if(skaits2>0){
            stringstream ss1;
            ss1 << skaits2;
            skaits = ss1.str();
        }else{
            cout<<"Tada bilesu skaita nevar but!"<<endl;
            error=1;
	}
	}while(error==1);

    setAutobusaNumurs(autobusaNumurs,nosaukums);
    setMarsruts(marsruts,nosaukums);
	setLaiks(laiks,nosaukums);
	setCena(cena,nosaukums);
	setBilesuskaits(skaits,nosaukums);
}


void Marsruti_reisi::setAutobusaNumurs(string autobusaNumurs,string nosaukums){//marsrutu parametri
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Numurs: "<<autobusaNumurs<<", ";
	file.close();
}

void Marsruti_reisi::setMarsruts(string marsruts,string nosaukums){//marsrutu parametri
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Marsruts: "<<marsruts<<", ";
	file.close();
}

void Marsruti_reisi::setLaiks(string laiks,string nosaukums){//marsrutu parametri
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Laiks: "<<laiks<<", ";
	file.close();
}

void Marsruti_reisi::setCena(string cena,string nosaukums){//marsrutu parametri
	ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Brauciena cena(parasta): "<<cena<<" eiro, ";
	file.close();
}

void Marsruti_reisi::setBilesuskaits(string skaits, string nosaukums){//marsrutu parametri
    ofstream file(string(string(nosaukums)).c_str(),ios::app);
	file<<"Bilesu skaits: "<<skaits<<" "<<endl;
	file.close();
}



