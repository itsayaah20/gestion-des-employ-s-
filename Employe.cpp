#include "Employe.h"  // Inclusion du fichier d'en-tête qui contient la déclaration de la classe "Employe"

// **Constructeur par défaut**
// Initialise les membres de la classe avec des valeurs par défaut.
Employe::Employe() 
    : identifiant(0), nom(""), prenom(""), adresse(""), poste(""), salaire(0.0), dateEmbauche("") {}

// **Constructeur paramétré**
// Initialise les membres de la classe avec les valeurs fournies en paramètres.
Employe::Employe(int id, string n, string p, string adr, string pos, double sal, string date) 
    : identifiant(id), nom(n), prenom(p), adresse(adr), poste(pos), salaire(sal), dateEmbauche(date) {}

// **Getters et Setters**
// Ces méthodes permettent d'accéder et de modifier les variables membres privées de la classe.

int Employe::getIdentifiant() const { return identifiant; }  // Renvoie l'identifiant de l'employé.
void Employe::setIdentifiant(int id) { identifiant = id; }  // Définit l'identifiant de l'employé.

string Employe::getNom() const { return nom; }  // Renvoie le nom de l'employé.
void Employe::setNom(string n) { nom = n; }  // Définit le nom de l'employé.

string Employe::getPrenom() const { return prenom; }  // Renvoie le prénom de l'employé.
void Employe::setPrenom(string p) { prenom = p; }  // Définit le prénom de l'employé.

string Employe::getAdresse() const { return adresse; }  // Renvoie l'adresse de l'employé.
void Employe::setAdresse(string adr) { adresse = adr; }  // Définit l'adresse de l'employé.

string Employe::getPoste() const { return poste; }  // Renvoie le poste de l'employé.
void Employe::setPoste(string pos) { poste = pos; }  // Définit le poste de l'employé.

double Employe::getSalaire() const { return salaire; }  // Renvoie le salaire de l'employé.
void Employe::setSalaire(double sal) { salaire = sal; }  // Définit le salaire de l'employé.

string Employe::getDateEmbauche() const { return dateEmbauche; }  // Renvoie la date d'embauche de l'employé.
void Employe::setDateEmbauche(string date) { dateEmbauche = date; }  // Définit la date d'embauche de l'employé.

// **Méthode saisie**
// Demande à l'utilisateur de saisir les informations de l'employé.
void Employe::saisie() {
    cout << "Enter ID: "; cin >> identifiant;  // Demande l'identifiant.
    cout << "Enter Name: "; cin >> nom;  // Demande le nom.
    cout << "Enter Surname: "; cin >> prenom;  // Demande le prénom.
    cout << "Enter Address: "; cin >> adresse;  // Demande l'adresse.
    cout << "Enter Position: "; cin >> poste;  // Demande le poste.
    cout << "Enter Salary: "; cin >> salaire;  // Demande le salaire.
    cout << "Enter Hire Date (YYYY-MM-DD): "; cin >> dateEmbauche;  // Demande la date d'embauche.
}

// **Méthode afficher**
// Affiche les informations de l'employé en utilisant l'opérateur de flux << sur un objet Employe.
void Employe::afficher() const {
    cout << *this;  // Utilisation de l'opérateur << sur l'objet actuel.
}

// **Méthode comparer**
// Compare deux employés en fonction de leur identifiant.
bool Employe::comparer(const Employe &e) const {
    return identifiant == e.identifiant;  // Retourne true si les identifiants sont égaux.
}

// **Surcharge de l'opérateur ==**
// Compare deux employés pour voir s'ils sont égaux en comparant leur identifiant.
bool Employe::operator==(const Employe &e) const {
    return identifiant == e.identifiant;  // Retourne true si les identifiants sont égaux.
}

// **Surcharge de l'opérateur <<**
// Permet d'afficher un objet Employe dans un flux de sortie (par exemple, cout).
ostream &operator<<(ostream &out, const Employe &e) {
    out << "ID: " << e.identifiant << ", Name: " << e.nom << ", Surname: " << e.prenom
        << ", Address: " << e.adresse << ", Position: " << e.poste
        << ", Salary: " << e.salaire << ", Hire Date: " << e.dateEmbauche;  // Affiche tous les attributs.
    return out;  // Retourne le flux de sortie pour permettre un chaînage d'opérations.
}

