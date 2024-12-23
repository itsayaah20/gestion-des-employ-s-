#include "Departement.h"
#include<iostream>
using namespace std;

// Constructeur par d�faut
// Initialise les attributs du d�partement avec des valeurs par d�faut
Departement::Departement() : id(0), nomDepartement(""), responsable(), dateCreation("") {}

// Constructeur param�tr�
// Initialise le d�partement avec les valeurs fournies : id, nom, responsable, et date de cr�ation
Departement::Departement(int id, string nom, Employe resp, string date) 
    : id(id), nomDepartement(nom), responsable(resp), dateCreation(date) {}

// Ajouter un employ� au d�partement
// V�rifie d'abord si l'employ� existe d�j�. Si c'est le cas, affiche un message d'erreur.
// Sinon, l'employ� est ajout� � la liste des employ�s du d�partement.
void Departement::ajouterEmploye(const Employe &e) {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i] == e) { // V�rifie si l'employ� est d�j� dans la liste
            cout << "Employee already exists!\n";
            return; // Si l'employ� existe d�j�, on quitte la fonction
        }
    }
    employes.push_back(e); // Si l'employ� n'existe pas, on l'ajoute � la liste
    cout << "Employee added successfully!\n";
}

// Supprimer un employ� du d�partement
// Recherche l'employ� par son identifiant et, si trouv�, le supprime de la liste.
// Si l'employ� n'est pas trouv�, un message d'erreur est affich�.
void Departement::supprimerEmploye(int id) {
    for (vector<Employe>::iterator it = employes.begin(); it != employes.end(); ++it) {
        if (it->getIdentifiant() == id) { // Trouve l'employ� par identifiant
            employes.erase(it); // Supprime l'employ� de la liste
            cout << "Employee removed successfully!\n";
            return;
        }
    }
    cout << "Employee not found!\n"; // Si l'employ� n'est pas trouv�
}

// Afficher la liste des employ�s du d�partement
// Parcourt la liste des employ�s et affiche chacun d'entre eux.
void Departement::afficherEmployes() const {
    for (size_t i = 0; i < employes.size(); ++i) {
        cout << employes[i] << endl; // Affiche l'employ� avec l'op�rateur <<
    }
}

// V�rifier si un employ� existe dans le d�partement
// Recherche un employ� par son identifiant et renvoie true si trouv�, sinon false.
bool Departement::verifierEmploye(int id) const {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i].getIdentifiant() == id) { // V�rifie si l'identifiant correspond
            return true; // L'employ� existe
        }
    }
    return false; // L'employ� n'existe pas
}

// Surcharge de l'op�rateur + pour fusionner deux d�partements
// Cr�e un nouveau d�partement qui contient tous les employ�s des deux d�partements.
// Les employ�s du d�partement d sont ajout�s � ce d�partement.
Departement Departement::operator+(const Departement &d) const {
    Departement merged = *this; // Cr�e une copie de l'objet actuel (le d�partement courant)
    for (size_t i = 0; i < d.employes.size(); ++i) {
        merged.ajouterEmploye(d.employes[i]); // Ajoute chaque employ� du d�partement d au d�partement courant
    }
    return merged; // Retourne le d�partement fusionn�
}

// Surcharge de l'op�rateur << pour afficher un d�partement
// Permet d'afficher un d�partement avec son ID, son nom, sa date de cr�ation et la liste de ses employ�s.
ostream &operator<<(ostream &out, const Departement &d) {
    out << "Department ID: " << d.id << ", Name: " << d.nomDepartement << ", Creation Date: " << d.dateCreation;
    out << "\nEmployees:\n";
    for (size_t i = 0; i < d.employes.size(); ++i) {
        out << d.employes[i] << endl; // Affiche chaque employ� du d�partement
    }
    return out; // Retourne le flux de sortie
}

