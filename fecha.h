#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>

using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int d,int m,int a);
        int Getdd() { return dd; }
        void Setdd(int val) { dd = val; }
        int Getmm() { return mm; }
        void Setmm(int val) { mm = val; }
        int Getaa() { return aa; }
        void Setaa(int val) { aa = val; }
        Fecha operator+(int val);
        bool operator>=(Fecha f);
        bool operator<=(Fecha f);
        bool operator>(Fecha f);
        bool operator<(Fecha f);
        bool operator==(Fecha f);
    private:
        int dd;
        int mm;
        int aa;
};
Fecha::Fecha(){
    dd=1;
    mm=1;
    aa=2014;
}
Fecha::Fecha(int d,int m,int a){
    dd=d;
    mm=m;
    aa=a;
}
Fecha Fecha::operator+(int val){
    int res;
    res=31-dd;
    while(val>res){
        val-=res;
        dd=1;
        mm++;
        if(mm==13){
            mm=1;
            aa++;
        }
        res=31-dd;
    }
    dd+=val;
    if(dd==31){
        mm++;
        if(mm==13){
            mm=1;
            aa++;
        }
        dd=1;
    }
    Fecha f1(dd,mm,aa);
    return f1;
}
bool Fecha::operator>=(Fecha f){
    int d, d1;
    d=(aa*365)+(mm*30)+dd;
    d1=(f.aa*365)+(f.mm*30)+f.dd;
    if(d>=d1)
        return true;
    return false;
}
bool Fecha::operator<=(Fecha f){
    int d, d1;
    d=(aa*365)+(mm*30)+dd;
    d1=(f.aa*365)+(f.mm*30)+f.dd;
    if(d<=d1)
        return true;
    return false;
}
bool Fecha::operator>(Fecha f){
    int d, d1;
    d=(aa*365)+(mm*30)+dd;
    d1=(f.aa*365)+(f.mm*30)+f.dd;
    if(d>d1)
        return true;
    return false;
}
bool Fecha::operator<(Fecha f){
    int d, d1;
    d=(aa*365)+(mm*30)+dd;
    d1=(f.aa*365)+(f.mm*30)+f.dd;
    if(d<d1)
        return true;
    return false;
}
bool Fecha::operator==(Fecha f){
    int d, d1;
    d=(aa*365)+(mm*30)+dd;
    d1=(f.aa*365)+(f.mm*30)+f.dd;
    if(d==d1)
        return true;
    return false;
}

#endif // FECHA_H
