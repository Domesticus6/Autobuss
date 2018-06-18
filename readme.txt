Manas programmas analize prieks parbauditaja:
Kas strada:
Iesana ieks programmas parada jums laiku,uznemuma logo un darbibas menu(tas ir prieks lietotaja, lai saprastu ar kadu programmu un firmu vins darbojas).
Saja programma tiek realizeta objektorienteta programmesana(klasses, objekti u. c.);
Visa programma darbojas iesana un iziesana no katra menu;
Pieejamas klases:
1.Admin(lietas saistitas ar administresanu);
2.Klients(visas darbibas ar marsuru meklesanu, savu profili, biletes pirksanu u. c.);
3.Viesis(interesantas informacijas apskate);;
4.Konts(saistiba ar naudu ieks klienta menu prieks biletes pirksanas);
5.Marsruti_reisi(prieks marsrutu pievienosanas ieks AdminMenu);
6)Leitotajs(ir galvena klase: Admin, Klients klasem);
1)ViesisnMenu(klase):
	1.1)Var paskatities informaciju viesim par sarakstiem(starptautiskiem un ieks Latvijas);
	1.2)Var paskatities informaciju par viesim par uznemumu;
	1.3)Var ari paskatities atsauksmes par so uznemumu;
	1.4)Ka ari iziet no si menu;
2)Registresana:
	2.1)Prieks registresanas jums vajag ievadit: savu uzvardu, vardu, login, parole un personas kods;
	2.2)Tad si informacija tiks ierakstita faila lietotaji.txt;
3)AdminMenu(klase), ir saistits ar Marsuti_reisi klasi: 
	3.1)Ieesana ieks AdminMenu ir ar paroles(12345) parbaudi, kas glabajas AdminPasword faila);
	3.2)Marsrutu pievienosana(vai ieks Latvijas sarakstslv.txt, vai nu strptautiska meroga starptautsaraksts.txt), katram veidam ir savs konkrets fails;
	3.3)Marsrutu redigesana(fails ar piezimi copy ir prieks parrakstisanas, kad notiek informacijas redigesanas process) un to apskate(ieks faila) un ir katram brauciena veidam, jo ieks latvijas un starptautiskie braucieni ir sadaliti katrs sava apaks menu;
	3.4)Visu profilu apskate un to labosana(copy faili, ir jau paskaidrots kapec);
	3.5)Profilu blokesana, tiek ierakstiti lietotaji blokesana.txt faila;
	3.6)Profilu atblokesana: lietotajs tiek izrakstits no blokesan.txt faila;
	3.7)Var paskatities informaciju par uznemumu;
	3.8)Sis informacijas labosana un pievienosana(uznemums.txt);
	3.9)Statistikas izvadisana par lietotaju un marsrutu, pec izvelas, izvedas uz ekrana);
	3.10)Atlaizu pievienosana prieks biletes pirksanas, to redigesna(atlaides.txt);
	3.11)Bilesu vestures apskate,kas tiks veidota, kad cilveki saks pirkt biletes un informacijas pilniga dzesana(vesture.txt);
	3.12)Atsauksmju par uznemumu apskate, kas tiks veidota, kad cilveks nopirks bileti un gribs atstat savu atsauksmi, un informacijas pilniga dzesana(atsauksmes.txt);
4)Klients(klase), ir saistits ar Konts klasi:
	4.1)Iesana ieks lietotaja notiek parbaude uz lietotaja logina, paroli un personas koda vienlaikus sakrisanu, ja jusu lietotajs ir blokets, tad jus nevaresiet sava lietotaja kabineta;
	4.2)Seit var paskatties sarakstus(ieks Latvijas vai starptautiskos):
	4.3)Paradit savas bilesu rezervacijas, kas tiek paraditas ar ieesanas procesa ievadito login;
	4.4)Paradit informaciju par sevi,kas tiek paraditas ar ieesanas procesa ievadito login;
	4.5)Nopirkt bilet, kur vispirms jus ievadat jums vajadzigo informaciju(prieks meklesanas ieks faila), vispirms jums vajag izveleties brauciena marsruta veidu,pec tam izveleties marsrutu un ievadit datus(bilesu skaitu, jusu vecumu), pec tam tiks parbaudits jusus konts, ja konts neeksiste, vai nepietiks naudas, tad paradisies noteiktais pazinojums, pec ta, jus atstasiet pazinojumu par uznemumu un bilete tiks izdrukata html formata.
	4.6)Jus varat mainit savu paroli(ievadot vecu un jaunu paroli);
	4.7)Pievienot kontu;
	4.8)Paskatities savu kontu;
Kas nestrada(kludas,programmas ficas):
	1)Nav ipasi loti konkretas statistikas(izvada visus datus, masinas kas ir vai nav; netikai klasi, vai masinas pieejamibu;
	2)Ja ievadat citu ciparu(no menu izvelnes), tad UserMenu un AdminMenu u. c. , jums prasis vai jus gribat atkartot darbibu noteikta menu; Sakum menu jums izvadis kludu un atkartosies izvele (registracija AdminMenu u. c.);
	3)Gadijuma ja pec registresanas jus nevarat ieejiet akkaunta, tad notika datu parslodze, tad user faila un login faila vajag izdzest user vai useru, vai ari izdarit projekta rebuild vai clean, tad vajadzetu visam stradat, ja ne tad restartejiet codeblock vai pasu datoru;
	4)Var but problemas ar iziesanu, no kaut kada menu(tas tika ieraudzits marsrutu menu pie latvijas braucienam);
	5)Ja jus kaut ko neievadijat pareizi ne pec nosacijumiem iekavas, tad programma var nokrasoties!;
Ja compilesanas bridi izvada kludu undefined_reference, tad izdariet rebuild vai clean.