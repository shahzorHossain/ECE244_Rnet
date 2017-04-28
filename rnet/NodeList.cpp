#include "NodeList.h"
#include "Node.h"
#include "Resistor.h"
#include <iostream>
#include <cmath>

NodeList::NodeList() {
    head = NULL;
}

NodeList::~NodeList() {
    Node* p;
    while (head != NULL) {
        p = head;
        head = p->getNext();
        delete p;
    }

}

void NodeList::setV(int node, double volt) {
    //traverses through all the nodes and sets the specific node to volt
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getData() == node) {
            cur->setV(volt);
            cout << "Set: node " << node << " to " << volt << " Volts" << endl;
            return;
        }
    }
    cout << "Error: node " << node << " not found" << endl;
    return;
}

void NodeList::unsetV(int node) {
    //traverses through all the nodes and unsets the specific node
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getData() == node) {
            cur->unsetVoltage();
            cout << "Unset: the solver will determine the voltage of node " <<
                    node << endl;
            return;
        }
    }
    cout << "Error: node " << node << " not found" << endl;
    return;
}

Node* NodeList::findOrInsertNode(int d) {

    //searches through list
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getData() == d) {
            return cur;
        }

    }
    //Node not in list so insert new node


    Node* n = new Node(d);
    Node* prev = NULL;
    Node* p = head;

    while (p != NULL && p->getData() < d) {
        prev = p;
        p = p->getNext();
    }
    //inserting now
    n->setNext(p);
    if (prev == NULL) { //head of the list
        head = n;
        return n;
    } else {
        prev->setNext(n);
        return n;
    }


}

bool NodeList::doesResistorExistInList(string s) {
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {

        if (cur->getList().searchResistor(s)) {

            return true;
        }
    }
    return false;
}


void NodeList::deleteResistorInList(string s) {

    int counter = 0;


    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getList().searchResistor(s)) {
            cur->getList().deleteResistor(s);
            counter++;
        }
    }
    //need a counter to ensure resistor is deleted in both the nodes
    if (counter >= 2) {
        cout << "Deleted: resistor " << s << endl;
        return;
    } else {
        cout << "Resistor name not found" << endl;
        return;
    }
}

void NodeList::deleteAllResistorsInList() {
    //deletes all the resistors in the node list
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {

        cur->getList().deleteAllResistors();

    }

    return;
}

void NodeList::modifyResistorInList(string s, double resistance_) {

    int counter = 0;
    double oldRes = 0;

    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getList().searchResistor(s)) {
            oldRes = cur->getList().getResistor(s)->getResistance();
            cur->getList().modifyResistor(s, resistance_);
            counter++;


        }
        /*need a counter to ensure the resistance is being modified in both
         *resistors*/
        
        if (counter >= 2) {
            
            cout << "Modified: resistor " << s << " from " << oldRes <<
                    " Ohms " << " to " << setprecision(2) << fixed <<
                    resistance_ << " Ohms" << endl;
            return;
        }
    }

    cout << "Error: resistor " << s << " not found" << endl;
    return;
}

void NodeList::printResistorInList(string s) {

    //prints a resistor in the node list
    
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getList().searchResistor(s)) {

            Resistor* r = cur->getList().getResistor(s);
            if (r != NULL) {
                cout << "Print:" << endl;
                r->print();
                return;
            }
        }
    }
    cout << "Error: resistor " << s << " not found" << endl;
    return;
}

void NodeList::printNodeInList(int d) {
    
    // prints a node filled with resistors
    int counter = 0;//need a counter to count number of resistors in node
    for (Node* cur = head; cur != NULL; cur = cur ->getNext()) {
        if (cur->getData() == d) {

            counter = cur->getList().countResistors(d);
            cout << "Connections at node " << d << ": " << counter <<
                    " resistor(s)" << endl;
            cur->getList().printResistors();

            return;
        }
    }
    return;
}

void NodeList::printAllNodesInList() {
    int counter = 0;//need a counter to check if any resistors exist in node
    Node* cur = head;
    if (cur == NULL) {
        return;
    }
    for (cur = head; cur != NULL; cur = cur ->getNext()) {

        counter = cur->getList().countResistors(cur->getData());
        if (counter > 0) {
            cout << "Connections at node " << cur->getData() << ": " <<
                    counter << " resistor(s)" << endl;
            cur->getList().printResistors();
        }

    }
    return;

}

void NodeList::deleteEmptyNode() {

    //function to delete all empty nodes
    Node* cur = head;
    Node* temp;

    while (cur != NULL) {
        temp = cur;
        cur = cur->getNext();
        delete temp;
    }
    head = NULL;

    return;

}

void NodeList::deleteAnEmptyNode() {

    //function to delete one empty node
    
    Node* cur = head;
    Node* prev = NULL;

    for (cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getList().anyResistor() == false) {
            if (prev == NULL) {
                head = NULL;

            } else {
                prev->setNext(cur->getNext());
            }
            delete cur;
            return;
        }

        prev = cur;
    }
}

void NodeList::solve() {

    double minIterationChange = MIN_ITERATION_CHANGE;
    double resistanceVal = 0;
    double currentVal = 0;
    bool flag = false;

    //sets all the unset nodes voltages to 0 
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getSet() == false) {
            cur->setVoltage(0);


        }

    }

    //starts traversing through node list
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        if (cur->getSet() == true) {
            flag = true;

        }
    }
    //if flag stays false, that means no nodes had voltages set

    if (flag == false) {
        cout << "Error: no nodes have their voltages set" << endl;
        return;
    }

    int count = 0;
    //counter to count enough iterations to ensure that the difference will
    //be minimum

    while (count < 200) {
        for (Node* curr = head; curr != NULL; curr = curr->getNext()) {


            if (curr->getSet() == false) { //if a node has set = false,enter

                /*starts traversing through resistor list, add the
                 *resistance of each resistor together*/

                for (Resistor* res = curr->getList().getHead(); res != NULL;
                        res = res->getNext()) {
                    resistanceVal = ((1 / (res->getResistance())) + resistanceVal);

                    /*if one of the endpoints matches the nodeID, take the
                     *voltage of the other endpoint and divide by respective
                     *resistance*/
                    
                    if (res->getEndpoint(0) == curr->getData()) {
                        Node* findNode = findOrInsertNode(res->getEndpoint(1));
                        currentVal = (currentVal + ((findNode->getVoltage()) /
                                (res->getResistance())));

                    }
                    else if (res->getEndpoint(1) == curr->getData()) {
                        Node* findNode = findOrInsertNode(res->getEndpoint(0));
                        currentVal = (currentVal + ((findNode->getVoltage()) /
                                (res->getResistance())));

                    }

                }

                //total Voltage at the node
                
                double totalVo = ((1 / resistanceVal) * currentVal);

                double delta = abs(totalVo - curr->getVoltage());

                curr->setVoltage(totalVo);

                /*if the delta becomes smaller than the iteration change,
                 *exit the loop since the voltage almost becomes constant*/
                
                /*delta != 0 since it's possible that after the first iteration
                 *the node has 0 voltage*/
                
                if ((delta < minIterationChange) && (delta != 0)) {
                    printVoltages();
                    
                    return;
                }

            }
            count++;
            //resets to 0 after each node iteration
            resistanceVal = 0;
            currentVal = 0;
        }
    }


}

void NodeList::printVoltages() {
    
    //function to traverse through all the nodes and print the voltages
    
    cout << "Solve: " << endl;
    for (Node* cur = head; cur != NULL; cur = cur->getNext()) {
        cout << "  Node " << cur->getData() << ": " << cur->getVoltage() 
                << " V" << endl;
    }
}