//

#include "genGraphFunctions.h"


void greeting()
{
    std::cout << "This program generates a sparse graph for argv[2], and a dense\n"
            "graph for argv[3] based on the number of vertices you are about to\n"
            "enter.  These output files can be used for the Prim and Kruskal\n"
            "algorithms to compare their running times and decide which algorithm\n"
            "works best for different graph types.\n\n";
}

void makeDenseGraph(std::ofstream& od, const int& number)
{
    od << number << '\n';

    //n^2 edges created
    for(int i=1; i<=number; ++i)
    {
        for(int j=1; j<=number; ++j)
        {
            //ensure they aren't the same
            if(i!=j)
                od << i << ' ' << j << ' ' << rand()%1000 <<'\n';
        }
    }
}

void makeSparseGraph(std::ofstream& os, const int& number)
{
    os << number << '\n';

    //ensure graph is connected
    for(int i=1; i<number; ++i)
        os << i << ' ' << i+1 << ' ' << rand()%1000 << '\n';

    //add some random values to sparse file
    std::srand(std::time(NULL));

    int randV1, randV2;
    for(int i=1; i<=number; ++i)
    {
        randV1 = rand()%number+1;
        randV2 = rand()%number+1;

        //ensure they aren't the same # b/c this
        // isn't a pseudo graph
        if(randV1!=randV2)
            os << randV1 << ' ' << randV2 << ' ' << rand()%1000 <<'\n';
    }
        
}

