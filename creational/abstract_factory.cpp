#include <iostream>
using namespace std;
class Gpu
{
public:
    virtual void makeGpu() = 0;
};
class Keyboard
{
public:
    virtual void makeKeyboard() = 0;
};
class Mouse
{
public:
    virtual void makeMouse() = 0;
};
class Monitor
{
public:
    virtual void makeMonitor() = 0;
};


class MsiGpu : public Gpu
{
public:
    void makeGpu() override
    {
        cout << "Msi Gpu made\n";
    }
};
class MsiMonitor : public Monitor

{
public:
    void makeMonitor() override
    {
        cout << "Msi Monitor made\n";
    }
};


class AsusGpu : public Gpu
{
public:
    void makeGpu() override
    {
        cout << "Asus Gpu made\n";
    }
};
class AsusMouse : public Mouse
{
public:
    void makeMouse() override
    {
        cout << "Asus Mouse made\n";
    }
};


class HpKeyboard : public Keyboard
{
public:
    void makeKeyboard() override
    {
        cout << "Hp Keyboard made\n";
    }
};
class HpMouse : public Mouse
{
public:
    void makeMouse() override
    {
        cout << "Hp Mouse made\n";
    }
};

class ProductFactory
{
public:
    virtual Keyboard* createKeyboard()=0;
    virtual Mouse* createMouse()=0;
    virtual Monitor* createMonitor()=0;
    virtual Gpu* createGpu()=0;
};
class MSI : public ProductFactory{
public:
    Gpu* createGpu () override{
        return new MsiGpu();
    }
    Monitor* createMonitor() override{
        return new MsiMonitor();
    }
     Keyboard* createKeyboard() override {
        return nullptr;
    }
    Mouse* createMouse() override {
        return nullptr;
    }
};
class ASUS : public ProductFactory{
public:
    Gpu* createGpu () override{
        return new AsusGpu();
    }
    Mouse* createMouse() override{ return new AsusMouse(); }
    Monitor* createMonitor() override {
        return nullptr;
    }
    Keyboard* createKeyboard() override {
        return nullptr;
    }
};


class HP : public ProductFactory{
public:
    Mouse* createMouse() override{ return new HpMouse(); }
    Keyboard* createKeyboard() override{ return new HpKeyboard(); }

    Monitor* createMonitor() override {
        return nullptr;
    }
    Gpu* createGpu() override {
        return nullptr;
    }

};

class Builder{
private:
    ProductFactory* factory;
public:   

    Builder(ProductFactory* f){
       factory=f;
    }
    void BuildProduct(const string &type){
        if (type=="keyboard" && factory->createKeyboard()){
            factory->createKeyboard()->makeKeyboard();
        }
        if (type=="mouse" && factory->createMouse()){
            factory->createMouse()->makeMouse();
        }
        if (type=="monitor" && factory->createMonitor()){
            factory->createMonitor()->makeMonitor();
        }
        if (type=="gpu" && factory->createGpu()){
            factory->createGpu()->makeGpu();
        }
    }   


};

int main()
{
    Builder builtHP(new HP());
    builtHP.BuildProduct("keyboard");
    builtHP.BuildProduct("mouse");
        
    Builder builtMsi(new MSI());
    builtMsi.BuildProduct("gpu");

    Builder buidAsus(new ASUS());
    buidAsus.BuildProduct("gpu");
    builtMsi.BuildProduct("monitor");

}