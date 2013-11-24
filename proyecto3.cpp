#include "reservacion.h"
#include "sala.h"
#include <fstream>

int main()
{
    int ids, clavep, clavec, capaci, longsala=0, menu;
    int dia, mes, year, id, duracion, longres=0;
    int x=0, z=0, y=0, days, months, years, dur, res;
    string nombre, nombreevent;
    bool pro, compu;
    bool decision=false;
    Sala salas[5];
    Reservacion reservaciones[100];
    Fecha fa;
    Fecha aux, aux2, aux2F, aux3, aux3F;
    ifstream sal;
    ifstream reser;
    ofstream reser1;
    bool arr[5]={true,true,true,true,true};
    
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
        
        salas[longsala].SetidSala(ids);
        salas[longsala].Setproyector(pro);
        salas[longsala].Setcomputadora(compu);
        salas[longsala].Setcapacidad(capaci);
        salas[longsala].SetnomSala(nombre);
        longsala++;
    }
    
    while(!reser.eof())
    {
        reser >> dia>>mes >> year>>id>> duracion;
        getline(reser, nombreevent);
        aux.Setdd(dia);
        aux.Setmm(mes);
        aux.Setaa(year);
        reservaciones[longres].SetfechaInicio(aux);
        reservaciones[longres].SetidSala(id);
        reservaciones[longres].Setduracion(duracion);
        reservaciones[longres].SetnombreEvento(nombreevent);
        longres++;
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
                    cout << "Nombre del evento:" << reservaciones[x].GetnombreEvento() << endl;
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
                cout << endl;
                for(int i=0;i<100;i++){
                    if(id==reservaciones[i].GetidSala()){
                        cout << "Nombre del evento:" << reservaciones[i].GetnombreEvento() << endl;
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
                        cout << endl;
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
                cout << endl;
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
                        cout << "Nombre del evento:" << reservaciones[x].GetnombreEvento() << endl;
                        cout << endl;
                    }
                    x++;
                }
                if(!decision){
                    cout << "No se encontraron reservaciones." << endl;
                    cout << endl;
                }
                decision=false;
                x=0;
                break;
                
            case 5:
                cout <<"Numero de personas para la reservacion: ";
                cin >> capaci;
                cout << "Fecha de inicio de evento:"<<endl;
                do{
                    cout << "Introduzca el dia: ";
                    cin >> dia;
                    if(dia>=1&&dia<=30)
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
                    cin >> mes;
                    if(mes>=1&&mes<=12)
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
                    cin >> year;
                    if(year>=2014)
                        decision=true;
                    else{
                        cout << endl;
                        cout << "El anio introducido es erroneo. Favor de ingresarlo de nuevo." << endl;
                        cout << endl;
                    }
                }while(decision==false);
                decision=false;
                
                cout <<"Tiempo de duracion(dias): ";
                cin >> duracion;
                do{
                    cout << "Requiere proyector( 1)Si, 2)No ): ";
                    cin >> clavep;
                    if(clavep==0||clavep==1)
                        decision=true;
                }while(!decision);
                decision=false;
                do{
                    cout << "Requiere computadora ( 1)Si, 2)No ): ";
                    cin >> clavec;
                    if(clavec==0||clavec==1)
                        decision=true;
                }while(!decision);
                decision=false;
                cout << "Nombre del evento: ";
                cin >> nombreevent;
                nombreevent = " " + nombreevent;
                if(clavep==1)
                    pro=true;
                else
                    pro=false;
                if(clavec==1)
                    compu=true;
                else
                    compu=false;
                aux2.Setdd(dia);
                aux2.Setmm(mes);
                aux2.Setaa(year);
                aux2F=aux2;
                aux2F+duracion;
                
                for (int k=0; k<longsala; k++)
                {
                    if((capaci<=salas[k].Getcapacidad())&&(clavep==salas[k].Getproyector())&&(clavec==salas[k].Getcomputadora()))
                    {
                        for (int m=0; m<longres; m++)
                        {
                            if (reservaciones[m].GetidSala()==salas[k].GetidSala())
                            {
                                aux3=reservaciones[m].GetfechaInicio();
                                aux3F=aux3;
                                aux3F+reservaciones[m].Getduracion();
                                if((aux2>=aux3&&aux2<=aux3F) || (aux2F>=aux3&&aux2F<=aux3F) || (aux3>=aux2&&aux3<=aux2F))
                                {
                                    arr[k]=false;
                                }
                            }
                        }
                    }
                    else
                        arr[k]=false;
                }
                cout << "Las salas disponibles son las siguientes:" << endl;
                cout << endl;
                for (int d=0; d<5; d++)
                {
                    if(arr[d]&&salas[d].GetidSala()!=0)
                    {
                        x=1;
                        cout << d+1 << ". " << salas[d].GetnomSala() << " ID: " << salas[d].GetidSala() << endl;
                    }
                }
                if(x==0){
                    cout << endl;
                    cout << "No existen salas disponibles." << endl;
                    cout << endl;
                }
                else{
                    cout << endl;
                    cout << "Inscriba el ID de la sala que desea reservar: ";
                    cin >> id;
                    reservaciones[longres].SetfechaInicio(aux2);
                    reservaciones[longres].SetidSala(id);
                    reservaciones[longres].Setduracion(duracion);
                    reservaciones[longres].SetnombreEvento(nombreevent);
                    longres++;
                    cout << endl;
                }
                x=0;
                for(int i=0;i<5;i++){
                    arr[i]=true;
                }
                break;
                
            case 6:
                cout << "Gracias por utilizar el sistema. Que tenga un excelente dia." << endl;
                reser1.open("C:\\Users\\Alejandro Zamudio\\Desktop\\Reserva.txt");
                for(int f=0; f<longres; f++){
                    reser1 << reservaciones[f].GetfechaInicio().Getdd() << " " << reservaciones[f].GetfechaInicio().Getmm() << " " << reservaciones[f].GetfechaInicio().Getaa() << " " << reservaciones[f].GetidSala() << " " << reservaciones[f].Getduracion() << reservaciones[f].GetnombreEvento();
                    if(f<longres-1)
                        reser1 << endl;
                }
                break;
            default: cout << "No se encontro un menu para este comando, intente de nuevo." << endl;
                break;
        }
    }while(menu!=6);
    sal.close();
    reser.close();
    return 0;
}
