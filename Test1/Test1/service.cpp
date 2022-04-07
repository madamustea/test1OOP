#include "service.h"

void Service::addSchool(std::string name, double longi, double lat, std::string date, bool v)
{
	School newS{ name,longi,lat,date,v };
	
	this->Repository->add_repo(newS);
}

void Service::deleteSchool(std::string name)
{
	School searched{ name,0.0,0.0,"",false};
	this->Repository->delete_repo(searched);
}
