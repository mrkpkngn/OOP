#include <iostream>
using namespace std;

class question{
private:
    string q;
    question *yes;
    question *no;

public:
    question(string ques);
    question* newYes(string ques);
    question* newNo(string ques);
    question* getYes();
    question* getNo();
    string getQuestion();
};
