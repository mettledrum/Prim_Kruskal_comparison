Kruskal and Prim algos
======================

sparse and dense graph runtime comparisons in C++
-------------------------------------------------

by Andrew Hoyle

usage
-----
There are 3 directories here, each containing files that can be compiled with g++ *.cpp once you are in one of the 3 directories.  genGraphs is the program I used to make the infiles read by Prim and Kruskal programs.  When you run it, specify the names of the sparse graph infile and dense graph infile on the command line to be created, ie: “./a.out sparse dense”. After compiling Prim and Kruskal in their respective directories, run each of those programs, and on the command line, type the name and location of the infile to be used, ie “./a.out infile.”  Prim and Kruskal show an adjacency matrix of the graph from the infile before it is processed.  Prim also asks for a source node for you to enter before it gives the results. 

I “instrumented” Prim’s code so I could see when the loops were running, but have commented them out to clean up the output to the terminal.  At the end, each program states the runtime of the algorithm itself NOT COUNTING the prep time involved with populating the adjacency matrix and queues to hold the vertices’ weights.  (Populating the adjacency matrix takes a lot of time for the dense graph!)  The genGraphs program creates a dense graph by linking EVERY node to ALL others, so there are about n2 edges in this graph given random edge weights b/w 1 and 1000.  The sparse graph first makes sure all the nodes are connected and then adds random edges into the mix, so there are around 2n edges in the sparse graph.
results
-------
It has been noted that Prim runs much more quickly when you have a dense graph, especially when using a Fibonacci heap.  The running time is with Fibonacci is O(E+lgV).  My implementation of Prim did not use Fibonacci, so the running time is O(ElgV).  Kruskal’s has been reported to run better on sparse graphs, with a running time of O(ElgV).

It makes sense that you should use Prim for dense graphs because it adds to the MCST one vertex a time, whereas Kruskal’s adds one edge at a time.  The looping on the Kruskal algorithm is based on sifting through minimum edges’ weights, and for a dense graph, there are n2 to search through.  Prim’s algorithm looping, on the other hand, is based off of sorting through vertices, which is only n.

Prim’s is more difficult to implement because the queue of vertices’ weights has to be updated and re-organized if a shorter edge is found.

When testing these graphs’ running times, I created several edge infiles in which there were 5000 vertices because my smaller graphs of 50 or so vertices didn’t yield a noticeable time difference.  My runs of 5000 vertices REALLY highlighted the difference in running times between the two algorithms:
times in seconds
----------------
<table>
  <tr>
    <th>Kruskal</th><th>Prim</th><th>graph</th>
  </tr>
  <tr>
    <td>266.497</td><td>10.467</td><td>dense</td>
  </tr>
  <tr>
    <td>0.188</td><td>5.444</td><td>sparse</td>
  </tr>
</table>
I realized that the average of Kruskal dense graphs was so high because in addition to it having to look through an n2 bag of edges’ weights, my minimum sorting algorithm was a naïve bubble-sort instead of a heap!  This is a great example of how computing time can be wasted when not using the most efficient algorithms.
