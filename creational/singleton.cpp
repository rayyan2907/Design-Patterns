#include<iostream>
using namespace std;
class Singleton{
private:
    int sum;
    static Singleton* instance;
    Singleton(){
        cout<<"object refrence is created\n";
    }
public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            instance=new Singleton();
            cout<<"no old object found. new made\n";
        }

        return instance;
    }

    int showSum(){
        return sum;
    }
    void getSum(int abc){
        sum=abc;
    }
};
Singleton* Singleton::instance=nullptr;
int main(){
    Singleton* s1= Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->getSum(2);
    s2->getSum(10);

    cout<<"value in s1 and s2 are ";
    int value1=s1->showSum();
    int value2 =s2->showSum();

    cout<<value1<<" and "<<value2;
    

}