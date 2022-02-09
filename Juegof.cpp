#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#define color SetConsoleTextAttribute
using namespace std;
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );


char Tablero1[19][27]={
    {57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,49  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,49  ,48  ,49  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,49  ,48  ,49  ,48  ,49  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,49  ,48  ,49  ,48  ,49  ,48  ,49  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,51  ,48  ,51  ,48  ,51  ,48  ,51  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,53  ,48  ,53  ,48 ,53 ,48 ,53 ,57  },
    {57  ,48  ,51  ,48  ,51  ,48  ,51  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,53  ,48  ,53 ,48 ,53 ,48 ,57  },
    {57  ,48  ,48  ,51  ,48  ,51  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,53  ,48 ,53 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,51  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,53 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,54  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,52 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,54  ,48  ,54  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,52  ,48 ,52 ,48 ,48 ,57  },
    {57  ,48  ,54  ,48  ,54  ,48  ,54  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,52  ,48  ,52 ,48 ,52 ,48 ,57  },
    {57  ,54  ,48  ,54  ,48  ,54  ,48  ,54  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,56  ,48  ,52  ,48  ,52  ,48 ,52 ,48 ,52 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,50  ,48  ,50  ,48  ,50  ,48  ,50  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,50  ,48  ,50  ,48  ,50  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,50  ,48  ,50  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,50  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48  ,48 ,48 ,48 ,48 ,57  },
    {57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  ,57  }
};

struct datos{
    string nombre;
    char id;
    int cMovimientos;
    int zInicio;
    int opuestoI;
    int opuestoJ;
};
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void Presentacion(){
    int logo[25][80]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,3,3,3,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,0,0,0,3,3,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,0,0,0,5,5,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,5,5,5,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,5,5,5,5,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    for(int i=0; i<25; i++){
        for(int j=0; j<80; j++){
            if(logo[i][j]== 1){
     	        cout<<char(219);
            }
            else if(logo[i][j]== 2){
                color(hConsole,178);  
     	        cout<<char(219);
                color(hConsole,180);
            }
            else if(logo[i][j]== 3){
                color(hConsole,189);  
     	        cout<<char(219);
                color(hConsole,180);
            }
            else if(logo[i][j]== 4){
                color(hConsole,179);  
     	        cout<<char(219);
                color(hConsole,180);
            }
            else if(logo[i][j]== 5){
                color(hConsole,184);  
     	        cout<<char(219);
                color(hConsole,180);
            }
            else if(logo[i][j]== 6){
                color(hConsole,190);  
     	        cout<<char(219);
                color(hConsole,180);
            }	
            else{
                cout<<" ";
            }	
        }
    	cout<<endl;
    }
}
void Creditos(){
    gotoxy(60,27);
    cout<<"Elaborador por:"<<endl;
    gotoxy(60,28);
    cout<<"RAMSES SALINAS"<<endl;
    gotoxy(60,29);
    cout<<"MAYCOL CRUZ"<<endl;
    gotoxy(60,30);
    cout<<"PAULO CALDERON"<<endl;
 }
int opciones(){
    int opcion, *aux=new int;
    *aux=0;
    cout<<"Presione 1 para leer instrucciones.\nPresione 2 para ver records.\nPresione 3 para jugar.\nPresione 4 para cerrar juego."<<endl;
    do{
        if(*aux>0)
            cout<<"Numero de opcion incorrecto, vuelva a intentar"<<endl;
        cout<<"Numero de opcion: ";
        cin>>opcion;
        (*aux)++;
    }while(opcion>4||opcion<1);
    delete aux;
    return opcion;
fflush(stdin);
}
void Instrucciones(){
    ifstream instrucciones;
    string cadena;
    instrucciones.open("Instrucciones.txt",ios::in);
    if(instrucciones.is_open()){
        getline(instrucciones,cadena);
        cout<<cadena<<endl;
        while(!instrucciones.eof()){
            getline(instrucciones,cadena);
            cout<<cadena<<endl;
        }
        instrucciones.close();
    }
    else
        cout<<"Error al abrir instrucciones"<<endl;
}
void borrarConsola(){
    gotoxy(1,1);
    for(int i=0; i<120; i++){
        for(int j=0; j<1; j++)
            cout<<"                                                                                                                  ";
        cout<<endl;
    }
    gotoxy(1,1);
}
void obtieneTablero(char **tablero){
    for(int i=0; i<19; i++)
        for(int j=0; j<27; j++)
            tablero[i][j]=Tablero1[i][j];
}

void registroJugadores(datos *jugador, int &contador, int cantJ){
    string *aux=new string;
    for(int i=0; i<2;i++){
        cout<<"Digita el nombre de un jugador: "; cin>>jugador[i].nombre;
        contador++;
        cout<<"Digite el caracter que identificara a "<<jugador[i].nombre<<": "; cin>>jugador[i].id;
        contador++;    
        fflush(stdin);
    }
    delete aux;
}
void dado(datos *jugador, int &contador, int cantJ){
    int *dado= new int[cantJ];
    char *presiono=new char,*aux=new char;
    string *aux1=new string;
    for(int i=0; i<cantJ; i++){
        srand(time(NULL));
        cout<<"Jugador "<<jugador[i].nombre<<",";
        do{
            cout<<" presiona enter para lanzar el dado: "<<endl; 
            contador++;
            *presiono=getch(); 
            if(*presiono==13){
                dado[i]=1+rand()%(6-1+1);
                cout<<"El dado dio "<<dado[i]<<" como resultado"<<endl;
                contador++;
            }
        }while (*presiono!=13);
    }
    cout<<endl;
    contador++;
    for(int i=0; i<cantJ; i++){
        for(int j=i; j<cantJ; j++){
            if(dado[i]<dado[j]){
            *aux=jugador[i].id;
            jugador[i].id=jugador[j].id;
            jugador[j].id=*aux;
            *aux1=jugador[i].nombre;
            jugador[i].nombre=jugador[j].nombre;
            jugador[j].nombre=*aux1;
            }
        }
    }
    for(int i=0; i<cantJ; i++){
        cout<<"Jugador "<<jugador[i].nombre<<", seras el jugador numero "<<i+1<<"."<<endl;
        contador++;
    }
    delete aux;
    delete aux1;
    delete presiono;
    delete dado;
    contador++;
}
void imprimirTablero(datos *jugador, char **tablero, int &contador, char &cincoSeis, char &cincoSiete){
    int *desplai=new int, *aux=new int;
    *aux=contador;
    color(hConsole,124);
    for(int i=0; i<19; i++){
        for(int j=0; j<27; j++){
            *desplai=*aux+i;
            gotoxy(j+27,*desplai);
            if(tablero[i][j]==48){
                cout<<"  ";
            }
            else if(tablero[i][j]==56){
                cout<<cincoSeis;
            }
            else if(tablero[i][j]==57){
                cout<<cincoSiete;
            }
            else{
                if(tablero[i][j]==jugador[0].id){
                    color(hConsole,115);
                    cout<<tablero[i][j];
                    color(hConsole,124);
                }
                else if(tablero[i][j]==jugador[1].id){
                    color(hConsole,117);
                    cout<<tablero[i][j];
                    color(hConsole,124);
                }
                else{
                    color(hConsole,121);
                    cout<<tablero[i][j];
                    color(hConsole,124);
                }
                
            }

        }
        contador++;
    }
    color(hConsole,180);
    delete desplai;
    delete aux;
    cout<<endl;
}
void escogeInicio(datos *jugador, char **tablero, int &contador){
    fflush(stdin);
    for(int i=0;  i<2; i++){
        do{
            cout<<"Jugador "<<jugador[i].nombre<<", digita el numero de tu zona de inicio: "; cin>>jugador[i].zInicio;
            contador++;
            switch (jugador[i].zInicio){
            case 1: jugador[i].zInicio=49;// ASCII
                    jugador[i].opuestoI=17;//Normal
                    jugador[i].opuestoJ=13;break;//Normal
            case 2: jugador[i].zInicio=50; 
                    jugador[i].opuestoI=1 ;
                    jugador[i].opuestoJ=13;break;
            case 3: jugador[i].zInicio=51; 
                    jugador[i].opuestoI=13;
                    jugador[i].opuestoJ=25; ;break;
            case 4: jugador[i].zInicio=52; 
                    jugador[i].opuestoI=5;
                    jugador[i].opuestoJ=1;break;
            case 5: jugador[i].zInicio=53; 
                    jugador[i].opuestoI=13;
                    jugador[i].opuestoJ=1 ;break;
            case 6: jugador[i].zInicio=54; 
                    jugador[i].opuestoI=5;
                    jugador[i].opuestoJ=25 ;break;
            default: cout<<"numero invalido"<<endl;
                    contador++;
                     jugador[i].zInicio=0; break;
            }
        }while (jugador[i].zInicio==0);
    }
    for(int i=0; i<19; i++){
        for(int j=0; j<27; j++){
            if(tablero[i][j]==jugador[0].zInicio){
                tablero[i][j]=jugador[0].id;
            }
            else if(tablero[i][j]==jugador[1].zInicio){
                tablero[i][j]=jugador[1].id;
            }
            else if(tablero[i][j]!=48&&tablero[i][j]!=56 &&tablero[i][j]!=57 &&tablero[i][j]!=jugador[1].zInicio&&tablero[i][j]!=jugador[2].zInicio){
                tablero[i][j]=56 ;    
            }
        }
    }
    fflush(stdin);
}
int determinaTurno(int &movimiento, int cantJ){
    int mod;
    mod=movimiento%cantJ;
    return mod;
}
void seleccionInvalida(int Y, int &contador, int &X, int &num){
    int *x=new int, *y=new int;
    *x=29+27;
    *y=Y,
    Y = Y+(contador-19);
    if(num!=4){
        gotoxy(*x, Y);
        if(num==2){
            cout<<"                                             ";
            num=4;
        }
        else if(num==0){
            cout<<"Seleccion invalida";
            num=2;
        }
        else if(num==1){
            cout<<"No es el turno de esa ficha!";
            num=2;
        }
        else if(num==3){
            cout<<"Debes colocar la ficha que seleccionaste.";
            num=2;
        }
        gotoxy(X+27, *y);
    }
    delete x;
    delete y;
}
double calculaDistancia(int &Y, int &X, int &cordX, int &cordY, double &difX, double &difY){
    double distancia;
    difX=cordX-X;
    difX=pow(difX,2);
    difY=cordY-Y;
    difY=pow(difY,2);
    distancia=pow(difX+difY,0.5);
    difX=pow(difX,0.5);
    difY=pow(difY,0.5);
    return distancia;
}
bool movimientoValido (datos *jugador, char **tablero, int &Y, int &X, int &cordX, int &cordY, int zInicio){
    double *difX=new double, *difY=new double;
    calculaDistancia(Y,X,cordX,cordY,*difX, *difY);
    switch(zInicio){
        case 0: if(*difX<=2&&*difY<=1){
                    delete difX;
                    delete difY;
                    return true;
                }
                else{
                    delete difX;
                    delete difY;
                    return false;
                }
                break;
        case 1: for(int a=0; a<2; a++){
                    for(int i=-*difY;i<=*difY;i++){
                        for(int j=-*difX;j<=*difX;j++){
                            if(cordY+i>=0&&cordX+j>=0&&cordY+i<19&&cordX+j<27){
                                if(tablero[cordY+i][cordX+j]==jugador[a].id&&i<=1&&i>=-1&&j>=-2&&j<=2){
                                    if(Y-(cordY+i)==(cordY+i)-cordY&&X-(cordX+j)==(cordX+j)-cordX){
                                        delete difX;
                                        delete difY;
                                        return true;
                                    }}}}}
                }
                delete difX;
                delete difY;
                return false;
                break;
        default:delete difX;
                delete difY;
                return false;
                break;
    }
}
void contadorMovimientos(datos *jugador, int &movimiento, int &turno, int &contador, int *movIndividual){
    switch(jugador[turno].zInicio){
        case 49:gotoxy(28+27,contador-18);break;
        case 50:gotoxy(28+27,contador-2); break;
        case 51:gotoxy(28+27,contador-17);break;
        case 52:gotoxy(28+27,contador-3); break;
        case 53:gotoxy(28+27,contador-16);break;
        case 54:gotoxy(28+27,contador-4); break;
    }
    cout<<"Movimiento numero "<<movIndividual[turno]+1<<" de "<<jugador[turno].nombre;
    movIndividual[turno]++; 
}
void Juego(datos *jugador, char **tablero, int &contador, int &F, int &movimiento,int &turno, int &X0, int &Y0, char &cincoSeis, int cantJ){
	int *X=new int, *Y=new int, *aux=new int,*aux2=new int, *num=new int, *cordX=new int, *cordY=new int;
    char Tecla;
    *X = 13+27;
    *aux=0;
    *aux2=0;
    *Y = 9+(contador-19);
    *num=4;
	gotoxy(*X, *Y);
	while (Tecla!='9'){
        *Y = *Y-(contador-19);
        *X = *X-27;
		Tecla = getch();
        seleccionInvalida(*Y,contador,*X,*num);
		if (Tecla == 72) {
			(*Y)--;
			if (tablero[*Y][*X] == 57 )
				(*Y)++;
		}
		else if (Tecla == 80) {
			(*Y)++;
			if (tablero[*Y][*X] == 57 )
				(*Y)--;
		}
		else if (Tecla == 75) {
			(*X)--;
			if (tablero[*Y][*X] == 57 )
				(*X)++;
		}
		else if (Tecla == 77) {
			(*X)++;
			if (tablero[*Y][*X] == '9')
				(*X)--;
		}
        else if(Tecla==13){
            if(tablero[*Y][*X]!=48 &&((*aux==0&&tablero[*Y][*X]==jugador[turno].id)||(*aux!=0&&tablero[*Y][*X]==56 ))){
                if(*aux==0){
                    color(hConsole,124);
                    *aux=tablero[*Y][*X];
                    *cordX=*X;
                    *cordY=*Y;
                    tablero[*Y][*X]=56 ;
                    cout<<cincoSeis;
                    color(hConsole,180);
                }
                else{
                    /*color(hConsole,115+(2*turno));
                    tablero[*Y][*X]=*aux;
                    *aux=0;
                    cout<<tablero[*Y][*X];
                    X0=*X;
                    Y0=*Y;
                    Tecla='9';
                    color(hConsole,180);*/
                    if(movimientoValido(jugador,tablero,*Y,*X,*cordX,*cordY,0)&&*aux2==0){
                        color(hConsole,115+(2*turno));
                        tablero[*Y][*X]=*aux;
                        *aux=0;
                        cout<<tablero[*Y][*X];
                        X0=*X;
                        Y0=*Y;
                        Tecla='9';
                        color(hConsole,180);
                    }
                    else{
                        if(movimientoValido(jugador,tablero,*Y,*X,*cordX,*cordY,1)){
                            color(hConsole,124);
                            tablero[*cordY][*cordX]=56 ;
                            gotoxy(*cordX+27, *cordY+(contador-19));
                            cout<<cincoSeis;
                            tablero[*Y][*X]=*aux;
                            *cordX=*X;
                            *cordY=*Y;
                            gotoxy(*X+27, *cordY+(contador-19));
                            color(hConsole,115+(2*turno));
                            cout<<tablero[*Y][*X];
                            X0=*X;
                            Y0=*Y;
                            (*aux2)++;
                            color(hConsole,180);
                        }
                        else{
                            *num=0;
                            seleccionInvalida(*Y,contador,*X,*num);
                        }
                    }
                }
            }
            else{
                if(*aux==0&&tablero[*Y][*X]!=jugador[turno].id&&tablero[*Y][*X]!=56 )
                    *num=1;
                else
                    *num=0;
                seleccionInvalida(*Y,contador,*X,*num);
            }
        }
        else if(Tecla=='9'&&*aux!=0&&*aux2==0){
            Tecla='x';
            *num=3;
            seleccionInvalida(*Y,contador,*X,*num);
        }
        else if(Tecla=='f'||Tecla=='F'){
            *X=27; *Y=18;
            F=1;
            Tecla='9';
        }
        *X = *X+27;
        *Y = *Y+(contador-19);
        gotoxy(*X, *Y);
	}
    movimiento++;
    delete aux;
    delete num;
    delete cordX;
    delete cordY;
    delete aux2;
}
void verificaGanador(datos *jugador, char **tablero, int &F, int &contador, int &ganador, int &X, int &Y, int &movimiento, int &turno){
    int *cordX=new int, *cordY=new int;
    double *distancia=new double, *aux1=new double, *aux2=new double, *suma=new double;
    *suma=0;
    *cordX=jugador[turno].opuestoJ;
    *cordY=jugador[turno].opuestoI;
    *distancia=calculaDistancia(Y,X,*cordX,*cordY,*aux1,*aux2);
    for(int i=0; i<19; i++){
        for(int j=0; j<27; j++){
            if(tablero[i][j]==jugador[turno].id){
                (*suma)+=calculaDistancia(i,j,*cordX,*cordY,*aux1,*aux2);
            }
        }
    }
    if(jugador[turno].opuestoJ==13){
        if(*suma<=25.35){
            gotoxy(5,contador);
            cout<<endl<<"Hay ganador!!!!\n   Felicidades "<<jugador[turno].id<<", tu si le sabes a las damas chinas."<<endl;
            ganador=turno;
            F=1;
        }        
    }
    else{
        if(*suma<=33.3){
            gotoxy(5,contador);
            cout<<endl<<"Hay ganador!!!!\n   Felicidades "<<jugador[turno].id<<", tu si le sabes a las damas chinas."<<endl;
            ganador=turno;
            F=1;
        }
    }
    
    delete cordX;
    delete cordY;
    delete distancia;
    delete aux1;
    delete aux2;
    delete suma;
}

void Ganador(datos *jugador, int &ganador, int *movIndividual){
    color(hConsole,180);
    int LogoGanador[25][80]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,0},
    {0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,0},
    {0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,2,2,2,2,0,0,2,2,2,2,2,2,2,0,0,2,2,2,2,0},
    {0,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    for(int i=0; i<14; i++){
        for(int j=0; j<80; j++){
            if(LogoGanador[i][j]!= 0){  
     	        cout<<char(219);
            }
            else
                cout<<" ";	
    	}
    	cout<<endl;
    }
    cout<<"      **"<<jugador[ganador].nombre<<"** por haber ganado en "<<movIndividual[ganador]<<" turnos"<<endl;
}
void accionRecord(datos *jugador, int *movIndividual, int &ganador, int tipo){
    ofstream records1;
    ifstream records2;
    string *aux=new string;
    switch (tipo){
    case 1: records1.open("records.txt",ios::app);
            if(records1.is_open())
                records1<<"   "<<jugador[ganador].nombre<<"\t\t"<<movIndividual[ganador]<<endl;
            else
                cout<<"Error al abrir records."<<endl;
            records1.close();
        break;
    case 2: records2.open("records.txt",ios::in);
            if(records2.is_open()){
                while(!records2.eof()){
                    getline(records2,*aux);
                    cout<<*aux<<endl;
                }
            }
            else
                cout<<"Error al abrir records"<<endl;
            records2.close();
        break;
    }
    delete aux;
    fflush(stdin);
}


int main(){
    datos *jugador= new datos[2];
    int *contador=new int, *movimiento=new int, *turno=new int, *X=new int, *Y=new int, *F=new int, *movIndividual=new int[2], *opcion=new int, *ganador=new int;
    char *cincoSeis=new char, *cincoSiete=new char, **tablero=new char*[19];
    *cincoSeis=254;
    *cincoSiete=178;
    for(int i=0; i<19; i++)
        tablero[i]=new char[27];
    color(hConsole,180);
    do{
        *contador=0;
        *movimiento=0;
        *ganador=-1;
        *F=0;
        for(int i=0; i<2; i++)
            movIndividual[i]=0;
        borrarConsola();
        Presentacion();
        Creditos();
        *opcion=opciones();
        switch(*opcion){
            case 1: borrarConsola();
                    Instrucciones();
                    cout<<"Presione cualquier tecla para regresar al menu inicial o 1 para jugar"<<endl;
                    *opcion=getch();
                    if(*opcion!=49){
                break;
                    }
            case 3: borrarConsola();
                    obtieneTablero(tablero);
                    registroJugadores(jugador,*contador,2);
                    dado(jugador,*contador,2);
                    imprimirTablero(jugador,tablero,*contador,*cincoSeis,*cincoSiete);
                    escogeInicio(jugador,tablero,*contador);
                    imprimirTablero(jugador,tablero,*contador,*cincoSeis,*cincoSiete);
                    do{
                        *turno=determinaTurno(*movimiento,2);
                        contadorMovimientos(jugador,*movimiento,*turno,*contador,movIndividual);
                        Juego(jugador,tablero,*contador,*F,*movimiento,*turno,*X,*Y,*cincoSeis,2);
                        verificaGanador(jugador,tablero,*F,*contador,*ganador,*X,*Y,*movimiento,*turno);
                    }while(*F!=1);
                    getch();
                    if(*ganador!=-1){
                        borrarConsola();
                        Ganador(jugador,*ganador,movIndividual);
                        accionRecord(jugador,movIndividual,*ganador,1);
                        getch();
                    }
                break;
            case 2: accionRecord(jugador,movIndividual,*ganador,2);
                    getch();
                break;
            case 4: *F=2; break;
        }

    }while(*F!=2);
    getch();
    for(int i=0; i<19; i++)
        delete [] tablero[i];
    delete [] tablero;
    delete contador;
    delete [] jugador;
    delete movimiento;
    delete turno;
    delete X;
    delete Y;
    delete ganador;
    delete [] movIndividual;
    delete F;
    delete opcion;
    delete cincoSeis;
    delete cincoSiete;
    getch();
    return 0;
}
