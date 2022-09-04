#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee() {

}

Employee::Employee(string fName, string lName, string employeeUCN, int projects, int experience, int workHours) {
    firstName = fName;
    lastName = lName;
    ucn = employeeUCN;
    workExperience = experience;
    projectParticipation = projects;
    workingHoursPerDay = workHours;
}

void Employee::setFirstName(string fName) {
    firstName = fName;
}

void Employee::setLastName(string lName) {
    lastName = lName;
}

string Employee::getName() {
    return firstName + " " + lastName;
}

void Employee::setUCN(string emplUCN) {
    ucn = emplUCN;
}

string Employee::getUCN() {
    return ucn;
}

void Employee::setWorkExperience(int experience) {
    workExperience = experience;
}

int Employee::getWorkExperience() {
    return workExperience;
}

void Employee::setWorkingHoursPerDay(int workHours) {
    workingHoursPerDay = workHours;
}

int Employee::getWorkingHourPerDay() {
    return workingHoursPerDay;
}

void Employee::setProjectsParticipation(int projects) {
    projectParticipation = projects;
}

int Employee::getProjectsParticipation() {
    return projectParticipation;
}

void Employee::showEmployeeData() {
    cout << "Employee's name: " << getName();
    cout << "\nEmployee's UCN: " << getUCN();
    cout << "\nEmployee's work experience: " << getWorkExperience() << " years\n";
    cout << "\nEmployee's working hours per day: " << getWorkingHourPerDay() << "\n";
    cout << "\nEmployee's projects involvement: " << getProjectsParticipation() << "\n\n";
}
