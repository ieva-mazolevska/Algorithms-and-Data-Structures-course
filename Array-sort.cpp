#include <iostream>
using namespace std;


int main()
{
    int komanda;
    int size;
    double array[size]; //nurodomas masyvo dydis
    int l;
    int u;

    cout << "Nurodykite masyvo dydi: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Iveskite " << i + 1 << " elementa: ";
        cin >> array[i];
    }
    cout << endl;
    cout << "Ivesti elementai: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";

    }
    cout << endl;

        while (true) {
            cout << "Pasirinkite operacija: \n";
            cout << "(0) Masyvo spausdinimas \n";
            cout << "(1) Ivesti nauja masyva \n";
            cout << "(2) Apskaiciuoti elementu kieki duotame intervale \n";
            cout << "(3) Apskaiciuoti elementu, einanciu po maksimalios reiksmes, suma \n";
            cout << "(4) Surusiuoti masyva didejimo tvarka \n";
            cout << "(5) Iseiti \n";
            cin >> komanda;
            if (komanda == 5) {break;}
            if (komanda != 0 && komanda != 1 && komanda != 2 && komanda != 3 && komanda != 4 && komanda != 5) {
                cout<<"Neteisinga komada. Bandykite dar karta: \n";
            }
            else if (komanda == 0) {

                cout << "Ivesti elementai: ";
                for (int i = 0; i < size; i++) {
                    cout << array[i] << " ";

                }
                cout << endl;
            }

            else if (komanda == 1) {
                cout << "Nurodykite masyvo dydi: ";
                cin >> size;
                for (int i = 0; i < size; i++) {
                    cout << "Iveskite " << i + 1 << " elementa: ";
                    cin >> array[i];
                }
                cout << endl;
                cout << "Ivesti elementai: ";
                for (int i = 0; i < size; i++) {
                    cout << array[i] << " ";

                }
                cout << endl;
            }
            else if (komanda == 2) {
                cout << "Iveskite intervala [a;b]\n";
                cout << "a: ";
                cin >> l;
                cout << endl;
                cout << "b: ";
                cin >> u ;
                cout << "Elementu esanciu intervale [" << l << ";" << u << "] kiekis: " << u - l + 1 << endl;

            }
            else if (komanda == 3) {
                int maxReiksme = array[0];
                int maxIndeksas = 0;
                int maxSuma = 0;
                for (int i = 0; i < size; i++) { //randama maksimali reiksme ir jos indeksas
                    if (array[i] > maxReiksme) {
                        maxReiksme = array[i];
                        maxIndeksas = i;
                    }
                }
                cout << "Maksimali reiksme masyve yra: " << maxReiksme << endl;
                cout << "Maksimalios reiksmes indeksas: " << maxIndeksas << endl;
                for(int i =maxIndeksas + 1; i < size; i++) { //susumuojami elementai po maxIndeksas
                    maxSuma += array[i];
                }
                cout << "Elementu, einanciu po maksimalios reiksmes, suma: " << maxSuma << endl;
            }
            else if (komanda == 4) {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (array[j] > array[j + 1]) {
                            // salia esantys elem yra lyginami ir keiciami vietomis, jei pirmasis yra didesnis uz antraji
                            int temp = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = temp;
                        }
                    }
                }
                cout <<"Masyvas surusiuotas didejimo tvarka: ";
                for (int i = 0; i < size; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
    return 0;
}
