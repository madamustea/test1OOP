#pragma once
#include"domain.h"
#include"DynamicArray.h"
#include"repository.h"
#include"service.h"
class UI {
private:
	Service* service;
public:
	//constructor
	UI(Service* service) :service(service) {};
	void listSchools();
	void UI_delete(std::stringstream& parameters);
	void run();
};