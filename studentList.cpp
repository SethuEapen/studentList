//inports
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

//including the namespace
using namespace std;

struct Student{//creates a struct that has a first and last name, an int, and a gpa
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};
//function init
Student* ADD();
void PRINT(vector<Student*> students);
void DELETE(vector<Student*>* students, int id);

int main()//main method
{
  bool exit = false;//determines if the code should continue running
  char input[7];// input for the add print delete exit
  vector<Student*> students;//vector of student pointers
  int idInput;// input for delete
  while(!exit){// main running loop
    cout << "Do you want to add, print, delete, or exit?" << endl;
    cin.get(input, 7);//getting 7 characters from the cin
    cin.clear();
    cin.ignore(100000, '\n');
    if(strcmp(input, "add") == 0){//if the input is add...
      students.push_back(ADD());//run ADD function and put he output into students
    }
    else if(strcmp(input, "print") == 0){//if the input is print...
      PRINT(students);//run print function
    }
    else if(strcmp(input, "delete") == 0){//if input is delete...
      cout << "You entered the Delete queue" << endl;
      cout << "Enter student id:";
      cin >> idInput;//get the id you want to delete
      cin.clear();
      cin.ignore(100000, '\n');
      DELETE(&students, idInput);//run delete function with input if adress of students
    }
    else if(strcmp(input, "exit") == 0){//if input is exit...
      exit = true;//change the value of exit to true to stop the program
    }
    else {
      cout << "Sorry I dont know what you mean" << endl;
    }
  }
  return 0;
}

Student* ADD(){//add function
  cout << "You entered Add queue" << endl;
  Student* newStud = new Student();//alocate to heap
  cout << "Enter first name: ";
  cin >> newStud->firstName;//what is first name?
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter last name: ";
  cin >> newStud->lastName;//what is last name?
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter id: ";
  cin >> newStud->id;//wthat is the student id?
  cin.clear();
  cin.ignore(100000, '\n');
  cout << "Enter gpa: ";
  cin >> newStud->gpa;//what is the gpa
  cin.clear();
  cin.ignore(100000, '\n');
  return newStud;//return a student pointer
}
void PRINT(vector<Student*> students){//print function
  cout << "You entered the Print queue" << endl;
  vector<Student*>::iterator it;//get a vetor student pointer itorator
  for(it = students.begin(); it != students.end(); ++it){//iterates through the student vector
    //following lines print out the students vector
    cout << "Student name: " << (*it)->firstName << " " << (*it)->lastName << endl;
    cout << "Student ID: " << (*it)->id << endl;
    cout << "Student GPA: " << fixed << setprecision(2) << (*it)->gpa << endl;
    cout << endl;
  }
}

void DELETE(vector<Student*>* students, int id){
  vector<Student*>::iterator it;//Student pointer iterator
  for(it = students->begin(); it != students->end(); ++it){//iterates through students
    if((*it)->id == id){//if the id of the student is eaqual to the one priviously entered...
      delete *it;//delete the memory of it in heap
      students->erase(it);//erase the index from student list
      return;//return if found
    }
  }
  cout << "Invalid ID" << endl;//if the function reaches here the id was invalid.
}
