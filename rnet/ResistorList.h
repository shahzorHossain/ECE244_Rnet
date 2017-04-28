/* 
 * File:   ResistorList.h
 * Author: hossa172
 *
 * Created on November 10, 2016, 2:58 AM
 */
#ifndef RESISTORLIST_H
#define RESISTORLIST_H


#include <string>
#include "Resistor.h"

class ResistorList{

private:
    Resistor *head;
    
    
public:
    ResistorList();
    ~ResistorList();
    void insertResistor(string s,double resistance_,int endpoints_[2]);
    bool searchResistor(string s);
    void deleteResistor(string s);
    void deleteAllResistors();
    void modifyResistor(string s,double resistance_);
    int countResistors(int d);
    bool anyResistor();
    void printResistors();
    Resistor* getResistor(string s);
    Resistor* getHead();
    
};



#endif /* RESISTORLIST_H */