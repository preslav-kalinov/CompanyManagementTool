#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee {
    private:
        std::string firstName;
        std::string lastName;
        std::string ucn;
        int workExperience;
        int projectParticipation;
        int workingHoursPerDay;
    public:
        Employee();
        Employee(std::string fName, std::string lName, std::string employeeUCN, int projects, int experience, int workHours);
        void setFirstName(std::string fName);
        void setLastName(std::string lName);
        std::string getName();
        void setUCN(std::string emplUCN);
        std::string getUCN();
        void setWorkExperience(int experience);
        int getWorkExperience();
        void setWorkingHoursPerDay(int workHours);
        int getWorkingHourPerDay();
        void setProjectsParticipation(int projects);
        int getProjectsParticipation();
        void showEmployeeData();
};

#endif
