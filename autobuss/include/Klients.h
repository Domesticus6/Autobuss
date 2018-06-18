#ifndef KLIENTS_H
#define KLIENTS_H

#include <Lietotajs.h>


class Klients : public Lietotajs
{
    public:
        Klients();
        virtual ~Klients();
        void registresana();
        void read_login(string);
        void read(string , string, string, string , string );
        void information(string);
        void read_id(string);
        void meklesana_rezervacijastaisisanasmenu(string, string, string, string);
        void meklesana_rezervacija(string, string, string,string);
        void biletes_pirksana(string, string, string);
        void rezervacija(string);
        void rezervacijas_drukasana();
        void lietotajs_menu();
        void rezervacijas_meklesana(string);
        void mainit_paroli(string,string,string);
    protected:
    private:
};

#endif // KLIENTS_H
