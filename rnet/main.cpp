
/* 
 * File:   main.cpp
 * Author: shahzorhossain
 *
 * Created on November 7, 2016, 9:35 PM
 */
#include <cstdlib>
#include "Rparser.h"




using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
     
    NodeList list;
    
    parser(list);

    list.deleteAllResistorsInList();
    list.deleteEmptyNode();
    return 0;
}