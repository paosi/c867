//
//  roster.h
//  scripting_programming
//

#ifndef roster_h
#define roster_h

#include <string>
#include "degree.h"
#include "student.h"


class Roster {    
public:
    std::vector<Student> classRosterArray;
    auto begin() const { return classRosterArray.begin(); }
    auto end() const { return classRosterArray.end(); }
        
    // Constructor
    Roster(std::vector<std::string> studentData);
    
    // Destructor
    ~Roster();
    
    // Class member functions
    void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentId);
    void printAll();
    void printAverageDaysInCourse(std::string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};


#endif /* roster_hpp */
