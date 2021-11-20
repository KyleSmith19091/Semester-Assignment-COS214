#include <iostream>
#include "../include/MerlinEngine.h"
#include <random>
#include <unistd.h>

using namespace std;

void MerlinEngine::checkTemperature(){

int temp = rand()%(80)+20;
if(temp>=80) 
{
cout<<"MERLIN ENGINE IS TOO HOT PLEASE ALLOW COOL DOWN"<<endl;
usleep(10000000);
}
else
cout<<"The Merlin Engine has a temperature of: "<<temp<<" degrees Celcius, which is still below the dangerous temperature of 80 degrees Celcius"<<endl;
}

void MerlinEngine::checkOil(){
int temp = rand()%(100)+1;
if(temp<=10)
{
cout<<"OIL LEAK DETECTED PLEASE WAIT FOR A PROFESSIONAL TO ARIVE"<<endl;
usleep(1000000);
}
else
cout<<"Oil is still full and cap is securely tightened"<<endl;
}

void MerlinEngine::startEngine(){
cout<<"The Merlin Engine started up successfully"<<endl;
}

Engine* MerlinEngine::clone(){
    return new MerlinEngine();
}