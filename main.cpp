#include <iostream>
#include "LlistaInscripcions.h"

using namespace std;
string FI = "#";

void gestionarInscripcionsPeriodeInicial(LlistaInscripcions &t){
    cout << "INSCRIPCIONS ALS JOCS OLIMPICS 2012" << endl;
    string nom, pais, modalitat;
    bool trobat = false;
    while(!trobat){
        cout << "NOM:" <<endl;
        getline(cin, nom);
        if(nom == FI){
            trobat = true;
        }else{
            cout << "NACIONALITAT I MODALITAT:" <<endl;
            getline(cin, pais);
            getline(cin, modalitat);
            Inscripcio inscripcio = Inscripcio(nom, modalitat, pais);
            if(t.getNum() == 0){
                t.omplirLlista(inscripcio);
                t.mostrar();
            }else if(t.existeix(inscripcio) == -1){
                t.omplirLlista(inscripcio);
                t.mostrar();
            }else{
                cout << "INSCRIPCIO JA FETA ANTERIORMENT" << endl;
                t.mostrar();
            }

        }
    }
    if(t.getNum() != 0){
        cout << "FINAL DEL PERIODE D'INSCRIPCIONS ALS JOCS OLIMPICS 2012 " << endl;
        t.mostrar();

    }

}
char mostrarMenu(){

    char op ='.';
    bool semafor = false;
    while(!semafor){

        cout << "(m) MOSTRAR" <<endl;
        cout << "(e) ESCOLLIR" <<endl;
        cout << "(d) DESINSCRIURE" << endl;
        cout << "(s) SORTIR" <<endl;
        cin >> op;
        if(op == 'm' or op =='e' or op == 'd' or op =='s'){
            semafor = true;
        }else{
            cout << "OPCIO NO VALIDA"<<endl;
        }
    }
    return op;
}
char mostrarSubmenu(){
    char sop;
    bool semafor = false;
    while(!semafor){
        cout << "(n) PER NOM"<<endl;
        cout << "(m) PER MODALITAT" <<endl;
        cout << "(p) PER PAIS" <<endl;
        cin >> sop;
        if(sop == 'n' or sop == 'm' or sop == 'p'){
            semafor = true;
        }else{
            cout << "OPCIO NO VALIDA" <<endl;
        }
    }

    return sop;

}
void escollir(char c, LlistaInscripcions &t){
    string nom, modalitat, pais;
    LlistaInscripcions filtrats;
    if(c == 'n'){
        cout << "NOM A CERCAR: "<<endl;
        cin.ignore(100, '\n');
        getline(cin, nom);
        Inscripcio ins = Inscripcio(nom);
        t.filtrar(ins, c, filtrats);
        if(filtrats.getNum() == 0){
            cout << "NO S'HA TROBAT CAP INSCRIPCIO AMB AQUEST CAMP" <<endl;
        }else{
            filtrats.mostrar();
        }
    }else if(c == 'm'){
        cout << "MODALITAT A CERCAR: "<<endl;
        cin.ignore(100, '\n');
        getline(cin ,modalitat);
        Inscripcio ins = Inscripcio(nom, modalitat);
        t.filtrar(ins, c, filtrats);
        if(filtrats.getNum() == 0){
            cout << "NO S'HA TROBAT CAP INSCRIPCIO AMB AQUEST CAMP" <<endl;
        }else{
            filtrats.mostrar();
        }
    }else if(c == 'p'){
        cout << "PAIS A CERCAR: "<< endl;
        cin.ignore(100, '\n');
        getline(cin ,pais);
        Inscripcio ins= Inscripcio(nom, modalitat, pais);
        t.filtrar(ins, c, filtrats);
        if(filtrats.getNum() == 0){
            cout << "NO S'HA TROBAT CAP INSCRIPCIO AMB AQUEST CAMP" <<endl;
        }else{
            filtrats.mostrar();
        }

    }
}
void tractarSegonaOpcio(char primeraOpcio, char segonaOpcio, LlistaInscripcions &t){

    if(primeraOpcio == 'm' and segonaOpcio == 'n'){
        t.ordena(segonaOpcio);
        t.mostrar();
    }else if(primeraOpcio == 'm' and segonaOpcio == 'm'){
        t.ordena(segonaOpcio);
        t.mostrar();
    }else if(primeraOpcio == 'm' and segonaOpcio == 'p'){
        t.ordena(segonaOpcio);
        t.mostrar();
    }else if(primeraOpcio == 'e' and segonaOpcio == 'n'){
        t.ordena(segonaOpcio);
        escollir(segonaOpcio, t);
    }else if(primeraOpcio == 'e' and segonaOpcio == 'm'){
        t.ordena(segonaOpcio);
        escollir(segonaOpcio, t);
    }else if(primeraOpcio == 'e' and segonaOpcio == 'p'){
        t.ordena(segonaOpcio);
        escollir(segonaOpcio, t);
    }
}
Inscripcio demanarBaixa(){
    string nom, pais, modalitat;
    cout << "NOM: "<<endl;
    cin.ignore(100, '\n');
    getline(cin, nom);
    cout << "NACIONALITAT I MODALITAT: "<<endl;
    cin >> pais;
    cin.ignore(100, '\n');
    getline(cin, modalitat);
    Inscripcio baixa = Inscripcio(nom, modalitat, pais);
    return baixa;
}
void tractarOpcio(char op, LlistaInscripcions &t){
    if(op == 'm' or op == 'e'){
        char segonaOpcio = mostrarSubmenu();
        tractarSegonaOpcio(op, segonaOpcio, t);
    }else if(op == 'd'){
        Inscripcio baixa = demanarBaixa();
        t.ordena('n');
        int pos = t.existeix(baixa);
        if(pos != -1){
            t.donarBaixa(pos);
            cout << "L'ATLETA S'HA DESINSCRIT" << endl;
        }else{
            cout << "L'ATLETA JA NO CONSTAVA A LA LLISTA" <<endl;
        }
    }
}
void gestionarConsultesIBaixes(LlistaInscripcions &t){

    bool sortir =false;
    while(!sortir){
        if(t.getNum() != 0){
            char op =mostrarMenu();
            if(op == 's'){
                cout << "US ESPEREM EL 2016!" <<endl;
                sortir = true;
            }else{
                tractarOpcio(op, t);
            }
        }else{
            cout << "FINAL DEL PERIODE D'INSCRIPCIONS ALS JOCS OLIMPICS 2012 " << endl;
            cout << "NO HI HA ATLETES INSCRITS" <<endl;
            cout << "US ESPEREM EL 2016!" <<endl;
            sortir = true;
        }
    }


}


int main() {
    LlistaInscripcions tInsc;
    gestionarInscripcionsPeriodeInicial(tInsc);
    gestionarConsultesIBaixes(tInsc);
    return 0;
}