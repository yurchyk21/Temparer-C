#include "Header.h"

int login(user &currentUser, user *userBase) {
	int triger = 0;
	int passTimesCounter = 0;
loginEnter:
	system("CLS");
	cout << "--------------STAFF DATABASE MENU--------------" << endl;
	cout << "Enter your login (employee ID): ";
	cin >> currentUser.employeeID;
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		if (currentUser.employeeID == userBase[i].employeeID) {
			cout << "\nEnter password (you have " << (3 - passTimesCounter) << " attempts): ";
			cin >> currentUser.userPass;
			passTimesCounter++;
			if (passTimesCounter < 3) {
				if (!strcmp(currentUser.userPass, userBase[i].userPass)) {
					currentUser.rights = userBase[i].rights;
					return 1;
				}
				else
				{
					cout << "Wrong password.\n Try again.  ";
					goto loginEnter;
				}
			}
			else {
				cout << "\nYou have entered wrong password 3 times. \nCheck out your login and try again later. \nBye." << endl;
				currentUser.rights = NoRights;
				return 0;
			}
		}
	}
}

void displayHead() {
	system("CLS");
	cout << "----------------------------PERSONELL DATABASE---------------------------------" << endl;
	cout << "|    |     First Name     |S| Passport |dep ID|          State / Region       |" << endl;
	cout << "| ID |    Fathers Name    |e| Tax Code |  /   |             City              |" << endl;
	cout << "|    |     Second Name    |x|Pens. code|workID|      Street / house / flat    |" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}
void displayLine() {
	cout << "-------------------------------------------------------------------------------" << endl;
}

void displayOneWorker(staff *worker) {
	cout << "|    |" << setw(NAME_SIZE) << worker->staffName.name <<\
		"| |" << worker->docs.passportSerial<< "  " << worker->docs.passportNumber << "|"\
		<<setw(6) << worker->departmentID<<"|"<<setw(ADDRESS_SIZE)<<worker->livingAddress.state <<"/"\
		<<  setw(ADDRESS_SIZE) << worker->livingAddress.region <<"|"<< endl;
	
	cout << "|" << setw(4) << worker->employeeID <<"|"<< setw(NAME_SIZE) << worker->staffName.fathersName <<\
		"|"<<((worker->sex)?("M"):("F"))<<"|" << worker->docs.taxCode << "|   /  |" << setw(ADDRESS_SIZE*2+1)\
		<< worker->livingAddress.city << "|" << endl;

	cout << "|    |" << setw(NAME_SIZE) << worker->staffName.surname << \
		"| |" <<setw(10) << worker->docs.pensionNumber << "|"\
		<< setw(6) << worker->specID << "|" << setw(ADDRESS_SIZE) << worker->livingAddress.street\
		<< "/" << setw(7) << worker->livingAddress.houseNumber<< "/" << setw(7) << worker->livingAddress.flatNumber << "|" << endl;
}

void displayDatabase(staff  *allStaff, int staffBaseSize) {
	displayHead();
	for (int i = 0; i < staffBaseSize; i++)
	{
		displayOneWorker(allStaff + i);
		displayLine();
		if (i>0 && i%49==0) {
			cout << "Press enter to cont³nue. ";
			system("PAUSE");
			system("CLS");
			displayHead();

		}
	}
	system("PAUSE");
}

//----------------------Find Menu and Find functions------------------------

void findEmployeeMenu(staff *allStaff, int staffBaseSize) {
	int menu = 1;
	while (menu)
	{
		system("CLS");
		cout << "--------------STAFF DATABASE MENU--------------" << endl;
		cout << "	-----------------FIND STAFF MENU----------------" << endl;
		cout << "	Press:" << endl;
		cout << "	1. To find employee by Staff ID." << endl;
		cout << "	2. To find employee by Surname." << endl;
		cout << "	3. To find employee by Tax code." << endl;
		cout << "	0. To exit." << endl;
		cout << "	Do your choise: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			findEmployeeByID(allStaff, staffBaseSize);
			break;
		case 2:
			findEmployeeBySurname(allStaff, staffBaseSize);
			break;
		case 3:
			findEmployeeByTaxCode(allStaff, staffBaseSize);
			break;
		case 0:
			cout << "Bye." << endl;
			break;
		default:
			cout << "Wrong choise. To try again press enter.";
			system("PAUSE");
			break;
		}
	}
}

void findEmployeeByID(staff  *allStaff, int staffBaseSize) {
	int tempID;
	cout << "Enter ID: ";
	cin >> tempID;
	for (int i = 0; i < staffBaseSize; i++)
	{
		if (allStaff[i].employeeID == tempID) {
			displayHead();
			displayOneWorker(allStaff+i);
			displayLine();
			system("PAUSE");
			return;
		}
	}
	cout << "Employee not found." << endl;
	system("PAUSE");
}

void findEmployeeByTaxCode(staff *allStaff, int staffBaseSize) {
	char* temp = new char[DATE_SIZE];
	cout << "Enter Tax Code: ";
	cin >> temp;
	int counter = 0;
	for (int i = 0; i < staffBaseSize; i++)
	{
		if (!strcmp(allStaff[i].docs.taxCode, temp)) {
			displayHead();
			displayOneWorker(allStaff + i);
			displayLine();
			counter++;
		}
	}
	delete[] temp;
	if (!counter) {
		cout << "Employee not found." << endl;
	}
	system("PAUSE");
}

void findEmployeeBySurname(staff *allStaff, int staffBaseSize) {
	char* temp = new char[NAME_SIZE];
	cout << "Enter Surname:";
	int counter = 0;
	cin >> temp;
	for (int i = 0; i < staffBaseSize; i++)
	{
		if (!stricmp(allStaff[i].staffName.surname, temp)) {
			if (!counter)
				displayHead();
			displayOneWorker(allStaff + i);
			displayLine();
			counter++;
		}
	}
	delete[] temp;
	if (!counter) {
		cout << "Employee not found." << endl;
	}
	system("PAUSE");
}



//------------------------Sort functions------------------------------

void sortEmployeeByWorkID(staff *allStaff, int staffBaseSize) {
	for (int i = 0; i < staffBaseSize; i++)
	{
		for (int j = 1; j < staffBaseSize-i; j++)
		{
			if (allStaff[j].specID<allStaff[j-1].specID) {
				swap(allStaff[j], allStaff[j - 1]);
			}
		}
	}
}

void sortEmployeeByDepartmentID(staff *allStaff, int staffBaseSize) {
	for (int i = 0; i < staffBaseSize; i++)
	{
		for (int j = 1; j < staffBaseSize - i; j++)
		{
			if (allStaff[j].departmentID < allStaff[j - 1].departmentID) {
				swap(allStaff[j], allStaff[j - 1]);
			}
		}
	}
}

//--------------------------------REPORT-------------------------------
void departmentStaffAndQuantity(staff  *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize) {
	int temp;
	int quantityCounter = 0;
	cout << "\nEnter department ID: ";
	cin >> temp;
	if (isDepartment(departmentBase, departmentBaseSize, temp)) {
		displayHead();
		for (int i = 0; i < staffBaseSize; i++)
		{
			if (allStaff[i].departmentID == temp)
			{
				quantityCounter++;
				displayOneWorker(allStaff + i);
				displayLine();
			}
		}
		cout << "QUANTITY OF DEPARTMENT: " << quantityCounter << endl;
	}
	else {
		cout << "No department with ID: " << temp << endl;
	}
	system("PAUSE");
}

// ----------------------whatching for department existing-----------------
int isDepartment(partition *departmentBase, int departmentBaseSize, int temp) {
	for (int i = 0; i < departmentBaseSize; i++)
	{
		if (departmentBase[i].unitID == temp)
		{
			return 1;
		}
	}
	return 0;
}
// ----------------------whatching for work existing-----------------
int isWork(work *workBase, int workBaseSize, int temp) {
	for (int i = 0; i < workBaseSize; i++)
	{
		if (workBase[i].workID == temp)
		{
			return 1;
		}
	}
	return 0;
}

// ----------------------whatching for Employee ID existing-----------------

int isEmployee(staff *allStaff, int staffBaseSize, int temp) {
	for (int i = 0; i < staffBaseSize; i++)
	{
		if (allStaff[i].employeeID == temp)
		{
			return 1;
		}
	}
	return 0;
}


//-----------------------------PHONE FUNCTIONS-------------------------

void findEmployeePhone(staff *allStaff, int staffBaseSize) {
	char* temp = new char[NAME_SIZE];
	cout << "Enter Surname:";
	int counter = 0;
	cin >> temp;
	for (int i = 0; i < staffBaseSize; i++)
	{
		if (!stricmp(allStaff[i].staffName.surname, temp)) {
			if (!counter) {
				cout << "-------------------------------------PHONES------------------------------------" << endl;
				cout << "|     First name     |     Second name    |   Work phone   |     cell phone   |" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
			}
			cout << "|" <<setw(NAME_SIZE)<< allStaff[i].staffName.name <<"|" << setw(NAME_SIZE) << allStaff[i].staffName.surname \
				<<"|"<<setw(16)<< allStaff[i].staffContacts.workPhone <<"|" << setw(18) << allStaff[i].staffContacts.cellPhone << "|" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			counter++;
		}
	}
	delete[] temp;
	if (!counter) {
		cout << "Employee not found." << endl;
	}
	system("PAUSE");
}

void displayPhoneBase(staff *allStaff, int staffBaseSize) {
	cout << "-------------------------------------PHONES------------------------------------" << endl;
	cout << "|     First name     |     Second name    |   Work phone   |     cell phone   |" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < staffBaseSize; i++)
	{
		cout << "|" << setw(NAME_SIZE) << allStaff[i].staffName.name << "|" << setw(NAME_SIZE) << allStaff[i].staffName.surname \
			<< "|" << setw(16) << allStaff[i].staffContacts.workPhone << "|" << setw(18) << allStaff[i].staffContacts.cellPhone << "|" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	}
	system("PAUSE");
}

//----------------------WORK AND DEPARTMENT LISTS DISPLAY--------

void displayWorkList(work *workBase, int workBaseSize) {
	cout << "-----------WORK LIST-------------" << endl;
	cout << "|  Work ID  |      Work name    |" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < workBaseSize; i++)
	{
		cout << "|" << setw(DATE_SIZE) << workBase[i].workID<< "|" << setw(NAME_SIZE) << workBase[i].workName << "|" << endl;
	}
	cout << "---------------------------------" << endl;
	system("PAUSE");
}

void displayDepartmentList(partition *departmentBase, int departmentBaseSize) {
	cout << "----------DEPARTMENT LIST--------" << endl;
	cout << "|Departm. ID|  Department name  |" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < departmentBaseSize; i++)
	{
		cout << "|" << setw(DATE_SIZE) << departmentBase[i].unitID << "|" << setw(NAME_SIZE) << departmentBase[i].unitName << "|" << endl;
	}
	cout << "---------------------------------" << endl;
	system("PAUSE");
}

