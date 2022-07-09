#include <iostream>
#include "Department.h"

using namespace std;

Department::Department() {

}

Department::Department(string name, int numWorkers) {
    departmentName = name;
    totalWorkers = numWorkers;
}

void Department::setDepartmentName(string name) {
    departmentName = name;
}

string Department::getDepartmentName() {
    return departmentName;
}

void Department::setTotalWorkers(int numWorkers) {
    totalWorkers = numWorkers;
}

int Department::getTotalWorkers() {
    return totalWorkers;
}

void Department::setDepartmentYears(int departmentYears) {
    years = departmentYears;
}

int Department::getDepartmentYears() {
    return (2022 - years);
}

void Department::showDepartmentData() {
    cout << "Total number of employees: " << getTotalWorkers() << "\n\n";
}
