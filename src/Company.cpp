#include <iostream>
#include <stdexcept>
#include "Company.h"

using namespace std;

Company::Company() {

}

Company::Company(string companyName, string companyType, bool isCompanyVatRegistered) {
	name = companyName;
	type = companyType;
	isVatRegistered = isCompanyVatRegistered;
}

void Company::setCompanyName(string compName) {
	name = compName;
}

string Company::getCompanyName() {
	return name;
}

void Company::setCompanyType(string compType) {
	type = compType;
}

string Company::getCompanyType() {
	return type;
}

void Company::setIsVatRegistered(bool isRegistered) {
	isVatRegistered = isRegistered;
}

bool Company::getIsVatRegistered() {
	return isVatRegistered;
}

ostream& operator << (std::ostream &stream, const Company &company) {
    stream << "Company name: " << company.name;
    return stream;
}

Company::~Company(){

}
