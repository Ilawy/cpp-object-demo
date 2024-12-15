#include "iostream"
#include "cstring"
#include "object.hh"

using namespace std;



int main(int argc, char const *argv[])
{
    Object name = "Mohammed";    
    Object age = 24;    
    Object isDeveloper = true;

    Object list[3];
    list[0] = name;
    list[1] = age;
    list[2] = isDeveloper;

    name = 24;
    age = "29";

    cout << "My name is " << name << ", I'm " << age << " years old and I'm " << (isDeveloper.as<bool>() ? "" : "not ") << "a developer" << endl;
    
    for(int i = 0; i < 3; i++){
        cout << list[i] << endl;
    }
    return 0;
}
