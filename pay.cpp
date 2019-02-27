#include "person.cpp"
#include <fstream>

void readData(int SIZE, Person employee[]);
void writeData(int SIZE, Person employee[]);

int main()
{
  int SIZE = 20;
  Person employee[SIZE];

  readData(SIZE, employee);
  writeData(SIZE, employee);

  return 0;
}

void readData(int SIZE, Person employee[])
{
  ifstream inFile;
  string fName;
  string lName;
  float rate;
  float hours;
  string temp;
  int i = 0;
  inFile.open("input.txt");

  while(!inFile.eof())
  {
    inFile >> fName;
    inFile >> lName;
    inFile >> rate;
    inFile >> hours;
    getline(inFile, temp);
    employee[i].setFirstName(fName);
    employee[i].setLastName(lName);
    employee[i].setPayRate(rate);
    employee[i].setHoursWorked(hours);
    i++;
  }
  inFile.close();
}

void writeData(int SIZE, Person employee[])
{
  ofstream outFile;
  outFile.open("output.txt");

  for(int i = 0; i < SIZE; i++)
  {
    outFile << employee[i].fullName() << " " << employee[i].totalPay() << endl;
  }
  outFile.close();
}
