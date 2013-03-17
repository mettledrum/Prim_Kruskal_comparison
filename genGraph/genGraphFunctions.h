/* 
 * File:   genGraphFunctions.h
 * Author: mettledrum
 *
 * Created on March 17, 2012, 2:55 PM
 */

#ifndef GENGRAPHFUNCTIONS_H
#define	GENGRAPHFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void greeting();

void makeSparseGraph(std::ofstream&, const int&);

void makeDenseGraph(std::ofstream&, const int&);

#endif	/* GENGRAPHFUNCTIONS_H */

