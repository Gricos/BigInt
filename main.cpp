#include "BigInt.h"
#include <conio.h>
#include <windows.h>

using namespace std;

///MENIU

void Lista()
{
    cout << "1. Afiseaza paritatea unui numar"<< '\n';
    cout << "2. Compara 2 numere"<< '\n';
    cout << "3. Aduna 2 numere"<< '\n';
    cout << "4. Scade 2 numere"<< '\n';
    cout << "5. Inmulteste un numar mare cu un scalar"<< '\n';
    cout << "6. Imparte un numar mare cu un scalar"<< '\n';
    cout << "7. Restul impartirii unui numar mare cu un scalar"<< '\n';
    cout << "8. Revezi meniul"<< '\n';
    cout << "9. Sterge ecranul" << '\n';
    cout << "10. Iesire"<< '\n';
}

void Meniu()
{
    Lista();
    int i = 0;
    bool ok = false;
    do
    {
        cin >> i;
        switch(i)
        {
            case 1:
                {
                    cout << "Introdu numarul"<< '\n';
                    BigInt numar1, numar2;
                    cin >> numar1;
                    if(numar1.Paritate())
                        cout << "Numarul este par" << '\n';
                    else
                        cout << "Numarul este impar" << '\n';
                }
                break;
            case 2:
                {
                    cout << "Introdu 2 numere"<< '\n';
                    BigInt numar1, numar2;
                    cin >> numar1 >> numar2;
                    if (numar1 > numar2)
                        cout << "Numarul 1 > numarul 2"<< '\n';
                    else if (numar1 < numar2)
                        cout << "Numarul 1 < numarul 2"<< '\n';
                    else
                        cout << "Numarul 1 = numarul 2" << '\n';
                }
                break;

            case 3:
                {
                    BigInt numar1, numar2;
                    cout << "Introdu 2 numere"<< '\n';
                    cin >> numar1 >> numar2;
                    numar1 = numar1 + numar2;
                    cout << numar1 << '\n';
                }
                break;
            case 4:
                {
                    BigInt numar1, numar2;
                    cout << "Introdu 2 numere (primul mai mare ca celalalt)"<< '\n';
                    cin >> numar1 >> numar2;
                    if(numar1 >= numar2)
                    {
                        numar1 = numar1 - numar2;
                        cout << numar1 << '\n';
                    }
                    else
                    {
                        cout << "Numerele nu sunt bune" << '\n';
                    }
                }
                break;
            case 5:
                {
                    BigInt numar1;
                    int numar2;
                    cout << "Introdu numarul mare" << '\n';
                    cin>>numar1;
                    cout << "Introdu scalarul de maxim 8 cifre" << '\n';
                    cin>>numar2;
                    numar1 = numar1 * numar2;
                    cout << numar1 << '\n';
                }
                break;
            case 6:
                {
                    BigInt numar1;
                    int numar2;
                    cout << "Introdu numarul mare" << '\n';
                    cin>>numar1;
                    cout << "Introdu scalarul de maxim 8 cifre" << '\n';
                    cin>>numar2;
                    numar1 = numar1 / numar2;
                    cout << numar1 << '\n';
                }
                break;
            case 7:
                {
                    BigInt numar1;
                    int numar2;
                    unsigned long long rest;
                    cout << "Introdu numarul mare" << '\n';
                    cin>>numar1;
                    cout << "Introdu scalarul de maxim 8 cifre" << '\n';
                    cin>>numar2;
                    rest = numar1 % numar2;
                    cout << '\n';
                    cout << "Rezultatul este: ";
                    cout << rest << '\n';
                }
                break;
            case 8:
                {
                    system("cls");
                    Lista();
                }
                break;
            case 9:
                {
                    system("cls");
                }
                break;
            case 10:
                {
                    ok=true;
                }
                break;
        };
    }while(!ok);
}


int main()
{
    Meniu();
}
