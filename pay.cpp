#include "person.cpp"
#include <fstream>
#include <vector>
#include <iomanip>

void readData(vector<Person> &employees);
void writeData(vector<Person> &employees);

int main()
{
  vector <Person> employees;

  readData(employees);
  writeData(employees);

  return 0;
}

void readData(vector<Person> &employees)
{
  int i = 0;
  ifstream inFile;
  string fName, lName, temp;
  float rate, hours;

  inFile.open("input.txt");

  while(!inFile.eof())
  {
    employees.emplace_back(fName, lName, rate, hours);
    inFile >> fName >> lName >> rate >> hours;
    getline(inFile, temp);
    employees.at(i).setFirstName(fName);
    employees.at(i).setLastName(lName);
    employees.at(i).setPayRate(rate);
    employees.at(i).setHoursWorked(hours);
    i++;
  }
  employees.pop_back();

  inFile.close();
}

void writeData(vector<Person> &employees)
{
  ofstream outFile;
  outFile.open("output.txt");

  for(int i = 0; i < employees.size(); i++)
  {
    outFile << setw(20) << left << employees.at(i).fullName() << "$" << setw(10) << left 
      << fixed << setprecision(2) << employees.at(i).totalPay() << endl;
  }
  outFile.close();
}
