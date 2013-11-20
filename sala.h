#ifndef SALA_H
#define SALA_H
#include <iostream>
#include <string>

using namespace std;

class Sala
{
    public:
        Sala();
        Sala(int ids,string ns,bool p,bool c,int cap);
        int GetidSala() { return idSala; }
        void SetidSala(int val) { idSala = val; }
        string GetnomSala() { return nomSala; }
        void SetnomSala(string val) { nomSala = val; }
        bool Getproyector() { return proyector; }
        void Setproyector(bool val) { proyector = val; }
        bool Getcomputadora() { return computadora; }
        void Setcomputadora(bool val) { computadora = val; }
        int Getcapacidad() { return capacidad; }
        void Setcapacidad(int val) { capacidad = val; }
        void muestra();
    private:
        int idSala;
        string nomSala;
        bool proyector;
        bool computadora;
        int capacidad;
};
Sala::Sala(){
    idSala=0;
    nomSala=" SIN NOMBRE";
    proyector=false;
    computadora=false;
    capacidad=10;
}
Sala::Sala(int ids,string ns,bool p,bool c,int cap){
    idSala=ids;
    nomSala=ns;
    proyector=p;
    computadora=c;
    capacidad=cap;
}
void Sala::muestra(){
    cout << "Id de sala: " << idSala << endl;
    cout << "Nombre de la sala: " << nomSala << endl;
    cout << "Tiene proyector: ";
    if(proyector)
        cout << "Si" << endl;
    else
        cout << "No" << endl;
    cout << "Tiene computadora: ";
    if(computadora)
        cout << "Si" << endl;
    else
        cout << "No" << endl;
    cout << "Capacidad: " << capacidad << " personas." << endl;
}

#endif // SALA_H
