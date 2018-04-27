#include <iostream>
#include "Person.hxx"
#include "Dog.hxx"

Person makeTwin(Person p){
    p.toString();
    return p;
}

int main() {

    Dog d1;
    d1.setName("Pink");
    d1.setAge(4);
    cout << d1.toString();
    d1.bark();

    Person p1{"A",1, d1};
    p1.setName("Ivan");
    p1.setAge(40);
    cout << p1.toString();

//    Dog d2;
//    d2.setName("Cookie");
//    d2.setAge(1);
//    cout << d2.toString();
//    d2.bark();
//
//    Person p2{"B",2, d2};
//    p2.setName("Dri");
//    p2.setAge(39);
//    cout << p2.toString();

    Person twin = makeTwin(p1);
    twin.toString();

    return 0;
}


