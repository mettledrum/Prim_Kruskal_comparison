//

#include <limits>

#include "unionFunctions.h"

void greeting()
{
    std::cout << "This program calculates the MCST based on Prim's algorithm.\n"
            "The nodes will be assigned \"parent\" values and weights from the\n"
            "parent values.  A MCST can be traced from the starting node to any\n"
            "other node in the connected graph whose edges are typed in the\n"
            "\"edges\" file.  Please press any key and then <ENTER> to continue.\n";

    char c;
    std::cin >> c;
    std::cout << std::endl;
}

void describeMatrix()
{
    std::cout << "Here is the adjacency matrix based on the \"edges\" infile:\n";
}

//add some error checking
int getStartNode(const int& vn)
{
    std::cout << "Please enter the node number you want the MCST to begin on\n"
            "followed by <ENTER>.  It must be larger or equal to 1, and less than\n"
            "or equal to " << vn << ".\n";

    int tempInt;
    std::cin >> tempInt;
    return tempInt;
}

simpVert extract_min(std::vector<simpVert>& sv)
{
    //make a temp simpVert with awfully large numbers
    simpVert theMin;
    theMin.key=std::numeric_limits<int>::max();
    theMin.extracted=false;
    theMin.label=std::numeric_limits<int>::max();
    theMin.parent=std::numeric_limits<int>::max();

    for(int i=0; i<sv.size(); ++i)
    {
        //<= is NECESSARY because you don't want SEG FAULT from the Min!
        if( (sv[i].key<=theMin.key) && (sv[i].extracted==false) )
            theMin=sv[i];
    }
    return theMin;
}

void displayPrim(const std::vector<simpVert>& sv)
{
    //show source node
    for(int i=0; i<sv.size(); ++i)
    {
        if(sv[i].key==0)
            std::cout << "vertex: " << sv[i].label << " is SOURCE";
        else
            std::cout << "vertex: " << sv[i].label << " has parent: " << sv[i].parent << ", and key: " << sv[i].key;

        std::cout << std::endl;
    }


}

void describePQ()
{
    std::cout << "Here is the priority queue of vertices to feed to the algorithm.\n"
            "The first value matches the starting node you entered, and the rest\n"
            "don't matter because they are all infinity:\n";
}

void describePrim()
{
    std::cout << "Here is the output of vertices with their parents and keys:\n";
}

void describePrimLoops()
{
    std::cout << "Here are the debugging outputs I used to find my problems:\n";
}

size_t getMatrixDims(std::ifstream& inny)
{
    size_t tempNumb;
    inny >> tempNumb;
    return tempNumb;
}
