#include<iostream>
using namespace std;
class MediaPlayer{
public:
    virtual void play(string audoType,string fileName)=0;
};
class AdvanceMediaPlayer{
public: 
    void playVlc(string filename){
        cout<<"Playing VLC file: "<<filename<<endl;
    }
    void playMP4(string filename){
        cout<<"Playing mp4 file: "<<filename<<endl;
    }
};
class MovPlayer{
public:
    void playMov(string filename){
        cout<<"Playing mov file: "<<filename<<endl;
    }
};
class MediaAdapter : public MediaPlayer{
private:
    AdvanceMediaPlayer* player;
public:
    MediaAdapter(){
        player = new AdvanceMediaPlayer();
    }

    void play(string audioType, string filename) override {
        if(audioType=="vlc"){
            player->playVlc(filename);
        }
        if(audioType=="mp4"){
            player->playMP4(filename);
        }
    }

};
class MovAdapter : public MediaPlayer{
private:
    MovPlayer* movplayer;
public:
    MovAdapter(){
        movplayer= new MovPlayer();
    }
    void play (string audiotype,string filename) override{
        if(audiotype=="mov"){
            movplayer->playMov(filename);
        }
    }
};
class AudioPlayer : MediaPlayer{
public:
    MediaAdapter adapter;
    MovAdapter movadapter;
    void play(string audioType,string filename) override {
        if(audioType=="mp3"){
            cout<<"Playing mp3 file: "<<filename<<endl;
        }
        else if (audioType=="vlc" || audioType=="mp4"){
            adapter.play(audioType,filename);
        }
        else if (audioType=="mov"){
            movadapter.play(audioType,filename);
        }
        else {
            cout<<"Format not supported\n";
        }
    }
};
int main(){

    AudioPlayer player;
    player.play("mp3","abc.mp4");
    player.play("avi","123.avi");
    player.play("mp4","file.mp4");
    player.play("vlc","old_video.vlc");
    player.play("mov","iphone.mov");
}