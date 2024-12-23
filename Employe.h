#ifndef EMPLOYE_H
#define EMPLOYE_H
// bibliothèques qui ona utiliser 
#include <iostream> // Pour les entrées/sorties standard
#include <string>   // Pour utiliser la classe string

using namespace std;

// Définition de la classe Employe
class Employe {
private:
    // Attributs privés de la classe Employe et declaration des parametre de la classe 
    int identifiant;      // Identifiant unique de l'employé
    string nom;           // Nom de l'employé
    string prenom;        // Prénom de l'employé
    string adresse;       // Adresse de l'employé
    string poste;         // Poste de l'employé dans l'entreprise
    double salaire;       // Salaire de l'employé
    string dateEmbauche;  // Date d'embauche de l'employé

public:
    // Constructeurs d'initialiser les parametre  de l'objet. 
    Employe(); // Constructeur par défaut (initialise l'employé avec des valeurs par défaut)
    Employe(int id, string n, string p, string adr, string pos, double sal, string date); // Constructeur paramétré (initialise avec les valeurs )

    // Getters et Setters
    int getIdentifiant() const; // Renvoie l'identifiant de l'employé
    void setIdentifiant(int id); // Modifie l'identifiant de l'employé

    string getNom() const; // Renvoie le nom de l'employé sans modifier l'objet
    void setNom(string n); // Modifie le nom de l'employé avec la valeur fournie

    string getPrenom() const; // Renvoie le prénom de l'employé
    void setPrenom(string p); // Modifie le prénom de l'employé

    string getAdresse() const; // Renvoie l'adresse de l'employé
    void setAdresse(string adr); // Modifie l'adresse de l'employé

    string getPoste() const; // Renvoie le poste de l'employé
    void setPoste(string pos); // Modifie le poste de l'employé

    double getSalaire() const; // Renvoie le salaire de l'employé
    void setSalaire(double sal); // Modifie le salaire de l'employé

    string getDateEmbauche() const; // Renvoie la date d'embauche de l'employé
    void setDateEmbauche(string date); // Modifie la date d'embauche de l'employé

    // Méthodes
    void saisie(); // Permet de saisir les paramètres de l'employé (via l'utilisateur)
    void afficher() const; // Affiche les informations de l'employé

    // Comparaison de deux employés
    bool comparer(const Employe &e) const; // Compare un employé avec un autre employé (e)

    // Surcharge d'opérateurs
    bool operator==(const Employe &e) const; // Vérifie si deux employés sont égaux (comparaison par attributs)
    // friend c'est un mot-clé utilisé pour déclarer qu'une fonction (ou une autre classe) a le droit d'accéder aux membres privés et protégés d'une autre classe
    friend ostream &operator<<(ostream &out, const Employe &e); // Permet d'afficher un employé dans un flux de sortie
};

#endif

