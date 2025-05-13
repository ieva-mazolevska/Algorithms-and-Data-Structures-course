/*Skaičius įrašykite į  vienkryptį sąrašą. Skaičiai gali kartotis.
 *Sukurti dvikryptį sąrašą į kurį papuola tik nepasikartojantys skaičiai. */

#include <iostream>
using namespace std;

struct vienKrypt {
    int data;
    vienKrypt* next;
};
vienKrypt* front = nullptr;
vienKrypt* rear = nullptr;

struct dviKrypt {
    int data;
    dviKrypt* next;
    dviKrypt* prev;
};
dviKrypt* head = nullptr;
dviKrypt* tail = nullptr;




void print_dviKrypt(dviKrypt* head) {
    cout << "Dvikryptis sarasas: ";
    dviKrypt* dabartinis = head;
    while (dabartinis != nullptr) {
        cout << dabartinis->data << " ";
        dabartinis = dabartinis->next;
    }
    cout << endl;
}

void print_vienKrypt(vienKrypt* head) {
    cout << "Vienkryptis sarasas: ";
    vienKrypt* dabartinis = front;
    while (dabartinis != nullptr) {
        cout << dabartinis->data << " ";
        dabartinis = dabartinis->next;
    }
    cout << endl;
}

int main() {
    int komanda;
    double b;
    while(true) {
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Elemento ivedimas i vienkrypti sarasa\n";
        cout << "(2) Vienkrypcio saraso spausdinimas\n";
        cout << "(3) Perkelti elementus i dvikrypti sarasa.\n";
        cout << "(4) Dvikrypcio saraso spausdinimas\n";
        cout << "(0) Iseiti\n";
        cin >> komanda;
        if (komanda == 0) {break;};
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6) {
            cout<<"Neteisinga komada. Bandykite dar karta: \n";
        }
        else if (komanda == 1) {
            //elem iterpimas
            cout << "Iveskite nauja elementa: ";
            cin >> b;
            vienKrypt* naujas = new vienKrypt();
            naujas->data = b;
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
        }else if (komanda == 2) {// spausdinti vienKrypt
            print_vienKrypt(front);
        }else if (komanda == 3) {//perkelti i dviKrypt
            if (front == nullptr) {
                cout << "Vienkryptis sarasas tuscias.\n";
                continue;
            }
            vienKrypt* elem = front;
                while (elem != nullptr) {
                    vienKrypt* sekantis = elem->next; // saugom
                    int el = elem->data;
                    int kiekKart = 0;
                    vienKrypt* temp = front;
                    while (temp != nullptr) {
                        if (temp->data == el) {
                            kiekKart++;
                        }
                        temp = temp->next;
                    }

                    if (kiekKart != 1) {
                        elem = sekantis;
                        continue;
                    }
                    dviKrypt* naujas = new dviKrypt();
                    naujas->data = el;
                    if (head == nullptr) {//pirmas mazgas
                        head = naujas;
                        tail = naujas;
                        naujas->next = nullptr;
                        naujas->prev = nullptr;
                    }else {
                        tail->next = naujas;
                        naujas->prev = tail;
                        naujas->next = nullptr;
                        tail = naujas;
                        }

                    // is vienkrypcio pasalinam visus su ta pacia reiksme
                    vienKrypt* isimti = front;
                    vienKrypt* buves = nullptr;
                    while (isimti != nullptr) {
                        if(isimti->data == el) {
                            if(isimti == front) {
                                front = isimti->next;
                            }else {
                                buves->next = isimti->next;
                            }

                            vienKrypt* temp = isimti;
                            isimti = isimti->next;
                            delete temp;
                        }else {
                            buves = isimti;
                            isimti = isimti->next;
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
        }else if (komanda == 4) { //Dvikrypcio saraso spausdinimas
            print_dviKrypt(head);
        }
    }

    return 0;
}
