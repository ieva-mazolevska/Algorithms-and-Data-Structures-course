/*2. Sukurti sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto elemento, norimo
elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas, kurios:
a. Visus skaičius nuo paskutiniojo 0 perkelia į vienkryptį ciklinį sąrašą.
b. Apskaičiuoja kiek cikliniame sąraše esančių elementų kurie yra didesnį už dvikrypčio
sąrašo visų elementų vidurkį.
c. Panaikina ciklinio sąrašo visus elementus esančios tarp trečiojo ir priešpaskutinio
elemento bei atspausdina juos ekrane.
Pastaba. Šioje užduotyje galima naudoti STL bibliotekas.
*/
#include <iostream>
#include <vector>
using namespace std;

struct sarasas {
    int data;
    sarasas* prev;
    sarasas* next;
};

int main() {
    sarasas* pradzia = nullptr;
    sarasas* pabaiga = nullptr;

    while (true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Saraso spausdinimas\n";
        cout << "(2) Naujo elemento ivedimas\n";
        cout << "(3) Elemento iterpimas\n";
        cout << "(4) Elemento salinimas\n";
        cout << "(5) Didziausias elementas\n";
        cout << "(6) Visus skaicius nuo paskutiniojo 0 perkelia i vienkrypti ciklini sarasa\n";
        cout << "(7) Apskaiciuoti, kiek cikliniame sarase esanciu elementu kurie yra didesni uz dvikrypcio saraso visu elementu vidurki\n";
        cout << "(8) Panaikinti ciklinio saraso visus elementus esancios tarp treciojo ir priespaskutinio elemento bei atspausdinti juos ekrane\n";
        cout << "(9) Iseiti\n";
        int komanda;
        cin >> komanda;
        if (komanda == 9) { break; }
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6 && komanda != 7 && komanda != 8 && komanda != 9) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        if (komanda == 1) {
            if (pradzia == nullptr) {cout << "Sarasas tuscias.\n";}
            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << endl;
        } else if (komanda == 2) {
            int elem;
            cout << "Iveskite nauja elementa: ";
            cin >> elem;
            sarasas* e = new sarasas();
            e->data = elem;
            e->next = nullptr;
            e->prev = pabaiga;
            if (pabaiga != nullptr) {
                pabaiga->next = e;
            }
            pabaiga = e;
            if (pradzia == nullptr) {
                pradzia = e;
            }
        }else if (komanda == 3) {
            // naujas elem
            cout << "Naujo elemento iterpimas. Pasirinkite: \n"; // įterpimą prieš ir po nurodyto elemento
            cout << "(1) Iterpti pries \n";
            cout << "(2) Iterpti po \n";
            int pasirinkimas;
            cin >> pasirinkimas;
            int temp, elem;
            if (pasirinkimas == 1) {
                cout << "Nurodykite pries kuri elementa norite iterpti nauja elementa: \n";
                cin >> temp;
                sarasas* dabartinis = pradzia;
                while (dabartinis != nullptr) {
                    if (dabartinis->data == temp) {
                        cout << "Nurodykite naujo elemento reiksme, kuri bus iterpta pries elementa " << temp << endl;
                        cin >> elem;
                        sarasas* e = new sarasas();
                        e->data = elem;
                        e->next = dabartinis;
                        e->prev = dabartinis->prev;
                        if (dabartinis->prev != nullptr) {
                            dabartinis->prev->next = e;
                        } else {
                            pradzia = e;
                        }
                        dabartinis->prev = e;
                        break;
                    }
                    dabartinis = dabartinis->next;
                }
            } else if (pasirinkimas == 2) {
                cout << "Nurodykite po kurio elemento norite iterpti nauja elementa: \n";
                cin >> temp;
                sarasas* dabartinis = pradzia;
                while (dabartinis != nullptr) {
                    if (dabartinis->data == temp) {
                        cout << "Nurodykite naujo elemento reiksme: \n";
                        cin >> elem;
                        sarasas* e = new sarasas();
                        e->data = elem;
                        e->next = dabartinis->next;
                        e->prev = dabartinis;
                        if (dabartinis->next != nullptr) {
                            dabartinis->next->prev = e;
                        } else {
                            pabaiga = e;
                        }
                        dabartinis->next = e;
                        break;
                    }
                    dabartinis = dabartinis->next;
                }
            }

        }
        else if (komanda == 4) {
            int elem;
            cout << "Iveskite elementa kuri norite salinti: ";
            cin >> elem;
            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr && dabartinis->data != elem) {
                dabartinis = dabartinis->next;
            }
            if (dabartinis != nullptr) {
                if (dabartinis->prev != nullptr) {
                    dabartinis->prev->next = dabartinis->next;
                } else {
                    pradzia = dabartinis->next;
                }
                if (dabartinis->next != nullptr) {
                    dabartinis->next->prev = dabartinis->prev;
                } else {
                    pabaiga = dabartinis->prev;
                }
                delete dabartinis;
            }
        } else if (komanda == 5) {
            sarasas* maxElem = pradzia;
            sarasas* dabartinis = pradzia;
            while (dabartinis != nullptr) {
                if (dabartinis->data > maxElem->data) {
                    maxElem = dabartinis;
                }
                dabartinis = dabartinis->next;
            }
            if (maxElem != nullptr) {
                cout << "Didziausias elementas: " << maxElem->data << endl;
            }
        } else if (komanda == 6) {
            vector<int> ciklinisSarasas;
            sarasas* dabartinis = pabaiga;
            while (dabartinis != nullptr && dabartinis->data != 0) {
                ciklinisSarasas.push_back(dabartinis->data);
                sarasas* temp = dabartinis;
                dabartinis = dabartinis->prev;
                // Ištrinti elementą iš dvikrypčio sąrašo
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    pradzia = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    pabaiga = temp->prev;
                }
                delete temp;
            }
            cout << "Dvikryptis sarasas: ";
            dabartinis = pradzia;
            while (dabartinis != nullptr) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << endl;
            cout << "Ciklinis sarasas: ";
            for (int elem : ciklinisSarasas) {
                cout << elem << " ";
            }
            cout << endl;
        } else if (komanda == 7) {
            vector<int> ciklinisSarasas;
            sarasas* dabartinis = pabaiga;
            while (dabartinis != nullptr && dabartinis->data != 0) {
                ciklinisSarasas.push_back(dabartinis->data);
                dabartinis = dabartinis->prev;
            }
            double suma = 0;
            int count = 0;
            dabartinis = pradzia;
            while (dabartinis != nullptr) {
                suma += dabartinis->data;
                count++;
                dabartinis = dabartinis->next;
            }
            double vidurkis = suma / count;
            int didesniuElemSk = 0;
            for (int elem : ciklinisSarasas) {
                if (elem > vidurkis) {
                    didesniuElemSk++;
                }
            }
            cout << "Elementu kurie yra didesni uz vidurki: " << didesniuElemSk << endl;
        }
        else if (komanda == 8) {
            if (pradzia != nullptr && pradzia != pabaiga && pradzia->next != pabaiga) {
                // Suskaiciuojami elem
                sarasas* dabartinis = pradzia;
                int size = 0;
                while (dabartinis != nullptr) {
                    size++;
                    dabartinis = dabartinis->next;
                }
                if (size < 5) {
                    cout << "Nepakanka elementu.\n";
                    continue;
                }

                // randamas 3 ir priespaskutinis elem
                sarasas* trecias = pradzia;
                for (int i = 1; i < 3; i++) {
                    trecias = trecias->next;
                }

                sarasas* priespaskutinis = pradzia;
                for (int i = 1; i < size - 1; i++) {
                    priespaskutinis = priespaskutinis->next;
                }

                // Pasalinami
                sarasas* dabartinis2 = trecias->next;
                vector<int> salinamiElementai;

                while (dabartinis2 != priespaskutinis) {
                    salinamiElementai.push_back(dabartinis2->data);
                    sarasas* temp = dabartinis2;
                    dabartinis2 = dabartinis2->next;

                    // Pasalinamas elem
                    temp->prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = temp->prev;
                    } else {
                        pabaiga = temp->prev; // jei pasalintas paskutinis elem
                    }

                    delete temp;
                }
                cout << "Pasalinti elementai: ";
                for (int elem : salinamiElementai) {
                    cout << elem << " ";
                }
                cout << endl;
            } else {
                cout << "Sarasas per trumpas.\n";
            }
        }
    }
    return 0;
}
