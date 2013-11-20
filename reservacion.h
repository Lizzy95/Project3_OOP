#ifndef RESERVACION_H
#define RESERVACION_H
#include "fecha.h"

class Reservacion
{
    public:
        Reservacion();
        Reservacion(int ids,string ne,Fecha f,int d);
        int GetidSala() { return idSala; }
        void SetidSala(int val) { idSala = val; }
        string GetnombreEvento() { return nombreEvento; }
        void SetnombreEvento(string val) { nombreEvento = val; }
        Fecha GetfechaInicio() { return fechaInicio; }
        void SetfechaInicio(Fecha f) { fechaInicio = f; }
        int Getduracion() { return duracion; }
        void Setduracion(int val) { duracion = val; }
        void muestra();
    private:
        int idSala;
        string nombreEvento;
        Fecha fechaInicio;
        int duracion;
};
Reservacion::Reservacion(){
    idSala=0;
    nombreEvento="SIN NOMBRE";
    Fecha f;
    fechaInicio=f;
    duracion=10;
}
Reservacion::Reservacion(int ids,string ne,Fecha f,int d){
    idSala=ids;
    nombreEvento=ne;
    fechaInicio=f;
    duracion=d;
}
void Reservacion::muestra(){
    cout << "Id de la sala: " << idSala << endl;
    cout << "Nombre del evento: " << nombreEvento << endl;
    cout << "Fecha de inicio 'dd/mm/aa': " << fechaInicio.Getdd() << "/" << fechaInicio.Getmm() << "/" << fechaInicio.Getaa() << endl;
    cout << "Duracion del evento: " << duracion << " dias" << endl;
}

#endif // RESERVACION_H
