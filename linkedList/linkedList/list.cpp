#include "list.h"
#include <string>

question::question(string ques){
    this->q = ques;
    this->yes = nullptr;
    this->no = nullptr;
};

question* question::newYes(string ques){
    this->yes = new question(ques);
    return this->yes;
}

question* question::newNo(string ques){
    this->no = new question(ques);
    return this->no;
}

question* question::getYes(){
    return this->yes;
}

question* question::getNo(){
    return this->no;
}

string question::getQuestion(){
    return this->q;
}
