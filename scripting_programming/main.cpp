//
//  main.cpp
//  scripting_programming
//

#include <iostream>
#include <vector>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;


// Print project heading
void projectHeading() {
    cout << "<Student Name>" << endl;
    cout << "Student ID: <Student ID>" << endl;
    cout << "Scripting & Programming - Applications - C867" << endl;
    cout << "Language Used: C++" << endl;
    cout << endl;
}

int main(int argc, const char * argv[]) {
        
    projectHeading();
    
    std::vector<std::string> studentData = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Paolo,Sidera,paolosidera@gmail.com,43,10,20,30,SOFTWARE"};
    
    // Instantiate a Roster object
    Roster classRoster(studentData);
    
    // Print the entire student roster
    classRoster.printAll();
    cout << endl;
    
    // Print all the invalid emails
    classRoster.printInvalidEmails();
    cout << endl;
    
    for (Student student : classRoster) {
        classRoster.printAverageDaysInCourse(student.getStudentId());
    }
    cout << endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;
    
    classRoster.remove("A3");
    
    return 0;
}
