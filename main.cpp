#include "Header.h"






int  main() {

	int userBaseSize = 0;
	int departmentBaseSize = 0;
	int workBaseSize = 0;
	int staffBaseSize = 0;
	
	user *userBase = setUserFromFile(userBaseSize);
	partition *departmentBase = setDepartmentsFromFile(departmentBaseSize);
	work *workBase = setWorksFromFile(workBaseSize);
	staff *staffBase = setStaffFromFile(staffBaseSize);

	user currentUser;
	login(currentUser, userBase);
	switch (currentUser.rights)
	{
	case NoRights:
		return -1;
		break;
	case Accountant:
		accountantMenu(staffBase,  staffBaseSize, workBase,  workBaseSize,  departmentBase,  departmentBaseSize);
		break;
	case HR:
		HRMenu(staffBase, staffBaseSize, workBase, workBaseSize, departmentBase, departmentBaseSize);
		break;
	case Worker:
		workerMenu(staffBase, staffBaseSize);
		break;
	default:
		break;
	}
	delete[] userBase;
	delete[] departmentBase;
	delete[] workBase;
	delete[] staffBase;
	return 0;
}
