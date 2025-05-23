#include<iostream>
using namespace std;
class Computer{
public:
    string cpu;
    string gpu;
    int ram;

    void showSpecs(){
        cout<<"The pc has cpu "<<cpu<<" and gpu "<<gpu<<" and has ram "<<ram<<" GB."<<endl;
    }
};
class ComputerBuilder{
public:
    virtual void buildCpu()=0;
    virtual void buildGpu()=0;
    virtual void buildRam()=0;
    virtual Computer* getComputer()=0;

};
class gammingComputer : public ComputerBuilder{
private:
    Computer* computer;
public:
    gammingComputer(){
        computer= new Computer();
    }
    void buildCpu() override{
        computer->cpu="intel i9 13 gen";
    }
    void buildGpu()override{
        computer->gpu="nvdia rtx 4090 ti";
    }
    void buildRam(){
        computer->ram=32;
    }
    Computer* getComputer() override{
        return computer;
    }
};

class officeComputer : public ComputerBuilder{
private:
    Computer* computer;
public:
    officeComputer(){
        computer= new Computer();
    }
    void buildCpu() override{
        computer->cpu="intel i3 8 gen";
    }
    void buildGpu()override{
        computer->gpu="nvdia gtx 1050 ti";
    }
    void buildRam(){
        computer->ram=8;
    }
    Computer* getComputer() override{
        return computer;
    }
};
class Director{
private:
    ComputerBuilder* comp;
public:
    Director(ComputerBuilder* c){
        comp = c;
    }
    void construct(){
        comp->buildCpu();
        comp->buildGpu();
        comp->buildRam();

    }

};
int main(){
    gammingComputer gamingcomp;
    officeComputer officecomp;

    Director d1(&gamingcomp);
    Director d2(&officecomp);

    d1.construct();
    d2.construct();

    Computer* gamepc=gamingcomp.getComputer();
    gamepc->showSpecs();    
    Computer* officepc= officecomp.getComputer();
    officepc->showSpecs();


}