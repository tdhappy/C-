
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <iomanip>


using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

int temp1=0;
int temp2=0;


Door hideCar(){    //Function that randomly selects a door to hide the car
   
   int d=0;
   d=(rand()%3)+1;
   
   return d;
   
}

Door openDoor1(int firstCoice){     //Function that computes the door number decided by Monty
    
    int d=0;
    
    do{
        d=(rand()%3)+1;
    }while(d==firstCoice);
    
    temp2=d;
    
    return d;
    
};

Door openDoor2(){   //Function to hold the value of 
    
    int d=temp2;
    temp2=0;
    
    return d;
}

Door makeFirstChoice1(){    //Function that compute the first choice
    
    int d=0;
    
    d=(rand()%3)+1;
    temp1=d;
    
    return d;
    
};

Door makeFirstChoice2(){    //Function that holds the value of First Choice
    
    int d=temp1;
    
    return d;
    
};

Door makeFirstChoice3(){    //Function that holds the value of First Choice
    
    int d=temp1;
    temp1=0;
    
    return d;
    
};

Door makeSecondChoice(int firstChoice, int openDoor){  //Function to make the second choice 
    
    int d=0;
    do{
        d=(rand()%3)+1;
    }while((d==openDoor)||(d==firstChoice));
    
    return d;
    
};

int main()
{
    
    int a=0;  
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    string win1;
    string win2;
    int count1=0;
    int count2=0;    
    float ratio=0.0;
        
        
        cout<<"  #    Car    First   Opened   Second     Win    Win"<<endl;
        cout<<"      here   choice     door   choice   first second"<<endl;
        cout<<endl;
        
        for(int i=1; i<(SIMULATION_COUNT+1); i++){
        
        srand(time(NULL)+i);  //To generate random choices every time the program is run. 
            
        a=hideCar();
        
        b=makeFirstChoice1();
        
        c=openDoor1(makeFirstChoice2()); //Monty opens this door if your first choice is true
        
        if(b!=a){               //Monty opens this door if your first choice is wrong
            
            do{
                c=(rand()%3)+1;
            }while(c==makeFirstChoice2()||(c==a));
            
        }
        
        if(c==openDoor1(makeFirstChoice2())){
            d=makeSecondChoice(makeFirstChoice3(),openDoor2());    
            
        }else{              //Condition to choose the second door when first choice is wrong
            
            do{
                d=(rand()%3)+1;    
            }while((d==makeFirstChoice2())||(d==c));
            
        }        
        
        if(b==a){          //Finding the number of win for staying on first choice
            
            win1="Yes";
            count1++;
        }
        else{
            
            win1="";
        }
        
        if(d==a){          //Finding the number of win for switching to second choice
            
            win2="Yes";
            count2++;
        }
        else{
            
            win2="";
        }        
        
        if((i>0)&&(i<10)){
        cout<<"   "<<i<<"     "<<a<<"        "<<b<<"        "<<c<<"        "<<d<<"     "<<win1<<"       "<<win2<<endl;
        }
        
        else if((i>9)&&(i<100)){
        cout<<"  "<<i<<"     "<<a<<"        "<<b<<"        "<<c<<"        "<<d<<"     "<<win1<<"       "<<win2<<endl;        
        }
        
        else if(i==100){        
        cout<<" "<<i<<"     "<<a<<"        "<<b<<"        "<<c<<"        "<<d<<"     "<<win1<<"       "<<win2<<endl;
        }
        
        }
        
        ratio=(count2*1.0/count1); //Win ratio of switch over stay
        
        cout<<endl;
        cout<<"   "<<count1<<" wins if stay with the first choice"<<endl;
        cout<<"   "<<count2<<" wins if switch to the second choice"<<endl;
        cout<<endl;
        cout.precision(2);
        cout<<"Win ratio of switch over stay: "<<ratio;

return 0;        

}



