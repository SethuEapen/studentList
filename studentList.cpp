#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Student{
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

Student* ADD();
void PRINT(vector<Student*> students);
void DELETE(vector<Student*>* students, string* str);

int main()
{
  bool exit = false;
  char input[6];
  vector<Student*> students;
  while(!exit){
    cout << "Do you want to add, print, delete, or exit?" << endl;
    cin.get(input, 6);
    cin.clear();
    cin.ignore(100000, '\n');
    if(strcmp(input, "add") == 0){
      students.push_back(ADD());
    }
    else if(strcmp(input, "print") == 0){
      PRINT(students);
    }
    else if(strcmp(input, "delete") == 0){
      DELETE(students*);
    }
    else if(strcmp(input, "exit") == 0){
      exit = true;
    }
    else {
      cout << "Sorry I dont know what you mean" << endl;
    }
  }
  return 0;
}

Student* ADD(){
  cout << "You entered Add queue" << endl;
  Student* newStud = new Student();
  cout << "Enter first name: ";
  cin >> newStud->firstName;
  cout << "Enter last name: ";
  cin >> newStud->lastName;
  cout << "Enter id: ";
  cin >> newStud->id;
  cout << "Enter gpa: ";
  cin >> newStud->gpa;
  return newStud;
}
void PRINT(vector<Student*> students){
  cout << "You entered the Print queue" << endl;
  vector<Student*>::iterator it;
  for(it = students.begin(); it != students.end(); ++it){
    cout << "Student name: " << (*it)->firstName;
    cout << (*it)->lastName << endl;
    cout << "Student ID: " << (*it)->id << endl;
    cout << "Student GPA: " << (*it)->gpa << endl;
    cout << endl;
  }
}

void DELETE(vector<Student*>* students, string* str){
  cout << "You entered the Print queue" << endl;
  vector<Student*>::iterator it;
  for(it = students.begin(); it != students.end(); ++it){
    if(strcmp((*it)->firstName + " " + (*it)->lastName, str){
	students.erase(it);
	return;
    }
  }
  cout << "That is not a student" << endl;
}
