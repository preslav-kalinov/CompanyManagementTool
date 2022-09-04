#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Company.h"
#include "Department.h"
#include "Employee.h"

using namespace std;

void printMenuHeader() {
	cout << "***************************************************************" << endl;
	cout << "*                      CompanyManagement                      *" << endl;
	cout << "***************************************************************" << endl;
	cout << endl;
}

void printActions() {
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "|                      Available Actions                      |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "| Action # |                   Description                    |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << "|    0     | Exit                                             |" << endl;
	cout << "|    1     | Enter a new company's data                       |" << endl;
	cout << "|    2     | Enter departments data                           |" << endl;
	cout << "|    3     | Enter employees data                             |" << endl;
	cout << "|    4     | Read departments data                            |" << endl;
	cout << "|    5     | Read employees data                              |" << endl;
	cout << "|    6     | Read all data from file                          |" << endl;
	cout << "+-------------------------------------------------------------+" << endl;
	cout << endl;
}

string toUpper(string strToConvert);
void addCompany(Company company, fstream &file);
void addDepartment(Department department[], int numberOfDepartments, int counter, fstream &file);
void addEmployee(Employee employee[][10], Department department[], int numberOfDepartments, fstream &file);
void showDepartmentData(Department department[], int departmentsCounter);
void showEmployeesData(Employee employee[][10], Department department[], int employeesCount, int numberOfDepartments);
void showAllData(fstream &file);

int main(int argc, char* argv[]) {
	Company company;
	Department department[10];
	Employee employee[10][10];
	int command;
	int companyCount = 0;
	int numberOfDepartments = 0;
	int employeesCount = 0;
	fstream contentFile;
	contentFile.open("company_management.txt", ios::out);

	if (!contentFile) {
		cout << "File does not exist.\n";
		exit(1);
	}

	printMenuHeader();

	while (true) {
		printActions();
		cout << "Choose an action (0-6): ";
		cin >> command;

		if (command < 0 || command > 7) {
			cout << "Invalid action number." << endl << endl;
			continue;
		}
		cout << endl;

		switch (command) {
			case 0:
				exit(0);
			case 1:
				addCompany(company, contentFile);
				companyCount++;
				break;
            case 2:
                cout << "Number of departments:\n(Note: Maximum departments could be 10.)\n";
                cin >> numberOfDepartments;
                addDepartment(department, numberOfDepartments, companyCount, contentFile);
                break;
            case 3:
                addEmployee(employee, department, numberOfDepartments, contentFile);
                employeesCount++;
                break;
            case 4:
                showDepartmentData(department, numberOfDepartments);
                break;
            case 5:
                showEmployeesData(employee, department, employeesCount, numberOfDepartments);
                break;
            case 6:
                showAllData(contentFile);
                break;
		}
	}
}

string toUpper(string strToConvert) {
	transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

void addCompany(Company company, fstream &file) {
	string companyName;
	string strToUpper;
	string companyType;
	string registeredVat;

	cout << "Enter company's name:\n";
	cin.ignore();
	getline(cin, companyName);
	company.setCompanyName(companyName);
	cout << company; //call the predefined <<
	cout << "\n";
	file << "Company:" << endl << "Name: " << companyName << endl;

	cout << "Enter type of company(ET/OOD/AD/EOOD):\n";
	cin >> companyType;

	strToUpper = toUpper(companyType);
	cout << strToUpper << "\n";

	if (strToUpper == "ET" || strToUpper == "OOD" || strToUpper == "AD" || strToUpper == "EOOD") {
		company.setCompanyType(strToUpper);
		file << "Type: " << strToUpper << endl;
	}
	else {
		cout << "Invalid company type!" << "\n";
		exit(1);
	}

	cout << "Is company registered with VAT yes or no:\n";
	cin >> registeredVat;
	strToUpper = toUpper(registeredVat);

	if (strToUpper == "YES") {
		cout << "Company is registered with VAT.\n\n";
		company.setIsVatRegistered(true);
		file << "Registered with VAT: " << strToUpper << endl << endl;
	} else if (strToUpper == "NO") {
		cout << "Company is not registered under VAT.\n\n";
		company.setIsVatRegistered(false);
		file << "Registered with VAT: " << strToUpper << endl << endl;
	}
	else {
		cout << "Invalid input!" << "\n";
		exit(1);
	}
}

void addDepartment(Department department[], int numberOfDepartments, int counter, fstream &file) {
    int departmentYears;
    int employeesNumber;
    string departmentName;

    if (counter == 0) {
        cout << "There is no company data detected! Department without company cannot exist!\n\n";
        return;
    }

    if (numberOfDepartments <= 0) {
        cout << "No departments will be recorded in this company.\n\n\n";
        file << "Company has no departments." << endl;
        return;
    }

    if (numberOfDepartments > 10) {
        cout << "Invalid data! Number of departments cannot exceed 10." << "\n";
        exit(1);
    }

    if (numberOfDepartments <= 10) {
        for (int i = 0; i < numberOfDepartments; i++) {

            cout << "Enter department name:\n";
            cin.ignore();
            getline(cin, departmentName);
            department[i].setDepartmentName(departmentName);
            file << "Department: " << endl << "Name: " << departmentName << endl;

            cout << "Enter number of workers in that department\n(Note: You can input max 10 workers.):\n";
            cin >> employeesNumber;

            if (employeesNumber <= 0) {
                cout << "No workers will be recorded in this company.\n\n\n";
                file << "Company has no workers." << endl;
                break;
            }

            if (employeesNumber < 11 && employeesNumber > 0) {
                department[i].setTotalWorkers(employeesNumber);
                file << "Number of workers: " << employeesNumber << endl;
            }
            else {
                do {
                    cout << "Please enter a valid data next try.\n";
                    cin >> employeesNumber;
                } while (employeesNumber > 10 || employeesNumber < 0);
            }

            cout << "Enter year of establishment:\n";
            cin >> departmentYears;
            department[i].setDepartmentYears(departmentYears);
            file << "Period since establishment: " << department[i].getDepartmentYears() << " years." << endl << endl;
        }
    }
}

void addEmployee(Employee employee[][10], Department department[], int numberOfDepartments, fstream &file) {
    string firstName;
    string lastName;
    string ucn;
    int employeesTotalNumber;
    int workExperience;
    int workingHoursPerDay;
    int projectParticipation;

    if (numberOfDepartments <= 0) {
        cout << "There no departments defined. Workers cannot be registered without a department!\n\n";
        file << "There are not any workers." << endl;
        return;
    }

    for (int i = 0; i < numberOfDepartments; i++) {
        employeesTotalNumber = department[i].getTotalWorkers();
        cout << "Total number of employees in department " << department[i].getDepartmentName() << " are: " << employeesTotalNumber << "\n\nRegister employees:\n";
        file << "Employees in department " << department[i].getDepartmentName() << ": " << endl;
        for (int j = 0; j < employeesTotalNumber; j++) {
            cout << "[Employee # " << j + 1 << "] " << "Enter first name: \n";
            cin >> firstName;
            cout << "[Employee # " << j + 1 << "] " << "Enter last name: \n";
            cin >> lastName;
            employee[i][j].setFirstName(firstName);
            employee[i][j].setLastName(lastName);
            file << "Employee #" << j + 1 << " :" << endl << "Name: " <<  employee[i][j].getName() << endl;

            cout << "[Employee # " << j + 1 << "] " << "Enter UCN: \n";
            cin >> ucn;
            employee[i][j].setUCN(ucn);
            file << "UCN: " <<  employee[i][j].getUCN() << endl;

            cout << "[Employee # " << j + 1 << "] " << "Enter experience(years): \n";
            cin >> workExperience;
            employee[i][j].setWorkExperience(workExperience);
            file << "Work experience: " <<  employee[i][j].getWorkExperience() << endl;

            cout << "[Employee # " << j + 1 << "] " << "Enter work hours per day by contract: \n";
            cin >> workingHoursPerDay;
            employee[i][j].setWorkingHoursPerDay(workingHoursPerDay);
            file << "Working hours per day: " <<  employee[i][j].getWorkingHourPerDay() << endl;

            cout << "[Employee # " << j + 1 << "] " << "Enter active projects: \n";
            cin >> projectParticipation;
            employee[i][j].setProjectsParticipation(projectParticipation);
            file << "Active projects: " <<  employee[i][j].getProjectsParticipation() << endl << endl;
        }
    }
}

void showDepartmentData(Department department[], int departmentsCounter) {
    if (departmentsCounter == 0) {
        cout << "There is no data for departments!\n\n";
        return;
    }

    for (int i = 0; i < departmentsCounter; i++) {
        cout << "The data for all " << department[i].getDepartmentName() << " departments is:\n";
        cout << "The department is " << department[i].getDepartmentYears() << " years old.\n";
        department[i].showDepartmentData();
    }
}

void showEmployeesData(Employee employee[][10], Department department[], int employeesCount, int numberOfDepartments) {
    int totalNumberEmployees;

    if (employeesCount == 0) {
        cout << "There are no registered employees!\n\n";
        return;
    }

    for (int i = 0; i < numberOfDepartments; i++) {
        totalNumberEmployees = department[i].getTotalWorkers();
        cout << "Number of workers in department " << department[i].getDepartmentName() << " are: " << totalNumberEmployees << "\n";
        cout << i + 1 << " WORKER: \n";
        for (int j = 0; j < totalNumberEmployees; j++) {
            employee[i][j].showEmployeeData();
        }
    }
}

void showAllData(fstream &file) {
    string line;

    if (file.is_open()) {
        file.close();
        cout << "File is closed for writing.\n";
    }

    cout << "All data from the company file:\n\n";
    file.open("company_management.txt", ios::in);

    if (!file) {
        cout << "File is not created correctly.\n";
        return;
    }

    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}
