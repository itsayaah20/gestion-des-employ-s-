#include "Employe.h"  // Inclusion du fichier d'en-t�te qui contient la d�claration de la classe "Employe"

// **Constructeur par d�faut**
// Initialise les membres de la classe avec des valeurs par d�faut.
Employe::Employe() 
    : identifiant(0), nom(""), prenom(""), adresse(""), poste(""), salaire(0.0), dateEmbauche("") {}

// **Constructeur param�tr�**
// Initialise les membres de la classe avec les valeurs fournies en param�tres.
Employe::Employe(int id, string n, string p, string adr, string pos, double sal, string date) 
    : identifiant(id), nom(n), prenom(p), adresse(adr), poste(pos), salaire(sal), dateEmbauche(date) {}

// **Getters et Setters**
// Ces m�thodes permettent d'acc�der et de modifier les variables membres priv�es de la classe.

int Employe::getIdentifiant() const { return identifiant; }  // Renvoie l'identifiant de l'employ�.
void Employe::setIdentifiant(int id) { identifiant = id; }  // D�finit l'identifiant de l'employ�.

string Employe::getNom() const { return nom; }  // Renvoie le nom de l'employ�.
void Employe::setNom(string n) { nom = n; }  // D�finit le nom de l'employ�.

string Employe::getPrenom() const { return prenom; }  // Renvoie le pr�nom de l'employ�.
void Employe::setPrenom(string p) { prenom = p; }  // D�finit le pr�nom de l'employ�.

string Employe::getAdresse() const { return adresse; }  // Renvoie l'adresse de l'employ�.
void Employe::setAdresse(string adr) { adresse = adr; }  // D�finit l'adresse de l'employ�.

string Employe::getPoste() const { return poste; }  // Renvoie le poste de l'employ�.
void Employe::setPoste(string pos) { poste = pos; }  // D�finit le poste de l'employ�.

double Employe::getSalaire() const { return salaire; }  // Renvoie le salaire de l'employ�.
void Employe::setSalaire(double sal) { salaire = sal; }  // D�finit le salaire de l'employ�.

string Employe::getDateEmbauche() const { return dateEmbauche; }  // Renvoie la date d'embauche de l'employ�.
void Employe::setDateEmbauche(string date) { dateEmbauche = date; }  // D�finit la date d'embauche de l'employ�.

// **M�thode saisie**
// Demande � l'utilisateur de saisir les informations de l'employ�.
void Employe::saisie() {
    cout << "Enter ID: "; cin >> identifiant;  // Demande l'identifiant.
    cout << "Enter Name: "; cin >> nom;  // Demande le nom.
    cout << "Enter Surname: "; cin >> prenom;  // Demande le pr�nom.
    cout << "Enter Address: "; cin >> adresse;  // Demande l'adresse.
    cout << "Enter Position: "; cin >> poste;  // Demande le poste.
    cout << "Enter Salary: "; cin >> salaire;  // Demande le salaire.
    cout << "Enter Hire Date (YYYY-MM-DD): "; cin >> dateEmbauche;  // Demande la date d'embauche.
}

// **M�thode afficher**
// Affiche les informations de l'employ� en utilisant l'op�rateur de flux << sur un objet Employe.
void Employe::afficher() const {
    cout << *this;  // Utilisation de l'op�rateur << sur l'objet actuel.
}

// **M�thode comparer**
// Compare deux employ�s en fonction de leur identifiant.
bool Employe::comparer(const Employe &e) const {
    return identifiant == e.identifiant;  // Retourne true si les identifiants sont �gaux.
}

// **Surcharge de l'op�rateur ==**
// Compare deux employ�s pour voir s'ils sont �gaux en comparant leur identifiant.
bool Employe::operator==(const Employe &e) const {
    return identifiant == e.identifiant;  // Retourne true si les identifiants sont �gaux.
}

// **Surcharge de l'op�rateur <<**
// Permet d'afficher un objet Employe dans un flux de sortie (par exemple, cout).
ostream &operator<<(ostream &out, const Employe &e) {
    out << "ID: " << e.identifiant << ", Name: " << e.nom << ", Surname: " << e.prenom
        << ", Address: " << e.adresse << ", Position: " << e.poste
        << ", Salary: " << e.salaire << ", Hire Date: " << e.dateEmbauche;  // Affiche tous les attributs.
    return out;  // Retourne le flux de sortie pour permettre un cha�nage d'op�rations.
}

