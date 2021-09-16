#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Busqueda_Interpolacion(int elementos[], int n, int num);

int main(void)
{
    int elementos[5];
	int num=0;
	int n=5;
	
	for(int i=0; i<5; i++){
		cout<<"Ingrese un numero"<<endl;
		cin>>elementos[i];
	}
	
	cout<<"\nIngrese el numero a buscar"<<endl;
	cin>>num;
	
    int resultado = Busqueda_Interpolacion(elementos, n, num);
    
    if (resultado == -1) {
        cout << "\nEl Elemento no existe"<<endl;
    }
    else cout << "\nElemento encontrado en la posicion: " << resultado;
    
	return 0;
}

int Busqueda_Interpolacion(int elementos[], int n, int num)
{
    int inf = 0;
    int sup = n - 1;
    int mitad;

    while ((elementos[sup] != elementos[inf]) && (num >= elementos[inf]) && (num <= elementos[sup])) {
    	
        mitad = inf + ((num - elementos[inf]) * (sup - inf) / (elementos[sup] - elementos[inf]));

        if (elementos[mitad] < num)
            inf = mitad + 1;
        else if (num < elementos[mitad])
            sup = mitad - 1;
        else
            return mitad;
    }

    if (num == elementos[inf])
        return inf ;
    else
        return -1;
}


