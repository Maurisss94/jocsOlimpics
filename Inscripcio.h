//
// Created by mauro on 27/03/16.
//

#ifndef JOCSOLIMPICSOBJECTES_INSCRIPCIO_H
#define JOCSOLIMPICSOBJECTES_INSCRIPCIO_H

#include <iostream>

using namespace std;
class Inscripcio {

public:
//CONSTRUCTOR.
    Inscripcio(string n = "", string m = "", string p = "");
    /**Constructor amb els parametres per defecte. **/
    //CONSULTORS
    string getNom() const;
    /**Pre:-- Post: REtorna el nom de la inscripcio.**/
    string getPais() const;
    /** Pre:-- Post: Retorna el pais de la inscripcio. **/
    string getModalitat() const;
    /** Pre: --; Post: retorna la modalitat de la inscripcip. **/

    //OPERADORS RELACIONALS
    bool operator==(const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual i i són iguals
    bool operator!=(const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual i i són diferents
    bool operator< (const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual és menor lexicogràficament que i
    bool operator<=(const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual és menor o igual lexicogràficament que i
    bool operator>(const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual és major lexicogràficament que i
    bool operator>=(const Inscripcio &i) const;
//Pre: --
//Post: cert si l’objecte actual és major lexicogràficament quei o són iguals


private:
    string nom, modalitat, pais;
};


#endif //JOCSOLIMPICSOBJECTES_INSCRIPCIO_H
