#include<iostream>
using namespace std;
class animal{
public:
    string name;

    void make_sound(){
    cout <<"This  ANIMAL SOUND"<<endl;


}
};
class dog : public animal{
public:
    void make_sound(){
     cout<<"THIS IS DOG"<<endl;
 cout<<"'''BOW,BOOW,BOOOO'''"<<endl;
 }
};
class cat:public dog{
public:
    void make_sound(){
cout<<"THIS IS CAT"<<endl;
cout<<"'''MIA  Mia  mia'''"<<endl;
}

};

int main(){
 cat c;
 dog d;
 animal a;

 a.make_sound();
 d.make_sound();
 c.make_sound();
}
