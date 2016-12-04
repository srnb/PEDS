/*
 * MapPrac.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: sriharsha
 */

#include <iostream>
#include <fstream>
#include <map>
#include "RequestFrequency.h"
using namespace std;

int main (int argc, char* argv[])
{
	//const string traceFileName = argv[1];

	long time, hashid, size,count=0;
	ofstream outfile;
	std::map<long,long> mymap;
	std::map<long,RequestFreq,PointComarator> freqmap;
	ifstream infile;
	infile.open("trace1.txt");
	cout <<"Intial value" <<count;
	while (infile >> time >> hashid >> size){
		/* if (mymap.find(hashid)!=mymap.end()) {
				cout<<"Found Duplicate: :" <<mymap.find(hashid)->first<< endl;
				mymap[hashid]++;
			}
			mymap.insert(std::make_pair(hashid,1));
			Request req=Request(time,hashid,size);*/

		if(freqmap.find(hashid)!=freqmap.end()){
			freqmap[hashid].setFreq(freqmap[hashid].getFreq()+1);

		}
		else{
			Request req=Request(time,hashid,size);
			std::list<Request> reqlist;
			reqlist.push_back(req);
			RequestFreq freqreq=RequestFreq();
			freqreq.setFreq(1);
			freqreq.setReqlist(reqlist);
			freqmap.insert(std::make_pair(hashid,freqreq));
		}
		//cout <<"HashID: "<< req.getHashId()<< endl;

		count++;
		//cout << "time: " << time << " hashid: " << hashid << " size " << size <<endl ;
	}
	infile.close();

	map<long,RequestFreq>::iterator it;
	outfile.open("ouputFile.txt");
	for (it=freqmap.begin();it!=freqmap.end();it++){
		cout <<"HASHCODE: " <<it->first;
		RequestFreq frq=it->second;
		cout<<" :"<<frq.getFreq()<<endl;
	}
	cout << "Number of requests: " << count << endl;
	cout <<"Map size is :" <<freqmap.size();
	return 0;



}


