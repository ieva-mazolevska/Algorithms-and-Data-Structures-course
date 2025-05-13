/*2. Duotas dvikryptis sąrašas, kuriame skaičiai gali kartotis. Sukurti vienkryptį sąrašą į
kurį pakliūna tik pasikartojantys skaičiai. */

#include <iostream>
using namespace std;

struct dviKrypt {
    int data;
    dviKrypt* next;
    dviKrypt* prev;
};

struct vienKrypt {
    int data;
    vienKrypt* next;
};

dviKrypt* head = nullptr;
vienKrypt* front = nullptr;


void print_dviKrypt(dviKrypt* head) {
    cout << "Dvikryptis sarasas: ";
    dviKrypt* dabartinis = head;
    while (dabartinis != nullptr) {
        cout << dabartinis->data << " ";
        dabartinis = dabartinis->next;
    }
    cout << endl;
}

int main() {
    int komanda, x;
    double temp, elem;
    while(true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Elemento ivedimas i dvikrypti sarasa\n";
        cout << "(2) Elemento salinimas is dvikrypcio sarasa\n";
        cout << "(3) Dvikrypcio saraso spausdinimas\n";
        cout << "(4) Perkelti pasikartojancius elementus i vienkrypti sarasa.\n";
        cout << "(5) Vienkrypcio saraso spausdinimas\n";
        cout << "(0) Iseiti\n";
        cin >> komanda;
        if (komanda == 0) {break;};
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        else if (komanda == 1) {
            //elem iterpimas
            cout << "Iveskite nauja elementa: ";
            cin >> elem;
            dviKrypt* naujas = new dviKrypt();
            naujas->data = elem;
            naujas->next = nullptr;
            naujas->prev = nullptr;

            if (head == nullptr) {
                head = naujas;
            } else {
                dviKrypt* dabartinis = head;
                while (dabartinis->next != nullptr) {
                    dabartinis = dabartinis->next;
                }
                dabartinis->next = naujas;
                naujas->prev = dabartinis;
            }
        }else if (komanda == 2) { // Pasalinti elementą
            if (head == nullptr) {
                cout << "Sarasas tuscias. Nera ko salinti.\n";
                continue;
            }

            cout << "Iveskite salinama elementa: ";
            cin >> elem;

            dviKrypt* dabartinis = head;

            while (dabartinis != nullptr) {
                if (dabartinis->data == elem) {
                    if (dabartinis == head) {// Jei elem pradzioj
                        head = dabartinis->next;
                        if (head != nullptr) {
                            head->prev = nullptr;
                        }
                    }else if (dabartinis->next == nullptr) {// Jei elem gale
                        dabartinis->prev->next = nullptr;
                    }else {// Jei viduryje
                        dabartinis->prev->next = dabartinis->next;
                        dabartinis->next->prev = dabartinis->prev;
                    }

                    delete dabartinis;
                    cout << "Elementas pasalintas.\n";
                    print_dviKrypt(head);
                    break;
                }

                dabartinis = dabartinis->next;
            }

            if (dabartinis == nullptr) {
                cout << "Elementas nerastas.\n";
            }
        }else if (komanda == 3) {// spausdinti dviKrypt
            print_dviKrypt(head);
        }else if (komanda == 4) {
            //perkelti i vienKrypt
            if (head == nullptr) {
                cout << "Dvikryptis sarasas tuscias.\n";
                continue;
            }
            dviKrypt* elem = head;
            while (elem != nullptr) {
                dviKrypt* sekantis = elem->next; // saugom

                int el = elem->data;
                int kiekKart = 0;
                dviKrypt* temp = head;
                while (temp != nullptr) {
                    if (temp->data == el) {
                        kiekKart++;
                    }
                    temp = temp->next;
                }

                if (kiekKart > 1) {
                    bool found = false;
                    vienKrypt* patikra = front;
                    while (patikra != nullptr) {
                        if (patikra->data == el) {
                            found = true;
                            break;
                        }
                        patikra = patikra->next;
                    }

                    if (!found) {
                        vienKrypt* naujas = new vienKrypt();
                        naujas->data = el;
                        naujas->next = nullptr;
                        if (front == nullptr) {
                            front = naujas;
                        } else {
                            vienKrypt* dabartinis = front;
                            while (dabartinis->next != nullptr) {
                                dabartinis = dabartinis->next;
                            }
                            dabartinis->next = naujas;
                        }

                        // is dvikrypcio pasalinam visus su ta pacia reiksme
                        dviKrypt* isimti = head;
                        while (isimti != nullptr) {
                            dviKrypt* kitas = isimti->next;
                            if (isimti->data == el) {
                                if (isimti == head) {
                                    head = isimti->next;
                                    if (head != nullptr) {
                                        head->prev = nullptr;
                                    }
                                } else {
                                    if (isimti->prev != nullptr)
                                        isimti->prev->next = isimti->next;
                                    if (isimti->next != nullptr)
                                        isimti->next->prev = isimti->prev;
                                }
                                delete isimti;
                            }
                            isimti = kitas;
                        }
                    }
                }
                elem = sekantis;
            }
            print_dviKrypt(head);
            cout << "Vienkryptis sarasas: ";
            vienKrypt* dabartinis = front;
            while (dabartinis != nullptr) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << endl;
        }else if (komanda == 5) { //Vienkrypcio saraso spausdinimas
            cout << "Vienkryptis sarasas: ";
            vienKrypt* dabartinis = front;
            while (dabartinis != nullptr) {
                cout << dabartinis->data << " ";
                dabartinis = dabartinis->next;
            }
            cout << endl;
        }
    }

    return 0;
}
