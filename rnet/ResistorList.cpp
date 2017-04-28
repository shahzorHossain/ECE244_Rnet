#include "ResistorList.h"

ResistorList::ResistorList(){
    head = NULL;
}

ResistorList::~ResistorList(){
    
    
}

void ResistorList::insertResistor(string name_,double resistance_,
        int endpoints_[2]){
     
    Resistor* r = new Resistor(name_,resistance_,endpoints_);
    Resistor* prev = NULL;
    Resistor* p = head;
    
    while(p!= NULL){
        prev = p;
        p=p->getNext();
    }
    //inserting now
    r->setNext(p);
    if(prev==NULL){ //head of the list
        head = r;
        
    }
    else{//inserts a resistor to the end of the list
    prev->setNext(r);
}
    
}
bool ResistorList::searchResistor(string s){
    for(Resistor* cur = head; cur!= NULL; cur =cur->getNext()){
        if(cur->getName() == s){
            return true;
        }
        
    }
    return false;
}
void ResistorList::deleteResistor(string s){
    Resistor* p = head;
    Resistor* prev = NULL;
    
    if(p == NULL){ //d is not in the list
        cout<<"Error: resistor "<<s<<" not found"<<endl;
        return;
        
    }
    while(p->getName() != s && p!= NULL){
        prev = p;
        p = p->getNext();
    }
    
    
    if(prev == NULL){ //p is the head of the list
        head = p->getNext();
    }
    else{
        prev->setNext(p->getNext());
    }
    
    delete p;
    return;
}
void ResistorList::deleteAllResistors(){
    
    Resistor* cur = head;
    Resistor* prev = NULL;
    
    if(cur == NULL){ //d is not in the list
        
        return;
        
    }
    while(cur!=NULL){
        prev = cur;
        cur = cur->getNext();
        delete prev;
        
    }
    
    
    return;
}

bool ResistorList::anyResistor(){
    //function to see if any resistor exists in a node
    
    Resistor* cur = head;
    if(cur == NULL){
        return false;
    }
    else{
        return true;
    }
}

void ResistorList::modifyResistor(string s,double resistance_){
    
    /*function to traverse through the resistors, and modify the specified 
     *resistor*/
    
    Resistor* p = head;
    
    for(p = head; p!=NULL; p=p->getNext()){
        if(p->getName() == s){
            if(p->getResistance() == resistance_){
                return;
            }
            
            p->setResistance(resistance_);
            return;
        }
        
    }
    
    
    return;
        
}

Resistor* ResistorList::getResistor(string s){
    
    //function to return a resistor of specified name
    
    for(Resistor* cur = head; cur!= NULL; cur =cur->getNext()){
        if(cur->getName() == s){
            return cur;
        }
        
    }
    return NULL;
}

int ResistorList::countResistors(int d){
    
    //function to return number of resistors in a node
    
    int counter = 0;
    Resistor* cur = head;
    if(cur = NULL){
        return 0;
    }
    for(cur = head; cur!= NULL; cur =cur->getNext()){
        
        counter++;
    }
    
    return counter;
}

void ResistorList::printResistors(){
    //function to print all resistors in a node
    for(Resistor* cur = head; cur!=NULL; cur = cur->getNext()){
        cout<<"  ";
        cur->print();
    }
    return;
}


Resistor* ResistorList::getHead(){
    //returns the head of the list
    return head;
}
