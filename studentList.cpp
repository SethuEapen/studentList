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
void DELETE(vector<Student*> students, int id);

int main()
{
  bool exit = false;
  char input[7];
  vector<Student*> students;
  int idInput;
  while(!exit){
    cout << "Do you want to add, print, delete, or exit?" << endl;
    cin.get(input, 7);
    cin.clear();
    cin.ignore(100000, '\n');
    if(strcmp(input, "add") == 0){
      students.push_back(ADD());
    }
    else if(strcmp(input, "print") == 0){
      PRINT(students);
    }
    else if(strcmp(input, "delete") == 0){
      cin >> idInput;
      cin.clear();
      cin.ignore(100000, '\n');
      DELETE(students, idInput);
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
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter last name: ";
  cin >> newStud->lastName;
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter id: ";
  cin >> newStud->id;
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter gpa: ";
  cin >> newStud->gpa;
  cin.clear();
  cin.ignore(100000, '\n');
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

void DELETE(vector<Student*> students, int id){
  cout << "You entered the Delete queue" << endl;
  vector<Student*>::iterator it;
  for(it = students.begin(); it != students.end(); ++it){
    if((*it)->id == id){
      cout << "Delete" << endl;
	students.erase(it);
	return;
    }
  }
  cout << "That is not a student" << endl;
}
