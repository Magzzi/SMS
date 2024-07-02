#include "student.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <stdexcept> // for invalid_argument

using namespace std;




bool Student::setName(const string& n) {
    // Check if the provided name is empty
    if (n.empty()) {
        cout << "Invalid. Student name cannot be empty." << endl;
        return false;
    }
    
    // Check if the name already exists
    for (const auto& existingName : studentNames) {
        if (n == existingName) {
            cout << "Invalid. Student name already exists." << endl;
            return false;
        }
    }
    
    // Set the name and add it to the list of names
    //name = n;
    studentNames.push_back(n);
    
    return true;
}


void Student::setID(){
	
	random_device rd;  // Seed
    mt19937 gen(rd()); // Standard mersenne_twister_engine
    uniform_int_distribution<> dis(10000, 99999);

    int year;
    // Get the current year
    {
        auto now = chrono::system_clock::now();
        auto in_time_t = chrono::system_clock::to_time_t(now);
        tm* tm = localtime(&in_time_t);
        year = 1900 + tm->tm_year;
    }

    int newID;
    do {
        int random_number = dis(gen);
        newID = stoi(to_string(year) + to_string(random_number));
    } while (find(idNUMBERS.begin(), idNUMBERS.end(), newID) != idNUMBERS.end());

    this->idNum = newID;
    idNUMBERS.push_back(newID);
    
    
}

bool Student::setDepartment(const std::string& d) {
    if (d.empty()) {
        std::cout << "Invalid. Department name cannot be empty." << std::endl;
        return false;
    }

    // Search for dep in the departments vector
    auto it = std::find(departments.begin(), departments.end(), d);
    if (it != departments.end()) {
        // Department found, set it
        //this->department = d;
        return true;
    } else {
        // Department not found
        //std::cout << "Department '" << d << "' not found. Cannot proceed." << std::endl;
        return false;
    }
    

}


Student::Student(const std::string& n, const std::string& d){
    if (!setName(n)) {
        throw std::invalid_argument("Failed to create student. Invalid name.");
    }
    
    if (!setDepartment(d)) {
        throw std::invalid_argument("Failed to create student. Invalid department.");
    }
    
    setID();
    name = n;
    department = d;
}

Student::~Student(){
	
}

int Student::getID() const {
    return idNum;
}

string Student::getName() const {
    return name;
}

string Student::getDepartment() const {
    return department;
}

void Student::displayDetails() const {
    cout << "||||| STUDENT INFORMATION |||||" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << idNum << endl;
    cout << "Department: " << department << endl;
}
