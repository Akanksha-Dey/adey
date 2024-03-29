


#include <iostream>
#include <string>  // Include the <string> header for using std::string
#include <cstdlib> // Include the <cstdlib> header for system function
using namespace std;

int i = 0;
struct Employee
{
    int id;
    float salary;
    string name, address, phone, department;
} E[25];

void insert()
{
    system("cls");
    cout << "\n\n Insert Employee Record";
    cout << "\n\n Enter Employee ID:";
    cin >> E[i].id;
    cout << "Enter Employee Name:";
    cin.ignore();
    getline(cin, E[i].name);
    cout << "Enter Employee Address:";
    getline(cin, E[i].address);
    cout << "Enter Employee Phone:";
    cin >> E[i].phone;
    cout << "Enter Employee Department:";
    cin.ignore();
    getline(cin, E[i].department);
    cout << "Enter Employee Salary:";
    cin >> E[i].salary;
    i++;
    cout << "\n\n Employee Record Inserted";
}

void search()
{
    system("cls");
    cout << "\n\n Employee Management System";
    if (i == 0)
    {
        cout << "\n\n Database Is Empty";
    }
    else
    {
        int t_id, found = 0;
        cout << "\n\n Enter Employee ID For Search:";
        cin >> t_id;
        for (int a = 0; a < i; a++)
        {
            if (t_id == E[a].id)
            {
                cout << "\n\n Employee Name:" << E[a].name;
                cout << "\n\n Employee Address:" << E[a].address;
                cout << "\n\n Employee Phone No.:" << E[a].phone;
                cout << "\n\n Employee Department:" << E[a].department;
                cout << "\n\n Employee Salary:" << E[a].salary;
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Employee ID Not Found";
        }
    }
}

void update()
{
    system("cls");
    cout << "\n\n Employee Management System";
    if (i == 0)
    {
        cout << "\n\n Database Is Empty";
    }
    else
    {
        int t_id, found = 0;
        cout << "\n\n Enter Employee ID For Update:";
        cin >> t_id;
        for (int a = 0; a < i; a++)
        {
            if (t_id == E[a].id)
            {
                cout << "\n\n Enter Employee Name:";
                cin.ignore();
                getline(cin, E[a].name);
                cout << "\n\n Enter Employee Address:";
                getline(cin, E[a].address);
                cout << "\n\n Enter Employee Phone No.:";
                cin >> E[a].phone;
                cout << "\n\n Enter Employee Department:";
                cin.ignore();
                getline(cin, E[a].department);
                cout << "\n\n Enter Employee Salary:";
                cin >> E[a].salary;
                cout << "\n\n Record Updated Successfully";
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Employee ID Not Found";
        }
    }
}

void del()
{
    system("cls");
    cout << "\n\n Employee Management System";
    if (i == 0)
    {
        cout << "\n\n Database Is Empty";
    }
    else
    {
        int t_id, found = 0;
        cout << "\n\n Enter Employee ID For Delete:";
        cin >> t_id;
        for (int a = 0; a < i; a++)
        {
            if (t_id == E[a].id)
            {
                for (int k = a; k < i - 1; k++)
                {
                    E[k] = E[k + 1]; // Shift elements to overwrite the deleted record
                }
                i--;
                cout << "\n\n Record Deleted Successfully";
                found++;
                break;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Employee ID Not Found";
        }
    }
}

void show()
{
    system("cls");
    cout << "\n\n Employee Management System";
    if (i == 0)
    {
        cout << "\n\n Database Is Empty";
    }
    else
    {
        for (int a = 0; a < i; a++)
        {
            cout << "\n\n Employee ID:" << E[a].id;
            cout << "\n\n Employee Name:" << E[a].name;
            cout << "\n\n Employee Address:" << E[a].address;
            cout << "\n\n Employee Phone No.:" << E[a].phone;
            cout << "\n\n Employee Department:" << E[a].department;
            cout << "\n\n Employee Salary:" << E[a].salary;
        }
    }
}

int main() // Use int main() instead of main()
{
    int choice;
p:
    system("cls");
    cout << "\n\n Employee Management System";
    cout << "\n\n 1. Insert Employee";
    cout << "\n\n 2. Search Employee";
    cout << "\n\n 3. Update Employee";
    cout << "\n\n 4. Delete Employee";
    cout << "\n\n 5. Show All Employee";
    cout << "\n\n 6. Exit";
    cout << "\n\n Enter Your Choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        del();
        break;
    case 5:
        show();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\n Invalid Option.... Please Try Again";
    }
    cin.ignore();
    cin.get();
    goto p;
}


