#include "cstring"
#include "iostream"
// #include "cstring"

// #define let Object

class Object
{
private:
    enum DT
    {
        INT,
        FLOAT,
        CHARP,
        BOOL
    };
    void *data;
    Object::DT dt;

public:
    Object(){}
    Object(int val)
    {
        data = new int(val);
        dt = Object::DT::INT;
    }

    Object(float val)
    {
        data = new float(val);
        dt = Object::DT::FLOAT;
    }

    Object(const char val[])
    {

        char *temp = new char[strlen(val + 1)];
        strcpy(temp, val);
        data = (void *)temp;
        dt = Object::DT::CHARP;
    }

    Object(bool val)
    {
        data = new bool(val);
        dt = Object::DT::BOOL;
    }

    template<typename T>
    Object(T &other){
        std::cout << "COPY" << std::endl;
    }


    // ~Object()
    // {
    //     switch (dt)
    //     {
    //     case INT:
    //         delete (int *)data;
    //         break;
    //     case FLOAT:
    //         delete (float *)data;
    //         break;
    //     case CHARP:
    //     {
    //         char *ptr = (char*)data;
    //         // delete []ptr;
    //         // std::cout << "DEL " << ptr << std::endl;
    //         break;
    //     }

    //     case BOOL:
    //         delete (bool *)data;
    //     }
    // }

    template <typename T>
    T &as()
    {
        return *(T *)(data);
    }

    friend std::ostream &operator<<(std::ostream &os, Object &j)
    {
        switch (j.dt)
        {
        case Object::DT::INT:
            os << *(int *)j.data;
            break;
        case Object::DT::FLOAT:
            os << *(int *)j.data;
            break;
        case Object::DT::CHARP:
            os << (char *)j.data;
            break;
        case Object::DT::BOOL:
            os << *(bool *)j.data;
            break;
        default:
            break;
        }

        return os;
    }
};