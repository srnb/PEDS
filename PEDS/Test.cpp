/*
 * Test.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: sriharsha
 */
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int function (int argc, char* argv[])
	{
		 //const string traceFileName = argv[1];

		  long time, hashid, size,count;
		  ifstream infile;
		  infile.open("File.txt");

		  while (infile >> time >> hashid >> size){
			count;
		    cout << "time: " << time << " hashid: " << hashid << " size " << size <<endl ;
		  }
		  infile.close();
          cout << "Number of requests" << count;
		  return 0;



}

