#include "reservacion.h"
#include "sala.h"
#include <fstream>

int main()
{
    int ids, clavep, clavec, capaci, i=0, menu;
    int dia, mes, year, id, duracion, j=0;
    int x=0;
    string nombre, nombreevent;
    bool pro, compu;
    Sala salas[5];
    Reservacion reservaciones[100];
    Fecha aux;
    ifstream sal;
    ifstream reser;
    ofstream sal1;
    ofstream reser1;

    sal.open("C:\\Users\\Alejandro Zamudio\\Desktop\\Salas.txt");
    reser.open("C:\\Users\\Alejandro Zamudio\\Desktop\\Reserva.txt");

    while(!sal.eof())
    {
        sal >> ids>>clavep >> clavec>>capaci>> nombre;

        if(clavep==1)
        {
            pro=true;
        }
        else
            pro=false;
        if (clavec==1)
        {
            compu=true;
        }
        else
            compu=false;

        salas[i].SetidSala(ids);
        salas[i].Setproyector(pro);
        salas[i].Setcomputadora(compu);
        salas[i].Setcapacidad(capaci);
        salas[i].SetnomSala(nombre);
        i++;
    }

    while(!reser.eof())
    {
        reser >> dia>>mes >> year>>id>> duracion;
        getline(reser, nombreevent);

        aux.Setdd(dia);
        aux.Setmm(mes);
        aux.Setaa(year);
        reservaciones[j].SetfechaInicio(aux);
        reservaciones[j].SetidSala(id);
        reservaciones[j].Setduracion(duracion);
        reservaciones[j].SetnombreEvento(nombreevent);
        j++;
    }

    do{
      cout << "Seleccione una de las opciones introduciendo el numero del caso deseado." << endl;
      cout << endl;
      cout << "1. Consultar la lista de salas." << endl;
      cout << "2. Consultar la lista de reservaciones." << endl;
      cout << "3. Consultar los eventos de una sala dada." << endl;
      cout << "4. Consultar los eventos de una fecha dada." << endl;
      cout << "5. Hacer una reservacion." << endl;
      cout << "6. Terminar." << endl;
      cout << "Input --> ";
      cin >> menu;
      cout << endl;
      switch(menu){
         case 1:
             while(salas[x].GetidSala()!=0&&x<5){
                salas[x].muestra();
                x++;
                cout << endl;
             }
             x=0;
         break;
         case 2:

         break;
         case 3:
         break;
         case 4:
         break;
         case 5:
         break;
         case 6: cout << "Gracias por utilizar el sistema. Que tenga un excelente dia." << endl;
         break;
         default: cout << "No se encontro un menu para este comando, intente de nuevo." << endl;
         break;
      }
  }while(menu!=6);
   return 0;
}
