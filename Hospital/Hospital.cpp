#include "Header.h"
#include "Menu.h"
#include "PatientManager.h"

int main()
{
    std::string taskName = "Hospital clients catalogue";
    std::vector<std::string> menuList = {
        "Display all patients",
        "Add new patient",
        "Delete one patient",
        "Show list of patients by doctors",
        "Show list of patients by diagnos",
        "Exit"
    };

    std::unique_ptr<Menu> m(new Menu(taskName, menuList));
    std::unique_ptr<PatientManager> manager(new PatientManager);
    manager->loadData();

    bool stop = false;
    do {
        system("cls");
        m->displayTaskName();
        m->displayMenuList();
        int choice = m->getChoice();
        switch (choice)
        {
        case 1:
            manager->displayAllPatients();
            break;
        case 2:
            manager->addPatient();
            break;
        case 3:
            manager->delPatient();
            break;
        case 4:
            manager->docList();
            break;
        case 5:
            manager->diagList();
            break;
        case 6: stop = true;
            break;
        default: std::cout << "\n Wrong choice";
            break;
        }
        if (stop) {
            break;
        }

    } while (m->allowContinue());
    
    std::cout << "\n Finish program\n";
}
