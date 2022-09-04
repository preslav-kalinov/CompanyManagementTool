#include <iostream>
#include <string>
#ifndef COMPANY_H
#define COMPANY_H

class Company {
    private:
        std::string name;
        std::string type;
        bool isVatRegistered;
    public:
        Company();
        Company(std::string companyName, std::string companyType, bool isCompanyVatRegistered);
        void setCompanyName(std::string name);
        std::string getCompanyName();
        void setCompanyType(std::string type);
        std::string getCompanyType();
        void setIsVatRegistered(bool isVatRegistered);
        bool getIsVatRegistered();
        friend std::ostream& operator << (std::ostream &stream, const Company &company);
};

#endif
