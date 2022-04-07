#pragma once
#include<iostream>

class School
{
private:
	
	std::string name;
	double longitude;
	double latitude;
	std::string date;
	bool visited;


public:
	/*Default constructor(size is unique)*/
	School() :name(""),longitude(0.0),latitude(0.0),date(""), visited(false) {}
	School(const std::string& name, double longi, double lati, const std::string& d, bool v) :
		name(name),longitude(longi),latitude(lati),date(d),visited(v) {}
	
	std::string GetName()const { return name; }
	
	double GetLongi()const { return longitude; }
	double GetLati()const { return latitude; }
	std::string GetDate()const { return date; }
	bool GetPhotograph()const { return visited; }

	/*The assignment operator*/
	School operator=(const School& s);


	/*Copy consructor.*/
	School(const School& s);
	

	bool operator==(const School& s);
	/*output: string containing the trench coat data*/
	std::string toStr();
};