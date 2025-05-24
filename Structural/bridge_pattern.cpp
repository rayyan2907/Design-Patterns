#include<iostream>
using namespace std;
class Device{
public:
    virtual void turnOff()=0;
    virtual void turnOn()=0;
    virtual void setVolume(int volume)=0;

};
class TV : public Device{
public:
    void turnOn()override{
        cout<<"Turning on Tv"<<endl;

    }
    void turnOff()override{
        cout<<"Turning Off Tv\n";

    }
    void setVolume(int volume)override{
        cout<<"Set tv volume to "<<volume<<endl;
    }
};


class Radio : public Device{
public:
    void turnOn()override{
        cout<<"Turning on Radio"<<endl;

    }
    void turnOff()override{
        cout<<"Turning Off Radio\n";

    }
    void setVolume(int volume)override{
        cout<<"Set Radio volume to "<<volume<<endl;
    }
};
class RemoteController{
protected:
    Device* device;
public:
    RemoteController(Device* dev){
        device=dev;

    }
    virtual void turnOff(){
        device->turnOff();
    }
    virtual void turnOn(){
        device->turnOn();
    }
    virtual void setVolume(int volume){
        device->setVolume(volume);
    }

};

class AdvanceRemote : public RemoteController{
public:
    AdvanceRemote(Device* dev) : RemoteController(dev) {}

    void mute(){
        cout << "muting the device"<<endl;
        device->setVolume(0);
    }
};
int main(){

    Device* tv = new TV();
    AdvanceRemote* tv_remote = new AdvanceRemote(tv);
    Device* radio = new Radio();
    AdvanceRemote* radio_remote = new AdvanceRemote(radio);

    tv_remote->turnOn();
    tv_remote->setVolume(100);
    tv_remote->turnOff();

    radio_remote->turnOn();
    radio_remote->setVolume(50);
    radio_remote->mute();
    radio_remote->turnOff();



}