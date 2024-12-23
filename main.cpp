#include "Employe.h"   // Inclusion de la classe Employe
#include "Departement.h" // Inclusion de la classe Departement
#include <iostream>     // Pour les entrées/sorties standard
using namespace std;

int main() {
    Departement department;  // Déclaration d'un objet de type Departement
    int choice;              // Variable pour stocker le choix de l'utilisateur

    cout << " ===== Gestion d employee =====" << endl; // Affiche le titre du programme

    do {
        // Affichage du menu principal avec différentes options
        cout << "\n Menu: \n";
        cout << "1. Cree Department\n";
        cout << "2. Ajouter un Employee dans Department\n";
        cout << "3. Afficher les détails du département \n";
        cout << "4. Verificatio si  Employee Exists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Lecture du choix de l'utilisateur

        switch (choice) {
            // Option 1: Créer un département
            case 1: {
                int id;
                string name, date;
                Employe responsable; // Un objet Employe pour le responsable du département

                // Demande à l'utilisateur d'entrer les détails du département
                cout << "Enter Department ID: ";
                cin >> id;
                cout << "Enter Department Name: ";
                cin >> name;
                cout << "Enter Department Creation Date (YYYY-MM-DD): ";
                cin >> date;

                // Demande à l'utilisateur d'entrer les détails du responsable
                cout << "\nEnter Responsible Employee Details:\n";
                responsable.saisie(); // Appel de la méthode saisie() de la classe Employe pour entrer les informations du responsable

                // Création du département avec les informations fournies
                department = Departement(id, name, responsable, date);
                cout << "Department created successfully!\n"; // Confirmation de la création du département
                break;
            }

            // Option 2: Ajouter un employé au département
            case 2: {
                Employe emp; // Un objet Employe pour un nouvel employé
                cout << "\nEnter Employee Details:\n";
                emp.saisie(); // Appel de la méthode saisie() de la classe Employe pour entrer les informations de l'employé
                department.ajouterEmploye(emp); // Ajoute l'employé au département
                break;
            }

            // Option 3: Afficher les détails du département
            case 3:
                cout << "\nDepartment Details:\n";
                cout << department; // Affiche les informations du département en utilisant l'opérateur <<
                break;

            // Option 4: Vérifier si un employé existe dans le département
            case 4: {
                int empID;
                cout << "Enter Employee ID to Verify: ";
                cin >> empID; // Demande à l'utilisateur d'entrer l'ID de l'employé à vérifier

                // Vérifie si l'employé existe dans le département
                if (department.verifierEmploye(empID)) {
                    cout << "Employee exists in the department.\n"; // Affiche si l'employé existe
                } else {
                    cout << "Employee does NOT exist in the department.\n"; // Affiche si l'employé n'existe pas
                }
                break;
            }

            // Option 5: Quitter le programme
            case 5:
                cout << "Exiting program. Goodbye!\n"; // Message de sortie
                break;

            // Cas par défaut: Si l'utilisateur entre une option invalide
            default:
                cout << "Invalid choice. Please try again.\n"; // Affiche un message d'erreur pour un choix invalide
        }
    } while (choice != 5); // Continue le menu jusqu'à ce que l'utilisateur choisisse de quitter (option 5)

    return 0; // Fin du programme
}

