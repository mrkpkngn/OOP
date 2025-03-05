#include <iostream>
#include "list.h"
using namespace std;

int main(int argc, const char * argv[]) {
    question *head = new question("Is it a Mammal?");
    head->newYes("Does it Have Stripes?");
    head->newNo("Does it Fly?");
    
    question *branch1Yes = head->getYes();
    branch1Yes->newYes("Is it Carnivore?");
    branch1Yes->newNo("It is a Pig");
    
    question *branch1No = head->getNo();
    branch1No->newYes("It is an eagle");
    branch1No->newNo("Does it Swim?");
    
    question *branch2Yes = branch1Yes->getYes();
    branch2Yes->newYes("It is tiger");
    branch2Yes->newNo("It is a zebra");
    
    question *branch3No = branch1No->getNo();
    branch3No->newYes("It is a penguin");
    branch3No->newNo("It is an Ostrich");
    
    question* current = head;
    
    while(current->getYes() != nullptr || current->getNo() != nullptr){
        char answer;
        cout << current->getQuestion() << endl;
        cout << "Y or N: ";
        cin >> answer;
        switch(answer){
            case 'Y':
                current = current->getYes();
                break;
                
            case 'N':
                current = current->getNo();
                break;
        }
    }
    
    cout << "Answer: " << current->getQuestion() << endl;
    getchar();
    
    return 0;
}
