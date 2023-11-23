#pragma once

#include "Patient.h"

class PatientManager
{
	std::vector<Patient> group;
public:
	void loadData();
	void saveData();
	void displayAllPatients() const;
	void addPatient();
	void delPatient();
	void docList() const;
	void diagList() const;
};

