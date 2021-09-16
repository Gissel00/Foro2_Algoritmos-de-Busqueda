//ALGORITMO DE BUSQUEDA POR SECUENCIA Y BINARIA

#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Busqueda_Secuencial(int num, int elementos[]);
void Busqueda_Binaria(int num, int elementos[]);

int main(int argc, char** argv) {
	
	int elementos[5];
	int num=0;

	
	for(int i=0; i<5; i++){
		cout<<"Ingrese un numero"<<endl;
		cin>>elementos[i];
	}
	
	cout<<"\nIngrese el numero a buscar"<<endl;
	cin>>num;
	
	cout<<"\nFuncion Secuencial"<<endl;
	Busqueda_Secuencial(num,elementos);
	
	cout<<"\nFuncion Binaria"<<endl;
	Busqueda_Binaria( num,  elementos);
}

void Busqueda_Secuencial(int num, int elementos[]){
	bool bandera=false;
	
	for(int i=0; i<5; i++){
		if(elementos[i]==num){
			bandera=true;
		}
	}
	
	if(bandera==false){
		cout<<"\nEl elemento no existe"<<endl;
	}else{
		cout<<"\nElemento encontrado"<<endl;
	}
	
}

void Busqueda_Binaria(int num, int elementos[])
{
	int mitad;
	bool bandera=false;
	
    int inf=0;
    int sup=5;
	
    while(inf<= sup)
    {
        mitad = (inf+sup)/2;
       
	    if(elementos[mitad]==num){
        	bandera=true;
        	break;
		}
		if(elementos[mitad]>num){
			sup=mitad;
			mitad = (inf+sup)/2;
		}
		if(elementos[mitad]<num){
			inf=mitad;
			mitad = (inf+sup)/2;
		}
    }
    
	if(bandera==false){
		cout<<"\nEl elemento no existe"<<endl;
	}else{
		cout<<"\nElemento encontrado en la posicion: "<<mitad<<endl;
	}
}
