//
// Created by mauro on 27/03/16.
//

#ifndef JOCSOLIMPICSOBJECTES_LLISTAINSCRIPCIONS_H
#define JOCSOLIMPICSOBJECTES_LLISTAINSCRIPCIONS_H

#include "Inscripcio.h"

class LlistaInscripcions {
/**Descripcio: Classe on es guardarán totes les inscripcions fetes.**/
public:
//CONSTRUCTORS
    LlistaInscripcions();
    /** Constructor per defecte, crea la taula buida i el numero d'elements a 0.**/

    //CONSULTORS
    int getNum() const;
    /**Pre:--;Post: Retorna el numero d'inscripcions realitzades. **/
    int existeix(Inscripcio inscripcio) const;
    /** Pre: Inscripcio feta amb tots els seus camps. Post: Busca a la taula un element i retorna la seva posició sino el troba retorna -1.**/
    void mostrar() const;
    /**Pre:--;Post: mostra per pantalla el contingut de la taula d'inscripcions. **/
    void filtrar(Inscripcio i, char c, LlistaInscripcions &filtrats) const;
    /** Pre: inscripcio a filtrar amb el seu criteri. Post: mostra el filtratge aplicat a la taula amb el seu criteri **/


    //MODIFICADORS
    void omplirLlista(Inscripcio inscripcio);
    /**Pre: inscripcio a realitzar. Post:ompla la llista d'inscripcions amb la inscripcio passada per parametre.**/
    void ordena(char c);
    /**Pre: caracter amb el criteri d'ordenació.Post:Ordena la taula segons el criteri que rep.**/
    void donarBaixa(int pos);
    /** Pre: posicio de l'element trobat.Post: Esborra de la taula l'inscripcio amb la pos indicada.**/

private:
    Inscripcio taulaInscripcions[5000];
    int numeroInscripcions;

    bool esMenor(Inscripcio i1, Inscripcio i2, char c);
    /**Pre:Inscripcio més petita i més gran i el seu criteri.Post: Retorna true si es més petita i1 que i2.**/
    void intercanvi(Inscripcio &i1,Inscripcio &i2);
    /**Pre:inscripcio a intercanviar entre elles. Post: S'intercanvien inscripcions de lloc. **/


};


#endif //JOCSOLIMPICSOBJECTES_LLISTAINSCRIPCIONS_H
