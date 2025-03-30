/*1. Duoti sveiki skaičiai n ir m (m<n).
 *Simboliai s1, s2, … , sn surašyti į sąrašą.
Sukurti kitą sąrašą, kuriame būtų simboliai sm+1, sm+2, …, sn, sm, …, s1.
 */


#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode *next;
};
listNode *head = nullptr;
listNode *tail = nullptr;

struct charNode {
    char data;
    charNode *next;
};

charNode *charHead = nullptr;
charNode *charTail = nullptr;
charNode *elem;

int main() {

    int n,m; //m<n
    char simbolis;
    cout << "Iveskite sveika skaiciu n: ";
    cin >> n;
    cout << "Iveskite gsveika skaiciu m: ";
    cin >> m;
    for (int i = 0; i <= n; i++) {
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
            cout << currentNode->data << ", ";
            currentNode = currentNode->next;
        }
    }




    return 0;
}
