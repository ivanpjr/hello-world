#pragma once
#include <string>
#include <iostream>
#include "Dog.hxx"
using namespace std;

class Person {
    string name;
    unsigned age;
    Dog& dog;
    //static int instanceCount;S

public:
    Person() = default;
    Person(const string& n, const unsigned a, Dog& d)
       : name{n},age{a},dog{d}
       {//instanceCount++;
           cout<<"Constructor Person{"<<name<<","<<age<<","<<dog.getName()<<"} @ "<<this<<endl;}

    Person(const Person& p)
            : name{p.name},age{p.age},dog{p.dog}
    {//instanceCount++;
        cout<<"Copy Constructor Person{"<<name<<","<<age<<","<<dog.getName()<<"} @ "<<this<<endl;}

    ~Person(){//instanceCount--;
        cout<<"Destructor Person{"<<name<<","<<age<<","<<dog.getName()<<"} @ "<<this<<endl;}

    string getName() const {return name;}
    unsigned getAge() const {return age;}
    void setName(const string& n) {name = n;}
    void setAge(unsigned a){age = a;}
    string toString() const {return name + ", " + to_string(getAge()) + ", " + dog.getName() + "\n";}
    //static void resetCount() {instanceCount=0;}
};

