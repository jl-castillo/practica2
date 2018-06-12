#include<iostream>
#include<conio.h>

using namespace std;

void quicksort(float a[],int prim,int ult);
void quicksort1(float a[],int prim,int ult);
void mostrar(float a[],int lim);
void entrada(float a[],int lim);
int promedio(float a[],int lim);
void Comparacion(float a[],int lim,float Prom);

int main(){
    float a[' '],Prom;
    int lim,opc;
    char res;
    do{
    	system("cls");
    	cout<<"1-Introducir calificaciones\n2-Mostrar Calificaciones\n";
		cout<<"3-Ordenar de manera descendente\n";
		cout<<"4-Ordenar de manera ascendente\n";
		cout<<"5-Promedio\n6-Mayores del Promedio"<<endl;
    	cin>>opc;
    	switch(opc){
    		case 1:cout<<"Igresar Numero de calificaciones a introducir: "<<endl;
    				cin>>lim;
    				cout<<"Ingrese Calificacion: "<<endl;
    				entrada(a,lim);
    				getch();
    				break;
    		case 2: cout<<"Mostrar las calificaciones: "<<endl;
	    			mostrar(a,lim);
	    			getch();
	    			break;
	    	case 3:  cout<<endl<<"Las calificaciones ordenadas de forma descendente: "<<endl;
	    		    quicksort(a,0,lim-1);
	    			mostrar(a,lim);
	    			getch();
	    			break;
	    	case 4: cout<<"Calificaciones ordenadas de forma ascendente: "<<endl;
	    			quicksort1(a,0,lim-1);
	    			mostrar(a,lim);
	    			getch();
	    			break;
	    	case 5: cout<<"Promedio de las calificaciones: "<<endl;
	    			Prom=promedio(a,lim);
	    			getch();
	    			break;
	    	case 6: cout<<"calificaciones mayores alpromedio son: "<<endl;
	    			Comparacion(a,lim,Prom);
	    			getch();
	    			break;
	    }
	system("cls");
	} 
	while(opc!=7);
	getch();		
}

void Comparacion(float a[],int lim,float Prom){
	int x;
    for(x=0;x<lim;x++){
   	if(a[x]>Prom)
        cout<<a[x]<<endl;
    }
}

int promedio(float a[],int lim){
	int x,L=0;
	float Prom;
    for(x=0;x<lim;x++){
        L=a[x]+L;
    }
    Prom=L/lim;
    cout<<Prom<<endl;
    return Prom;
}

    void entrada(float a[],int lim){
        int x;
        for(x=0;x<lim;x++){
        cout<<"a["<<x<<"]=";
        cin>>a[x];
        }
    }

    void mostrar(float a[],int lim){
        int x;
        for(x=0;x<lim;x++){
                cout<<a[x]<<" "<<endl;
        }
    }

    void quicksort(float a[],int prim,int ult){
        int central,i,j,pivote,temp;
        central=(prim+ult)/2;
        pivote=a[central];
        i=prim;
        j=ult;
        do{
            while(a[i]<pivote)i++;
            while(a[j]>pivote)j--;
            if(i<=j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i++;
                j--;
            }
        }while(i<=j);
        if(prim<j)
            quicksort(a,prim,j);
        if(i<ult)
            quicksort(a,i,ult);
    }

void quicksort1(float a[],int prim,int ult){
        int central,i,j,pivote,temp;
        central=(prim+ult)/2;
        pivote=a[central];
        i=prim;
        j=ult;
        do{
            while(a[i]>pivote)i++;
            while(a[j]<pivote)j--;
            if(i<=j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i++;
                j--;
            }
        }while(i<=j);
        if(prim<j)
            quicksort(a,prim,j);
        if(i<ult)
            quicksort(a,i,ult);
    }

