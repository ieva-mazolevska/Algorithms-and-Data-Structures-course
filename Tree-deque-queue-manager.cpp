/*Sukurti dvejetainį medį, kurio elementai sveiki skaičiai. Realizuoti įterpimo, paieškos,
spausdinimo ir šalinimo operacijas bei atlikti šiuos veiksmus:
a. Įrašyti iš medžio visus skaičius, kurie priklauso intervalui [a;b] į deką, realizuotą kaip
sąrašas, į pradžią.
b. Įrašyti iš medžio visus skaičius, kurie priklauso intervalui [0;a] į deką, realizuotą kaip
sąrašas, į pabaigą.
c. Pašalinti iš medžio visus skaičius, kurie priklauso intervalui [b;c] iš medžio, įrašant
juos į eilę, realizuotą kaip sąrašas.
d. Spausdinti deką ir eilę
 *
 */


#include <iostream>
using namespace std;

struct medis {
    int data;
    medis *desine;
    medis *kaire;
    static medis *saknis; //static, kad butu bendras visiems
};
medis *medis::saknis = nullptr; //Inicializacija
//elemento iterpimas
medis* iterpti(medis *saknis, int x){ //rekursine funkcija
    if (saknis == nullptr) {
        medis *p = new medis;
        p->data = x;
        p->kaire = nullptr;
        p->desine = nullptr;
        return p;
    }else if(x > saknis->data) {
        saknis->desine = iterpti(saknis->desine,x);
    }else {
        saknis->kaire=iterpti(saknis->kaire,x);
    }
    return saknis;
}
medis* paieska (medis *saknis, int x) {
    //elemento paieska
    if (saknis == nullptr || saknis->data == x) {
        return saknis;
    }
    else if(x > saknis->data) {
        return paieska(saknis->desine,x);
    }
    else {
        return paieska(saknis->kaire,x);
    }

}

bool paieska2(medis *saknis, int x) {
        while (saknis != nullptr) {
            if (saknis->data == x) {
                return true; //elementas rastas
            } else if (x < saknis->data) {
                saknis = saknis->kaire; // iesko kairej pusej
            }else {
                saknis = saknis->desine; //iesko desinej pusej
            }
        }
        return false; // elem nerastas
    }

void spausdinti(medis *saknis) {
    if (saknis != nullptr) {
        spausdinti(saknis->kaire);
        cout << saknis->data << " ";
        spausdinti(saknis->desine);

    }
}
medis* rasti_min(medis *saknis){
    if(saknis == nullptr)
        return nullptr;
    else if(saknis->kaire != nullptr)
        return rasti_min(saknis->kaire);
    return saknis;
}
medis* rasti_max(medis *saknis) {
    if(saknis == nullptr) {
        return nullptr;
    }else if(saknis->desine != nullptr) {
        return rasti_max(saknis->desine);
    }
    return saknis;
}
medis* panaikinti(medis *saknis, int x) {
    if (saknis == nullptr) {
        return nullptr;
    }else if(x>saknis->data) {
        saknis->desine = panaikinti(saknis->desine, x);
    }else if(x<saknis->data) {
        saknis->kaire = panaikinti(saknis->kaire, x);
    }
    else if(saknis->kaire == nullptr && saknis->desine == nullptr) {
        delete saknis;
        return nullptr;
    }else if(saknis->kaire == nullptr ||saknis->desine == nullptr) {
        medis *temp;
        if(saknis->kaire == nullptr) {
            temp = saknis->desine;
        }else{temp = saknis->kaire;}
        free(saknis);
        return temp;
    }
    else {
        medis *temp = rasti_max(saknis->kaire);
        saknis->data = temp->data;
        saknis->kaire = panaikinti(saknis->kaire, temp->data);
    }
    return saknis;
}
struct DekoSarasas {
    int data;
    DekoSarasas *next;
    DekoSarasas *prev;
};
struct Dekas {
    DekoSarasas *pradzia;
    DekoSarasas *pabaiga;
    Dekas() : pradzia(nullptr), pabaiga(nullptr) {}
    void prideti_i_pradzia(int data) {
        DekoSarasas *naujas = new DekoSarasas{data, pradzia, nullptr};
        if (pradzia != nullptr) {
            pradzia->prev = naujas;
        }
        pradzia = naujas;
        if (pabaiga == nullptr) {
            pabaiga = naujas;
        }
    }
    void prideti_i_pabaiga(int data) {
        DekoSarasas *naujas = new DekoSarasas{data, nullptr, pabaiga};
        if (pabaiga != nullptr) {
            pabaiga->next = naujas;
        }
        pabaiga = naujas; //priskirta pabaiga
        if (pradzia == nullptr) {
            pradzia = naujas;
        }
    }
};
//elem paieska intervale
void paieskaInt(medis *saknis, int a, int b, Dekas& dekas) {
    if (saknis == nullptr) {return;}
    if (saknis->data >= a && saknis->data <= b) {
        dekas.prideti_i_pradzia(saknis->data);
    }
    if(saknis->data >= a) {
        paieskaInt(saknis->kaire, a, b, dekas);
    }
    if (saknis->data <= b) {
        paieskaInt(saknis->desine, a, b, dekas);
    }
}
void paieskaIntP(medis *saknis, int a, Dekas& dekas) {
    if (saknis == nullptr) return;
    if (saknis->data >= 0 && saknis -> data <= a) {
        dekas.prideti_i_pabaiga(saknis->data);
    }
    if (saknis->data > 0) {
        paieskaIntP(saknis->kaire, a, dekas);
    } if(saknis->data <= a) {
        paieskaIntP(saknis->desine, a, dekas);
    }

}
void spausdinti_deka (Dekas& dekas) {
    DekoSarasas *temp = dekas.pradzia;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
struct eileSarasas{
    int data;
    eileSarasas *next;
};
struct eile {
    int size;
    eileSarasas *pradzia;
    eileSarasas *pabaiga;
    eile() : size(0), pradzia(nullptr), pabaiga(nullptr){}
};
struct elem {
    int data;
    struct elem *next;
};
void intialize (eile *q) {
    q->size = 0;
    q->pradzia = nullptr;
    q->pabaiga = nullptr;
}
bool isempty(eile *q) {
    return q->pradzia == nullptr;
}
void iterptiE(eile *q, int reiksme) {
    eileSarasas *temp = new eileSarasas{reiksme, nullptr};
        if(!isempty(q)) {
            q->pabaiga->next = temp;
            q->pabaiga = temp;
        } else {
            q->pradzia = q->pabaiga = temp;
        }
            q->size++;
        }
medis* pasalintiEile(medis* saknis, int b, int c, eile& eile) {
    if(saknis == nullptr) {return nullptr;}
    if (saknis->data >= b && saknis->data <= c) {
        iterptiE(&eile, saknis->data);
        saknis = panaikinti(saknis, saknis->data);
    }
    if (saknis != nullptr && saknis -> data >= b) {
        saknis->kaire = pasalintiEile(saknis->kaire, b, c, eile);
    }
    if (saknis != nullptr && saknis->data <= c) {
        saknis->desine = pasalintiEile(saknis->desine, b, c, eile);
    }
    return saknis;
}
void spausdinti_eile(eile& eile) {
    eileSarasas *temp = eile.pradzia;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Dekas global_dekas;
eile global_eile;
int main() {
    int komanda, x, a, b, c;
    while(true) {
        cout << endl;
        cout << "Pasirinkite norima operacija: \n";
        cout << "(1) Medzio spausdinimas\n";
        cout << "(2) Naujo elemento iterpimas\n";
        cout << "(3) Elemento salinimas\n";
        cout << "(4) Paieska\n";
        cout << "(5) a. Irasyti is medzio visus skaicius, kurie priklauso intervalui [a;b] i deka, realizuota kaip sarasas, i pradzia:\n";
        cout << "(6) b. Irasyti is medzio visus skaicius, kurie priklauso intervalui [0;a] i deka, realizuota kaip sarasas, i pabaiga\n";
        cout << "(7) c. Pasalinti is medzio visus skaicius, kurie priklauso intervalui [b;c] is medzio, irasyti juos i eile, realizuota kaip sarasas\n";
        cout << "(8) d. Spausdinti deka ir eile\n";
        cout << "(9) Iseiti\n";
        cin >> komanda;
        if (komanda == 9) { break; }
        if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5 && komanda != 6 && komanda != 7 && komanda != 8 && komanda != 9) {
            cout << "Neteisinga komanda. Bandykite dar karta: \n";
        }
        else if (komanda == 1) {
            cout << "Medis: ";
            spausdinti(medis::saknis);// Saraso spausdinimas
        }
        else if (komanda == 2) {
            cout << "Iveskite elementa: ";
            cin >> x;
            medis::saknis = iterpti(medis::saknis, x);

        }else if (komanda == 3) {
            cout << "Iveskite elementa: ";
            cin >> x;
            panaikinti(medis::saknis, x);
        }
        else if (komanda == 4) {
            cout << "Iveskite elementa: ";
            cin >> x;
            if (paieska2(medis::saknis, x)) {
                cout << "Elementas rastas.";
            }else {
                cout << "Elelmentas nerastas.";
            }
        }
        else if (komanda == 5) {
            //a. Irasyti is medzio visus skaicius, kurie priklauso intervalui [a;b] i deka, realizuota kaip sarasas, i pradzia
            cout << "Iveskite intervala: \n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
            cout << "Dekas: ";
            Dekas dekas;
            paieskaInt(medis::saknis, a, b, global_dekas);//elemento paieska
            spausdinti_deka(global_dekas);
        }
        else if (komanda == 6) { //b. Irasyti is medzio visus skaicius, kurie priklauso intervalui [0;a] i deka, realizuota kaip sarasas, i pabaiga
            cout << "Iveskite intervala: \n";
            cout << "a: ";
            cin >> a;
            Dekas dekas;
            paieskaIntP(medis::saknis, a, global_dekas);
            spausdinti_deka(global_dekas);
        }
        else if (komanda == 7) {
            cout << "Iveskite intervala: \n";
            cout << "b: ";
            cin >> b;
            cout << endl;
            cout << "c: ";
            cin >> c;
            cout << endl;
            cout << "Eile: ";
            eile eile;
            medis::saknis = pasalintiEile(medis::saknis, b, c, global_eile);
            spausdinti_eile(global_eile);
        }
        else if (komanda == 8) {
            Dekas dekas;
            cout << "Dekas: ";
            spausdinti_deka(global_dekas);
            cout << endl;
            eile eile;
            cout << "Eile: ";
            spausdinti_eile(global_eile);
            cout << endl;
        }
    }
        return 0;
}
