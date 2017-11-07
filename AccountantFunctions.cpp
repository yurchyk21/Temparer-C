#include "Header.h"

void accountantMenu(staff *allStaff, int staffBaseSize, work *workBase, int workBaseSize, partition *departmentBase, int departmentBaseSize) {
	int menu = 1;
	while (menu)
	{
		system("CLS");
		cout << "--------------STAFF DATABASE MENU (accountant)-------------" << endl;
		cout << "Press:" << endl;
		cout << "1. To display all database." << endl;
		cout << "2. To find employee." << endl;
		cout << "3. To sort employees by department ID." << endl;
		cout << "4. To sort employees by work ID." << endl;
		cout << "5. To display Report: staff of department + quantity." << endl;
		cout << "6. To show wages-fund by department." << endl;
		cout << "7. To show Report: Staff list by departments with department and firm sallary" << endl;
		cout << "8. To find employee's phone number by surname." << endl;
		cout << "9. To show phone database." << endl;
		cout << "10. To display works list." << endl;
		cout << "11. To display departments list." << endl;
		cout << "0. To exit." << endl;
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
			departmentFund(allStaff, staffBaseSize, departmentBase, departmentBaseSize);
			break;
		case 7:
			sallaryReport(allStaff, staffBaseSize, departmentBase, departmentBaseSize);
			break;
		case 8:
			findEmployeePhone(allStaff, staffBaseSize);
			break;
		case 9:
			displayPhoneBase(allStaff, staffBaseSize);
			break;
		case 10:
			displayWorkList(workBase, workBaseSize);
			break;
		case 11:
			displayDepartmentList(departmentBase, departmentBaseSize);
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

void departmentFund (staff *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize) {

	unsigned int depSallary;
	unsigned int depPremium;
	unsigned int depBonus;

	unsigned int firmSallary=0;
	unsigned int firmPremium=0;
	unsigned int firmBonus=0;
	system("CLS");
	cout << "--------------------------------DEPARTMENTS SALLARY----------------------------" << endl;
	cout << "|Departm. ID|  Department name    | Sallary  |  Premium |  Bonuses | Summary  |" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < departmentBaseSize; i++)
	{
		
		depSallary = 0;
		depPremium = 0;
		depBonus = 0;
		for (int j = 0; j < staffBaseSize; j++)
		{
			if (allStaff[j].departmentID==departmentBase[i].unitID)
			{
				depSallary += allStaff[j].sallary.sallarySumm;
				depPremium += (allStaff[j].sallary.sallarySumm*allStaff[j].sallary.premiumPercent / 100);
				depBonus += allStaff[j].sallary.bonusSumm;
			}
		}
		firmSallary += depSallary;
		firmPremium += depPremium;
		firmBonus += depBonus;
		cout << "|" << setw(DATE_SIZE) << departmentBase[i].unitID << "|" << setw(NAME_SIZE+1) << departmentBase[i].unitName << "|"\
			<< setw(DATE_SIZE-1) << depSallary <<  "|" << setw(DATE_SIZE-1) << depPremium<<"|" << \
			setw(DATE_SIZE-1) << depBonus << "|" << setw(DATE_SIZE-1) << (depSallary + depPremium + depBonus) << "|" << endl;
	}

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|            SUMMARY            |" << setw(DATE_SIZE) << firmSallary << "|" << setw(DATE_SIZE) \
		<< firmPremium << "|" << setw(DATE_SIZE) << firmBonus << "|" << setw(9) << (firmSallary + firmPremium + firmBonus) << "|" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	system("PAUSE");
}

void sallaryReport(staff *allStaff, int staffBaseSize, partition *departmentBase, int departmentBaseSize) {
	
	unsigned int depSallary;
	unsigned int depPremium;
	unsigned int depBonus;

	unsigned int firmSallary = 0;
	unsigned int firmPremium = 0;
	unsigned int firmBonus = 0;
	
	cout << "--------------------DEPARTMENTS STAFF LIST + SALLARY REPORT--------------------" << endl;
	cout << "|   Staff ID   |     First Name     |    Fathers Name    |     Second Name    |" << endl;
	
	for (int i = 0; i < departmentBaseSize; i++)
	{
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(DATE_SIZE) << departmentBase[i].unitID<<" : "<< setw(DATE_SIZE) << departmentBase[i].unitName <<  endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	
		depSallary = 0;
		depPremium = 0;
		depBonus = 0;

		for (int j = 0; j < staffBaseSize; j++)
		{
			if (departmentBase[i].unitID== allStaff[j].departmentID) {
				cout << "|" << setw(14) << allStaff[j].employeeID << "|" << setw(NAME_SIZE) << allStaff[j].staffName.name << "|" << setw(NAME_SIZE) << allStaff[j].staffName.fathersName << "|" << setw(NAME_SIZE) << allStaff[j].staffName.surname<<"|" << endl;
				depSallary += allStaff[j].sallary.sallarySumm;
				depPremium += (allStaff[j].sallary.sallarySumm*allStaff[j].sallary.premiumPercent / 100);
				depBonus += allStaff[j].sallary.bonusSumm;
			}
		}
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "|"<<  setw(DATE_SIZE) << departmentBase[i].unitName <<"Sallary:" << setw(9) << depSallary << " | Premium: " << setw(9) << depPremium << " | Bonuses: " << setw(9) << depBonus<< "|" << endl;
		cout << "| TOTAL DEPARTMENT SALLARY: " << setw(DATE_SIZE) << depSallary + depPremium + depBonus << "|" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;

		firmSallary += depSallary;
		firmPremium += depPremium;
		firmBonus += depBonus;
	}
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "| FIRM Sallary :  " << setw(DATE_SIZE) << firmSallary << " |  Premium: " << setw(DATE_SIZE) << firmPremium << " |  Bonuses: " << setw(DATE_SIZE) << firmBonus << "  |" << endl;
	cout << "| TOTAL  FIRM  SALLARY: " << setw(DATE_SIZE) << firmSallary + firmPremium + firmBonus << "|" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	system("PAUSE");
}