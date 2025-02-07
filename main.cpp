/*
Henry Xu
9/4/2024
C++
Student List
*/
//imports
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>  
#include <cstring>
#include "node.h"
#include "student.h"
#include "hashtables.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void addS(hashtables* table);//prepare the functions
void printS(hashtables* table);
void randomS(hashtables* table);
void deleteS(hashtables* table);


int main(){
    char command[50];
    hashtables* table = new hashtables(100);
    while(true){
        cout << "What command would you like to run?" << endl;//ask the user for the command they would like to run
    cin >> command;
	char add[50] = "add";
	char print[50] = "print";
	char delet[50] = "delete";
    char random[50] = "random";
    char quit[50] = "quit";
        if (strcmp(command, add) == 0){//if they run the command add then run the function add
            addS(table);
        }
        else if (strcmp(command, print) == 0){//if they run the command print then run the function print
            printS(table);
        }
        else if (strcmp(command, delet) == 0){//if they run the command delete then run the function delete
            deleteS(table);
        }
        else if (strcmp(command, random) == 0){
            randomS(table);
        }
        else if (strcmp(command, quit) == 0){//if they run the command quit then delete all the students in the vector list
            delete table;
            break;
        }
        else{
            cout << "Your input was not valid your options are: add, print, delete, random, quit.";//their command isn't valid
        }
    }
   delete table;
}

void randomS(hashtables* table){
    //getting first names from the file
    char fnames[100][50];
    ifstream MyReadFile("firstnames.txt");
    int i = 0;
    while (MyReadFile && i < 100) {
        char letters[50];
        if (MyReadFile.getline(letters, 50)) {
            strncpy(fnames[i], letters, 49);
            fnames[i][49] = '\0';
            i++;
        }
    }
    MyReadFile.close();

    // Getting last names from the file
    char lnames[100][50];
    ifstream MyReadFile2("lastname.txt");
    i = 0;
    while (MyReadFile2 && i < 100) {
        char letters[50];
        if (MyReadFile2.getline(letters, 50)) {
            strncpy(lnames[i], letters, 49); //Store in lnames
            lnames[i][49] = '\0';
            i++;
        }
    }
    MyReadFile2.close();


    int times = 0;
    cout << "How many times would you like to create a random student?:" << endl;//ask the user for the Id they would like to search
    cin >> times;
    srand(time(0));
    int checkid = 0;

    for(int x = 0; x < times; x++){//creating a random student
        Student* newStudent = new Student;
        int firstnamenum = rand() % 100;
        int lastnamenum = rand() % 100;

        float gpa = static_cast<float>(rand()) / RAND_MAX * 4.0;;
        while (table->info(checkid) != NULL){
            checkid++;
        }
        newStudent->makestudent(fnames[firstnamenum], lnames[lastnamenum], checkid, gpa);
        table->insert(checkid, newStudent);
        cout << "first name: " << fnames[firstnamenum] << ", last name: " << lnames[lastnamenum] << ", ID: " << checkid << ", GPA: " << gpa << endl;
    }
}

void addS(hashtables* table){//adding a new student function
    Student* newStudent = new Student;//create a new student
    char fname[50];
    char lname[50];
    float gpa;
    int ID;
    cout << "What is the student's first name?:";//ask for their info
    cin >> fname;
    cout << "What is the student's last name?:";
    cin >> lname;
    cout << "What is the student's GPA?:";
    cin >> gpa;
    cout << "What is the student's ID?:";
    cin >> ID;
    newStudent->makestudent(fname, lname, ID, gpa);
    table->insert(ID, newStudent);
    cout << "Done" << endl;
}


void printS(hashtables* table){//function for printing students
  //int command = 0;
  //cout << "Which student would you like to print? Input their ID:" << endl;//ask the user for the Id they would like to search
  //cin >> command;
  //Student* nstudent = table->info(command);
  //if(nstudent == NULL){
  //    cout << "This person does not exist" << endl;
  //}
  //else{
  //    cout << "This student is called" << nstudent->getfirst()
  //    << " " << nstudent->getlast() << endl << "They have a gpa of: " 
  //    << nstudent->getGPA() << endl << "Their ID is: " << nstudent->getID() << endl;
  //}
  table->print();
}

void deleteS(hashtables* table) {//function for deleting students
    int del;
    cout << "Which student would you like to delete? Print out their ID: ";
    cin >> del;

    table->remove(del);

    cout << "This student has been deleted" << endl;
}

