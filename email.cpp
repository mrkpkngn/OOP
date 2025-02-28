#include <iostream>
#include <string>

using namespace std;

class Email
{
private:
    string emailAddress;

public:
    Email(const string &email)
    {
        emailAddress = email;
    }

    bool isValid()
    {
        if (emailAddress.find('@') != string::npos && emailAddress.find('.') != string::npos)
        {
            return true;
        }
        return false;
    }

    string getDomain()
    {
        int symbolAtPos = emailAddress.find('@'); // find @ position
        if (symbolAtPos != string::npos)
        {
            return emailAddress.substr(symbolAtPos + 1); // return substring after @
        }
        return "";
    }

    string getUser()
    {
        int symbolAtPos = emailAddress.find('@'); // find @ position
        if (symbolAtPos != string::npos)
        {
            return emailAddress.substr(0, symbolAtPos); // return substring after @
        }
        return "";
    }

    void changeAddress(string newAddress)
    {
        emailAddress = newAddress;
    }

    void getEmail()
    {
        cout << "Email: " << emailAddress << "\nIs Valid?: " << isValid() << "\nUser: " << getUser() << "\nDomain: " << getDomain() << "\n";
    }
};

int main()
{
    Email currEmail("mrk.pkngn@gmail.com");
    currEmail.getEmail();
    currEmail.changeAddress("terezanova75@gmail");
    currEmail.getEmail();
    return 0;
}
