#ifndef KONTS_H
#define KONTS_H
using namespace std;
#include <string>
class Konts{
    public:
        Kontss(string, string);
        void pievienot_Kontu(string,string);
		void setKontaNumurs(string,string);
		void paradit_Kontu(string);
    protected:
    private:
        string personalID;
        string kontaNumurs;
};

#endif // KONTS_H
