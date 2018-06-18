#include "Admiin.h"
#include "../menu.h"
#include "Lietotajs.h"
#include "../includeMarsruti/Marsruti_reisi.h"
using namespace std;
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <cstring>
Admiin::Admiin()
{
    //ctor
}

Admiin::~Admiin()
{
    //dtor
}

void Admiin::admin(){
int error, izvele, repeat;
string s, parole;
Admiin a;
do{
    error=0;
    cout<<"Ievadiet paroli:"<<endl;//parbaude uz paroli
    cin>>parole;
    ifstream file("AdminPasword.txt");
    while(getline(file,s)){
        if(parole==s){
            cout<<"Viss ir ok!"<<endl;
        }else{
            cout<<"Nepareiza parole"<<endl;
            error=1;}
    }
    file.close();
}while(error==1);
    error=0;
    system("cls");
    do{
        izvele=0;
    do{
        do{
            system("cls");
            adminMenu();
            cout<<"Ko gribat izdarit?"<<endl;
            cin>>izvele;
            switch (izvele){//AdminMenu izvelnu menu
            case 1:
                a.saraksts_menu(&repeat);
                break;
            case 2:
                a.klients_menu(&repeat);
                break;
            case 3:
                a.uznemums_menu(&repeat);
                break;
            case 4:
                a.statistika_menu(&repeat);
                break;
            case 5:
                atlaidess(&repeat);
                break;
            case 6:
                repeat=0;
                system("cls");
                break;
            case 7:{
                a.bilesu_vesture_menu(&repeat);
                break;
            }
            case 8:{
                a.atsauksmes_menu(&repeat);
                break;
            }
            default:
            cout<<"Kluda"<<endl;
            error=1;
            system("cls");
            }

        }while(repeat==1);

    }while(error==1);
    cout<<"Gribat vel kaut ko izdarit?(1-ja, 0-ne)"<<endl;
    cin>>izvele;
    }while(izvele==1);
    system("cls");
}


void Admiin::redigesanas_funkcija(const  char *name, const char *name_copy){//redigesanas funkcija(pamata, pa vardiem mainot rindas informaciju vai pilnigi dzesot faila saturu
string s, nosaukums;
Lietotajs l;
int izvele, izvele1,  izvele2;
cout<<"Ko gribi izlabot?"<<endl;
system("cls");
do{
        printMenuAdminlabosana();
        cin>>izvele;
        switch(izvele){
        case 1:{
            cout<<"Vai jus gribat paskatities faila informaciju(ja-1, ne-0)"<<endl;
            cin>>izvele1;
            if(izvele1==1){
               l.paraditSarakstu(nosaukums);
            }
            ifstream file(name);
            cout<<"Ievadi rindu   :"<<endl;
            int number_line_editing;
            cin>>number_line_editing;
            int i_number_line_now=0;
            ofstream output(name_copy);
            while(getline(file,s )){
                i_number_line_now++;
                if(i_number_line_now==number_line_editing){
                    string word_old;
                    string word_new;
                    cout<<"Ievadi veco vardu un jauno"<<endl;
                    cin >> word_old >> word_new;
                    size_t ind = s.find(word_old);
                    if (ind!=string::npos){
                            s.replace(ind,word_old.size(),word_new);
                    }
                }
                    output<<s<<endl;
            }

            file.close();
            output.close();
            ifstream gg(name_copy);
            ofstream filee(name);

            while (getline(gg,s)){
                filee<<s<<endl;
            }
            filee.close();
            break;
        }

        case 2:{
            cout<<"Vai jus gribat paskatities faila informaciju(ja-1, ne-0)"<<endl;
            cin>>izvele1;
            if(izvele1==1){
                l.paraditSarakstu(nosaukums);
            }

            ofstream output(name_copy);
            fstream file(name_copy, ios::out);
            file.close();
            output.close();
            ifstream gg(name_copy);
            ofstream filee(name);

            while (getline(gg,s)){
                filee<<s<<endl;
            }
            filee.close();
            break;
        }

        case 3:{
            cout<<"Vai jus gribat paskatities faila informaciju(ja-1, ne-0)"<<endl;
            cin>>izvele1;
            if(izvele1==1){
                l.paraditSarakstu(nosaukums);
            }

            ifstream file(name);
            cout<<"Ievadi rindu:"<<endl;
            int number_line_editing;
            cin>>number_line_editing;
            int   i_number_line_now=0;
            ofstream output(name_copy);

            while(getline(file,s )){//notiek noteiktas ievaditas rindas meklesana faila un visu rindu pareiza parvietosana faila(lai nebutu brivo rindu faila pec rindas(-du) dzesanu
                i_number_line_now++;
                if(i_number_line_now!=number_line_editing){
                    output<<s<<endl;
                }
            }

            file.close();
            output.close();
            ifstream gg(name_copy);//parrakstisana no copy faila uz galvenu failu
            ofstream filee(name);

            while (getline(gg,s)){
                filee<<s<<endl;
            }
            filee.close();
            break;
        }
        }

        cout<<"Gribat kaut ko vel izdarit?(ja-1,ne-0)"<<endl;//darbibas atkartosana AdminMenu
        cin>>izvele2;
        system("cls");
}while(izvele2==1);
}
/**void Marsruti_darbibas::sarakstu_pievienosana(const  char *name){
int id_line=0, error=0;
int id, atkartojums, sakumlaiks, beigulaiks,  cena;
string sakumpunkts, galapunkts,s ;
do{
error==0;
    ifstream file(name);
    while(getline(file,s)){
        id_line++;
    }

    file.close();
    id= id_line;

    fflush(stdin);
    cout<<"Ievadi brauciena atiesanas punktu:"<<endl;
    getline(cin,sakumpunkts);

    fflush(stdin);
    cout<<"Ievadi brauciena galapunktu:"<<endl;
    getline(cin,galapunkts);

    do{
            error=0;
        fflush(stdin);
        cout<<"Ievadi brauciena atiesanas laiku(tikai stundas):"<<endl;
        cin>>sakumlaiks;
        if (sakumlaiks>0 && sakumlaiks<=24){
            cout<<"Viss ir ok!"<<endl;
        }else{
            system("cls");
            cout<<"Nepareizi ievaditais laiks!"<<endl;
            error=1;
        }
    }while(error==1);

    do{
        error=0;
        fflush(stdin);
        cout<<"Ievadi brauciena pieesanas laiku:"<<endl;
        cin>>beigulaiks;
        if (beigulaiks>0 && beigulaiks<=24){
            cout<<"Viss ir ok!"<<endl;
        }else{
            system("cls");
            cout<<"!"<<endl;
            error=1;
        }
    }while(error==1);

        do{
            error==0;
            fflush(stdin);
            cout<<"Ievadi brauciena cenu:"<<endl;
            cin>>cena;
            if (cena>=0 && sakumlaiks<=24){
                cout<<"Viss ir ok!"<<endl;
            }else{
                system("cls");
                cout<<"Nepareizi ievadita biletes cena"<<endl;
                error=1;
            }
        }while(error==1);

        fstream fout(name,ios::app);
        fout<<"Numurs "<<id+1<<" "<<sakumpunkts<<" - "<<galapunkts<<" Brauciena laiks: "<<sakumlaiks<<" - "<<beigulaiks<<", Brauciena cena: "<<cena<<" eiro"<<endl;
        fout.close();

        id++;//rindu vajag turpinat
        cout<<"Vai ju gribat ievadit informaciju nakamam marsrutam?(1-ja,0-ne)"<<endl;
        cin>>atkartojums;
}while(atkartojums);
}
**/
int Admiin::saraksts_menu(int *repeat){//braucienu menu
    int izvele, error, repeat1, repeat2;
do{
    error=0;
    system("cls");
    adminMenuSaraksti();
    cin>>izvele;
    switch(izvele){
    case 1:{
        sarakstslv(&repeat1);
        break;
    }
    case 2:{
        sarakstsstarpt(&repeat2);
        break;
    }
    case 3:{
    *repeat=1;
    exit;
    break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}

int  Admiin::sarakstsstarpt(int *repeat2){//menu prieks starptautiskiem marsrutiem
Marsruti_reisi m;
int izvele, error;
string nosaukums;
do{
    const char *name;
    const char *name_copy;
    error=0;
    system("cls");
     adminMenuSarakstistarp();
    cin>>izvele;
    switch(izvele){
    case 1:{
        nosaukums="starptsaraksts.txt";
        paraditSarakstu(nosaukums);
        break;
    }
    case 2:{
        string stringName ="starptsaraksts.txt" ;
        string stringName1 ="starptsaraksts_copy.txt" ;
        name = stringName.c_str();
        name_copy = stringName1.c_str();
        redigesanas_funkcija(name, name_copy);
        break;
    }
    case 3:{
    *repeat2=1;
    exit;
    break;
    }
    case 4:{
        string stringName ="starptsaraksts.txt" ;
        nosaukums = stringName.c_str();
       m.pievienot(nosaukums);
    }
    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}

int  Admiin::sarakstslv(int *repeat){//menu prieks marsrutiem ieks latvijas
int izvele, error;
Marsruti_reisi m;
string nosaukums;
do{
    const char *name;
    const char *name_copy;
    error=0;
    system("cls");
    adminMenuSarakstilv();
    cin>>izvele;
    switch(izvele){
    case 1:{
        paraditSarakstu(nosaukums);
        break;
    }
    case 2:{
        string stringName ="sarakstslv.txt" ;
        string stringName1 ="sarakstslv_copy.txt" ;
        name = stringName.c_str();
        name_copy = stringName1.c_str();
        redigesanas_funkcija(name, name_copy);
        break;
    }
    case 3:{
    *repeat=1;
    exit;
    break;
    }
    case 4:{
        string stringName ="sarakstslv.txt" ;
        nosaukums = stringName.c_str();
        m.pievienot(nosaukums);
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}


int Admiin::klients_menu(int *repeat){//klienta menu, seit mes varam paskatities lietotaju sarakstu, izmainit vinu informaciju, atbloket tos, vai ari nobloket
int izvele, error;
Admiin a;
string nosaukums;
char name[25], name1[25];
do{
const char *name;
const char *name1;
const char *name_copy;
error=0;
    system("cls");
    adminMenuProfili();
    cin>>izvele;
    switch(izvele){
    case 1:{
        nosaukums="lietotaji.txt";
        paraditSarakstu(nosaukums);
        break;
    }
    case 2:{
        string stringName ="lietotaji.txt" ;
        string stringName1 ="lietotaji_copy.txt" ;
        name = stringName.c_str();
        name_copy = stringName1.c_str();
        a.redigesanas_funkcija(name, name_copy);
        break;
    }
    case 3:{
        a.lietotaju_blokesana();
        break;
    }
    case 4:{
    *repeat=1;
    exit;
    break;
    }
    case 5:{
        string stringName ="blokesana.txt" ;
        string stringName1 ="pazinojums.txt" ;
        name = stringName.c_str();
        name1 = stringName1.c_str();
        a.lietotaju_atblokesana(name, name1);
    break;

    }
    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);

}

void Admiin::lietotaju_blokesana(){
int izvele;
string nosaukums;
Lietotajs l;
/**int izvele;
string line;
    cout<<"Vai jus gribat paskatities faila informaciju(ja-1, ne-0)"<<endl;
      cin>>izvele;
            if(izvele==1){
                paraditKlientusarakstu();}
    int line_now; int line_block;
    ifstream lietotaji("lietotaji.txt");
    fstream fout("blokesana.txt",ios::app);
    cout<<"Izvelies lietotaju::(rindu)";
    cin>>line_block;
    line_now=0;
    line_block=line_block-1;
    while (getline(lietotaji, line)){
        if(line_block!=line_now){}
        else{
            fout<<line<<endl;
            fout.close();
        }
          line_now++;
        }
 **/
 cout<<"Gribat paskatities Useru sarakstu?"<<endl;
 cin>>izvele;
 if(izvele==1){
    nosaukums="lietotaji.txt";
    l.paraditSarakstu(nosaukums);
 }
 string login, line;
 ifstream file("lietotaji.txt");
 fstream fout("blokesana.txt",ios::app);
	cout<<"Ievadi lietotaja vardu: "<<endl;
	cin>>login;
	while (getline(file,line)){
		if(line.find(login+" ")!=string::npos)
            fout<<line<<endl;

	}
fout.close();
file.close();
}

void Admiin::lietotaju_atblokesana(const char *name, const char *name1){
Lietotajs l;
string nosaukums;
nosaukums="pazinojums.txt";
string login, line, line1;
	cout<<"--------------------------------------------"<<endl;
	l.paraditSarakstu(nosaukums);
	cout<<"--------------------------------------------"<<endl;
	ifstream file1(name);
    ofstream outfile;
    ofstream outfile1;
    ifstream file(name1);
   cout<<"Ievadi lietotaja vardu: "<<endl;
	cin>>login;
	while (getline(file,line)){
		if(line.find(login+" ")!=string::npos){}
		else{
            outfile.open(name1);
			outfile<<line<<endl;
			outfile.close();
            }
	}
	while (getline(file1,line1)){
		if(line1.find("Lietotajs "+login+" ")!=string::npos){}
		else{
            outfile1.open(name);
			outfile1<<line1<<endl;
            outfile1.close();
            }

	}

	file1.close();
}
int Admiin::uznemums_menu(int *repeat){//menu prieks informacijas par uznemumu(tas redigesana, pievienosana in apskate)
int izvele, error;
const char *name;
const char *name_copy;
string nosaukums;
Admiin a;
do{

    error=0;
    system("cls");
    adminUznemumsMenu();
    cin>>izvele;
    switch(izvele){
    case 1:
        nosaukums="uznemums.txt";
        a.paraditSarakstu(nosaukums);
        break;
    case 2:{
        string stringName ="uznemums.txt" ;
        string stringName1 ="uznemums_copy.txt" ;
        name = stringName.c_str();
        name_copy = stringName1.c_str();
        redigesanas_funkcija(name, name_copy);
        break;
    }
    case 3:{
        string stringName ="uznemums.txt" ;
        name = stringName.c_str();
        informacijas_pievienosan_kompanija(name);
        break;
    }
    case 4:{
    *repeat=1;
    exit;
    break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);

}

void Admiin::informacijas_pievienosan_kompanija(const char *name){
string kompanija, gads ,klase, pasts, telefons, vieta, laiks;
int error, garums, garums1,cipars;
    cout<<"Par kompaniju informacijas ievadisana:"<<endl;
    fflush(stdin);
    cout<<"Ievadi informaciju par so kompaniju:"<<endl;
    getline(cin,kompanija);
    fflush(stdin);
    cout<<"Kompanijas kontaktu ievadisana:"<<endl;
    cout<<"Ievadi kompanijas e-pastu:"<<endl;
    getline(cin,pasts);
    do{
        error=0;
        garums=0;
        cout<<"Ievadi kompanijas telefonu:(+371)"<<endl;
        fflush(stdin);
        getline(cin,telefons);
        string str1 (telefons);
        string str=telefons;
        cipars=atoi(str.c_str());
        stringstream ss;
        ss << cipars;
        string str2 = ss.str();
        garums=str1.length();
        garums1=str2.length();
        if(garums!=garums1){
            cout<<"Tads talrunis neeksiste!(varbut jus ievadijat kaut kadu burtu) "<<endl;
            error=1;
        }else
            if(garums==8 ){
                cout<<"Telefona numurs ir derigs!"<<endl;
                error=0;
            }else{
                cout<<"Sis telefona numurs nav derigs!"<<endl;
                error=1;
            }
    }while(error==1);

        fflush(stdin);
        cout<<"Ievadi ofisa atrasanas vietu:"<<endl;
        getline(cin,vieta);
        fflush(stdin);
        cout<<"Ievadi ofisa darba laiku:"<<endl;
        getline(cin,laiks);
        fstream fout2(name,ios::app);
        fout2<<"Par mums:"<<endl;
        fout2<<kompanija<<endl;
        fout2<<"Kontakti:"<<endl;
        fout2<<"Musu e-pasts: "<<pasts<<endl;
        fout2<<"Musu telefons: "<<telefons<<endl;
        fout2<<"Ofisa atrasanas vieta: "<<vieta<<endl;
        fout2<<"Ofisa darba laiks"<<laiks<<endl;
}

int Admiin::statistika_menu(int *repeat){//statistikas menu prieks lietotajiem un marsrutiem
    int error, izvele;
   do{
    error=0;
    system("cls");
    adminStatistika();
    cin>>izvele;
    switch(izvele){
    case 1:{
        statistika_user();
        break;
    }
    case 2:{
        statistika_marsruti();
        break;
    }
    case 3:{
    *repeat=1;
    exit;
    break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
system ("pause");
        system("cls");
}

void Admiin::statistika_user(){
int daudzums=0;
string s;
    ifstream file("lietotaji.txt");
	while (getline(file, s)) {
		daudzums++;
	}
	cout<<"Lietotaju daudzums: "<<daudzums<<endl;
	file.close();
	cout<<"Lietotaju saraksts:"<<endl;
    cout<<"--------------------------------------"<<endl;
    ifstream file1("lietotaji.txt");
    while(getline(file1,s)){
        cout<<s<<endl;
    }
    cout<<"--------------------------------------"<<endl;
    file1.close();
    	cout<<"Bloketo lietotaju saraksts:"<<endl;
    cout<<"-------------------------------------"<<endl;
     ifstream file2("blokesana.txt");
	while (getline(file2, s)) {
		 cout<<s<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	file2.close();
}

void Admiin::statistika_marsruti(){
int daudzums=0;
string nosaukums;
string s;
    ifstream file("sarakstslv.txt");
	while (getline(file, s)) {
		daudzums++;
	}
	cout<<"Braucienu  daudzums Latvijas saraksta: "<<daudzums<<endl;
	file.close();

	cout<<"Vietejo braucienu saraksts:"<<endl;
    cout<<"--------------------------------------"<<endl;
    nosaukums="sarakstslv.txt";
    paraditSarakstu(nosaukums);

    ifstream file1("starptsaraksts.txt");
	while (getline(file1, s)) {
		daudzums++;
	}
	cout<<"Braucienu  daudzums starptautiska saraksta: "<<daudzums<<endl;
	file1.close();

	cout<<"Starptautisko braucienu saraksts:"<<endl;
    cout<<"--------------------------------------"<<endl;
    nosaukums="starptsaraksts.txt";
    paraditSarakstu(nosaukums);
}

int Admiin::atlaidess(int *repeat){//atlaides menu, kur mes varam pievienot atlaides, labot tas vai parskatit
    int error, izvele;
do{
    const char *name;
    const char *name1;
    error=0;
    system("cls");
    adminMenuAtlaides();
    cin>>izvele;
    switch(izvele){
    case 1:{
        atlaides_labosana();
        break;
    }
    case 2:{
        string stringName ="atlaides.txt" ;
        string stringName1 ="atlaides2.txt" ;
        name = stringName.c_str();
        name1 = stringName1.c_str();
        atlaides_pievienosana(name,name1);
        break;
    }
    case 3:{
    *repeat=1;
    exit;
    break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}

void Admiin::atlaides_pievienosana(const char *name, const char *name1){
int  error=0;
string cena,cena1, cena2, cena3;
error==0;
    fflush(stdin);
    cout<<"Ievadi atlaidi studentiem:"<<endl;
    getline(cin,cena);

    fflush(stdin);
    cout<<"Ievadi atlaidi berniem:"<<endl;
    getline(cin,cena1);

    fflush(stdin);
    cout<<"Ievadi atlaidi pensionariem:"<<endl;
    getline(cin,cena2);

    fflush(stdin);
    cout<<"Ievadi atlaidi invalidiem:"<<endl;
    getline(cin,cena3);

    fstream fout(name,ios_base::out | ios_base::trunc);
    fstream fout1(name1,ios_base::out | ios_base::trunc);
    fout<<"Atlaide invalidiem:"<<cena3<<endl;
    fout<<"Atlaide pensionariem:"<<cena2<<endl;
    fout<<"Atlaide berniem:"<<cena1<<endl;
    fout<<"Atlaide studentiem:"<<cena<<endl;
    fout.close();
    fout1<<cena3<<endl;
    fout1<<cena2<<endl;
    fout1<<cena1<<endl;
    fout1<<cena<<endl;
    fout1.close();
}
int  Admiin::bilesu_vesture_menu(int *repeat){
int izvele, error;
string nosaukums;
Admiin a;
do{
error=0;
    system("cls");
    adminMenuVesture();
    cin>>izvele;
    switch(izvele){
    case 1:{
        nosaukums="vesture.txt";
        a.paraditSarakstu(nosaukums);
        break;
    }
    case 2:{
        vestures_labosana();
        break;
    }
    case 3:{
    *repeat=1;
    exit;
    break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}
void Admiin::atlaides_labosana(){
	fstream clear_vesture("atlaides.txt", ios::out);
    clear_vesture.close();

    fstream clear_vesture1("atlaides2.txt", ios::out);
    clear_vesture1.close();
}


void Admiin::vestures_labosana(){
    fstream clear_vesture("vesture.txt", ios::out);
    clear_vesture.close();
}

int  Admiin::atsauksmes_menu(int *repeat){//atsauksmju menu seit mes varam apskatit vai izdzest atsauksmes
int izvele, error;
string nosaukums;
Lietotajs l;
do{
error=0;
    system("cls");
    adminMenuatsauksmes();
    cin>>izvele;
    switch(izvele){
    case 1:{
        nosaukums="atsauksmes.txt";
        l.paraditSarakstu(nosaukums);
        break;
    }
    case 2:{
        atsauksmes_labosana();
        break;
    }
    case 3:{
        *repeat=1;
        exit;
        break;
    }

    default:
        cout<<"Kluda"<<endl;
        error=1;
        system("cls");
    }
}while(error==1);
}

void Admiin::atsauksmes_labosana(){
    fstream clear_atsauksmes("atsauksmes.txt", ios::out);
    clear_atsauksmes.close();
}

