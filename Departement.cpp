#include "Departement.h"
#include<iostream>
using namespace std;

// Constructeur par défaut
// Initialise les attributs du département avec des valeurs par défaut
Departement::Departement() : id(0), nomDepartement(""), responsable(), dateCreation("") {}

// Constructeur paramétré
// Initialise le département avec les valeurs fournies : id, nom, responsable, et date de création
Departement::Departement(int id, string nom, Employe resp, string date) 
    : id(id), nomDepartement(nom), responsable(resp), dateCreation(date) {}

// Ajouter un employé au département
// Vérifie d'abord si l'employé existe déjà. Si c'est le cas, affiche un message d'erreur.
// Sinon, l'employé est ajouté à la liste des employés du département.
void Departement::ajouterEmploye(const Employe &e) {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i] == e) { // Vérifie si l'employé est déjà dans la liste
            cout << "Employee already exists!\n";
            return; // Si l'employé existe déjà, on quitte la fonction
        }
    }
    employes.push_back(e); // Si l'employé n'existe pas, on l'ajoute à la liste
    cout << "Employee added successfully!\n";
}

// Supprimer un employé du département
// Recherche l'employé par son identifiant et, si trouvé, le supprime de la liste.
// Si l'employé n'est pas trouvé, un message d'erreur est affiché.
void Departement::supprimerEmploye(int id) {
    for (vector<Employe>::iterator it = employes.begin(); it != employes.end(); ++it) {
        if (it->getIdentifiant() == id) { // Trouve l'employé par identifiant
            employes.erase(it); // Supprime l'employé de la liste
            cout << "Employee removed successfully!\n";
            return;
        }
    }
    cout << "Employee not found!\n"; // Si l'employé n'est pas trouvé
}

// Afficher la liste des employés du département
// Parcourt la liste des employés et affiche chacun d'entre eux.
void Departement::afficherEmployes() const {
    for (size_t i = 0; i < employes.size(); ++i) {
        cout << employes[i] << endl; // Affiche l'employé avec l'opérateur <<
    }
}

// Vérifier si un employé existe dans le département
// Recherche un employé par son identifiant et renvoie true si trouvé, sinon false.
bool Departement::verifierEmploye(int id) const {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i].getIdentifiant() == id) { // Vérifie si l'identifiant correspond
            return true; // L'employé existe
        }
    }
    return false; // L'employé n'existe pas
}

// Surcharge de l'opérateur + pour fusionner deux départements
// Crée un nouveau département qui contient tous les employés des deux départements.
// Les employés du département d sont ajoutés à ce département.
Departement Departement::operator+(const Departement &d) const {
    Departement merged = *this; // Crée une copie de l'objet actuel (le département courant)
    for (size_t i = 0; i < d.employes.size(); ++i) {
        merged.ajouterEmploye(d.employes[i]); // Ajoute chaque employé du département d au département courant
    }
    return merged; // Retourne le département fusionné
}

// Surcharge de l'opérateur << pour afficher un département
// Permet d'afficher un département avec son ID, son nom, sa date de création et la liste de ses employés.
ostream &operator<<(ostream &out, const Departement &d) {
    out << "Department ID: " << d.id << ", Name: " << d.nomDepartement << ", Creation Date: " << d.dateCreation;
    out << "\nEmployees:\n";
    for (size_t i = 0; i < d.employes.size(); ++i) {
        out << d.employes[i] << endl; // Affiche chaque employé du département
    }
    return out; // Retourne le flux de sortie
}

