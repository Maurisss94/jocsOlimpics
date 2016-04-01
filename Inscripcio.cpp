//
// Created by mauro on 27/03/16.
//

#include "Inscripcio.h"
//Inscripcio::Inscripcio() {
//    nom = "";
//    modalitat = "";
//    pais = "";
//}
Inscripcio::Inscripcio(string n, string m, string p) {
    nom = n;
    modalitat = m;
    pais = p;
}
bool Inscripcio::operator==(const Inscripcio &i) const {
    return i.nom == nom and i.pais == pais and i.modalitat == modalitat;
}
bool Inscripcio::operator!=(const Inscripcio &i) const {
    return !(*this == i);
}
bool Inscripcio::operator<(const Inscripcio &i) const {
    return (nom<i.nom or (nom == i.nom and pais<i.pais or (nom == i.nom and pais == i.pais and modalitat<i.modalitat)));
}
bool Inscripcio::operator<=(const Inscripcio &i) const {
    return (*this < i || *this == i);
}
bool Inscripcio::operator>(const Inscripcio &i) const {
    return !(*this < i || *this == i);
}
bool Inscripcio::operator>=(const Inscripcio &i) const {
    return !(*this < i);
}
string Inscripcio::getModalitat() const {
    return modalitat;
}
string Inscripcio::getNom() const {
    return nom;
}
string Inscripcio::getPais() const {
    return pais;
}
