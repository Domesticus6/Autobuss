#include "Klients.h"
using namespace std;
#include <iostream>
#include <fstream>
#include "../includeKonts/Konts.h"
#include <string>
#include "../menu.h"
#include <windows.h>
#include <sstream>
#include <time.h>
Klients::Klients()
{
    //ctor
}

Klients::~Klients()
{
    //dtor
}

struct Users{//truktura prieks lietotaja registresanas un iesnas ieks vina kabineta
string login ,parole,email, personalID, vards, uzvards;
int telefons;
}users[1000];

void Klients::read(string login, string parole, string personalID, string vards, string uzvards){//mekle ievaditus lietotaja datus prieks ieesanas oeks lietotaja kabineta
    ifstream fin ("lietotaji.txt");
    for (int i =0;i<1000;i++){
        fin>>users[i].login>>users[i].parole>>users[i].personalID>>users[i].vards>>users[i].uzvards;
    }
}

void Klients::registresana()//lietotaja registresana kur ir parbaude uz lietotaja login un personas koda sakrisanu
{
	string vards;
	string uzvards;
	string login;
	string parole;
	string personalID;

    bool flagg = true;
    do{
        flagg=true;
        cout<<"Ievadit login "<<endl;
	    cin>>login;
	    read_login(login);
	    for(int i=0;i<1000;i++){
	       if (login==users[i].login){
	           cout<<"Tads lietotajs  ar tadu loginu jau eksiste! "<<endl;
	           flagg=false;
	       break;
	       }
        }
    }while(!flagg);
	    cout<<"Ievadiet paroli"<<endl;
	    cin>>parole;
	    do{
        flagg = true;
	    cout<<"Ievadit personalID "<<endl;
	    cin>>personalID;
	    read_id(personalID);
	    for(int i=0;i<1000;i++){
	       if (personalID==users[i].personalID){
	           cout<<"Tads lietotajs ar tadu id jau eksiste! "<<endl;
	           flagg=false;
	       break;
	       }
	    }
	    }while(!flagg);
        cout<<"Ievadiet savu vardu"<<endl;
        cin>>vards;
        cout<<"Ievadiet savu uzvardu"<<endl;
        cin>>uzvards;

	    fstream fout("lietotaji.txt",ios::app);
	    fout<<login<<" "<<parole<<" "<<personalID<<" "<<vards<<" "<<uzvards<<endl;
	    cout<<"Regestracija bija veiksmiga"<<endl;
	    Sleep(1000);
	    system("cls");
}
void Klients::read_login(string login){//mekle lietotaja login, tas ir vajadzigs prieks parbaudes uz lietotaju sakrisanu
	ifstream fin("lietotaji.txt");
    for(int i=0;i<1000;i++){
        fin>>users[i].login;
    }
    fin.close();
}
void Klients::read_id(string personalID){//mekle lietotaja personas kodu, tas ir vajadzigs prieks parbauded uz lietotaja sakrisanu
	ifstream fin("lietotaji.txt");
    for(int i=0;i<1000;i++){
        fin>>users[i].personalID;
    }
    fin.close();
}

void Klients::lietotajs_menu(){
Klients k;
Konts k1;
int izvele, error, izvele2=0;
string login, tell,line, personalID, parole, vards, uzvards, kontaNumurs;

      system("cls");
    cout<<"Ievadiet login "<<endl;//paroles un logina ievadisana prieks ieesanas UserMenu
    cin>>login;
    cout<<"Ievadiet paroli"<<endl;
    cin>>parole;
    cout<<"Ievadiet personas kodu"<<endl;
    cin>>personalID;
    read(login, parole, personalID, vards, uzvards);
    system("cls");
    bool flag=true;
    for(int i=0;i<1000;i++){
        if (login==users[i].login && parole==users[i].parole  && personalID==users[i].personalID){//ievaditu datu parbaude
            fstream file("blokesana.txt");//ja esi blokets, tad nevaresi ieet sava kabineta un tev vajadzes aizsutit pazinojumu adminam, lai vins tevi atbloketu
            while (getline(file,line)){
                if(line.find(login+" ")!=string::npos){
                    system("cls");
                    cout<<"Opa kluda!"<<endl;
                    cout<<"Sis lietotajs ir blokets!"<<endl;
                    cout<<"Pameginiet velreiz ielogoties vai paprasiet Adminam nonemt blokesanu(1-ja un 0-ne)"<<endl;
                    cin>>izvele;
                    error=1;
                    if(izvele==1){
                        fstream fout("pazinojums.txt",ios::app);
                        fout<<"Lietotajs "<<login<<" prasa jus vinu atbloket"<<endl;
                        fout.close();
                    }
                    break;
                }
            }
            system("pause");
        if(error!=1){
        do{

            izvele=0;
            cout<<"Jus iegajat ka "<<login<<" Lietotajs, Jums ir piejejamas sadas funkcijas:"<<endl;
            klientsMenu();
            cin>>izvele;
            string nosaukums, nosaukums2, nosaukums3;
            switch(izvele){
            case 1:{
                nosaukums="sarakstslv.txt";
                paraditSarakstu(nosaukums);
                break;
            }
            case 2:{
                nosaukums="starptsaraksts.txt";
                paraditSarakstu(nosaukums);
                break;
            }
            case 3:{
                k.rezervacijas_meklesana(personalID);
                break;
            }
            case 4:{
                k.information(login);
                break;
            }
            case 5:{
                cout<<"Pazinojums: Ja jus ievadisiet konta informaciju atkal, tad jusu pasreizejais konts tiks pilnigi parrakstits!"<<endl;
                k1.pievienot_Kontu(kontaNumurs,personalID);
                break;
            }
            case 6:{
                meklesana_rezervacijastaisisanasmenu(personalID, nosaukums, nosaukums2, nosaukums3);
                break;
            }
            case 7:{
                k.mainit_paroli(login, parole, personalID);
                break;
            }
            case 8:{
                k1.paradit_Kontu(personalID);
                break;
            }
               case 9:{
                cout<<"Ata!"<<endl;
                system("cls");
                break;
            }
            default:
            cout<<"Kluda"<<endl;
            }
            cout<<"Gribat kaut ko vel izdarit?(ja-1,ne-0)"<<endl;
            cin>>izvele2;
            system("cls");
        }while(izvele2==1);

        flag=false;
        system("cls");
        }else{
        cout<<"Lai jums veicas!"<<endl;
    }
        }
        }

        system("cls");
        if(error!=1)
    if (flag){
            system("cls");
        cout<<"Nepareizs login vai parole"<<endl;

    }

}
void Klients::meklesana_rezervacijastaisisanasmenu(string personalID, string nosaukums, string nosaukums2, string nosaukums3){//biletes rezervacijas galvena menu,kur atrodas meklesanas un pirksanas funkcijas
    string line;
    int izvele, izvele1;
    cout<<"Kadu marsrutu veidu  gribi izveleties?(prieks biletes pirksanas)"<<endl;
    cout<<"1-Vietejos braucienus"<<endl;
    cout<<"2-Starptautiskos braucienus"<<endl;
    cin>>izvele;
    switch(izvele){
    case 1: {
        do{
	    nosaukums="sarakstslv.txt";
	    nosaukums2="sarakstslv_copy2.txt";
	    nosaukums3="sarakstslv_copy22.txt";
        meklesana_rezervacija(nosaukums, personalID, nosaukums2, nosaukums3);
        cout<<"Meklet vel?(1-ja, 0-ne)"<<endl;
        cin>>izvele1;
        }while(izvele1==1);
        ifstream saraksts(nosaukums2);{
                while (getline(saraksts, line)){
                    cout<<line<<endl;
                }
                saraksts.close();
        }
        biletes_pirksana(personalID,nosaukums2,nosaukums3);
        break;
    }

    case 2:{
        do{
        nosaukums="starptsaraksts.txt";
        nosaukums2="starptsaraksts_copy2.txt";
        nosaukums3="starptsaraksts_copy22.txt";
        meklesana_rezervacija(nosaukums, personalID, nosaukums2, nosaukums3);
        cout<<"Meklet vel?(1-ja, 0-ne)"<<endl;
        cin>>izvele1;
        }while(izvele1==1);
        ifstream saraksts(nosaukums2);{
                while (getline(saraksts, line)){
                    cout<<line<<endl;
                }
                saraksts.close();
        }
        biletes_pirksana(personalID,nosaukums2,nosaukums3);
        break;
       }
}
}

void Klients::meklesana_rezervacija(string nosaukums, string personalID, string nosaukums2, string nosaukums3){//vajadziga prieks lietotaja datu meklesana
int izvele, i;
string line;
cout<<"Ko jus gribat meklet?"<<endl;
klientsMenumeklesana();
cin>>izvele;
    switch(izvele){
    case 1:{
        i=0;
        string autobusaNumurs;
        cout<<"Ievadiet autobusa numuru:"<<endl;
        cin>>autobusaNumurs;
        ifstream file(nosaukums);
        if (file.peek() == ifstream::traits_type::eof())
            cout<<"Nav neviena marsruta!"<<endl;
        else{
            ofstream output(nosaukums2);
            while(getline(file,line)){
            if (line.find("Numurs: "+autobusaNumurs)!=string::npos){
                i++;
                cout<<line<<endl;
                output<<i<<")"<<line<<endl;
            }
            }
        file.close();
        output.close();
        }
        break;
    }
    case 2:{
        i=0;
        string marsruts;
        cout<<"Ievadiet autobusa marsrutu (piem. Riga-Liepaja):"<<endl;
        cin>>marsruts;
        ifstream file(nosaukums);
        if (file.peek() == ifstream::traits_type::eof())
            cout<<"Nav neviena marsruta!"<<endl;
        else{
            ofstream output(nosaukums2);
            while(getline(file,line)){
            if (line.find("Marsruts: "+marsruts)!=string::npos){
                i++;
                cout<<line<<endl;
                output<<i<<")"<<line<<endl;
            }
            }
        file.close();
        output.close();
        break;
        }
    }
    case 3:{
    i=0;
    string cena;
        cout<<"Ievadiet autobusa marsruta cenu (piem. 12):"<<endl;
        cin>>cena;
        ifstream file(nosaukums);
        if (file.peek() == ifstream::traits_type::eof())
            cout<<"Nav neviena marsruta!"<<endl;
        else{
            ofstream output(nosaukums);
            while(getline(file,line)){
            if (line.find("Brauciena cena(parasta): "+cena)!=string::npos){
                i++;
                cout<<line<<endl;
                output<<i<<" "<<line<<endl;
            }
            }
        file.close();
        output.close();
        break;
    }
    }
    }
}
void Klients::biletes_pirksana(string personalID, string nosaukums2, string nosaukums3){//biletes pirksana:vajadziga marsruta izvele, datu ievadisana, biletes drukasana un atsauksmes par uznemumu atstasana
string line;
int line_number_now;
int line_number_chose, error=0, reizes=0;
do{
    ofstream fout(nosaukums3);
    ifstream saraksts(nosaukums2);

    reizes=0;
    error=0;
    cout<<"Kadu marsrutu jus gribat izveleties?"<<endl;
    cin>>line_number_chose;
    fflush(stdin);
    line_number_now=0;
		while(getline(saraksts,line)){
			line_number_now++;
        if (line_number_now==line_number_chose){
            fout<<line;
            reizes++;
		}
		}
		if(reizes==0){
            cout<<"Tada izveleta marsruta nav, meginiet velreiz!"<<endl;
            error=1;
		}else{
            cout<<"Viss ir ok!"<<endl;
		}
        fout.close();
        saraksts.close();
}while(error==1);

ifstream atlaide("atlaides2.txt");
string atlaidee, atlaide2, atlaide3, atlaide4, line2;
int skaits1, skaits2, skaits3, skaits4;
        line_number_now=0;
        cout<<"Cik biletes jus gribat nopirkt berniem?"<<endl;
        cin>>skaits1;
        while(getline(atlaide,atlaidee)){
            if(line_number_now == 1){
                cout<<atlaidee<<endl;
                break;
            }
            line_number_now++;
        }
        double atlaideee1;
        stringstream st;
        st << atlaidee;
        st >> atlaideee1;
        cout<<atlaideee1<<endl;
        atlaide.close();
        system("pause");
        /**
        line_number_now=0;
        cout<<"Cik biletes jus gribat nopirkt invalidiem?"<<endl;
        cin>>skaits2;
         while(getline(atlaide,line2)){
            line_number_now++;
        if(line_number_now==2){
            getline(atlaide,atlaide2);
            break;
        }
        }
        double atlaideee2;
        stringstream st1;
        st1 << atlaidee;
        st1 >> atlaideee2;
        cout<<atlaideee2<<endl;

        line_number_now=0;
        cout<<"Cik biletes jus gribat nopirkt pensionariem?"<<endl;
        cin>>skaits3;
         while(getline(atlaide,line2)){
            line_number_now++;
        if(line_number_now==3){
            getline(atlaide,atlaide3);
            break;
        }
        }
        double atlaideee3;
        stringstream st2;
        st2 << atlaidee;
        st2 >> atlaideee3;
        cout<<atlaide3<<endl;

        line_number_now=0;
        cout<<"Cik biletes jus gribat nopirkt studentiem?"<<endl;
        cin>>skaits4;
         while(getline(atlaide,line2)){
            line_number_now++;
        if(line_number_now==1){
            getline(atlaide,atlaide4);
            break;
        }
        }
        double atlaideee4;
        stringstream st3;
        st3 << atlaidee;
        st3 >> atlaideee4;
        cout<<atlaideee4<<endl;
        system("pause");
            double out;
            stringstream st11;

            st >> out;

            double nauda_nauda;
            nauda_nauda=out;
            cout<<nauda_nauda<<endl;

            string konta_numurs;
            string nauda_konta;
            string temp;

            temp=personalID+"-Konts.txt";
            ifstream konts(string(string(temp)).c_str());

            ofstream output("tempfile.txt");
            while (!konts.eof()){
                getline(konts,konta_numurs,',');
                getline (konts, nauda_konta);

                double outt;
                stringstream stt;
                stt << nauda_konta;
                stt >> outt;

                cout<<outt;
                if(outt>nauda_nauda){
                    double  summa;
                    summa=outt-nauda_nauda;
                    cout<<konta_numurs<<endl;
                    cout<<summa;
                    output<<konta_numurs<<","<<summa;
                    time_t rawtime;
                    struct tm *timeinfo;
                    time ( &rawtime );
                    timeinfo = localtime ( &rawtime );
                    ofstream vesture("vesture.txt",ios::app);
                    vesture<<"Lietotajs "<<temp<<" nopirka bileti"<<   ","<<","<< asctime(timeinfo)<<endl;
                }
                else{
                    cout<<"Nepietiek lidzekljus"<<endl;
                    break;
                }
            }
ifstream saraksts(nosaukums2);
	            konts.close();
	            output.close();
	            saraksts.close();
	            remove(temp.c_str());
	            rename("tempfile.txt",temp.c_str());

**/
}

void Klients::mainit_paroli(string login,string parole,string personalID){
    string  p_old,p_new;
    ifstream lietotaji("lietotaji.txt");
    ofstream lietotaji_temp("lietotaji_temp.txt");
    string line;
    while(getline(lietotaji,line)){
            if(line.find(login)!=string::npos && line.find(personalID)!=string::npos){
        cout<<"Ievadi  jauno paroli"<<endl;
        cin>> p_new;
        size_t ind = line.find(parole);
                if (ind!=string::npos){//ja ir atrsts
                  line.replace(ind,parole.size(),p_new);
                }
            }
                  lietotaji_temp<<line<<endl;

    }
    lietotaji.close();
    lietotaji_temp.close();
    remove("lietotaji.txt");
    rename ("lietotaji_temp.txt","lietotaji.txt");

}


void Klients::rezervacijas_meklesana(string personalID){//jusu rezervaciju meklesana pec jusu peronas koda
	ifstream file("rezervacijas.txt");
    string line;
		while (getline(file,line)){
			if(line.find(personalID+" ")!=string::npos)
				cout<<line<<endl;
		}
	file.close();
}

void Klients::information(string login){//jusu informacijaa izvadisana(par jums)
	ifstream file("lietotaji.txt");
		string line;
		while (getline(file,line)){
			if(line.find(login+" ")!=string::npos)
				cout<<line<<endl;
		}
	file.close();
}
