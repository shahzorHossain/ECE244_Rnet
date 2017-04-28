/* 
 * File:   Rparser.h
 * Author: hossa172
 *
 * Created on November 10, 2016, 2:58 AM
 */

#ifndef RPARSER_H
#define RPARSER_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "NodeList.h"


using namespace std; 

int argumentCheck(stringstream& myStream);

void insertR(stringstream& lineStream,stringstream& lineStream2,
        string resistorID,string temp,
        double resistorVal,int nodeid1,int nodeid2,
        NodeList& list);

void modifyR(stringstream& lineStream, stringstream& lineStream2,
        string resistorID,double resistorVal,string temp,NodeList& list);

void printR(stringstream& lineStream, string resistorID, string temp,NodeList& list);

void printNode(stringstream& lineStream, stringstream& lineStream2,
        int nodeid1,int nodeid2,string temp, char c,NodeList& list);

void deleteR(stringstream& lineStream, string resistorID, string temp,NodeList& list);

void parser(NodeList& list);

void setV(stringstream& lineStream, NodeList& list);

void unsetV(stringstream& lineStream, NodeList& list);

void solve(NodeList& list);

#endif /* RPARSER_H */