#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Employee{
private:
    string employee_no;
    string name;
    string designation;
    string salary;

public:
    Employee() {}

    Employee(string employee_no ,string name, string designation, string salary) 
    {
        this->employee_no = employee_no;
        this->name = name;
        this->designation = designation;
        this->salary = salary;
    }

    void show() {
        cout << setw(12) << this->employee_no << '|'
             << setw(20) << this->name << '|'
             << setw(30) << this->designation << '|'
             << setw(20) << this->salary << '|' << endl;
    }

    string get_id() {
        return this->employee_no;
    }

};

class Operations{
private:
    ofstream fileOut;
    ifstream fileIn;

    char *file_name;

public:
    Operations() {
        this->file_name = (char*)"EmployeeDB.txt";
    }

    void add_record() {
        fileOut.open(this->file_name, ios::app);

        string employee_no;
        string name;
        string designation;
        string salary;

        cout << "Employee ID                 : ";
        cin >> employee_no;
        cout << "Name of the employee        : ";
        getchar();
        getline(cin, name);
        cout << "Designation of the employee : ";
        getline(cin, designation);
        cout << "salary of the employee      : ";
        cin >> salary;

        // Employee *employee = new Employee(employee_no, name, designation, salary);

        // Add to list
        fileOut << employee_no << '\n' << name << '\n' << designation << '\n' << salary << '\n';

        // close file
        fileOut.close();

    }

    void list_all() {
        Employee *employee = new Employee();

        cout << "=======================================================================================" << endl;
        cout << setw(12) << "Employee No" << '|'
             << setw(20) << "Employee Name" << '|'
             << setw(30) << "Designation" << '|'
             << setw(20) << "Salary" << '|' << endl;
        cout << "=======================================================================================" << endl;

        // open file
        fileIn.open( this->file_name, ios::in);

        // show all
        while (fileIn) {
            string employee_no, name, designation, salary;
            getline(fileIn, employee_no);
            getline(fileIn, name);
            getline(fileIn, designation);
            getline(fileIn, salary);

            if ( (employee_no == "" and name == "") and (designation == "" and salary == "") ) break;

            employee = new Employee(employee_no, name, designation, salary);
            employee->show();
        }

        fileIn.close();
    }

    void modify_record() {
        string id;
        cout << "Employee NO : ";
        cin >> id;

        Employee *employee = new Employee();

        // open new file
        char temp[] = "temp.txt";
        fileOut.open("temp.txt", ios::app);

        // open file
        fileIn.open( this->file_name, ios::in);

        // show all
        while (fileIn) {
            string employee_no, name, designation, salary;
            getline(fileIn, employee_no);
            getline(fileIn, name);
            getline(fileIn, designation);
            getline(fileIn, salary);


            if ( (employee_no == "" and name == "") and (designation == "" and salary == "") ) break;

            if (id == employee_no) {

                cout << "Name of the employee        : ";
                getchar();
                getline(cin, name);
                cout << "Designation of the employee : ";
                getline(cin, designation);
                cout << "salary of the employee      : ";
                cin >> salary;

            }

            fileOut << employee_no << '\n' << name << '\n' << designation << '\n' << salary << '\n';
        }

        // replace file
        fileIn.close();
        fileOut.close();

        remove(this->file_name);
        rename(temp, this->file_name);
    }

    void delete_record() {
        string id;
        cout << "Employee NO : ";
        cin >> id;

        Employee *employee = new Employee();

        // open new file
        char temp[] = "temp.txt";
        fileOut.open("temp.txt", ios::app);

        // open file
        fileIn.open( this->file_name, ios::in);

        // show all
        while (fileIn) {
            string employee_no, name, designation, salary;
            getline(fileIn, employee_no);
            getline(fileIn, name);
            getline(fileIn, designation);
            getline(fileIn, salary);

            if (id != employee_no) {
                fileOut << employee_no << '\n' << name << '\n' << designation << '\n' << salary << '\n';
            }

        }

        // replace file
        fileIn.close();
        fileOut.close();

        remove(this->file_name);
        rename(temp, this->file_name);
    }
};

int choice() {
    cout << "\033[2J\033[1;1H";
    cout << "1. Add Record\n" 
         << "2. List Records\n"
         << "3. Modify Records\n"
         << "4. Delete Record\n"
         << "5. Exit" << endl;


    int choice;
    cin >> choice;

    return choice;
}

int main() {
    Operations *ob = new Operations();

    while (1) {
        
        switch(choice()) {
            case 1: ob->add_record();
                    break;
            case 2: ob->list_all();
                    break;
            case 3: ob->modify_record();
                    break;
            case 4: ob->delete_record();
                    break;
            case 5: exit(0);
                    break;
            default : cout << "Please enter a valid choice.";
        }

        cout << "\n[press 'enter key']";
        getchar();
        getchar();

    }

    return 0;

}