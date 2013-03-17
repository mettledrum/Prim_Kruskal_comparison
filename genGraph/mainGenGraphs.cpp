//Creates external files to be read by Kruskal and Prim algorithms
// for the comparison of running times b/w dense and sparse graphs.

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "genGraphFunctions.h"

int main(int argc, char** argv)
{

   //error checking for files and correct a.out
    //entry
    if(argc!=3)
    {
        //enter the required command line argument format
        std::cerr<<"Not enough a.out information.\n"
                "Format is: \".\\a.out sparse_graph_name dense_graph_name\n\"";
        return EXIT_FAILURE;
    }

    std::ofstream outfileSparse(argv[1], std::fstream::out);
    if(!outfileSparse)
    {
        //creates or just opens?
        std::cout<<"Could not open output file Sparse.\n";
        return EXIT_FAILURE;
    }

    greeting();

    int vertNumber;
    std::cout << "Please give the # of vertices for your graph to have: ";
    std::cin >> vertNumber;

    makeSparseGraph(outfileSparse, vertNumber);

    outfileSparse.clear();
    outfileSparse.close();

    //---------------------next graph-------------------------------------------

    std::ofstream outfileDense(argv[2], std::fstream::out);
    if(!outfileDense)
    {
        //creates or just opens?
        std::cout<<"Could not open output file Dense.\n";
        return EXIT_FAILURE;
    }

    makeDenseGraph(outfileDense, vertNumber);
    outfileDense.close();
    

    return EXIT_SUCCESS;
}

