#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Busqueda_Fibonacci(int A[], int x, int n);

int main()
{
    int n = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 8;
    
    int resultado = Busqueda_Fibonacci(arr, x, n);
    if (resultado == -1) {
        cout << "\nEl Elemento no existe"<<endl;
    }
    else cout << "\nElemento encontrado en la posicion: " << resultado;
    return 0;
}


int Busqueda_Fibonacci(int A[], int x, int n)
{
    int fbM2 = 0;
    int fbM1 = 1;
    int fbM = fbM2 + fbM1;
    int offset = -1;
    while (fbM < n)
    {
        fbM2 = fbM1;
        fbM1 = fbM;
        fbM  = fbM2 + fbM1;
    }
    while (fbM > 1)
    {
        int i = min(offset + fbM2, n - 1);
        if (A[i] < x)
        {
            fbM  = fbM1;
            fbM1 = fbM2;
            fbM2 = fbM - fbM1;
            offset = i;
        }
        else if (A[i] > x)
        {
            fbM  = fbM2;
            fbM1 = fbM1 - fbM2;
            fbM2 = fbM - fbM1;
        }
        else return i;
    }
    if (fbM1 && A[offset + 1] == x)
        return offset + 1;

    return -1;
}


