#include<stdio.h>
#include<iostream>
using namespace std;
class student {
public:
    student(int n=5){count=n; score=new int[count];};
    ~student(){delete [] score;};
    int *score, count;
    string name;
};
int main(){
    student a(3); a.name="John"; a.score[0]=70; a.score[1]=60; a.score[2]=30;
    student b=a; b.name="Mary"; b.score[2]=90;
}

