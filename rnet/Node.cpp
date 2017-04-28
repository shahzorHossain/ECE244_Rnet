
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Node.h"
#include "Resistor.h"

Node::Node(){
    data = 0;
    next = NULL;
    voltage = 0;
    set = false;
}

Node::Node(int d){
    data = d;
    next = NULL;
}

Node::Node(int d, Node* n){
    data = d;
    next = n;
}
int Node::getData() const{
    return data;
}

void Node::setData(int _d){
    data = _d;
}

Node* Node::getNext() const{
    return next;
}

void Node::setNext(Node* _n){
    next = _n;
}

ResistorList& Node::getList(){
    return resistorList;
}

void Node::setV(double _voltage){
    set = true;
    voltage = _voltage;
}

void Node::unsetVoltage(){
    set = false;
}

bool Node::getSet(){
    return set;
}

void Node::setVoltage(double volt){
    voltage = volt;
}

double Node::getVoltage(){
    return voltage;
}

Node::~Node(){
   
}

