#include "repository.h"
#include<iostream>
void Repo::add_repo(School s)
{
	if (this->exists(s) == true)throw std::exception("school already exists");

	else {
		this->dynamicArray->add(s);
	}

}
bool Repo::exists(School s)
{
	int ok = 0;
	for (int i = 0; i < this->dynamicArray->getNrOfElems(); i++) {
		if (this->dynamicArray->GetElems()[i].GetName()== s.GetName()) {

			ok = 1;
		}

	}
	if (ok == 1)return true;
	else return false;
}

School Repo::search(School s)
{
	int position = 0;
	for (int i = 0; i < this->dynamicArray->getNrOfElems(); i++) {
		if (this->dynamicArray->GetElems()[i] == s) {

			position = i;
			break;
		}
	}
	return this->dynamicArray->GetElems()[position];
}

void Repo::delete_repo(School s)
{

	if (this->exists(s) == false)throw std::exception("school does not exists");

	else {
		this->dynamicArray->remove(s);
		
		std::cout << " school removed " ;
	}
}