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
    char symbol;
    charNode *next;
};
charNode *charHead = nullptr;
charNode *charTail = nullptr;

int main() {

    int n,m; //m<n
    cout << "Iveskite sveika skaiciu n: ";
    cin >> n;
    cout << "Iveskite gsveika skaiciu m: ";
    cin >> m;
    for (int i = 0; i <= n; i++) {
        charNode *newNode = new charNode; //kuriamas naujas node simboliui
        newNode->next = nullptr;
        charHead->next = newNode;
        charTail->next = newNode;
        cout << "Iveskite simboli: ";
        cin >> newNode->symbol;
        cout << endl;
        newNode->next = newNode;
        charTail->next = newNode;

    }
    cout << "Simboliu sarasas: ";
    charNode *currentNode = charHead; //loop'ui eiti per sarasa
    while(currentNode != nullptr) { //saraso spausdinimas
        cout << currentNode->symbol << ", ";
        currentNode = currentNode->next;
    }




    return 0;
}
