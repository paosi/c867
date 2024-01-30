//
//  roster.cpp
//  scripting_programming
//

#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;


// Constructor
Roster::Roster(vector<string> studentData) {
    
    for (string student : studentData) {
        vector<string> studentInfo;
        size_t index = 0, end = 0;
        
        while ((end = student.find(",", index)) != string::npos) {
            studentInfo.push_back(student.substr(index, end - index));
            index = end + 1;
        }
        
        studentInfo.push_back(student.substr(index));
        string degree = studentInfo[8];
        DegreeProgram degreeProgram;
    
        if (degree == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (degree == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degree == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        else {
            cout << "Invalid Degree" << endl;
            break;
        }
           
        Student studentObj;
        studentObj.setStudentId(studentInfo.at(0));
        studentObj.setFirstName(studentInfo.at(1));
        studentObj.setLastName(studentInfo.at(2));
        studentObj.setEmail(studentInfo.at(3));
        studentObj.setAge(stoi(studentInfo.at(4)));
        studentObj.setNumDays(stoi(studentInfo.at(5)), stoi(studentInfo.at(6)), stoi(studentInfo.at(7)));
        studentObj.setDegree(degreeProgram);
        
        classRosterArray.push_back(studentObj);
    }
}

// Destructor
Roster::~Roster() {}

// Add student info to the roster
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
    
    Student studentObj;
    studentObj.setStudentId(studentId);
    studentObj.setFirstName(firstName);
    studentObj.setLastName(lastName);
    studentObj.setEmail(emailAddress);
    studentObj.setAge(age);
    studentObj.setNumDays(days1, days2, days3);
    studentObj.setDegree(degreeProgram);
    
    classRosterArray.push_back(studentObj);
}

// Remove student from the roster by student id
void Roster::remove (string studentId) {
    std::vector<Student> updatedRoster;
    bool hasId = false;
    
    for (Student student : classRosterArray) {
        if (studentId == student.getStudentId()) {
            hasId = true;
            break;
        }
    }
    
    for (Student student : classRosterArray) {
        if (studentId != student.getStudentId()) {
            updatedRoster.push_back(student);
        }
        else {
            cout << "Removed student at index: " << student.getStudentId() << endl;
        }
    }
    
    if (!hasId) {
        cout << "Student with ID " << studentId << " not found" << endl;
    }
    classRosterArray = updatedRoster;
}

// Output the entire class roster
void Roster::printAll() {
    for (Student student : classRosterArray) {
        student.print();
    }
}
    
// Output the average number of days a student spent on their courses
void Roster::printAverageDaysInCourse(string studentId) {
    
    int sum = 0;
    int avgDays = 0;
    
    for (Student student : classRosterArray) {
        array<int, 3> numDays = student.getNumDays();
        
        if (studentId == student.getStudentId()) {
            for (int day : student.getNumDays()) {
                sum += day;
            };
            avgDays = sum / numDays.size();
            cout << "Average number of days in course: " << avgDays << endl;
        }
    }
}

// Output all the invalid email addresses in the roster
void Roster::printInvalidEmails() {
    regex validEmail(R"([\w\.\-]+\@[\w\.\-]+\.[a-zA-Z]{2,})");
    for (Student student : classRosterArray) {
        if (!regex_match(student.getEmail(), validEmail)) {
            cout << "Invalid Email: " << student.getEmail() << endl;
        }
    }
}

// Print the student roster according to degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (Student student : classRosterArray) {
        if (degreeProgram == student.getDegreeProgram())
            student.print();
        };
}

