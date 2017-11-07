#include "Header.h"
void workerMenu(staff *allStaff, int staffBaseSize) {
	int menu = 1;
	while (menu)
	{
		system("CLS");
		cout << "--------------STAFF DATABASE MENU--------------" << endl;
		cout << "Press:" << endl;
		cout << "1. To find employee's phone number by surname." << endl;
		cout << "2. To show phone database." << endl;
		cout << "0. To exit." << endl;
		cout << "Do your choise: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			findEmployeePhone(allStaff, staffBaseSize);
			break;
		case 2:
			displayPhoneBase(allStaff, staffBaseSize);
			break;
		case 0:
			system("CLS");
			cout << "Good bye." << endl;
			return;
			break;
		default:
			cout << "Wrong choise. To try again press enter.";
			system("PAUSE");
		}
	}
}
