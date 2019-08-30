#include <iostream>
#include <conio.h>
#include <math.h>

//The Philosopher's problem

using namespace std;

int tph, philname[20], status[20], howhung, hu[20], cho;

int one(){
    int pos=0;
    cout<<"\nAllow 1 philosopher to eat at anytime.\n";
    for(int i=0;i<howhung;i++,pos++){
        cout<<"\nP "<<philname[hu[pos]]<<" is granted to eat";
        for(int j=pos+1;j<howhung;j++){
            cout<<"\nP "<<philname[hu[j]]<<" is waiting";
        }
    }
}

int two(){
    int s=0, t, r;
    cout<<"\nAllow 2 philosophers to eat at at the same time.\n";
    for(int i=0;i<howhung;i++){
        for(int j=i+1;j<howhung;j++){
            if((abs(philname[hu[i]]-philname[hu[j]])>=2) && ((philname[hu[i]]-philname[hu[j]])!=5)){
                cout<<"\n\nCombination "<<s+1;
                t = hu[i];
                r = hu[j];
                s++;
                cout<<"\nP "<<philname[hu[i]]<<" and "<<philname[hu[j]]<<" are granted to eat";
                for(int k=0;k<howhung;k++){
                    if((hu[k]!=t) && (hu[k]!=r)){
                    cout<<"\nP "<<philname[hu[k]]<<" is waiting";
                    }
                }
            }
        }
    }
}

int main(){
    cout<<"\n\nDINING PHILOSOPHER'S PROBLEM";
    cout<<"\nEnter the total no. of philosophers: ";
    cin>>tph;
    for(int i=0;i<tph;i++){
        philname[i] = i+1;
        status[i] = 1;
    }
    cout<<"How many are hungry : ";
    cin>>howhung;
    if(howhung==tph){
        cout<<"\nAll are hungry..\nDead lock stage will occur";
        cout<<"\nExiting...";
    }
    else{
        for(int i=0;i<howhung;i++){
            cout<<"Enter philosopher "<<i+1<<" position : ";
            cin>>hu[i];
            hu[i]--;
            status[hu[i]]=2;
        }
        do{
            cout<<"\n\n1. One can eat a time\t2. Two can eat at a time\nEnter your choice : ";
            cin>>cho;
            switch(cho){
            case 1 : one();
            break;
            case 2 : two();
            break;
            default : cout<<"\nInvalid option..";
            }
        }
        while(1);
        }
    }
