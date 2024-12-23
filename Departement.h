#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

// Inclusion des bibliothèques nécessaires
#include "Employe.h" // Inclusion de la classe Employe (le département contient des employés)
#include <vector>     // Pour utiliser la classe vector (liste dynamique)
#include <ctime>      // Pour gérer les dates (comme la date de création du département)

class Departement {
private:
    // Attributs privés de la classe Departement
    int id;                        // Identifiant unique du département
    string nomDepartement;         // Nom du département (ex : "Ressources Humaines")
    Employe responsable;           // Responsable du département (de type Employe)
    vector<Employe> employes;      // Liste des employés du département (contenue dans un vecteur)
    string dateCreation;           // Date de création du département

public:
    // Constructeurs
    Departement(); // Constructeur par défaut (initialise un département avec des valeurs par défaut)
    Departement(int id, string nom, Employe resp, string date); // Constructeur paramétré (initialise un département avec des valeurs spécifiques)

    // Méthodes de gestion des employés
    void ajouterEmploye(const Employe &e); // Ajoute un employé au département
    void supprimerEmploye(int id);         // Supprime un employé du département en fonction de son identifiant
    void afficherEmployes() const;         // Affiche la liste des employés du département
    bool verifierEmploye(int id) const;    // Vérifie si un employé avec l'identifiant donné existe dans le département
    void afficherAnciennete() const;      // Affiche l'ancienneté des employés du département

    // Surcharge d'opérateurs
    Departement operator+(const Departement &d) const; // Fusionne deux départements (ajoute les employés d'un département à un autre)
    friend ostream &operator<<(ostream &out, const Departement &d); // Permet d'afficher un département dans un flux de sortie (ex : cout)
};

#endif

