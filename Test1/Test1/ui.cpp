#include "ui.h"
#include<cstring>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <fstream>
#include<exception>
#include <windows.h>

void UI::listSchools()
{
	School* schools = this->service->getSchools();
	for (int i = 0; i < this->service->getNr(); i++) {
		std::cout << this->service->getSchools()[i].toStr() << "\n";

	}
}

void UI::UI_delete(std::stringstream& parameters)
{
	
		std::string currentParameter;
		getline(parameters, currentParameter, ',');
		std::string name = currentParameter;
		this->service->deleteSchool(name);

}

void UI::run()
{
	std::string inputString, command;
	while (true) {
		try {
			getline(std::cin, inputString);

			if (inputString.compare("exit") == 0) {
				return;
			}
			if (inputString.compare("list") == 0) {
				this->listSchools();
			}
			std::stringstream parameterStream{ inputString };


			getline(parameterStream, command, ' ');

			
			if (command.compare("delete") == 0) {
				this->UI_delete(parameterStream);
				continue;
			}
			
			

		}
	
		catch (std::exception&) {
			std::cout << "No!" << std::endl;
		}
	}
}
