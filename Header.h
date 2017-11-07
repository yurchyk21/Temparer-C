#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#define ADDRESS_SIZE 15
#define NAME_SIZE 20
#define DATE_SIZE 11
#define PHONE_SIZE 20
#define DATABASE_SIZE 500
#define STRING_LONG 250
#define RADIX10 10

using namespace std;

enum accessRights { NoRights=0, Accountant, HR, Worker };

struct user
{
	int employeeID;
	char *userPass = new char[NAME_SIZE];
	accessRights rights;	
};


struct earn
{
	int sallarySumm;
	int premiumPercent;
	int bonusSumm;
};

struct EmployeeName
{
	char *name = new char[NAME_SIZE];
	char *fathersName = new char[NAME_SIZE];
	char *surname = new char[NAME_SIZE];
};

struct documents {
	char *passportSerial = new char[2];
	char *passportNumber = new char[6];
	char * taxCode = new char[DATE_SIZE];
	char * pensionNumber = new char[DATE_SIZE];
};
struct partition
{
	int unitID;
	char *unitName = new char[NAME_SIZE];
};
struct work {
	int workID;
	char *workName = new char[NAME_SIZE];
};
struct address
{
	char *state = new char[ADDRESS_SIZE];
	char *region = new char[ADDRESS_SIZE];
	char *city = new char[ADDRESS_SIZE];
	char *street = new char[ADDRESS_SIZE];
	int houseNumber;
	int flatNumber;
};

struct contacts
{
	char *workPhone = new char[PHONE_SIZE];
	char *cellPhone = new char[PHONE_SIZE];
	char *eMail = new char[NAME_SIZE];

};

struct staff
{
	int employeeID;
	EmployeeName staffName;
	documents docs;
	bool sex;
	char *birthdayDate = new char [DATE_SIZE];
	char *startWorkDate = new char [DATE_SIZE];
	address livingAddress;
	earn sallary;
	int departmentID;
	int specID;
	contacts staffContacts;
};

// --------------- Prototypes Common---------------
int login(user &currentUser,  user  *userBase);
void displayHead();
void displayLine();
void displayOneWorker(staff  * worker);
void displayDatabase(staff  * allStaff, int staffBaseSize);
void findEmployeeMenu(staff  * allStaff, int staffBaseSize);
void findEmployeeByID(staff  * allStaff, int staffBaseSize);
void findEmployeeByTaxCode(staff  * allStaff, int staffBaseSize);
void findEmployeeBySurname(staff  * allStaff, int staffBaseSize);
void sortEmployeeByWorkID(staff  * allStaff, int staffBaseSize);
void sortEmployeeByDepartmentID(staff  * allStaff, int staffBaseSize);
void departmentStaffAndQuantity(staff  * allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize);
int isDepartment(partition *departmentBase, int departmentBaseSize, int temp);
int isWork(work *workBase, int workBaseSize, int temp);
int isEmployee(staff *allStaff, int staffBaseSize, int temp);
void findEmployeePhone(staff *allStaff, int staffBaseSize);
void displayPhoneBase(staff *allStaff, int staffBaseSize);
void displayWorkList(work *workBase, int workBaseSize);
void displayDepartmentList(partition *departmentBase, int departmentBaseSize);

//-------------------- Prototypes Worker----------------
void workerMenu(staff  * allStaff, int staffBaseSize);



//-------------------- Prototypes Accountant----------------
void accountantMenu(staff  * allStaff, int staffBaseSize, work *workBase, int workBaseSize, partition *departmentBase, int departmentBaseSize);
void departmentFund(staff *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize);
void sallaryReport(staff *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize);





//--------------------- Prototypes HR------------------
void HRMenu(staff *allStaff, int &staffBaseSize, work *workBase, int &workBaseSize, partition *departmentBase, int &departmentBaseSize);
void addEmployee(staff *allStaff, int staffBaseSize);
void addWork(work *workBase, int workBaseSize);
void addDepartment(partition *departmentBase, int departmentBaseSize);
staff* deleteEmployee(staff *allStaff, int staffBaseSize);
void changeDeparmentWork(staff *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize, work *workBase, int workBaseSize);
staff *setBase(staff *allStaff, int &staffBaseSize);


//--------------------- Prototypes FILE------------------
user *setUserFromFile(int &userBaseSize);
partition *setDepartmentsFromFile(int &departmentBaseSize);
work *setWorksFromFile(int &workBaseSize);
staff *setStaffFromFile(int &staffBaseSize);
void fillInUserFile(user *userBase, int userBaseSize);
void fillInDepartmentsFile(partition *departmentBase, int departmentBaseSize);
void fillInWorksFile(work *workBase, int workBaseSize);
void fillInStaffFile(staff *staffBase, int staffBaseSize);
