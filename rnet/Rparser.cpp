
#include "Rparser.h"
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"
#include "ResistorList.h"


using namespace std;

int argumentCheck(stringstream& myStream) {
    
    //if the stream fails, it means error is present
    if (myStream.fail()) {
        
        //if the stream reaches the end,
        // it means that there aren't few arguments
        // as it didn't stop in between
        if (myStream.eof()) {
            
            return 2;
            
        }//if it stops in between,
        //then it means there is a type mismatch
        // and invalid argument
        else {
            
            return 1;
            
        }
    }
    return 0;
    
}


void insertR(stringstream& lineStream,stringstream& lineStream2,
             string resistorID,string temp,
             double resistorVal,int nodeid1,int nodeid2,NodeList& list){
    
    //parse an insertR command
    
    lineStream >> resistorID;
    
    lineStream >> resistorVal;
    
    lineStream >> nodeid1;
    
    lineStream >> nodeid2;
    
    if (resistorVal < 0) { //if resistance is negative,
        //print error
        cout << "Error: negative resistance" << endl;
    }//if any of the nodes are out of bounds, print error
                 //checks for too few arguments
    else if (argumentCheck(lineStream) == 2) {
        
        cout << "Error: too few arguments" << endl;
    }
    //checks for too many with peek() and seeing if
    //any string is read after any space or tab
    else if (lineStream.peek() <= ' ' && lineStream >> temp) {
        cout << "Error: too many arguments" << endl;
    }
    //checks to see if there is a type mismatch at the end
    // or in the middle of the string
    else if (lineStream.peek() > ' ' ||
             argumentCheck(lineStream) == 1) {
        
        cout << "Error: invalid argument" << endl;
    }
    
    else {// if all errors are checked print it out
            
        int endpoints[2] = {nodeid1,nodeid2};
        
        //creates or checks if node exists
        
        Node* node1 = list.findOrInsertNode(nodeid1);
        Node* node2 = list.findOrInsertNode(nodeid2);
 
        //checks to see if resistor already exists
        if(list.doesResistorExistInList(resistorID)){
           cout<<"Error: resistor "<<resistorID<<" already exists"<<endl;
        }
        //starts inserting resistors in respective nodes
        else{
        node1->getList().insertResistor(resistorID,resistorVal,endpoints);
        node2->getList().insertResistor(resistorID,resistorVal,endpoints);
        
        
        cout << "Inserted: resistor " << resistorID << " " <<
        setprecision(2) << fixed << resistorVal <<
        " " << "Ohms " << nodeid1 << " -> " << nodeid2 << endl;
            }
    }
            
       }
    

void modifyR(stringstream& lineStream, stringstream& lineStream2,
             string resistorID,double resistorVal,string temp,NodeList& list){
    
    int i;
    bool flag = true;
   
    lineStream >> resistorID;
    
    lineStream >> resistorVal;
    
    double old;
    
    //checks for negative resistor value
    if (resistorVal < 0) {
        cout << "Error: negative resistance" << endl;
    }//checks for few arguments
    else if (argumentCheck(lineStream) == 2) {
        
        cout << "Error: too few arguments" << endl;
    }//checks for too many arguments after space or tab
    else if (lineStream.peek() <= ' ' && lineStream >> temp) {
        cout << "Error: too many arguments" << endl;
    }                //checks for type mismatch at end or in the middle
    else if (lineStream.peek() > ' ' ||
             argumentCheck(lineStream) == 1) {
        
        cout << "Error: invalid argument" << endl;
    } else {
        
        //modifies resistor
        list.modifyResistorInList(resistorID,resistorVal);
                
        }
            
            }
    

void printR(stringstream& lineStream, string resistorID, string temp,NodeList& list){
    
    int i =0;
    bool flag = true;
    
    lineStream >> resistorID;
    //checks to see too few
    if (argumentCheck(lineStream) == 2) {
        
        cout << "Error: too few arguments" << endl;
        
    }
    
    
    else if (lineStream.peek() <= ' ' && lineStream >> temp) {
        cout << "Error: too many arguments" << endl;
    }
    //no peek is needed since it's a string
    else if (argumentCheck(lineStream) == 1) {
        
        cout << "Error: invalid argument" << endl;
    }
    else {
       
        //prints out the resistor in given list
       list.printResistorInList(resistorID);
       
    }
    
}

void printNode(stringstream& lineStream, stringstream& lineStream2,
               int nodeid1,int nodeid2, string temp, char c,NodeList& list){
    
    lineStream >> temp; //this is for reading the string "all"
    lineStream2 >> nodeid1; //this is for reading integers
    
    
                //checks to see if argument is inputted
    if (argumentCheck(lineStream) == 2) {
        
        cout << "Error: too few arguments" << endl;
    } else if (!lineStream2.fail()) { //if integer value is inputted
        // eg: 234 or 253rxn
        
        c = lineStream2.peek(); // puts peek into a char type
        //and uses it to see if
        //there is anything after int is read
        //if there is, it is an error
        if (c > ' ') {
            
            cout << "Error: invalid argument" << endl;
            
        }//checks to see if there is a space and string afterwards
        else if (c == ' ' && lineStream >> temp) {
            cout << "Error: too many arguments" << endl;
        } else {
            
            //prints out specified node
            cout << "Print: " << endl;
            list.printNodeInList(nodeid1);
            
            }
                
            
        
        
    } else if (!lineStream.fail()) { //if any string is inputted
        
                if (temp == "all" && lineStream.eof()) { //if its "all" and
                    //end of file
                    
                    //prints out all the nodes
                    cout << "Print: " << endl;
                    list.printAllNodesInList();
                    
                } else if (temp != "all") {

                    cout << "Error: invalid argument" << endl;
                } else {
                    cout << "Error: too many arguments" << endl;
                }
            }
            
         else if (temp != "all") {
            
            cout << "Error: invalid argument" << endl;
        } else {
            cout << "Error: too many arguments" << endl;
        }
    }
    


void deleteR(stringstream& lineStream, string resistorID, string temp,NodeList& list){
    
    lineStream >> resistorID;
    
    
    //same code from printR
    if (argumentCheck(lineStream) == 2) {
        
        cout << "Error: too few arguments" << endl;
    } else if (resistorID == "all" && lineStream.eof()) {
        
        
        list.deleteAllResistorsInList(); //deletes all resistors in list
        list.deleteEmptyNode(); //deletes all nodes
        cout<<"Deleted: all resistors"<<endl;
        
    } else if (lineStream.peek() <= ' ' && lineStream >> temp) {
        cout << "Error: too many arguments" << endl;
    } else if (argumentCheck(lineStream) == 1) {
        
        cout << "Error: invalid argument" << endl;
    } else {
        
        //deletes a specific resistor
        list.deleteResistorInList(resistorID);
        //deletes specific node in list if no other resistors are connected
        list.deleteAnEmptyNode();
        
    }
}

void setV(stringstream& myStream, NodeList& list){
    
    double voltage;
    int nodeid;
    
    myStream>>nodeid;
    myStream >> voltage;
    //sets voltage
    list.setV(nodeid,voltage);
    
    return;
    
}

void unsetV(stringstream& myStream, NodeList& list){
    
    int nodeid;
    
    myStream>>nodeid;
     
    list.unsetV(nodeid); //unsets the node
    
    return;
    
}

void solve(NodeList& list){
    
    list.solve();
}

void parser(NodeList& list){
    
    string line;
    string resistorID;
    double resistorVal;
    int nodeid1 = 1;
    int nodeid2 = 0;
    char c; //declaration for the peek() function

    
    
    
    
    cout << "> ";
    
    getline(cin, line); //Get a line from standard input
    
    while (!cin.eof()) {
        //Put the line in a stringstream for parsing
        //Making a new stringstream for each line so flags
        //etc etc are in a known state
        
        string command;
        string temp;
        stringstream lineStream(line);
        stringstream lineStream2(line); //I created another stream for
        // reading int in printNode
        
        
        lineStream >> command;
        lineStream2 >> command;
        
        
        
        if (command == "insertR") {
            
            insertR(lineStream,lineStream2,resistorID,temp,resistorVal,
                    nodeid1,nodeid2,list);
            
        } else if (command == "modifyR") {
            
            modifyR(lineStream, lineStream2, resistorID, resistorVal,temp,list);
            
        } else if (command == "printR") {
            
            printR(lineStream,resistorID,temp,list);
            
            
            
        } else if (command == "printNode") {
            
            printNode(lineStream, lineStream2, nodeid1, nodeid2, temp, c,list);
            
        } else if (command == "deleteR") {
            
            deleteR(lineStream,resistorID,temp,list);
            
        } else if(command == "setV"){
            
            setV(lineStream,list);
            
        } else if(command == "unsetV"){
            
            unsetV(lineStream,list);
            
        } else if(command == "solve"){
            
            solve(list);
        } 
        
        else {
            
            cout << "Error: invalid command" << endl;
        }
        
        cout << "> ";
        
        getline(cin, line); //gets the next line and loops it
        // puts that line into lineStream in the loop
        
    }
    
    
    
    
}