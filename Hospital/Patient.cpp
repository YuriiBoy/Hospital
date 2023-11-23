#include "Header.h"
#include "Patient.h"

Patient::Patient() : id(0), name("-"), age(0), doc("-"), diagnoz("-")
{}

Patient::Patient(int id, std::string name, int age, std::string doc, std::string diagnoz)
	: id(id), name(name), age(age), doc(doc), diagnoz(diagnoz)
{}

void Patient::display() const
{

	std::cout << std::setw(5) << id;
	std::cout << std::setw(20) << name;
	std::cout << std::setw(10) << age;
	std::cout << std::setw(20) << doc;
	std::cout << std::setw(20) << diagnoz;
	std::cout << std::endl;
}

int Patient::getId() const
{
	return id;
}

std::string Patient::getName() const
{
	return name;
}

int Patient::getAge() const
{
	return age;
}

std::string Patient::getDoc() const
{
	return doc;
}

std::string Patient::getDiagnoz() const
{
	return diagnoz;
}
