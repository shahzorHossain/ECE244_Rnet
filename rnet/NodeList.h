/* 
 * File:   NodeList.h
 * Author: hossa172
 *
 * Created on November 10, 2016, 2:58 AM
 */

#ifndef NODELIST_H
#define NODELIST_H
#include <string>
#include "Node.h"
#define MIN_ITERATION_CHANGE 0.0001;



class NodeList{
private: 
    Node * head;
    
public:
    NodeList();
    ~NodeList();
    Node* findOrInsertNode(int d);
    void deleteEmptyNode();
    bool doesResistorExistInList(string s);
    void deleteResistorInList(string s);
    void deleteAllResistorsInList();
    void modifyResistorInList(string s,double resistance_);
    void printResistorInList(string s);
    void printNodeInList(int d);
    void setV(int node, double volt);
    void unsetV(int node);
    void printAllNodesInList();
    void deleteAnEmptyNode();
    void solve();
    void printVoltages();
};


#endif /* NODELIST_H */