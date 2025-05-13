/*1. Sukurti ciklinį vienkryptį sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto
elemento, norimo elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas,
kurios:
a. Pirmus 6 neigiamus skaičius perkelia į dvikryptį ciklinį sąrašą.
b. Apskaičiuoja kiek dvikrypčiame cikliniame sąraše esančių lyginių elementų pagal
absoliučią reikšmę suma yra didesnė už vienkrypčio ciklinio sąrašo visų nelyginių
elementų sumą.
c. Panaikina ciklinio sąrašo pirmąjį, vidurinį ir paskutinį elementą, ir atspausdina juos
ekrane
Pastaba. Šioje užduotyje negalima naudoti STL bibliotekų.
 *
 */

#include <iostream>
using namespace std;

struct sarasas {
    int data;
    sarasas* next;
};
struct sarasas *sarasasRod;

struct el {
    el *next, *prev;
    int data;
};


int main() {
    el *pradzia, *rod;
    pradzia = new el;
    pradzia->next = pradzia;
    pradzia->prev = pradzia;
    pradzia->data = 0;
    rod = pradzia;
    delete pradzia;

    double m, n;
    cout << "Iveskite intervalo pradini rezi: \n";
    cin >> n;
    cout << "Iveskite intervalo galutini rezi: \n";
    cin >> m;
    sarasas *L = new sarasas (); //sukuria nauja saraso elementa
    sarasas *q = L; //q rodo i L
    for(int i=n; i<=m; i++) {
        sarasas *p = new sarasas (); //naujas elementas
        p->data = i;
        q->next = p;
        q = p;
    }
    //daromas ciklinis sarasas:
    q->next = L -> next;
    q = q->next;
    free (L);

    int komanda; //meniu
    int temp, elem; // iterpimas


    while(true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Saraso spausdinimas\n";
        cout << "(2) Naujo elemento ivedimas\n";
        cout << "(3) Elemento salinimas\n";
        cout << "(4) Didziausias elementas\n";
        cout << "(5) Pirmus 6 neigiamus skaicius perkelti i dvikrypti ciklini sarasa\n";
        cout << "(6) Apskaiciuoti, kiek dvikrypciame cikliniame sarase esanciu lyginiu elementu, pagal absoliucia reiksme, suma yra didesne uz vienkrypcio ciklinio saraso visu nelyginiu elementu suma\n";
        cout << "(7) Panaikinti ciklinio saraso pirmaji, vidurini ir paskutini elementa, ir atspausdinti juos ekrane.\n";
        cout << "(8) Iseiti\n";
        cin >> komanda;
        if (komanda == 8) {break;};
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6 && komanda != 7 && komanda != 8) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        else if (komanda == 1) { //saraso spausdinimas
            sarasas* dabartinis = q;
            while (dabartinis -> next != q) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << dabartinis->data << endl; //atspausdina paskutini mazga
        }
        else if (komanda == 2) {
            // naujas elem
            cout << "Naujo elemento iterpimas. Pasirinkite: \n"; //įterpimą prieš ir po nurodyto elemento
            cout << "(1) Iterpti pries \n";
            cout << "(2) iterpti po \n";
            cin >> komanda;
            if (komanda == 1) {
                cout << "Nurodykite pries kuri elementa norite iterpti nauja elementa: \n";
                cin >> temp;
                sarasas *dabartinis = q;
                while (dabartinis->next != q) {
                    if (dabartinis->next->data == temp) {
                        cout << "Nurodykite naujo elemento reiksme, kuri bus iterpta pries elementa " << temp << endl;
                        cin >> elem;
                        sarasas *e = new sarasas();
                        e->data = elem;
                        e->next = dabartinis->next;
                        dabartinis->next = e;
                        break;
                    }
                    dabartinis = dabartinis->next;
                }

            }
            else if (komanda == 2) {
                cout << "Nurodykite po kurio elemento norite iterpti nauja elementa: \n";
                cin >> temp;
                sarasas *dabartinis = q;
                while (dabartinis->next != q) {
                    if (dabartinis->data == temp) {
                        cout << "Nurodykite naujo elemento reiksme: \n";
                        cin >> elem;
                        sarasas *e = new sarasas();
                        e->data = elem;
                        e->next = dabartinis->next;
                        dabartinis->next = e;
                        break;
                    }
                    dabartinis = dabartinis->next;
                }
            }
        }
        else if (komanda == 3) {// elemento salinimas
            cout << "Nurodykite, kuri elementa reikia pasalinti: \n";
            cin >> elem;
            sarasas *dabartinis = q;
            while(dabartinis -> next != q) {
                if(dabartinis->next->data == elem) {
                    sarasas *temp = dabartinis->next;
                    dabartinis->next = dabartinis->next->next;
                    delete (temp);
                    break;
                }
                dabartinis = dabartinis->next;
            }

        }
        else if (komanda == 4) { //didziausias elementas
            sarasas *dabartinis = q;
            int maxElem = dabartinis->data;
            while(dabartinis->next != q) {
                if(maxElem < dabartinis->next->data) {
                    maxElem = dabartinis->next->data;
                }
                dabartinis = dabartinis->next;
            } if(maxElem < dabartinis->data) {
                maxElem = dabartinis->data;
            }
            cout << "Didziausias elementas: " << maxElem << endl;
        }
else if (komanda == 5) { // Pirmus 6 neigiamus skaicius perkelia i dvikrypti ciklini sarasa
    sarasas *dabartinis = q;
    int neigiamiSkaiciai = 0;
    cout << "Pradinis sarasas: ";
    sarasas *temp = q;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != q);
    cout << endl;
    pradzia = nullptr;

    //perkelia neigiamus
    sarasas *ankstesnis = nullptr;
    while (dabartinis != nullptr && dabartinis->next != q && neigiamiSkaiciai < 6) {
        if (dabartinis->data < 0) {
            el *elem = new el;
            elem->data = dabartinis->data;
            if (pradzia == nullptr) {
                pradzia = elem;
                pradzia->next = pradzia;
                pradzia->prev = pradzia;
            } else {
                el *paskutinis = pradzia->prev;
                paskutinis->next = elem;
                elem->prev = paskutinis;
                elem->next = pradzia;
                pradzia->prev = elem;
            }
            ++neigiamiSkaiciai;

            // Istrinami elem is pradinio saraso
            if (ankstesnis != nullptr) {
                ankstesnis->next = dabartinis->next;
            } else {
                // jei elem yra pirmas
                sarasas *temp = q;
                while (temp->next != q) {
                    temp = temp->next;
                }
                q = dabartinis->next;
                temp->next = q;
            }
            sarasas *temp = dabartinis;
            dabartinis = dabartinis->next;
            delete temp;
        } else {
            ankstesnis = dabartinis;
            dabartinis = dabartinis->next;
        }
    }

    el *dabartinisDv = pradzia;
    if (dabartinisDv != nullptr) {
        el *pradziosRod = pradzia;
        cout << "Dvikryptis ciklinis sarasas: ";
        do {
            cout << dabartinisDv->data << " ";
            dabartinisDv = dabartinisDv->next;
        } while (dabartinisDv != pradziosRod);
        cout << endl;
    }

    cout << "Galutinis ciklinis vienkryptis sarasas: ";
    temp = q;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != q);
    cout << endl;
    pradzia = nullptr;
}
        else if (komanda == 6) {
            sarasas *dabartinis = q;
            int nelyginiuSuma = 0;
            while (dabartinis->next != q) {
                if (dabartinis->data % 2 != 0) {
                    nelyginiuSuma += dabartinis->data;
                }
                dabartinis = dabartinis->next;
            }
            if (dabartinis->data % 2 != 0) {//paskutiniam elem
                nelyginiuSuma += dabartinis->data;
            }
            el *dabartinisDv = pradzia;
            int lyginiuSuma = 0;

            if (dabartinisDv != nullptr) {
                el *pradziosRod = pradzia;
                do {
                    if (abs(dabartinisDv->data) % 2 == 0) {
                        lyginiuSuma += abs(dabartinisDv->data);
                    }
                    dabartinisDv = dabartinisDv->next;
                } while (dabartinisDv != pradziosRod);
            }
            int skirtumas = lyginiuSuma - nelyginiuSuma;
            if (lyginiuSuma > nelyginiuSuma) {
                cout << "Lyginiu elementu suma dvikrypciame cikliniame sarase yra " << abs(skirtumas) << " didesne uz nelyginiu elementu suma vienkrypciame cikliniame sarase." << endl;
            } else {
                cout << "Lyginiu elementu suma dvikrypciame cikliniame sarase yra " << abs(skirtumas) << " mazesne uz nelyginiu elementu suma vienkrypciame cikliniame sarase." << endl;
            }
        }
        else if (komanda == 7) { // Panaikina ciklinio saraso pirmaji, vidurini ir paskutini elementa, ir atspausdina juos ekrane

            //istrinamas pirmas elem
            if (q == nullptr) {break;}
            else {
                sarasas *dabartinis = q;
                while (dabartinis->next != q) {
                    dabartinis = dabartinis->next;
                }
                sarasas *pirmas = q;
                q = q->next;
                dabartinis->next = q;
                cout << "Pirmas elementas: " << pirmas->data << endl;
                delete pirmas;
            }

            //istrinamas paskutinis elem
            if (q == nullptr) {break;}
            else {
                sarasas *dabartinis = q;
                sarasas *ankstesnis = nullptr;
                while (dabartinis->next != q) {
                    ankstesnis = dabartinis;
                    dabartinis = dabartinis->next;
                }
                if (ankstesnis != nullptr) {
                    ankstesnis->next = q;
                    cout << "Paskutinis elementas: " << dabartinis->data << endl;
                    delete dabartinis;
                }


                //istrinamas vidurinis elem

                if (q == nullptr) {break;}
                else {
                    //kiek elementu sarase
                    int elemSk = 0;
                    sarasas *vidurinis = q;
                    do {
                        elemSk++;
                        vidurinis = vidurinis->next;
                    } while (vidurinis != q);

                    //randamas vidurinis elem
                    int vidurinisIndex = elemSk / 2;
                    sarasas *dabartinis = q;
                    sarasas *ankstesnis = nullptr;
                    for (int i = 0; i < vidurinisIndex; i++) {
                        ankstesnis = dabartinis;
                        dabartinis = dabartinis->next;
                    }
                    //istrinimas
                    if (ankstesnis != nullptr) {
                        ankstesnis->next = dabartinis->next;
                        cout << "Vidurinis elementas: " << dabartinis->data << endl;
                        delete dabartinis;
                    }
                }
                }
            sarasas* dabartinis = q;
            while (dabartinis -> next != q) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << dabartinis->data << endl; //atspausdina paskutini mazga
            }
    }
        return 0;
}
