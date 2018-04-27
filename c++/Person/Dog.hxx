#pragma once
#include <string>
#include <iostream>
using namespace std;

class Dog {
    string name;
    unsigned age;
    //static int instanceCount;

public:
    Dog() = default;
    Dog(const string& n, const unsigned a)
            : name{n},age{a}
    {
        //instanceCount++;
        cout<<"Constructor Dog{"<<name<<","<<age<<"} @ "<<this<<endl;}
    ~Dog(){
        //instanceCount--;
        cout<<"Destructor Dog{"<<name<<","<<age<<"} @ "<<this<<endl;}

    string getName() const {return name;}
    unsigned getAge() const {return age;}
    void setName(const string& n) {name = n;}
    void setAge(unsigned a){age = a;}
    void bark() const {cout << getName() << ": -Wuff!" << endl;}
    string toString() const {return name + "," + to_string(getAge()) + "\n";}
    //static void resetCount() {instanceCount=0;}

};

