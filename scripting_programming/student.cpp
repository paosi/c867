//
//  student.cpp
//  scripting_programming
//

#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;


// Constructor
Student::Student() {}

// Destructor
Student::~Student() {}

// Accessors
string Student::getStudentId() const {
    return id;
}
string Student::getFirstName() const {
    return fName;
}
string Student::getLastName() const {
    return lName;
}
string Student::getEmail() const {
    return email;
}
int Student::getAge() const {
    return age;
}
array<int, 3> Student::getNumDays() const {
    return {days[0], days[1], days[2]};
}
DegreeProgram Student::getDegreeProgram() const {
    return degree;
}

// Mutators
void Student::setStudentId(string studentId) {
    id = studentId;
}
void Student::setFirstName(string firstName) {
    fName = firstName;
}
void Student::setLastName(string lastName) {
    lName = lastName;
}
void Student::setEmail(string emailAddress) {
    email = emailAddress;
}
void Student::setAge(int studentAge) {
    age = studentAge;
}
void Student::setNumDays(int day1, int day2, int day3) {
    days[0] = day1;
    days[1] = day2;
    days[2] = day3;
}
void Student::setDegree(DegreeProgram degreeProgram) {
    degree = degreeProgram;
}

// Print functions
string Student::printNumDays() {
    return "{" + to_string(days[0]) + ", " + to_string(days[1]) + ", " + to_string(days[2]) + "}";
}
string Student::printDegreeProgram() {
    string tempDegree;
    if (degree == 0) {
        tempDegree = "Security";
    }
    else if (degree == 1) {
        tempDegree = "Network";
    }
    else if (degree == 2) {
        tempDegree = "Software";
    }
    else {
        tempDegree = "Invalid Degree";
    }
    return tempDegree;
}
void Student::print() {
    cout << getStudentId() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge() << "\tDays In Course: " << printNumDays() << "\tDegree Program: " << printDegreeProgram() << endl;
}


