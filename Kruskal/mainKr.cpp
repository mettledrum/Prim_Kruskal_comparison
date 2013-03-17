//Andrew Hoyle
//3/17/12

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>

#include <deque>
#include <queue>
#include <limits>
#include <vector>

#include "weightRC.h"
#include "vertex.h"
#include "Matrix.h"
#include "unionFunctions.h"

int main(int argc, char** argv)
{
//--------------------matrix of weights-----------------------------------------

   //error checking for files and correct a.out
    //entry
    if(argc!=2)
    {
        //enter the required command line argument format
        std::cerr<<"Not enough a.out information.\n"
                "Format is: \".\\a.out edges_file_name\n\"";
        return EXIT_FAILURE;
    }

    //ifstream instantiation and error checking
    std::ifstream infile(argv[1], std::ifstream::in);
    if(!infile)
    {
        std::cout<<"Could not open input file.\n";
        return EXIT_FAILURE;
    }

    greeting();

    //create the square adjacency matrices by looking
    // at first value in infile
    const size_t vertNumber=getMatrixDims(infile);

    //create matrix class to display weights
    Matrix<int> MyM(vertNumber, vertNumber);

    //reset the infile get pointer b/c getEdgesFromFile needs
    // pointer to be at the top of the infile
    infile.seekg(0);

    //populate matrix with edge weights
    MyM.getEdgesFromFile(infile);

    describeMatrix();

    //display adjacency matrix created by infile
    std::cout << MyM << std::endl;

//--------------------matrix of weights-----------------------------------------

//--------------------priority que of weights-----------------------------------

    std::deque<weightRC> theWeights;
    std::priority_queue<weightRC> theWeightsPQ;

    //inc prevents duplicates on uni-directional graph
    int inc=1;
    for(int i=0; i<vertNumber; ++i)
    {
        for(int j=inc; j<vertNumber; ++j)
        {
            if(MyM[i][j]!=std::numeric_limits<int>::max())
            {
                weightRC tempWRC;
                tempWRC.Vcol=j;
                tempWRC.Vrow=i;
                tempWRC.theWeight=MyM[i][j];

                theWeightsPQ.push(tempWRC);
            }
        }
        ++inc;
    }

    //reverse max PQ to min ordering first, deque
    // now holds the weights in non-increasing order
    while(!theWeightsPQ.empty())
    {
        theWeights.push_front(theWeightsPQ.top());
        theWeightsPQ.pop();
    }

    describePQ();

    for(int i=0; i<theWeights.size(); ++i)
        displayWeightsRC(theWeights[i]);

    std::cout << std::endl;

//--------------------priority que of weights-----------------------------------

//--------------------array of vertices using make_the_set----------------------

    vertex theVs[vertNumber];

    //populates array with 0-(vertNumber-1)
    //[idx] of array will be used to identify vertex
    for(int i=0; i<vertNumber; ++i)
    {
        vertex tempV;
        tempV.label=i+1;
        theVs[i]=tempV;
    }

    for(int i=0; i<vertNumber; ++i)
        make_the_set(theVs[i]);
    
//--------------------array of vertices using make_the_set----------------------

//-----------------------run Kruskal's Algorithm--------------------------------

    std::vector<weightRC> A;

    double beginTime = clock();

    while(!theWeights.empty())
    {
        vertex u, v;
        u = theVs[theWeights.front().Vcol];
        v = theVs[theWeights.front().Vrow];

        if( find_the_set(u) != find_the_set(v) )
        {
            A.push_back(theWeights.front());
            unionizer(u, v);
        }

        theWeights.pop_front();
    }

    double endTime = clock();

    describeKruskal();

    for(int i=0; i<A.size(); ++i)
        std::cout << "(" << A[i].Vrow+1 << ", " << A[i].Vcol+1 << ") " << A[i].theWeight << std::endl;

//-----------------------run Kruskal's Algorithm--------------------------------

    //report timing
    std::cout <<"\nThe running time was: " << (endTime-beginTime)/CLOCKS_PER_SEC;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

