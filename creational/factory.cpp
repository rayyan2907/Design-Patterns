#include <iostream>
using namespace std;
class shape
{
public:
    virtual void draw() = 0;
};
class rectangle : public shape
{
public:
    void draw() override
    {
        cout << "Drawing a rectangle\n";
    }
};
class trinagle : public shape
{
public:
    void draw() override
    {
        cout << "Drawinng a trinangle\n";
    }
};
class circle :public shape{
public:
    void draw() override
    {
        cout<<"Drawing a circle\n";
    }
};

class Factory
{
public:
    static shape *createShape(const string &type)
    {
        if (type == "rectangle"){
            return new rectangle();
        }
        if(type=="triangle"){
            return new trinagle();
        }
        if(type=="circle"){
            return new circle();
        }
        return nullptr;
    }
};

int main()
{
    shape* s1= Factory::createShape("rectangle");
    shape* s2 = Factory::createShape("triangle");
    shape* s4= Factory::createShape("rectangle");
    shape* s3 = Factory::createShape("circle");

    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();

}