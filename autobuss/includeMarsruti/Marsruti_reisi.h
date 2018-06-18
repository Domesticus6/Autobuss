#ifndef MARSRUTI_REISI_H
#define MARSRUTI_REISI_H
#include <string>
using namespace std;
class Marsruti_reisi{
    public:
        Marsruti_reisi();
        virtual ~Marsruti_reisi();

        void pievienot(string);
        Marsruti_reisi(string,string,string,string,string);
        void setAutobusaNumurs(string, string);
        void setMarsruts(string, string);
        void setLaiks(string, string);
        void setCena(string, string);
        void setBilesuskaits(string, string);
    protected:
    private:
        string autobusaNumurs;
        string marsruts;
        string laiks;
        string cena;
        string nosaukums;
};

#endif // MARSRUTI_REISI_H
