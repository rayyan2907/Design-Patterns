#include<iostream>
using namespace std;
class Shape{
public:
    virtual void draw()=0;
    virtual Shape* clone()=0;
};
class Rectangle : public Shape{
private:
    int height,width;
public:
    Rectangle(int w,int h){
        height=h;
        width=w;
    }
    void draw() override{
        cout<<"a rectangle of height "<<height<<" cm and width "<< width<<" cm is made\n";
    }
    Rectangle* clone() override{
        return new Rectangle(*this);
    }
    
};


class Circle : public Shape{
private:
    int radius;
public:
    Circle(int r){
        radius = r;
    }
    void draw() override{
        cout<<"a circle of radius "<<radius<< " is made\n";
    }
    Circle* clone() override{
        return new Circle(*this);
    }
    
};

int main(){

    Shape* circle = new Circle(10);
    Shape* rectangle = new Rectangle(10,15);
    Shape* cloneCircle = circle->clone();
    Shape* cloneRect = rectangle->clone();


    circle->draw();
    cloneCircle->draw();
    cloneRect->draw();
    rectangle->draw();
}