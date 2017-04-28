/* 
 * File:   Resistor.h
 * Author: hossa172
 *
 * Created on November 10, 2016, 2:58 AM
 */

#ifndef RESISTOR_H
#define RESISTOR_H

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

class Resistor
{
private:
    string name;
    double resistance; //resistance
     // string holding the label
    int endpointNodeIDs[2]; //IDs of nodes attached to it
    Resistor* next;
    
public:
    Resistor(string name_,double resistance_,int endpoints_[2]);
    
    //endpoints_ holds the node indices to which this resistor connects
    
    string getName(); //returns the name
    double getResistance() const; //returns the resistance
    
    void setResistance(double resistance_);
  
    void print();
    
    int getEndpoint(int x) const;
    
    Resistor* getNext() const;
    
    void setNext(Resistor* next_);
    
    ~Resistor();
    
};


#endif /* RESISTOR_H */