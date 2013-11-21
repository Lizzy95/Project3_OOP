#include "reservacion.h"
#include "sala.h"
#include <fstream>

int main()
{
    int ids, clavep, clavec, capaci, i=0, menu;
    int dia, mes, year, id, duracion, j=0;
    int x=0, z=0, y=0, days, months, years, dur, res;
    string nombre, nombreevent;
    bool pro, compu;
    bool decision=false;
    Sala salas[5];
    Reservacion reservaciones[100];
    Fecha fa;
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
             cout << "Lista de salas:" << endl;
             cout << endl;
             while(salas[x].GetidSala()!=0&&x<5){
                salas[x].muestra();
                x++;
                cout << endl;
             }
             x=0;
         break;

         case 2:
             cout << "Lista de reservaciones:" << endl;
             cout << endl;
             while(reservaciones[x].GetidSala()!=0&&x<100){
                decision=true;
                while(y==0&&z<5){
                    if(reservaciones[x].GetidSala()==salas[z].GetidSala()){
                        y=1;
                        cout << "Nombre de la sala: " << salas[z].GetnomSala() << endl;
                    }
                    z++;
                }
                y=0;
                z=0;
                cout << "Nombre del evento: " << reservaciones[x].GetnombreEvento() << endl;
                cout << "Fecha de inicio 'dd/mm/aa': " << reservaciones[x].GetfechaInicio().Getdd() << "/" << reservaciones[x].GetfechaInicio().Getmm() << "/" << reservaciones[x].GetfechaInicio().Getaa() << endl;
                dur=reservaciones[x].Getduracion();
                days=reservaciones[x].GetfechaInicio().Getdd();
                months=reservaciones[x].GetfechaInicio().Getmm();
                years=reservaciones[x].GetfechaInicio().Getaa();
                res=31-days;
                while(dur>res){
                    dur-=res;
                    days=1;
                    months++;
                    if(months==13){
                        months=1;
                        years++;
                    }
                    res=31-days;
                }
                days+=dur;
                if(days==31){
                    months++;
                    if(months==13){
                        months=1;
                        years++;
                    }
                days=1;
                }
                Fecha fe(days,months,years);
                cout << "Fecha de termino 'dd/mm/aa': " << fe.Getdd() << "/" << fe.Getmm() << "/" << fe.Getaa() << endl;
                cout << endl;
                x++;
             }
             if(!decision){
                cout << "No existen reservaciones." << endl;
                cout << endl;
             }
             decision=false;
             x=0;
         break;

         case 3:
             do{
             cout << "Introduzca el id de la sala: ";
             cin >> id;
             for(int i=0;i<5;i++){
                if(id==salas[i].GetidSala()){
                    x=1;
                }
             }
             if(x==0){
                cout << endl;
                cout << "Dicha sala no fue encontrada. Intente de nuevo." << endl;
                cout << endl;
             }
             }while(x==0);
             x=0;
             for(int i=0;i<100;i++){
                if(id==reservaciones[i].GetidSala()){
                    cout << "Nombre del evento: " << reservaciones[i].GetnombreEvento() << endl;
                    cout << "Fecha de inicio 'dd/mm/aa': " << reservaciones[i].GetfechaInicio().Getdd() << "/" << reservaciones[i].GetfechaInicio().Getmm() << "/" << reservaciones[i].GetfechaInicio().Getaa() << endl;
                    dur=reservaciones[i].Getduracion();
                    days=reservaciones[i].GetfechaInicio().Getdd();
                    months=reservaciones[i].GetfechaInicio().Getmm();
                    years=reservaciones[i].GetfechaInicio().Getaa();
                    res=31-days;
                    while(dur>res){
                        dur-=res;
                        days=1;
                        months++;
                        if(months==13){
                            months=1;
                            years++;
                        }
                        res=31-days;
                    }
                    days+=dur;
                    if(days==31){
                        months++;
                        if(months==13){
                            months=1;
                            years++;
                        }
                    days=1;
                    }
                    Fecha fe(days,months,years);
                    cout << "Fecha de termino 'dd/mm/aa': " << fe.Getdd() << "/" << fe.Getmm() << "/" << fe.Getaa() << endl;
                }
             }
         break;

         case 4:
             do{
                cout << "Introduzca el dia: ";
                cin >> days;
                if(days>=1&&days<=30)
                    decision=true;
                else{
                    cout << endl;
                    cout << "El dia introducido es erroneo. Favor de ingresarlo de nuevo." << endl;
                    cout << endl;
                }
             }while(decision==false);
             decision=false;

             do{
                cout << "Introduzca el mes: ";
                cin >> months;
                if(months>=1&&months<=12)
                    decision=true;
                else{
                    cout << endl;
                    cout << "El mes introducido es erroneo. Favor de ingresarlo de nuevo." << endl;
                    cout << endl;
                }
             }while(decision==false);
             decision=false;

             do{
                cout << "Introduzca el anio: ";
                cin >> years;
                if(years>=2014)
                    decision=true;
                else{
                    cout << endl;
                    cout << "El anio introducido es erroneo. Favor de ingresarlo de nuevo." << endl;
                    cout << endl;
                }
             }while(decision==false);
             decision=false;

             fa.Setdd(days);
             fa.Setmm(months);
             fa.Setaa(years);
             while(reservaciones[x].GetidSala()!=0&&x<100){
                decision=true;
                Fecha fan;
                fan=reservaciones[x].GetfechaInicio();
                fan+reservaciones[x].Getduracion();
                if(fa>=reservaciones[x].GetfechaInicio()&&fa<=fan){
                    while(y==0&&z<5){
                        if(reservaciones[x].GetidSala()==salas[z].GetidSala()){
                            y=1;
                            cout << "Nombre de la sala: " << salas[z].GetnomSala() << endl;
                        }
                        z++;
                    }
                    y=0;
                    z=0;
                    cout << "Nombre del evento: " << reservaciones[x].GetnombreEvento() << endl;
                    cout << endl;
                }
                x++;
             }
             if(!decision){
                cout << endl;
                cout << "No se encontraron reservaciones." << endl;
                cout << endl;
             }
             decision=false;
             x=0;
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
