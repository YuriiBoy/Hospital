#include "Header.h"
#include "PatientManager.h"

void PatientManager::loadData()
{
	std::ifstream fin;
	fin.open("Data.txt");
	int id;
	std::string name;
	int age;
	std::string doc;
	std::string diagnoz;

	while (!fin.eof()) 	{
		fin >> id;
		fin.ignore();
		std::getline(fin, name);
		fin >> age;
		fin.ignore();
		std::getline(fin, doc);
		std::getline(fin, diagnoz);

		Patient pat(id, name, age, doc, diagnoz);
		group.push_back(pat);
		std::cout << "\n List of patients has been loaded\n";
	}
	group.pop_back();
	fin.close();
}

void PatientManager::saveData()
{
	std::ofstream fout;
	fout.open("Data.txt");

	for (int i = 0; i < group.size(); i++) {
		Patient temp = group[i];
		fout << temp.getId() << std::endl;
		fout << temp.getName() << std::endl;
		fout << temp.getAge() << std::endl;
		fout << temp.getDoc() << std::endl;
		fout << temp.getDiagnoz() << std::endl;
	}
	fout.close();
	std::cout << "\n List of patients is saved\n";
}

void PatientManager::displayAllPatients() const
{
	if (group.empty()) {
		std::cout << "\n Patients list is empty\n";
	}
	else {
		const int N = group.size();
		std::cout << "\n There are " << N << " parients in the list\n";
		std::cout << std::setw(5) << "N" << std::setw(21) << " Name: ";
		std::cout << std::setw(10) << " Age : " << std::setw(20) << " Doctor name:";
		std::cout << std::setw(20) << " Diagnoz:\n";
		for (int i = 0; i < N; i++) {
			group[i].display();
		}
	}
}

void PatientManager::addPatient()
{
	int id;
	std::string name;
	int age;
	std::string doc;
	std::string diagnoz;

	id = group.back().getId() + 1;
	std::cin.ignore();
	std::cout << "\n Input name of the patient: - ";
	std::getline(std::cin, name);
	std::cout << "\n Input age of the patient: - ";
	std::cin >> age;
	std::cin.ignore();
	std::cout << "\n Input name of the doctor: - ";
	std::getline(std::cin, doc);
	std::cout << "\n Input name of diagnoz: - ";
	std::getline(std::cin, diagnoz);

	Patient newPatient(id, name, age, doc, diagnoz);
	group.push_back(newPatient);
	saveData();
}

void PatientManager::delPatient()
{
	int id;
	std::cout << "\n Please input patient`s ID to delete: ";
	std::cin >> id;
	auto iter = std::find_if(group.begin(), group.end(),
		[id](Patient& p) {return(p.getId() == id); });
	if (iter == group.end()) {
		std::cout << "\n There is no such patient";
	}
	else {
		group.erase(iter);
		std::cout << "\n The patient has been deleted\n";
		saveData();
	}
}

void PatientManager::docList() const
{
	std::string doc;
	std::cout << "\n Please input name of the doctor to see its patients: \n";
	std::cin.ignore();
	std::getline(std::cin, doc);

	std::for_each(group.begin(), group.end(),
		[doc](const Patient& p) {
			if (p.getDoc() == doc) {
				p.display();
			}
		});
	
}

void PatientManager::diagList() const
{
	std::string diagnoz;
	std::cout << "\n Please input the diagnoz to see patients with it: \n";
	std::cin.ignore();
	std::getline(std::cin, diagnoz);

	std::for_each(group.begin(), group.end(),
		[diagnoz](const Patient& p) {
			if (p.getDiagnoz() == diagnoz) {
				p.display();
			}
		});

}
