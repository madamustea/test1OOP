#include"domain.h"
#include"DynamicArray.h"
#include"repository.h"
#include"service.h"
#include"ui.h"
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

#include<sstream>
using namespace std;
void test_delete_repo()
{
	DynamicArray<School> dynamicArray;
	Repo Repository(&dynamicArray);


	try {
		Repository.add_repo(School{"s1",44.5,55.6,"23.04.2000",false});
		Repository.delete_repo(School{ "s1",0.0,0.0,"",false});

	}
	catch (std::exception&) {}
	assert(Repository.getNr() == 0);

}

void test_deleteServ() {
	DynamicArray<School> dynamicArray;

	Repo Repository(&dynamicArray);
	
	Service service(&Repository);
	service.addSchool("s2",0.0,0.0,"2.3.2022",false);
	service.deleteSchool("s2");
	assert(service.getNr() == 0);
}

int main()
{
	test_delete_repo();
	test_deleteServ();
	DynamicArray<School> dynamicArray;
	


	Repo Repository(&dynamicArray);
	Service service(&Repository);
	service.addSchool("Avram_Iancu", 46.77, 23.60, "15.04.2022", true);
	service.addSchool("George_Cosbuc", 46.77, 23.58, "18.04.2022", false);
	service.addSchool("Alexandru_Vaida", 46.77, 23.63, "23.04.2022", false);
	service.addSchool("Romulus_Guga", 46.77, 23.63, "21.04.2022", false);
	service.addSchool("Colegiu_T", 46.77, 23.63, "19.04.2022", false);
	UI ui(&service);

	ui.run();
	return 0;
}