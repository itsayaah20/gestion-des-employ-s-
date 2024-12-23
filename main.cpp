#include "Employe.h"   // Inclusion de la classe Employe
#include "Departement.h" // Inclusion de la classe Departement
#include <iostream>     // Pour les entr�es/sorties standard
using namespace std;

int main() {
    Departement department;  // D�claration d'un objet de type Departement
    int choice;              // Variable pour stocker le choix de l'utilisateur

    cout << " ===== Gestion d employee =====" << endl; // Affiche le titre du programme

    do {
        // Affichage du menu principal avec diff�rentes options
        cout << "\n Menu: \n";
        cout << "1. Cree Department\n";
        cout << "2. Ajouter un Employee dans Department\n";
        cout << "3. Afficher les d�tails du d�partement \n";
        cout << "4. Verificatio si  Employee Exists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Lecture du choix de l'utilisateur

        switch (choice) {
            // Option 1: Cr�er un d�partement
            case 1: {
                int id;
                string name, date;
                Employe responsable; // Un objet Employe pour le responsable du d�partement

                // Demande � l'utilisateur d'entrer les d�tails du d�partement
                cout << "Enter Department ID: ";
                cin >> id;
                cout << "Enter Department Name: ";
                cin >> name;
                cout << "Enter Department Creation Date (YYYY-MM-DD): ";
                cin >> date;

                // Demande � l'utilisateur d'entrer les d�tails du responsable
                cout << "\nEnter Responsible Employee Details:\n";
                responsable.saisie(); // Appel de la m�thode saisie() de la classe Employe pour entrer les informations du responsable

                // Cr�ation du d�partement avec les informations fournies
                department = Departement(id, name, responsable, date);
                cout << "Department created successfully!\n"; // Confirmation de la cr�ation du d�partement
                break;
            }

            // Option 2: Ajouter un employ� au d�partement
            case 2: {
                Employe emp; // Un objet Employe pour un nouvel employ�
                cout << "\nEnter Employee Details:\n";
                emp.saisie(); // Appel de la m�thode saisie() de la classe Employe pour entrer les informations de l'employ�
                department.ajouterEmploye(emp); // Ajoute l'employ� au d�partement
                break;
            }

            // Option 3: Afficher les d�tails du d�partement
            case 3:
                cout << "\nDepartment Details:\n";
                cout << department; // Affiche les informations du d�partement en utilisant l'op�rateur <<
                break;

            // Option 4: V�rifier si un employ� existe dans le d�partement
            case 4: {
                int empID;
                cout << "Enter Employee ID to Verify: ";
                cin >> empID; // Demande � l'utilisateur d'entrer l'ID de l'employ� � v�rifier

                // V�rifie si l'employ� existe dans le d�partement
                if (department.verifierEmploye(empID)) {
                    cout << "Employee exists in the department.\n"; // Affiche si l'employ� existe
                } else {
                    cout << "Employee does NOT exist in the department.\n"; // Affiche si l'employ� n'existe pas
                }
                break;
            }

            // Option 5: Quitter le programme
            case 5:
                cout << "Exiting program. Goodbye!\n"; // Message de sortie
                break;

            // Cas par d�faut: Si l'utilisateur entre une option invalide
            default:
                cout << "Invalid choice. Please try again.\n"; // Affiche un message d'erreur pour un choix invalide
        }
    } while (choice != 5); // Continue le menu jusqu'� ce que l'utilisateur choisisse de quitter (option 5)

    return 0; // Fin du programme
}

