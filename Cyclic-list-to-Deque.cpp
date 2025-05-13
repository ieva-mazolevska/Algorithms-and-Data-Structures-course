/*1. Sukurti dinaminį dvikryptį ciklinį sąrašą,
realizuojant elemento įterpimo, pašalinimo, spausdinimo bei paieškos funkcijas.
Perkelti to sąrašo visus elementus į vienkryptį sąrašą,
kuris turi būti realizuotas kaip dekas
(įterpimas į priekį ar į galą, pašalinimas iš pradžios ar iš galo).
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
    do {
        cout << dabartinis->data << " ";
        dabartinis = dabartinis->next;
    }while (dabartinis != head);
    cout << endl;

}

void isvalyti_dviKrypt(dviKrypt*& head, dviKrypt*& tail) {
    if (head == nullptr) {return;}

    dviKrypt* dabartinis = head;
    do {
        dviKrypt* temp = dabartinis;
        dabartinis = dabartinis->next;
        delete temp;
    }while(dabartinis != head);
    head = nullptr;
    tail = nullptr;
}
struct dekas {
    int data;
    dekas* next;
};
dekas* front = nullptr;
dekas* rear = nullptr;
void print_dekas(dekas* front) {
    if (front == nullptr) {
        cout << "Vienkryptis sarasas (dekas) tuscias.\n";
    }else {
        cout << "Vienkryptis sarasas (dekas): ";
        dekas* dabartinis = front;
        while(dabartinis != nullptr) {
            cout << dabartinis->data << " ";
            dabartinis = dabartinis->next;
        }
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
        cout << "(5) Perkelti elementus i vienkrypti sarasa, kuris turi buti realizuotas kaip dekas.\n";
        cout << "(6) Vienkrypcio saraso (Dekas) spausdinimas\n";
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
                naujas->next = naujas;
                naujas->prev = naujas;
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
                    do {
                        if (dabartinis->data == elem) {
                            dviKrypt* naujas =  new dviKrypt();
                            naujas->data = temp;
                            naujas->next = dabartinis;
                            naujas->prev = dabartinis->prev;
                            dabartinis->prev->next = naujas;
                            dabartinis->prev = naujas;
                            if (dabartinis == head) {
                                head = naujas; //atnaujinam pradzia, kai iterpiama pries pirma elem
                            }
                            found = true;
                            break;
                        }
                        dabartinis = dabartinis->next;
                    }while (dabartinis != head);
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
                    do {
                        if (dabartinis->data == elem) {
                            dviKrypt* naujas =  new dviKrypt();
                            naujas->data = temp;
                            naujas->next = dabartinis->next;
                            naujas->prev = dabartinis;
                            dabartinis->next->prev = naujas;
                            dabartinis->next = naujas;
                            if (dabartinis == tail) {
                                tail = naujas;
                            }
                            found = true;
                            break;
                        }
                        dabartinis = dabartinis->next;
                    }while (dabartinis != head);

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
                    naujas->prev = dabartinis->prev;
                    dabartinis->prev->next = naujas;
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
                    naujas->next = dabartinis->next;
                    naujas->prev = dabartinis;
                    dabartinis->next->prev = naujas;
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
            do {
                if (dabartinis->data == elem) {
                    found = true;
                    if(head == tail) { // kai tik vienas elem
                        delete dabartinis;
                        head = nullptr;
                        tail = nullptr;
                    }else {
                        dabartinis->next->prev = dabartinis->prev;
                        dabartinis->prev->next = dabartinis->next;
                        if(dabartinis == head) {
                            head = dabartinis->next;
                        }
                        if(dabartinis == tail) {
                            tail = dabartinis->prev;
                        }
                        delete dabartinis;
                    }
                    break;
                }
                dabartinis = dabartinis->next;
            }while(dabartinis != head);
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
                cout << "Pirmas elementas: " << head->data << endl;
                cout << "Paskutinis elementas: " << tail->data << endl;
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
            do {
                if (dabartinis->data == temp) {
                    cout << "Elementas " << dabartinis->data << " rastas. Jo adresas "<< dabartinis << endl;
                    found = true;
                    break;
                }
                dabartinis = dabartinis->next;
            }while (dabartinis != head);
                if (!found) {
                    cout << "Elementas nerastas.\n";
                }
            }
        }else if (komanda == 5) { //Perkelti
            cout << "Pasirinkite norima operacija: \n";
            cout << "(1) Elementu perkelimas i pradzia\n";
            cout << "(2) Elementu perkelimas i pabaiga\n";
            cout << "(3) Elementu pasalinimas is pradzios\n";
            cout << "(4) Elementu pasalinimas is pabaigos\n";
            cout << "(5) Spausdinti deka\n";
            cout << "(0) Grizti i pagrindini meniu\n";
            cin >> komanda;
            if (komanda == 0) {continue;};
            if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6) {
                cout<<"Neteisinga komada. Bandykite dar karta: \n";
            }
            else if (komanda == 1) { // iterpti i pradzia
                if(head == nullptr) {
                    cout << "Dvikryptis sarasas tuscias. Nera ko perkelti.\n";
                }else {
                    dviKrypt* dabartinis = head;
                    do {
                        dekas* naujas = new dekas();
                        naujas->data = dabartinis->data;
                        naujas->next = front;
                        front = naujas;
                        if(rear == nullptr) { //jei dekas tuscias
                            rear = front;
                        }
                        dabartinis = dabartinis->next;
                    }while(dabartinis != head);
                    cout << "Elementai perkelti.\n";
                    print_dekas(front);
                    isvalyti_dviKrypt(head, tail);
                    print_dviKrypt(head);

                }
            }else if (komanda == 2) { //iterpti i pabaiga
                if(head == nullptr) {
                    cout << "Dvikryptis sarasas tuscias. Nera ko perkelti.\n";
                }else {
                    dviKrypt* dabartinis = head;
                    do {
                        dekas* naujas = new dekas();
                        naujas->data = dabartinis->data;
                        naujas->next = nullptr;
                        if(front == nullptr) { // jei tuscias
                            front = rear = naujas;
                        }else {
                            rear->next = naujas;
                            rear = naujas;
                        }
                        dabartinis = dabartinis->next;
                    }while(dabartinis != head);
                    cout << "Elementai perkelti.\n";
                    print_dekas(front);
                    isvalyti_dviKrypt(head, tail);
                    print_dviKrypt(head);
                }
            }else if (komanda == 3) { // salinti is pradzios
                if (front == nullptr) {
                    cout << "Vienkryptis sarasas (dekas) tuscias.\n";
                }else {
                    dekas* temp = front;
                    front = front->next;
                    if(front == nullptr) {
                        rear = nullptr;
                    }
                    delete temp;
                }

            }else if (komanda == 4) {// salinti is pabaigos
                struct dekas* temp = new struct dekas();
                if (front == nullptr) {
                    cout << "Vienkryptis sarasas (dekas) tuscias.\n";
                }else if(front == rear) {
                    delete rear;
                    front = nullptr;
                    rear = nullptr;
                }else {
                    dekas *temp = front;
                    while(temp->next != rear) {
                        temp = temp->next;
                    }
                    delete rear;
                    rear = temp;
                    rear->next = nullptr;
                }
            }else if (komanda == 5) {print_dekas(front);} // spausdinti deka
        }else if (komanda == 6) {print_dekas(front);} // spausdinti deka
    }
    return 0;
}
