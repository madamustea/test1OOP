#include"domain.h"
#include<string>
#include<stdlib.h>

School School::operator=(const School& s) {
	this->name = s.name;
	this->longitude = s.longitude;
	this->latitude = s.latitude;
	this->date = s.date;
	this->visited = s.visited;
	return *this;

}

School::School(const School& s)
{
	this->name = s.name;
	this->longitude = s.longitude;
	this->latitude = s.latitude;
	this->date = s.date;
	this->visited = s.visited;


}
bool School::operator==(const School& s) {
	if (this->name == s.name)return true;
	else return false;
}
std::string School::toStr() {
	std::string longiString = std::to_string(this->longitude);
	std::string latiString = std::to_string(this->latitude);
	std::string vString = std::to_string(this->visited);
	return name+"|" + longiString + "," + latiString + "|" + date + "|"+ vString;
}