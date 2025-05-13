/*1. 2. Sukurti dinaminį dvikryptį sąrašą, realizuojant elemento įterpimo, pašalinimo,
spausdinimo bei paieškos funkcijas. Perkelti to sąrašo visus elementus į
vienkryptį ciklinį sąrašą. Atspausdinti visus vienkrypčio ciklinio sąrašo
elementus.
 */


#include <iostream>
using namespace std;

struct dviKrypt {
    dviKrypt* next;
    int data;
    dviKrypt* prev;
};
dviKrypt* head = nullptr;
dviKrypt* tail = nullptr;;
void print_dviKrypt(dviKrypt* head) {
    if (head == nullptr) {
        cout << "Dvikryptis sarasas tuscias.\n";
        return;
    }
    dviKrypt* dabartinis = head;
    cout << "Dvikryptis sarasas: ";
    while (dabartinis != nullptr) {
        cout << dabartinis->data << " ";
        dabartinis = dabartinis->next;
    }
    cout << endl;

}

void isvalyti_dviKrypt(dviKrypt*& head, dviKrypt*& tail) {
    if (head == nullptr) {return;}

    dviKrypt* dabartinis = head;
    while(dabartinis != nullptr) {
        dviKrypt* temp = dabartinis;
        dabartinis = dabartinis->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}
struct vienKrypt {
    int data;
    vienKrypt* next;
};
vienKrypt* front = nullptr;
vienKrypt* rear = nullptr;
void print_vienKrypt(vienKrypt* front) {
    if (front == nullptr) {
        cout << "Vienkryptis ciklinis sarasas tuscias.\n";
    }else {
        cout << "Vienkryptis ciklinis sarasas: ";
        vienKrypt* dabartinis = front;
        do {
            cout << dabartinis->data << " ";
            dabartinis = dabartinis->next;
        }while(dabartinis != front);
        cout << endl;
    }
}



int main()
{
    int komanda, x;
    double temp, elem;
    while(true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Elemento iterpimas i dvikrypti sarasa\n";
        cout << "(2) Elemento salinimas is dvikrypcio sarasa\n";
        cout << "(3) Dvikrypcio saraso spausdinimas\n";
        cout << "(4) Elemento paieska dvikrypciame sarase\n";
        cout << "(5) Perkelti elementus i vienkrypti ciklini sarasa\n";
        cout << "(6) Vienkrypcio saraso spausdinimas\n";
        cout << "(0) Iseiti\n";
        cin >> komanda;
        if (komanda == 0) {break;};
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        else if (komanda == 1) {
            //elem iterpimas
            if(head == nullptr) {
                print_dviKrypt(head);
                cout << "Iveskite nauja elementa: ";
                cin >> temp;
                dviKrypt* naujas = new dviKrypt();
                naujas->data = temp;
                naujas->next = nullptr;
                naujas->prev = nullptr;
                head = naujas;
                tail = naujas;
            }else {
                print_dviKrypt(head);
                cout << "Pasirinkite norima operacija: \n";
                cout << "(1) Iterpti pries nurodyta elementa\n";
                cout << "(2) Iterpti po nurodyto elemento\n";
                cout << "(3) Iterpti saraso pradzioje\n";
                cout << "(4) Iterpti saraso pabaigoje\n";
                cout << "(0) Grizti i pagrindini meniu\n";
                cin >> komanda;
                if (komanda == 0) {continue;};
                if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6) {
                    cout<<"Neteisinga komada. Bandykite dar karta: \n";
                }
                else if (komanda == 1) { // iterpti pries
                    print_dviKrypt(head);
                    cout << "Nurodykite elementa, pries kuri norite iterpti nauja elementa: ";
                    cin >> elem;
                    cout << "Iveskite nauja elementa: ";
                    cin >> temp;
                    dviKrypt* dabartinis = head;
                    bool found = false;
                    while (dabartinis != nullptr) {
                        if (dabartinis->data == elem) {
                            dviKrypt* naujas =  new dviKrypt();
                            naujas->data = temp;
                            naujas->next = dabartinis;
                            naujas->prev = dabartinis->prev;
                            if(dabartinis->prev != nullptr) {
                                dabartinis->prev->next = naujas;
                            }else {
                                head = naujas;
                            }
                            dabartinis->prev = naujas;
                            found = true;
                            break;
                        }
                        dabartinis = dabartinis->next;
                    }
                    if (!found) {
                        cout << "Nurodyto elemento nera sarase.\n";
                    }
                }else if(komanda == 2) { // iterpti po
                    print_dviKrypt(head);
                    cout << "Nurodykite elementa, po kurio norite iterpti nauja elementa: ";
                    cin >> elem;
                    cout << "Iveskite nauja elementa: ";
                    cin >> temp;
                    dviKrypt* dabartinis = head;
                    bool found = false;
                    while (dabartinis != nullptr){
                        if (dabartinis->data == elem) {
                            dviKrypt* naujas =  new dviKrypt();
                            naujas->data = temp;
                            naujas->next = dabartinis->next;
                            naujas->prev = dabartinis;
                            if(dabartinis->next != nullptr) {
                                dabartinis->next->prev = naujas;
                            }else {
                                tail = naujas;
                            }
                            dabartinis->next = naujas;
                            found = true;
                            break;
                        }
                        dabartinis = dabartinis->next;
                    }
                    if(!found) {
                        cout << "Nurodyto elemento nera sarase.\n";
                    }
                }
                else if(komanda == 3) { // iterpti saraso pradzioje
                    print_dviKrypt(head);
                    cout << "Iveskite nauja elementa: ";
                    cin >> temp;
                    dviKrypt* dabartinis = head;
                    dviKrypt* naujas = new dviKrypt();
                    naujas->data = temp;
                    naujas->next = dabartinis;
                    naujas->prev = nullptr;
                    dabartinis->prev = naujas;
                    head = naujas;
                }
                else if(komanda == 4) { // iterpti saraso pabaigoje
                    print_dviKrypt(head);
                    cout << "Iveskite nauja elementa: ";
                    cin >> temp;
                    dviKrypt* dabartinis = tail;
                    dviKrypt* naujas = new dviKrypt();
                    naujas->data = temp;
                    naujas->next = nullptr;
                    naujas->prev = dabartinis;
                    dabartinis->next = naujas;
                    tail = naujas;
                }
                print_dviKrypt(head);
            }
        }
        else if (komanda == 2) {//elem salinimas
            cout << "Nurodykite salinama elementa: ";
            cin >> elem;
            dviKrypt* dabartinis = head;
            bool found = false;
            while(dabartinis != nullptr) {
                if (dabartinis->data == elem) {
                    found = true;
                    if(head == tail) { // kai tik vienas elem
                        delete dabartinis;
                        head = nullptr;
                        tail = nullptr;
                    }else {
                        if(dabartinis == head) {
                            head = dabartinis->next;
                            head->prev = nullptr;
                        }else if(dabartinis == tail) {
                            tail = dabartinis->prev;
                            tail->next = nullptr;
                        }else {
                            dabartinis->next->prev = dabartinis->prev;
                            dabartinis->prev->next = dabartinis->next;

                        }
                        delete dabartinis;
                    }
                    break;
                }
                dabartinis = dabartinis->next;
            }
            print_dviKrypt(head);
            if(!found) {
                cout << "Nurodyto elemento nera sarase.\n";
            }
        }
        else if (komanda == 3) {
            //spausdinimas
            if(head == nullptr && tail == nullptr) {
                cout << "Dvikryptis sarasas tuscias.\n";
            }else{
                print_dviKrypt(head);
            }
        }
        else if (komanda == 4) {
            //paieska
            cout << "Iveskite ieskoma elementa: ";
            cin >> temp;
            dviKrypt* dabartinis = head;
            bool found = false;
            if (head == nullptr) {
                cout << "Sarasas tuscias.\n";
            } else {
                while (dabartinis != nullptr) {
                    if (dabartinis->data == temp) {
                        cout << "Elementas " << dabartinis->data << " rastas. Jo adresas "<< dabartinis << endl;
                        found = true;
                        break;
                    }
                    dabartinis = dabartinis->next;
                }
                if (!found) {
                    cout << "Elementas nerastas.\n";
                }
            }
        }else if (komanda == 5) {//Perkelti i vienkrypti ciklini
            if(head == nullptr) {
                cout << "Dvikryptis sarasas tuscias. Nera ko perkelti.\n";
            }else {
                dviKrypt* dabartinis = head;
                while(dabartinis != nullptr) {
                    vienKrypt* naujas = new vienKrypt();
                    naujas->data = dabartinis->data;
                    if(front == nullptr) { //pirmam elem
                        front = naujas;
                        rear = naujas;
                        naujas->next = front;
                    }else {
                        rear->next = naujas;
                        rear = naujas;
                        rear->next = front;
                    }
                    dabartinis = dabartinis->next;
                }
                cout << "Elementai perkelti.\n";
                print_vienKrypt(front);
                isvalyti_dviKrypt(head, tail);
                print_dviKrypt(head);
            }

        }else if (komanda == 5) {print_vienKrypt(front);} // spausdinti deka
        else if (komanda == 6) {print_vienKrypt(front);} // spausdinti deka
    }
    return 0;
    }
