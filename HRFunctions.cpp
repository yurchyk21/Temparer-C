#include "Header.h"

void HRMenu(staff *allStaff, int &staffBaseSize, work *workBase, int &workBaseSize, partition *departmentBase, int &departmentBaseSize) {
	int menu=1;
	while (menu)
	{
		system("CLS");
		cout << "--------------STAFF DATABASE MENU (HR)------------" << endl;
		cout << "Press:" << endl;
		cout << "1. To display all database." << endl;
		cout << "2. To find employee." << endl;
		cout << "3. To sort employees by department ID." << endl;
		cout << "4. To sort employees by work ID." << endl;
		cout << "5. To display Report:staff of department + quantity." << endl;
		cout << "6. To add emlployees." << endl;
		cout << "7. To add work ID." << endl;
		cout << "8. To add department ID." << endl;
		cout << "9. To delete employee." << endl;
		cout << "10. To find employee's phone number by surname." << endl;
		cout << "11. To change employee's department and work." << endl;
		cout << "12. To show phone database." << endl;
		cout << "13. To display works list." << endl;
		cout << "14. To display departments list." << endl;
		cout << "20. To save changes." << endl;
		cout << "0. To exit without saving changes." << endl;
		cout << "Do your choise: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			displayDatabase(allStaff, staffBaseSize);
			break;
		case 2:
			findEmployeeMenu(allStaff, staffBaseSize);
			break;
		case 3:
			sortEmployeeByDepartmentID(allStaff, staffBaseSize);
			break;
		case 4:
			sortEmployeeByWorkID(allStaff, staffBaseSize);
			break;
		case 5:
			departmentStaffAndQuantity(allStaff, staffBaseSize, departmentBase, departmentBaseSize);
			break;
		case 6:
			addEmployee(allStaff, staffBaseSize);
			staffBaseSize++;
			break;
		case 7:
			addWork(workBase, workBaseSize);
			workBaseSize++;
			break;
		case 8:
			addDepartment(departmentBase, departmentBaseSize);
			departmentBase++;
			break;
		case 9:
			allStaff = deleteEmployee(allStaff, staffBaseSize);
			staffBaseSize--;
			break;
		case 10:
			findEmployeePhone(allStaff, staffBaseSize);
			break;
		case 11:
			changeDeparmentWork(allStaff, staffBaseSize, departmentBase, departmentBaseSize, workBase, workBaseSize);
			break;
		case 12:
			displayPhoneBase(allStaff, staffBaseSize);
			break;
		case 13:
			displayWorkList(workBase, workBaseSize);
			break;
		case 14:
			displayDepartmentList(departmentBase, departmentBaseSize);
			break;
		case 20:
			fillInDepartmentsFile(departmentBase, departmentBaseSize);
			fillInWorksFile(workBase, workBaseSize);
			fillInStaffFile(allStaff, staffBaseSize);
			break;
		case 99:
			allStaff = setBase(allStaff, staffBaseSize);
			break;
		case 0:
			system("CLS");
			cout << "Good bye." << endl;
			return;
			break;
		default:
			cout << "Wrong choise. To try again press enter.";
			system("PAUSE");
			break;
		}
	}
}

//---------------------------HR Functions-----------------------------
void addEmployee(staff *allStaff, int staffBaseSize) {
	system("CLS");
	cout << "--------------STAFF DATABASE MENU--------------" << endl;
	cout << "	-----------------NEW EMPLOYEE ADD--------------" << endl;
	allStaff[staffBaseSize].employeeID = staffBaseSize+1;
	cout << "New employee ID:" << allStaff[staffBaseSize].employeeID<<endl;
	cout << "Enter first name: ";
	cin >> allStaff[staffBaseSize].staffName.name;
	cout << "Enter surname: ";
	cin >> allStaff[staffBaseSize].staffName.surname;
	cout << "Enter fathers name: ";
	cin >> allStaff[staffBaseSize].staffName.fathersName;
	cout << "Enter passport serial: ";
	cin >> allStaff[staffBaseSize].docs.passportSerial;
	cout << "Enter passport number: ";
	cin >> allStaff[staffBaseSize].docs.passportNumber;
	cout << "Enter tax code: ";
	cin >> allStaff[staffBaseSize].docs.taxCode;
	cout << "Enter pension number(if no enter 0): ";
	cin >> allStaff[staffBaseSize].docs.pensionNumber;
	cout << "Enter sex(0 for Female, 1 for Male):";
	cin >> allStaff[staffBaseSize].sex;
	cout << "Enter birthday date(dd.mm.yyyy):";
	cin >> allStaff[staffBaseSize].birthdayDate;
	cout << "Enter start work date (dd.mm.yyyy):";
	cin >> allStaff[staffBaseSize].startWorkDate;
	cout << "Enter living address:";
	cout << "	Enter state:";
	cin >> allStaff[staffBaseSize].livingAddress.state;
	cout << "	Enter region:";
	cin >> allStaff[staffBaseSize].livingAddress.region;
	cout << "	Enter city:";
	cin >> allStaff[staffBaseSize].livingAddress.city;
	cout << "	Enter street:";
	cin >> allStaff[staffBaseSize].livingAddress.street;
	cout << "	Enter house number:";
	cin >> allStaff[staffBaseSize].livingAddress.houseNumber;
	cout << "	Enter flat number:";
	cin >> allStaff[staffBaseSize].livingAddress.flatNumber;
	cout << "Enter sallary summ:";
	cin >> allStaff[staffBaseSize].sallary.sallarySumm;
	cout << "Enter premium percent:";
	cin >> allStaff[staffBaseSize].sallary.premiumPercent;
	cout << "Enter bonus summ:";
	cin >> allStaff[staffBaseSize].sallary.bonusSumm;
	cout << "Enter department ID:";
	cin >> allStaff[staffBaseSize].departmentID;
	cout << "Enter work ID:";
	cin >> allStaff[staffBaseSize].specID;
	cout << "Enter work phone number:";
	cin >> allStaff[staffBaseSize].staffContacts.workPhone;
	cout << "Enter cell phone number:";
	cin >> allStaff[staffBaseSize].staffContacts.cellPhone;
	cout << "Enter e-mail address:";
	cin >> allStaff[staffBaseSize].staffContacts.eMail;
	cout << "You have done. Thank you. Press enter"<<endl;
	system("PAUSE");

}


void addWork(work *workBase, int workBaseSize) {
	int control;
workAdd:	
system("CLS");
	cout << "--------------STAFF DATABASE MENU--------------" << endl;
	cout << "	-----------------NEW WORK ADD------------------" << endl;
	cout << "	Enter work ID: ";
	cin >> control;
	if (isWork(workBase, workBaseSize, control))
	{
		cout << "Work ID is already exist. Try again." << endl;
		system("PAUSE");
		goto workAdd;
	}
	else {
		workBase[workBaseSize].workID = control;
		cout << "	Enter work Name: ";
		cin >> workBase[workBaseSize].workName;
	}
}

void addDepartment(partition *departmentBase, int departmentBaseSize) {
	int control;
departmentAdd:
	system("CLS");
	cout << "--------------STAFF DATABASE MENU--------------" << endl;
	cout << "	--------------NEW DEPARTMENT ADD-----------------" << endl;
	cout << "	Enter department ID: ";
	cin >> control;
	if (isDepartment(departmentBase, departmentBaseSize, control))
	{
		cout << "Department ID is already exist. Try again." << endl;
		system("PAUSE");
		goto departmentAdd;
	}
	else {
		departmentBase[departmentBaseSize].unitID = control;
		cout << "	Enter department Name: ";
		cin >> departmentBase[departmentBaseSize].unitName;
	}
}

staff* deleteEmployee(staff *allStaff, int staffBaseSize) {
	int idToDelete;
emplDel:
	system("CLS");
	cout << "Enter Employee ID to delete Employee: ";
	cin >> idToDelete;
	if (isEmployee(allStaff, staffBaseSize, idToDelete)) {
		staff *temp = new staff[staffBaseSize - 1];
		for (int i = 0, j = 0; j < staffBaseSize; i++, j++)
		{
			if (allStaff[j].employeeID != idToDelete) {
				temp[i] = allStaff[j];
			}
			else {
				i--;
			}
		}
		delete[] allStaff;
		return temp;
	}
	else
	{
		cout << "Employee ID does not exist. Try again." << endl;
		system("PAUSE");
		goto emplDel;
	}
}

void changeDeparmentWork(staff *allStaff, int staffBaseSize, partition *departmentBase,\
	int departmentBaseSize, work *workBase, int workBaseSize) {
	int tempStaffID;
	int tempWorkID;
	int tempDepID;
staffID:
	system("CLS");
	cout << "Enter employee ID to change deparment and work: ";
	cin >> tempStaffID;
	if (isEmployee(allStaff, staffBaseSize, tempStaffID)) {
	DepID:
		cout << "Enter employees new department ID:";
		cin >> tempDepID;
		if (isDepartment(departmentBase, departmentBaseSize, tempDepID))
		{
		workID:
			cout << "Enter employees new work ID:";
			cin >> tempWorkID;
			if (isWork(workBase, workBaseSize, tempWorkID)) {
				for (int i = 0; i < staffBaseSize; i++)
				{
					if (allStaff[i].employeeID == tempStaffID) {
						allStaff[i].departmentID = tempDepID;
						allStaff[i].specID = tempWorkID;
					}
				}
			}
			else
			{
				cout << "Work ID does not exist. Try again." << endl;
				system("PAUSE");
				goto workID;
			}

		}
		else
		{
			cout << "Department ID does not exist. Try again." << endl;
			system("PAUSE");
			goto DepID;
		}
	}
	else
	{
		cout << "Staff ID does not exist. Try again." << endl;
		system("PAUSE");
		goto staffID;
	}
}

staff *setBase(staff *allStaff, int &staffBaseSize) {
	staff *newStaffBase = new staff[DATABASE_SIZE];
setStaffBase:
	cout << "Enter size of base you want to create: ";
	cin >> staffBaseSize;
	if (staffBaseSize > 0 && staffBaseSize <= DATABASE_SIZE) {
		for (size_t i = 0; i < staffBaseSize; i++)
		{
			addEmployee(newStaffBase, i);
		}
	}
	else {
		cout << "Wrong size. Try again." << endl;
		goto setStaffBase;
	}
	delete[] allStaff;
	return newStaffBase;
	}