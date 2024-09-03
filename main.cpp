#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class Agent {
public:
    virtual void deluj() = 0;
    virtual std::string izvestaj() = 0;
};

class Politicar : public Agent {
private:
    int popularnost;
    std::string zakon;
public:
    Politicar() : popularnost(std::rand() % 101 - 50), zakon("nema novih zakona") {}

    void deluj() override {
        int akcija = std::rand() % 100;
        if (akcija < 15) {
            zakon = "uvodenje novog zakona o porezima.";
            popularnost -= 10;
        } else if (akcija < 30) {
            zakon = "ukidanje zakona o radu.";
            popularnost += 5;
        } else if (akcija < 45) {
            zakon = "zabrana protesta.";
            popularnost -= 15;
        } else if (akcija < 60) {
            zakon = "uvodenje zakona o obrazovanju.";
            popularnost += 10;
        } else if (akcija < 75) {
            zakon = "povecanje plata javnim sektorom.";
            popularnost += 8;
        } else if (akcija < 90) {
            zakon = "ukidanje zakona o ekologiji.";
            popularnost -= 12;
        }
    }

    std::string izvestaj() override {
        return "Politicar ima popularnost od " + std::to_string(popularnost) + "% i nedavno je " + zakon + "\n";
    }

    int getPopularnost() {
        return popularnost;
    }

    void resetujPopularnost() {
        popularnost = std::rand() % 101 - 50;
    }
};

class Gradjani : public Agent {
private:
    bool protest;
    int zaposleni;
public:
    Gradjani() : protest(false), zaposleni(std::rand() % 100) {}

    void deluj() override {
        int akcija = std::rand() % 100;
        if (akcija < 10) {
            protest = true; // Pojedinci
        } else if (akcija < 30) {
            protest = true; // Grupa (rudari, doktori, itd.)
        } else {
            protest = false;
        }
        zaposleni = std::rand() % 100;
    }

    std::string izvestaj() override {
        std::string stanje = protest ? "Gradjani protestuju." : "Gradjani su zadovoljni.";
        return stanje + " Zaposlenost je na nivou od " + std::to_string(zaposleni) + "%.\n";
    }
};

class Ucenici : public Agent {
private:
    int procenatZavrsenih;
public:
    Ucenici() : procenatZavrsenih(std::rand() % 101) {}

    void deluj() override {
        int akcija = std::rand() % 100;
        if (akcija < 20) {
            procenatZavrsenih -= 10;
        } else if (akcija < 40) {
            procenatZavrsenih -= 5;
        } else {
            procenatZavrsenih += 5;
        }
    }

    std::string izvestaj() override {
        return "Procenat ucenika koji su zavrsili skolovanje ove godine je " + std::to_string(procenatZavrsenih) + "%.\n";
    }
};

class Drzava {
private:
    std::vector<Agent*> agenti;
    int stabilnost;
    int inflacija;
    int rastEkonomije;
    int BDP;
    int populacija;
    int prirodniPrirastaj;
    bool tenzije;
    bool uRatu;
    int mobilisani;
    int poginuli;
    int godina;
    int izboriInterval; 
    std::string razlogRaspada;
    bool opasnost;
    bool teroristickiNapad;
    bool atentatNaPoliticara;
    Politicar* trenutniPoliticar;
    std::string razlogProtesta;
    bool teroristickiNapadPrisutan;
    bool atentatPrisutan;
    int imigracija;
    int emigracija;

public:
    Drzava() : stabilnost(100), inflacija(2), rastEkonomije(3), BDP(6733991320000), populacija(6664000), prirodniPrirastaj(1), tenzije(false), uRatu(false), mobilisani(0), poginuli(0), godina(0), izboriInterval(4), razlogRaspada(""), opasnost(false), teroristickiNapad(false), atentatNaPoliticara(false), trenutniPoliticar(new Politicar()), razlogProtesta(""), teroristickiNapadPrisutan(false), atentatPrisutan(false), imigracija(0), emigracija(0) {}

    ~Drzava() {
        delete trenutniPoliticar;
        for (Agent* agent : agenti) {
            delete agent;
        }
    }

    void dodajAgenta(Agent* agent) {
        agenti.push_back(agent);
    }

    void azurirajPopulaciju() {
        populacija += (populacija * imigracija / 100) - (populacija * emigracija / 100);
        if (populacija <= 0) {
            populacija = 0;
            razlogRaspada = "Populacija je pala na 0.";
        }
    }

    void azurirajBDP() {
        BDP = (BDP * (100 + rastEkonomije)) - (BDP * inflacija);
    }

    void simulirajGodinu() {
        godina++;
        std::cout << "\nGodina " << godina << ": Simulacija pocinje...\n";

        for (Agent* agent : agenti) {
            agent->deluj();
        }

        // Odredivanje dogadaja
        int dogadjaj = std::rand() % 100;
        if (dogadjaj < 10) {
            tenzije = true;
            std::cout << "Pojavile su se tenzije izmedju zemalja.\n";
        } else if (dogadjaj < 20) {
            if (tenzije) {
                uRatu = true;
                tenzije = false;
                stabilnost -= 20;
                mobilisani = std::rand() % 50 + 10;
                poginuli = mobilisani * (std::rand() % 30) / 100;
                std::cout << "Izbio je rat! Mobilisano " << mobilisani << "%, poginulo " << poginuli << "%.\n";
            }
        } else if (dogadjaj < 30) {
            inflacija += 2;
            stabilnost -= 5;
            std::cout << "Inflacija je porasla na " << inflacija << "%.\n";
        } else if (dogadjaj < 40) {
            rastEkonomije -= 2;
            stabilnost -= 5;
            std::cout << "Ekonomski rast je opao na " << rastEkonomije << "%.\n";
        } else if (dogadjaj < 50) {
            rastEkonomije += 3;
            stabilnost += 5;
            std::cout << "Ekonomski rast je stabilan na " << rastEkonomije << "%.\n";
        } else if (dogadjaj < 60) {
            opasnost = true;
            teroristickiNapad = true;
            teroristickiNapadPrisutan = true;
            poginuli = std::rand() % 100;
            std::cout << "Pojavio se teroristicki napad. Poginulo je " << poginuli << " ljudi.\n";
        } else if (dogadjaj < 70) {
            opasnost = true;
            atentatNaPoliticara = true;
            atentatPrisutan = true;
            bool uspesan = std::rand() % 2;
            std::cout << "Pojavio se atentat na politicara. ";
            if (uspesan) {
                std::cout << "Atentat je bio uspesan. Pokrecu se vanredni izbori.\n";
                Politicar* noviPoliticar = new Politicar();
                std::cout << "Novo izabran politicar. ";
                if (noviPoliticar->getPopularnost() >= trenutniPoliticar->getPopularnost()) {
                    std::cout << "Novi politicar je popularniji.\n";
                } else {
                    std::cout << "Stari politicar je ostao na vlasti.\n";
                }
                delete trenutniPoliticar;
                trenutniPoliticar = noviPoliticar;
            } else {
                std::cout << "Atentat nije bio uspesan.\n";
            }
        } else if (dogadjaj < 80) {
            std::cout << "Organizovani su protesti. ";
            int povod = std::rand() % 3;
            if (povod == 0) {
                razlogProtesta = "nove zakone";
            } else if (povod == 1) {
                razlogProtesta = "zabranu protesta";
            } else {
                razlogProtesta = "ukidanje zakona";
            }
            std::cout << "Gradjani protestuju zbog " << razlogProtesta << ".\n";
            stabilnost -= 15;
            if (std::rand() % 2) {
                std::cout << "Zakon je povucen zbog protesta.\n";
            } else {
                std::cout << "Zakon je ostao na snazi.\n";
            }
        }

        // Ažuriranje BDP-a i populacije
        azurirajBDP();
        azurirajPopulaciju();

        // Prikaz izveštaja
        for (Agent* agent : agenti) {
            std::cout << agent->izvestaj();
        }

        std::cout << "BDP: " << BDP << "\n";
        std::cout << "BDP po stanovniku: " << (populacija > 0 ? BDP / populacija : 0) << "\n";
        std::cout << "Stabilnost: " << stabilnost << "%\n";
        std::cout << "Inflacija: " << inflacija << "%\n";
        std::cout << "Rast ekonomije: " << rastEkonomije << "%\n";

        if (stabilnost <= 10) {
            razlogRaspada = "Stabilnost je pala ispod 10%.";
            std::cout << "Drzava je u opasnosti od raspada.\n";
        } else if (stabilnost <= 0) {
            razlogRaspada = "Stabilnost je pala na 0%.";
            std::cout << "Drzava se raspala zbog potpune destabilizacije.\n";
            std::cout << "Razlog raspada: " << razlogRaspada << "\n";
            return; // Kraj simulacije
        }

        // Pauza izmedu godina
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    void pokreniSimulaciju() {
        while (true) {
            simulirajGodinu();
            if (!razlogRaspada.empty()) {
                break;
            }
        }
    }
};

int main() {
    std::srand(std::time(nullptr));
    Drzava drzava;
    drzava.dodajAgenta(new Politicar());
    drzava.dodajAgenta(new Gradjani());
    drzava.dodajAgenta(new Ucenici());
    drzava.pokreniSimulaciju();
    return 0;
}

