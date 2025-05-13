/*1. Duoti sveiki skaičiai n ir m (m<n).
 *Simboliai s1, s2, … , sn surašyti į sąrašą.
Sukurti kitą sąrašą, kuriame būtų simboliai sm+1, sm+2, …, sn, sm, …, s1.
 */


#include <iostream>
using namespace std;


struct charNode {
    char data;
    charNode *next;
};

charNode *charHead = nullptr;
charNode *charTail = nullptr;
charNode *elem;

struct newNode {
    char data;
    newNode* next;
};
newNode* front = nullptr;
newNode* rear = nullptr;



int main() {
    int n,m; //m<n
    char simbolis;
    cout << "Iveskite sveika skaiciu n: ";
    cin >> n;
    cout << "Iveskite sveika skaiciu m: ";
    cin >> m;
    for (int i = 1; i <= n; i++) { //kuriamas pirmas sarasas
        elem = new charNode (); //kuriamas naujas node simboliui
        cout << "Iveskite simboli: ";
        cin >> simbolis;
        elem->data = simbolis;
        elem->next = nullptr;
        if (charHead == nullptr) {
            //pirmojo mazgo tvarkymas
            charHead = elem;
            charTail = elem;
        } else {//jei sarasas netuscias
            charTail->next = elem; //paskutinio elem rodykle rodo i nauja paskutini mazga
            charTail = elem;
        }
    }
    cout << "Simboliu sarasas: ";
    charNode *currentNode = charHead; //loop'ui eiti per sarasa
    if (charHead == nullptr ) {
        cout << "Sarasas yra tuscias.\n";
    }else {
        while(currentNode != nullptr) { //saraso spausdinimas
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
    cout << endl;
    charNode* currentNaujas = charHead;
    if (charHead == nullptr) {cout << "Sarasas yra tuscias.\n";}
    else {
        for (int i = 1; i <= m; i++) {
            currentNaujas = currentNaujas->next;
        }

        while (currentNaujas != nullptr) {
            newNode* naujas = new newNode ();
            naujas->data = currentNaujas->data;
            naujas->next = nullptr;
            if(front == nullptr) {
                front = naujas;
                rear = naujas;
            }else {
                rear->next = naujas;
                rear = naujas;
            }
            currentNaujas = currentNaujas->next;
        }

        int i = 0;
        int elementOfInterest = m-1;
        while (i < m) {
            currentNaujas = charHead;
            for (int j = 0; j <= elementOfInterest; j++) {
                if (j != elementOfInterest) {
                    currentNaujas = currentNaujas->next;
                    continue;
                }
                newNode* naujas = new newNode();
                naujas->data = currentNaujas->data;
                naujas->next = nullptr;
                rear->next = naujas;
                rear = naujas;
                currentNaujas = currentNaujas->next;
            }
            elementOfInterest--;
            i++;
        }

        newNode* temp2 = new newNode ();
        temp2 = front;
        cout << "Naujas sarasas: ";
        while (temp2 != nullptr) {
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }
    }
    return 0;
}
