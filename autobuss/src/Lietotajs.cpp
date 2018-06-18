#include "Lietotajs.h"
#include <iostream>
#include <string>
#include <fstream>
Lietotajs::Lietotajs()
{
    //ctor
}

Lietotajs::~Lietotajs()
{
    //dtor
}

void Lietotajs::paraditSarakstu(string nosaukums){//kaut kada faila informacijas izvade uz ekrana
	string line;
	ifstream file(string(string(nosaukums)).c_str());
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

