#include <iostream>
using namespace std;

int main() {

    double x;
    int komanda;

    struct sarasas {
        int duomuo;
        sarasas* kitas;
    };
    sarasas* pradzia = nullptr;
    sarasas* pabaiga = nullptr;
    cout << "Sarasas yra tuscias. Iveskite nauja elementa: \n";
    cin >> x;

    sarasas* elem = new sarasas ();
    elem->duomuo = x;
    elem->kitas = nullptr;
    pradzia = elem;
    pabaiga = elem;

    while(true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(0) Saraso spausdinimas\n";
        cout << "(1) Naujo elemento ivedimas\n";
        cout << "(2) Maziausio saraso elemento vietos numeris\n";
        cout << "(3) Sandauga elementu, esanciu tarp pirmojo neigiamo elemento ir antrojo neigiamo elemento\n";
        cout << "(4) Saraso performavimas\n";
        cout << "(5) Iseiti\n";
        cin >> komanda;
        if (komanda == 5) {break;};
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        else if (komanda == 0) { //saraso spausdinimas
            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr) {
                cout << dabartinis->duomuo << " ";
                dabartinis = dabartinis->kitas;
            }
            cout << endl;
        }
        else if (komanda == 1) { // naujas elem
            cout << "Iveskite nauja elementa: \n";
            cin >> x;
            elem = new sarasas();
            elem->duomuo = x;
            elem->kitas = nullptr;
            pabaiga->kitas = elem;
            pabaiga = elem;
        }
        else if (komanda == 2) { //maziausio elem vietos numeris
            int minReiksme = pradzia -> duomuo;
            int minVieta = 0;
            int vieta = 0;
            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr) {
                if (dabartinis->duomuo < minReiksme) {
                    minReiksme = dabartinis->duomuo;
                    minVieta = vieta;
                }
                dabartinis = dabartinis->kitas;
                vieta++;
            }
            cout << "Maziausio elemento indeksas yra: " << minVieta << endl;
            cout << "Maziausio elemento vietos numeris: " << minVieta + 1 << endl;

        }
        else if (komanda == 3) {
            //elem sandauga
            int neigElem = 0; // kai 1, isijungia daugyba
            int sand = 1; // elem sandauga
            sarasas* dabartinis = pradzia;
            while(dabartinis != nullptr) {
                if (dabartinis->duomuo < 0) {
                    neigElem++;
                    if (neigElem == 2) {break;}
                }
                else if (neigElem == 1) {
                    sand *=dabartinis->duomuo;
                }
                dabartinis = dabartinis->kitas;
                }
            if (neigElem < 2) {
                cout << "Saraše nera pakankamai neigiamu elementu." << endl;
            }
            else {cout << "Elelmentu sandauga: " << sand << endl;}
        }
        else if (komanda == 4) { //performavimas: pirma < 3, o paskui visi likę.
            sarasas* mazPradzia = nullptr; // <3 saraso pradzia
            sarasas* mazPabaiga = nullptr; // <3 saraso pabaiga
            sarasas* likePradzia = nullptr; // likusiu saraso pradzia
            sarasas* likePabaiga = nullptr; //likusiu saraso pabaiga

            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr) {
                if (abs(dabartinis->duomuo) < 3) { //abs - absoliuti reiksme
                    if (mazPradzia == nullptr) {
                        mazPradzia = dabartinis;
                        mazPabaiga = dabartinis;
                    }
                    else { //jei netuscias, prideda i gala
                        mazPabaiga->kitas = dabartinis;
                        mazPabaiga = dabartinis;
                    }
                }
                else { //didesnius deda i kita sarasa
                    if (likePradzia == nullptr) {
                        likePradzia = dabartinis;
                        likePabaiga = dabartinis;
                    }
                    else { //jei netuscias, deda i pabaiga
                        likePabaiga->kitas = dabartinis;
                        likePabaiga = dabartinis;
                    }
                }
                dabartinis = dabartinis->kitas; //ziuri kita elem
            }
            if (mazPabaiga !=nullptr) {//jei nera <3 elem
                mazPabaiga->kitas = likePradzia;
                pradzia = mazPradzia;
            }
            else {
                pradzia = likePabaiga;
            }
            if (likePabaiga !=nullptr) {
                likePabaiga->kitas = nullptr;
            }
        }
    }
    return 0;
}
