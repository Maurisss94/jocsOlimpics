//
// Created by mauro on 27/03/16.
//

#include "LlistaInscripcions.h"

LlistaInscripcions::LlistaInscripcions() {
    numeroInscripcions = 0;
}
int LlistaInscripcions::existeix(Inscripcio inscripcio) const{
    int mig, esq=0, dreta =numeroInscripcions-1;
    bool trobat = false;
    while(!trobat and esq<=dreta){
        mig = (esq+dreta)/2;
        if(inscripcio<taulaInscripcions[mig]){
            dreta= mig-1;
        }else if(inscripcio>taulaInscripcions[mig]){
            esq=mig+1;
        }else{
            trobat = true;
        }
    }
    if(!trobat){
        mig = -1;
    }
    return mig;
}
int LlistaInscripcions::getNum() const {
    return numeroInscripcions;
}
void LlistaInscripcions::omplirLlista(Inscripcio inscripcio) {
    int i= numeroInscripcions;
    while(i>0 and inscripcio<taulaInscripcions[i-1]){
        taulaInscripcions[i] = taulaInscripcions[i-1];
        i--;
    }
    taulaInscripcions[i] = inscripcio;
    numeroInscripcions++;
    cout << "LA INSCRIPCIO S'HA FET CORRECTAMENT" << endl;

}
void LlistaInscripcions::mostrar() const {
    cout << "ATLETES PARTICIPANTS:" << endl;
    for(int i=0;i<numeroInscripcions;i++){
        cout << taulaInscripcions[i].getNom() << " - " << taulaInscripcions[i].getPais() << " - " << taulaInscripcions[i].getModalitat() <<endl;
    }
}
void LlistaInscripcions::ordena(char c) {

    for(int i=0;i<numeroInscripcions;i++){
        for(int j=numeroInscripcions-1;j>i;j--){
            if(esMenor(taulaInscripcions[j], taulaInscripcions[j-1], c)){
                intercanvi(taulaInscripcions[j-1], taulaInscripcions[j]);
            }
        }
    }

}
bool LlistaInscripcions::esMenor(Inscripcio i1, Inscripcio i2, char c) {
    if(c == 'm'){
        return (i1.getModalitat()< i2.getModalitat() or
                (i1.getModalitat() == i2.getModalitat() and i1.getNom() < i2.getNom() or
                (i1.getModalitat() == i2.getModalitat() and i1.getNom() == i2.getNom()) and i1.getPais() < i2.getPais()));
    }else if(c == 'p'){
        return (i1.getPais() < i2.getPais() or
                (i1.getPais() == i2.getPais() and i1.getNom()<i2.getNom() or
                 (i1.getPais() == i2.getPais() and i1.getNom() == i2.getNom() and i1.getModalitat() < i2.getModalitat())));
    }else if(c == 'n'){
        return i1 < i2;
    }
}
void LlistaInscripcions::intercanvi(Inscripcio &i1, Inscripcio &i2) {
    Inscripcio A = i1;
    Inscripcio B = i2;

    i1 = B;
    i2 = A;

}
void LlistaInscripcions::filtrar(Inscripcio inscripcio, char c, LlistaInscripcions &filtrats) const {
    filtrats.numeroInscripcions = 0;
    for(int i =0;i<numeroInscripcions;i++){
        if(c == 'n'){
            if(inscripcio.getNom() == taulaInscripcions[i].getNom()){
                filtrats.taulaInscripcions[filtrats.numeroInscripcions] = taulaInscripcions[i];
                filtrats.numeroInscripcions++;
            }
        }else if(c == 'p'){
            if(inscripcio.getPais() == taulaInscripcions[i].getPais()){
                filtrats.taulaInscripcions[filtrats.numeroInscripcions] = taulaInscripcions[i];
                filtrats.numeroInscripcions++;
            }
        }else if(c == 'm'){
            if(inscripcio.getModalitat() == taulaInscripcions[i].getModalitat()){
                filtrats.taulaInscripcions[filtrats.numeroInscripcions] = taulaInscripcions[i];
                filtrats.numeroInscripcions++;
            }
        }

    }
}
void LlistaInscripcions::donarBaixa(int pos) {
    for(int i=pos;i<numeroInscripcions-1;i++){
        taulaInscripcions[i] = taulaInscripcions[i+1];
    }
    numeroInscripcions--;
}
