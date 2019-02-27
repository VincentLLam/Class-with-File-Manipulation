#include "person.cpp"
#include <fstream>

int readData(int SIZE, Person employee[]);
void writeData(int num, Person employee[]);

int main()
{
  int SIZE = 20;
  int num = 0;
  Person employee[SIZE];

  num = readData(SIZE, employee);
  writeData(num, employee);

  return 0;
}

int readData(int SIZE, Person employee[])
{
  ifstream inFile;
  string fName, lName, temp;
  float rate, hours;
  int i = 0;
  inFile.open("input.txt");

  while(!inFile.eof())
  {
    inFile >> fName >> lName >> rate >> hours;
    getline(inFile, temp);
    employee[i].setFirstName(fName);
    employee[i].setLastName(lName);
    employee[i].setPayRate(rate);
    employee[i].setHoursWorked(hours);
    i++;
  }
  i--;

  inFile.close();
  return i;
}

void writeData(int num, Person employee[])
{
  ofstream outFile;
  outFile.open("output.txt");

  for(int i = 0; i < num; i++)
  {
    outFile << employee[i].fullName() << " " << employee[i].totalPay() << endl;
  }
  outFile.close();
}
