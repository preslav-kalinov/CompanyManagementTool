#include <string>
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department {
    private:
        std::string departmentName;
        int years;
        int totalWorkers;
    public:
        Department();
        Department(std::string name, int numWorkers);
        void setDepartmentName(std::string name);
        std::string getDepartmentName();
        void setTotalWorkers(int numWorkers);
        int getTotalWorkers();
        void setDepartmentYears(int departmentYears);
        int getDepartmentYears();
        void showDepartmentData();
        ~Department();
};

#endif
