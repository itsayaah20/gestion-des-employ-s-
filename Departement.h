#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

// Inclusion des biblioth�ques n�cessaires
#include "Employe.h" // Inclusion de la classe Employe (le d�partement contient des employ�s)
#include <vector>     // Pour utiliser la classe vector (liste dynamique)
#include <ctime>      // Pour g�rer les dates (comme la date de cr�ation du d�partement)

class Departement {
private:
    // Attributs priv�s de la classe Departement
    int id;                        // Identifiant unique du d�partement
    string nomDepartement;         // Nom du d�partement (ex : "Ressources Humaines")
    Employe responsable;           // Responsable du d�partement (de type Employe)
    vector<Employe> employes;      // Liste des employ�s du d�partement (contenue dans un vecteur)
    string dateCreation;           // Date de cr�ation du d�partement

public:
    // Constructeurs
    Departement(); // Constructeur par d�faut (initialise un d�partement avec des valeurs par d�faut)
    Departement(int id, string nom, Employe resp, string date); // Constructeur param�tr� (initialise un d�partement avec des valeurs sp�cifiques)

    // M�thodes de gestion des employ�s
    void ajouterEmploye(const Employe &e); // Ajoute un employ� au d�partement
    void supprimerEmploye(int id);         // Supprime un employ� du d�partement en fonction de son identifiant
    void afficherEmployes() const;         // Affiche la liste des employ�s du d�partement
    bool verifierEmploye(int id) const;    // V�rifie si un employ� avec l'identifiant donn� existe dans le d�partement
    void afficherAnciennete() const;      // Affiche l'anciennet� des employ�s du d�partement

    // Surcharge d'op�rateurs
    Departement operator+(const Departement &d) const; // Fusionne deux d�partements (ajoute les employ�s d'un d�partement � un autre)
    friend ostream &operator<<(ostream &out, const Departement &d); // Permet d'afficher un d�partement dans un flux de sortie (ex : cout)
};

#endif

