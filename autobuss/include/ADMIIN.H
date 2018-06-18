#ifndef ADMIIN_H
#define ADMIIN_H

#include <Lietotajs.h>


class Admiin : public Lietotajs{
    public:
        Admiin();
        virtual ~Admiin();
        void admin();
        saraksts_menu(int *);
        sarakstsstarpt(int *);
        sarakstslv(int *);
        void redigesanas_funkcija(const  char *, const char *);
        int uznemums_menu(int*);
        void informacijas_pievienosan_kompanija(const char*);
        int statistika_menu(int*);
        void statistika_user();
        void statistika_marsruti();
        void lietotaju_blokesana();
        void lietotaju_atblokesana(const char* , const char *);
        int klients_menu(int*);
        int atlaidess(int*);
        void atlaides_pievienosana(const char *, const char *);
        void atlaides_labosana();
        int bilesu_vesture_menu(int*);
        void vestures_labosana();
        int atsauksmes_menu(int*);
        void atsauksmes_labosana();
    protected:
    private:
};

#endif // ADMIIN_H
