#pragma once
#include"domain.h"
#include"DynamicArray.h"
class Repo {
private:
	DynamicArray<School>* dynamicArray;
	
public:
	//constructor
	Repo(DynamicArray<School>* dynamicArray) :dynamicArray(dynamicArray) {}
	
	bool exists(School s);
	/*
	* input - school object
	* output - object deleted from array
	*/
	void delete_repo(School s);
	void add_repo(School s);

	School* GetDynamicArray() {
		return dynamicArray->GetElems();
	}
	int getNr() { return dynamicArray->getNrOfElems(); }
	School search(School s);
};