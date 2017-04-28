#include "Resistor.h"

Resistor::Resistor(string name_, double resistance_, int endpoints_[])
{
    
    name = name_;
    resistance = resistance_;
    endpointNodeIDs[0] = endpoints_[0];
    endpointNodeIDs[1] = endpoints_[1];
    
}
string Resistor::getName(){
    return name;
}

double Resistor::getResistance() const{
    return resistance;
}

void Resistor::setResistance(double resistance_){
    resistance = resistance_;
    
}

int Resistor::getEndpoint(int x) const{
    return endpointNodeIDs[x];
}

void Resistor::print(){
            
    cout << setfill(' ') << setw(20);
    cout << left << name;
    cout << ' ' << setfill(' ') << setw(8)<< right <<resistance  << ' '
            << "Ohms ";
    cout << endpointNodeIDs[0] << "->" << endpointNodeIDs[1] << endl;
}

Resistor* Resistor::getNext() const{
    return next;
}

void Resistor::setNext(Resistor* next_){
    next = next_;
}

Resistor::~Resistor(){
   
}
