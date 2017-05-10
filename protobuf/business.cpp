/*
MIT LICENSE (C) 2012 Filip Stoklas, FipS
http://forums.4fips.com/viewtopic.php?f=3&t=807
*/

#include <iostream>
#include <fstream>
#include "out/business.pb.h"

using namespace std;

/// Saves a demo company object to 'company.bin'.
void save() {
    business::Company company;
    company.set_name("Example Ltd.");
    company.set_url("http://www.example.com");

    // 1st employee
    {
        business::Employee *employee = company.add_employee();
        employee->set_first_name("John");
        employee->set_last_name("Doe");
        employee->set_email("john.doe@example.com");
    }

    // 2nd employee
    {
        business::Employee *employee = company.add_employee();
        employee->set_first_name("Jane");
        employee->set_last_name("Roe");
        employee->set_email("jane.roe@example.com");
    }

    fstream output("company.bin", ios::out | ios::trunc | ios::binary);
    company.SerializeToOstream(&output);
}

/// Loads a demo company object from 'company.bin' and dumps its data.
void load() {
    business::Company company;
    fstream input("company.bin", ios::in | ios::binary);

    company.ParseFromIstream(&input);
    cout << "Company: " << company.name() << "\n";
    cout << "URL: " << (company.has_url() ? company.url() : "N/A") << "\n";

    cout << "\nEmployees: \n\n";
    for(int i = 0, n = company.employee_size(); i < n; ++i) {
        const business::Employee &employee = company.employee(i);
        cout << "First name: " << employee.first_name() << "\n";
        cout << "Last name: " << employee.last_name() << "\n";
        cout << "Email: " << employee.email() << "\n";
        cout << "\n";
    }
}

int main() {
    save();
    load();
    return 0;
}

// output:
// Company: Example Ltd.
// URL: http://www.example.com
//
// Employees:
//
// First name: John
// Last name: Doe
// Email: john.doe@example.com

// First name: Jane
// Last name: Roe
// Email: jane.roe@example.com

