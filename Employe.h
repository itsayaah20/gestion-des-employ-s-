#ifndef EMPLOYE_H
#define EMPLOYE_H
// biblioth�ques qui ona utiliser 
#include <iostream> // Pour les entr�es/sorties standard
#include <string>   // Pour utiliser la classe string

using namespace std;

// D�finition de la classe Employe
class Employe {
private:
    // Attributs priv�s de la classe Employe et declaration des parametre de la classe 
    int identifiant;      // Identifiant unique de l'employ�
    string nom;           // Nom de l'employ�
    string prenom;        // Pr�nom de l'employ�
    string adresse;       // Adresse de l'employ�
    string poste;         // Poste de l'employ� dans l'entreprise
    double salaire;       // Salaire de l'employ�
    string dateEmbauche;  // Date d'embauche de l'employ�

public:
    // Constructeurs d'initialiser les parametre  de l'objet. 
    Employe(); // Constructeur par d�faut (initialise l'employ� avec des valeurs par d�faut)
    Employe(int id, string n, string p, string adr, string pos, double sal, string date); // Constructeur param�tr� (initialise avec les valeurs )

    // Getters et Setters
    int getIdentifiant() const; // Renvoie l'identifiant de l'employ�
    void setIdentifiant(int id); // Modifie l'identifiant de l'employ�

    string getNom() const; // Renvoie le nom de l'employ� sans modifier l'objet
    void setNom(string n); // Modifie le nom de l'employ� avec la valeur fournie

    string getPrenom() const; // Renvoie le pr�nom de l'employ�
    void setPrenom(string p); // Modifie le pr�nom de l'employ�

    string getAdresse() const; // Renvoie l'adresse de l'employ�
    void setAdresse(string adr); // Modifie l'adresse de l'employ�

    string getPoste() const; // Renvoie le poste de l'employ�
    void setPoste(string pos); // Modifie le poste de l'employ�

    double getSalaire() const; // Renvoie le salaire de l'employ�
    void setSalaire(double sal); // Modifie le salaire de l'employ�

    string getDateEmbauche() const; // Renvoie la date d'embauche de l'employ�
    void setDateEmbauche(string date); // Modifie la date d'embauche de l'employ�

    // M�thodes
    void saisie(); // Permet de saisir les param�tres de l'employ� (via l'utilisateur)
    void afficher() const; // Affiche les informations de l'employ�

    // Comparaison de deux employ�s
    bool comparer(const Employe &e) const; // Compare un employ� avec un autre employ� (e)

    // Surcharge d'op�rateurs
    bool operator==(const Employe &e) const; // V�rifie si deux employ�s sont �gaux (comparaison par attributs)
    // friend c'est un mot-cl� utilis� pour d�clarer qu'une fonction (ou une autre classe) a le droit d'acc�der aux membres priv�s et prot�g�s d'une autre classe
    friend ostream &operator<<(ostream &out, const Employe &e); // Permet d'afficher un employ� dans un flux de sortie
};

#endif

