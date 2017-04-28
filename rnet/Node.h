/* 
 * File:   Node.h
 * Author: hossa172
 *
 * Created on November 10, 2016, 2:57 AM
 */

#ifndef NODE_H
#define NODE_H
#include "ResistorList.h"

class Node
{
private:
    int data;
    Node *next;
    ResistorList resistorList;
    double voltage;
    bool set;
    
public:
    Node();
    
    Node(int d);
    
    Node(int d,Node* n);
    
    int getData() const;
    
    void setData(int _d);
    
    Node* getNext() const;
    
    void setNext(Node* _n);
    
    ResistorList& getList();
    
    void setV(double _voltage);
    
    void unsetVoltage();
    
    bool getSet();
    
    void setVoltage(double volt);
    
    double getVoltage();
    
    ~Node();
    
    
};



#endif /* NODE_H */