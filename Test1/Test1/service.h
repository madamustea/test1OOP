#pragma once
#include"domain.h"
#include"DynamicArray.h"
#include"repository.h"
#include"Validator.h"

#include"repository.h"

class Service {
private:
	Repo* Repository;

public:
	Service(Repo* Repository) :Repository(Repository) {};
	void addSchool(std::string name, double longi, double lat, std::string date, bool v);
	/*
	* input - string with name
	* output - the school with that name is searched and deleted
	*/
	void deleteSchool(std::string name);
	School* getSchools() { return Repository->GetDynamicArray(); }
	int getNr() { return Repository->getNr(); }
};