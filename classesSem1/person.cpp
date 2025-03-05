#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
    string birthNum;

public:
    Person(string fName, string lName, string birNum)
    {
        firstName = fName;
        lastName = lName;
        birthNum = birNum;
    }

    string getGender()
    {
        int digits = stoi(birthNum.substr(2, 2));
        if (digits > 12)
        {
            return "Female";
        }

        return "Male";
    }

    string getBirth()
    {
        string day = birthNum.substr(4, 2);
        int monthInt = stoi(birthNum.substr(2, 2));
        if (monthInt > 12)
        {
            monthInt -= 50;
        }

        string month;
        if (monthInt < 10)
        {
            month = "0" + to_string(monthInt);
        }
        else
        {
            month = to_string(monthInt);
        }

        int year = stoi(birthNum.substr(0, 2));
        if (year > 25)
        {
            year += 1900;
        }
        else
        {
            year += 2000;
        }

        return day + "." + month + "." + to_string(year);
    }

    string fullName()
    {
        return firstName + " " + lastName;
    }

    void setName(string newName)
    {
        firstName = newName;
    }

    void setSurname(string newSurname)
    {
        lastName = newSurname;
    }

    void printInfo()
    {
        cout << "Full Name:\t" << fullName() << "\nGender:\t\t" << getGender() << "\nDate of Birth:\t" << getBirth() << "\n\n";
    }
};

int main()
{
    Person currPerson("Mark", "Pakingan", "041105");
    currPerson.printInfo();
    currPerson.setName("Mark Daniel");
    currPerson.printInfo();
    Person terezaNova("Tereza", "Nova", "065206");
    terezaNova.printInfo();
    terezaNova.setSurname("Pakingan");
    terezaNova.printInfo();
    return 0;
}
