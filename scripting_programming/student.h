//
//  student.h
//  scripting_programming
//

#ifndef student_h
#define student_h

#include <iostream>
#include <string>
#include "degree.h"


class Student {
private:
    std::string id;
    std::string fName;
    std::string lName;
    std::string email;
    int age;
    int days[3];
    DegreeProgram degree;
    
public:
    // Constructor
    Student();
    
    // Destructor
    ~Student();
    
    // Accessors
    std::string getStudentId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    int getAge() const;
    std::array<int, 3> getNumDays() const;
    DegreeProgram getDegreeProgram() const;
    
    // Mutators
    void setStudentId(std::string studentId);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string emailAddress);
    void setAge(int studentAge);
    void setNumDays(int day1, int day2, int day3);
    void setDegree(DegreeProgram degreeProgram);
    
    // Print student data
    std::string printNumDays ();
    std::string printDegreeProgram ();
    void print();

};

#endif /* student_h */
