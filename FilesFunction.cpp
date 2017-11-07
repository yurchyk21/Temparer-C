#include "Header.h"

//------------------FILL IN BASES FROM FILES-----------
user *setUserFromFile(int &userBaseSize) {
	user *temp = new user[DATABASE_SIZE];
	FILE *userFile = fopen("users.txt","r");
	char *buffer = new char[STRING_LONG];
	char *element;
	while (!feof(userFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, userFile);
		
		element = strtok(buffer, ":");
		for (int i = 1; i <= 3; i++)
		{
			if (i == 1)
			temp[userBaseSize].employeeID = atoi(element);
			if (i == 2)
				strcpy(temp[userBaseSize].userPass,element);
			if (i == 3)
				temp[userBaseSize].rights = ((atoi(element)==1)? Accountant : ((atoi(element) == 2)? HR : Worker));
			element = strtok(NULL, ":");
		}
		userBaseSize++;
	}
	delete[] buffer;
	fclose(userFile);
	return temp;
}

partition *setDepartmentsFromFile(int &departmentBaseSize) {
	partition *temp = new partition[DATABASE_SIZE];
	FILE *departmentsFile = fopen("departments.txt", "r");
	char *buffer = new char[STRING_LONG];
	char *element;
	while (!feof(departmentsFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, departmentsFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 2; i++)
		{
			if (i == 1)
				temp[departmentBaseSize].unitID = atoi(element);
			if (i == 2)
				strcpy(temp[departmentBaseSize].unitName, element);
			element = strtok(NULL, ":");
		}
		departmentBaseSize++;
	}
	delete[] buffer;
	fclose(departmentsFile);
	return temp;
}
work *setWorksFromFile(int &workBaseSize) {
	work *temp = new work[DATABASE_SIZE];
	FILE *worksFile = fopen("works.txt", "r");
	char *buffer = new char[STRING_LONG];
	char *element;
	while (!feof(worksFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, worksFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 2; i++)
		{
			if (i == 1)
				temp[workBaseSize].workID = atoi(element);
			if (i == 2)
				strcpy(temp[workBaseSize].workName, element);
			element = strtok(NULL, ":");
		}
		workBaseSize++;
	}
	delete[] buffer;
	fclose(worksFile);
	return temp;
}


staff *setStaffFromFile(int &staffBaseSize) {
	staff *temp = new staff[DATABASE_SIZE];
	FILE *staffFile = fopen("employees.txt", "r");
	FILE *addressFile = fopen("addresses.txt", "r");
	FILE *sallaryFile = fopen("sallary.txt", "r");
	FILE *contactsFile = fopen("contacts.txt", "r");

	char *buffer = new char[STRING_LONG];
	char *element;
	int counter =0;	
	while (!feof(staffFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, staffFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 13; i++)
		{ 
			switch (i)
			{
			case 1:
				temp[staffBaseSize].employeeID = atoi(element);
				break;
			case 2:
				strcpy(temp[staffBaseSize].staffName.surname, element);
				break;
			case 3:
				strcpy(temp[staffBaseSize].staffName.name, element);
				break;
			case 4:
				strcpy(temp[staffBaseSize].staffName.fathersName, element);
				break;
			case 5:
				strcpy(temp[staffBaseSize].docs.passportSerial, element);
				break;
			case 6:
				strcpy(temp[staffBaseSize].docs.passportNumber, element);
				break;
			case 7:
				strcpy(temp[staffBaseSize].docs.taxCode, element);
				break;
			case 8:
				strcpy(temp[staffBaseSize].docs.pensionNumber, element);
				break;
			case 9:
				temp[staffBaseSize].sex = atoi(element);
				break;
			case 10:
				strcpy(temp[staffBaseSize].birthdayDate, element);
				break;
			case 11:
				strcpy(temp[staffBaseSize].startWorkDate, element);
				break;
			case 12:
				temp[staffBaseSize].departmentID = atoi(element);
				break;
			case 13:
				temp[staffBaseSize].specID = atoi(element);
				break;
			default:
				break;
			}
			element = strtok(NULL, ":");
		}
		staffBaseSize++;
	}

	counter = 0;
	while (!feof(addressFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, addressFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 7; i++)
		{
			switch (i)
			{
			case 1:
				break;
			case 2:
				strcpy(temp[counter].livingAddress.state, element);
				break;
			case 3:
				strcpy(temp[counter].livingAddress.region, element);
				break;
			case 4:
				strcpy(temp[counter].livingAddress.city, element);
				break;
			case 5:
				strcpy(temp[counter].livingAddress.street, element);
				break;
			case 6:
				temp[counter].livingAddress.houseNumber = atoi(element);
				break;
			case 7:
				temp[counter].livingAddress.flatNumber = atoi(element);
				break;
			default:
				break;

			}
			element = strtok(NULL, ":");
		}
			counter++;
	}
	counter = 0;
	while (!feof(sallaryFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, sallaryFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 4; i++)
		{
			switch (i)
			{
			case 1:
				break;
			case 2:
				temp[counter].sallary.sallarySumm = atoi(element);
				break;
			case 3:
				temp[counter].sallary.premiumPercent = atoi(element);
				break;
			case 4:
				temp[counter].sallary.bonusSumm = atoi(element);
				break;
			default:
				break;

			}
			element = strtok(NULL, ":");
		}
		counter++;

	}

	counter = 0;
	while (!feof(contactsFile))
	{
		strcpy(buffer, "");
		fgets(buffer, STRING_LONG, contactsFile);
		element = strtok(buffer, ":");
		for (int i = 1; i <= 4; i++)
		{
			switch (i)
			{
			case 1:
				break;
			case 2:
				strcpy(temp[counter].staffContacts.workPhone, element);
				break;
			case 3:
				strcpy(temp[counter].staffContacts.cellPhone, element);
				break;
			case 4:
				strcpy(temp[counter].staffContacts.eMail, element);
				break;
			default:
				break;

			}
			element = strtok(NULL, ":");
		}
		counter++;

	}

	delete[] buffer;

	fclose(staffFile);
	fclose(addressFile);
	fclose(sallaryFile);
	fclose(contactsFile);
	return temp;
}
//------------------FILL IN FILES FROM BASES-----------------

void fillInUserFile(user *userBase, int userBaseSize) {
	FILE * fileUser = fopen("users.txt", "w");
	char *buffer = new char[STRING_LONG];
	for (int i = 0; i < userBaseSize; i++)
	{
		fputs(itoa(userBase[i].employeeID, buffer, RADIX10), fileUser);
		fputs(":", fileUser);
		fputs(userBase[i].userPass, fileUser);
		fputs(":", fileUser);
		fputs(itoa(userBase[i].rights, buffer, RADIX10), fileUser);
		if(i!= (userBaseSize-1))
		fputs("\n", fileUser);
	}
	delete[] buffer;
	fclose(fileUser);
}

void fillInDepartmentsFile(partition *departmentBase, int departmentBaseSize) {
	FILE *fileDepartments = fopen("departments.txt", "w");
	char *buffer = new char[STRING_LONG];
	for (int i = 0; i < departmentBaseSize; i++)
	{
		fputs(itoa(departmentBase[i].unitID, buffer, RADIX10), fileDepartments);
		fputs(":", fileDepartments);
		fputs(departmentBase[i].unitName, fileDepartments);
		fputs(":", fileDepartments);
		if (i != (departmentBaseSize - 1))
		fputs("\n", fileDepartments);
	}
	delete[] buffer;
	fclose(fileDepartments);
}

void fillInWorksFile(work *workBase, int workBaseSize) {
	FILE *fileWorks = fopen("works.txt", "w");
	char *buffer = new char[STRING_LONG];
	for (int i = 0; i < workBaseSize; i++)
	{
		fputs(itoa(workBase[i].workID, buffer, RADIX10), fileWorks);
		fputs(":", fileWorks);
		fputs(workBase[i].workName, fileWorks);
		fputs(":", fileWorks);
		if (i != (workBaseSize - 1))
		fputs("\n", fileWorks);
	}
	delete[] buffer;
	fclose(fileWorks);
}


void fillInStaffFile(staff *staffBase,int staffBaseSize) {
	FILE *fileStaff = fopen("employees.txt", "w");
	FILE *fileAddress = fopen("addresses.txt", "w");
	FILE *fileSallary = fopen("sallary.txt", "w");
	FILE *fileContacts = fopen("contacts.txt", "w");

	char *buffer = new char[STRING_LONG];
	int counter = 0;
	for (int i = 0; i < staffBaseSize; i++)
	{
		fputs(itoa(staffBase[i].employeeID, buffer, RADIX10), fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].staffName.surname, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].staffName.name, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].staffName.fathersName, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].docs.passportSerial, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].docs.passportNumber, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].docs.taxCode, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].docs.pensionNumber, fileStaff);
		fputs(":", fileStaff);
		fputs(itoa((int(staffBase[i].sex)), buffer, RADIX10), fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].birthdayDate, fileStaff);
		fputs(":", fileStaff);
		fputs(staffBase[i].startWorkDate, fileStaff);
		fputs(":", fileStaff);
		fputs(itoa(staffBase[i].departmentID, buffer, RADIX10), fileStaff);
		fputs(":", fileStaff);
		fputs(itoa(staffBase[i].specID, buffer, RADIX10), fileStaff);
		fputs(":", fileStaff);
		if (i != (staffBaseSize - 1))
		fputs("\n", fileStaff);


		fputs(staffBase[i].docs.taxCode, fileAddress);
		fputs(":", fileAddress);
		fputs(staffBase[i].livingAddress.state, fileAddress);
		fputs(":", fileAddress);
		fputs(staffBase[i].livingAddress.region, fileAddress);
		fputs(":", fileAddress);
		fputs(staffBase[i].livingAddress.city, fileAddress);
		fputs(":", fileAddress);
		fputs(staffBase[i].livingAddress.street, fileAddress);
		fputs(":", fileAddress);
		fputs(itoa(staffBase[i].livingAddress.houseNumber, buffer, RADIX10), fileAddress);
		fputs(":", fileAddress);
		fputs(itoa(staffBase[i].livingAddress.flatNumber, buffer, RADIX10), fileAddress);
		fputs(":", fileAddress);
		if (i != (staffBaseSize - 1))
		fputs("\n", fileAddress);

		fputs(itoa(staffBase[i].employeeID, buffer, RADIX10), fileSallary);
		fputs(":", fileSallary);
		fputs(itoa(staffBase[i].sallary.sallarySumm, buffer, RADIX10), fileSallary);
		fputs(":", fileSallary);
		fputs(itoa(staffBase[i].sallary.premiumPercent, buffer, RADIX10), fileSallary);
		fputs(":", fileSallary);
		fputs(itoa(staffBase[i].sallary.bonusSumm, buffer, RADIX10), fileSallary);
		fputs(":", fileSallary);
		if (i != (staffBaseSize - 1))
		fputs("\n", fileSallary);

		fputs(itoa(staffBase[i].employeeID, buffer, RADIX10), fileContacts);
		fputs(":", fileContacts);
		fputs(staffBase[i].staffContacts.workPhone, fileContacts);
		fputs(":", fileContacts);
		fputs(staffBase[i].staffContacts.cellPhone, fileContacts);
		fputs(":", fileContacts);
		fputs(staffBase[i].staffContacts.eMail, fileContacts);
		fputs(":", fileContacts);
		if (i != (staffBaseSize - 1))
		fputs("\n", fileContacts);
	}

	delete[] buffer;

	fclose(fileStaff);
	fclose(fileAddress);
	fclose(fileSallary);
	fclose(fileContacts);
}
