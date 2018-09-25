#include <iostream>
#include <vector>

using namespace std;

void ADD(vector<Student*> students);
void PRINT(vector<Student*> students);
void DELETE(vector<Student*> students);

struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

int main()
{
  bool exit = false;
  char input[6];
  vector<Student*> students;
  while(!exit){
    cin.get(input, 6);
    cin.clear();
    cin.ignore(100000, '\n');
    if(strcmp(input, "add") == 0){
      ADD(students);
    }
    else if(strcmp(input, "print") == 0){
      PRINT(students);
    }
    else if(strcmp(input, "delete") == 0){
      DELETE(students);
    }
  }
}

void ADD(vector<Student*> students){
  Student newStud;
  cin >> newStud.firstName;
  cin >> newStud.lastName;
  cin >> newStud.id;
  cin >> newStud.gpa;
  students.push_back(newStud);
}

void PRINT(vector<Student*> students){

}

void DELETE(vector<Student*> students){

}
