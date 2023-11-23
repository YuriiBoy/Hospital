#pragma once

class Patient
{
	int id;
	std::string name;
	int age;
	std::string doc;
	std::string diagnoz;
public:
	Patient();
	Patient(int id, std::string name, int age, std::string doc, std::string diagnoz);
	void display() const;
	int getId() const;
	std::string getName() const;
	int getAge() const;
	std::string getDoc() const;
	std::string getDiagnoz() const;
};

