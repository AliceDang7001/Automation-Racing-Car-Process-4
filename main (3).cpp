//===Alice Dang===//
#include "mbed.h"

//===Car Pin===//
PwmOut A(D6);
PwmOut B(D9);
PwmOut C(D10);
PwmOut D(D5);
PwmOut CraneServo(A6);
AnalogIn OptoSorter(A3);
PwmOut SorterServo(A2);
DigitalIn Startbutton(D2);


//====Running Function====//
void Forward(float time1){
    A = 1; B=0; C=1; D=0;
    //wait(time1);
    //A = 0; B = 0; C=0; D=0;
    }
void Backward(float time2){
    A = 0; B=1; C=0; D=1;
    //wait(time2);
    //A = 0; B = 0; C=0; D=0;
    }
void Right(float time3){
    A = 0; B=1; C=1; D=0;
    //wait(time3);
    //A = 0; B = 0; C=0; D=0;
    }
void Left(float time4){
    A = 1; B=0; C=0; D=1;
    //wait(time4);
    //A = 0; B = 0; C=0; D=0;
    }
    
//====Period====//    
void init(){
    A.period(0.01);
    B.period(0.01);
    C.period(0.01);
    D.period (0.01);
 }   
 
//===Main Code===//
int main()
{
    while( Startbutton == 0){ 
      wait(1);
    }
    
    //===Car Movement===//
    init();
    Forward(1);

    
    //===Object Interaction===//
    CraneServo.pulsewidth(.00125);

    
    //===Sorting Procedures===//  
        while(1){    
            float analog = OptoSorter * 3.3;    
        
            if(analog > 2.75){
            SorterServo.pulsewidth(0.0007); //Black Block 
            wait(0.05);
            SorterServo.pulsewidth(0.00125); 
            wait(0.05);
            }
    
            if(analog <= 0.75){ //White Block
        
            SorterServo.pulsewidth(0.00125); 
            wait(0.05);
            SorterServo.pulsewidth(0.0007); 
            wait(0.05);
            
            }
    
            if(analog >= 0.85 && analog <= 2.6) { 
            
            SorterServo.pulsewidth(0.0007); 
            wait(0.05);
            }
        }
    
    
    
}
