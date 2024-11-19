/*
Henry Xu
9/4/2024
C++
Student List
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>  
#include <cstring>
using namespace std;




struct Student {//create the class
    char firstName[50];
    char lastName[50];
    int studentID;
    float gpa;
};


void addS(vector<Student*> &studentslist);//prepare the functions
void printS(vector<Student*> &studentslist);
void deleteS(vector<Student*> &studentslist);




int main(){
    char command[50];
    vector<Student*> studentslist;//create the vector of pointers
    while(true){
        cout << "What command would you like to run?" << endl;//ask the user for the command they would like to run
        cin >> command;
	char add[50] = "add";
	char print[50] = "print";
	char delet[50] = "delete";
        char quit[50] = "quit";
        if (strcmp(command, add) == 0){//if they run the command add then run the function add
            addS(studentslist);
        }
        else if (strcmp(command, print) == 0){//if they run the command print then run the function print
            printS(studentslist);
        }
        else if (strcmp(command, delet) == 0){//if they run the command delete then run the function delete
            deleteS(studentslist);
        }
        else if (strcmp(command, quit) == 0){//if they run the command quit then delete all the students in the vector list
            for (auto it = studentslist.begin(); it != studentslist.end(); it++) {
                delete *it;
            }
            studentslist.clear();//clear the vector of pointers
            break;
        }
        else{
            cout << "Your input was not valid your options are: add, print, delete, quit.";//their command isn't valid
        }
    }
}


void addS(vector<Student*> &studentslist){//adding a new student function
    Student* newStudent = new Student;//create a new student
    cout << "What is the student's first name?:";//ask for their info
    cin >> newStudent->firstName;
    cout << "What is the student's last name?:";
    cin >> newStudent->lastName;
    cout << "What is the student's GPA?:";
    cin >> newStudent->gpa;
    cout << "What is the student's ID?:";
    cin >> newStudent->studentID;
    studentslist.push_back(newStudent);//add the student into the vector
}
void printS(vector<Student*> &studentslist){//function for printing students
    int count = 1;
    for(Student* currentstudent: studentslist){ //for each student
        float gpa = currentstudent->gpa;
        float roundedgpa = round(gpa*100)/100;//round their GPA and print out their basic info
        cout << "Student " << count << " "<< currentstudent->firstName << " " << currentstudent->lastName << endl;
        cout << "GPA:" << fixed << setprecision(2) << currentstudent->gpa << " Student ID:" << currentstudent->studentID << endl;
        count++;
    }
}
void deleteS(vector<Student*> &studentslist) {//function for deleting students
    int del;
    std::cout << "Which student would you like to delete? Print out their ID: ";
    std::cin >> del;//find their ID and save it.
    
    for (auto it = studentslist.begin(); it != studentslist.end(); it++) {//go through the list of students
        if ((*it)->studentID == del) {//when you find their id
            delete *it;//delete it from the heap
            studentslist.erase(it);//delete it from the vector
            cout << "Student# " << del << " has been deleted." << endl;
            return;
        }
    }
    cout << "This student doesn't exist" << endl;//if the id doesn't exist then print it out.
}

