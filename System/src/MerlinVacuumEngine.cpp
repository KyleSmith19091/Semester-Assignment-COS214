#include <iostream>
#include "../include/MerlinVacuumEngine.h"
#include <random>
#include <unistd.h>

using namespace std;

void MerlinVacuumEngine::checkTemperature(){

int temp = rand()%(100)+20;
if(temp>=90) 
{
cout<<"VACUUM MERLIN ENGINE IS TOO HOT PLEASE ALLOW COOL DOWN"<<endl;
usleep(10000000);
}
else
cout<<"The Vacuum Merlin Engine has a temperature of: "<<temp<<" degrees Celcius, which is still below the dangerous temperature of 90 degrees Celcius"<<endl;
}

void MerlinVacuumEngine::checkOil(){
int temp = rand()%(100)+1;
if(temp<=20)
{
    if(temp<=10)
    cout<<"OIL LEAK DETECTED IN THE LEFT MOST CONTAINER, PLEASE WAIT FOR A PROFESSIONAL TO ARIVE"<<endl;
    else
    cout<<"OIL LEAK DETECTED IN THE RIGHT MOST CONTAINER, PLEASE WAIT FOR A PROFESSIONAL TO ARIVE"<<endl;
usleep(1000000);
}
else
cout<<"Both oil containers have been filled up"<<endl;
}

void MerlinVacuumEngine::startEngine(){
cout<<"The Vacuum Merlin Engine started up successfully"<<endl;
}
