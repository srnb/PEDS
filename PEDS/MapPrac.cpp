/*
 * MapPrac.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: sriharsha
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "RequestFrequency.h"
using namespace std;

int main (int argc, char* argv[])
{
	//const string traceFileName = argv[1];

	long time, hashid, size,count=0;
	ofstream outfile;
	std::map<long,long> mymap;
	std::map<long,RequestFreq> freqmap;
	ifstream infile;
	infile.open("trace1.txt");
	//cout <<"Intial value" <<count;
	while (infile >> time >> hashid >> size){
				if(freqmap.find(hashid)!=freqmap.end()){
			std::list<long> reqlist1=freqmap[hashid].getReqlist();
			Request req1=Request(time,hashid,size);
			std::list<long> reqlist2;
			reqlist2.push_back(time);
			reqlist1.merge(reqlist2);
			freqmap[hashid].setReqlist(reqlist1);
			freqmap[hashid].setFreq(freqmap[hashid].getFreq()+1);

		}
		else{
			//Request req=Request(time,hashid,size);
			std::list<long> reqlist;
			reqlist.push_back(time);
			RequestFreq freqreq= RequestFreq();
			freqreq.setFreq(1);
			freqreq.setReqlist(reqlist);
			freqreq.setSize(size);
			freqreq.setHashid(hashid);
			std::list<long> templist=freqreq.getReqlist();
              //cout<<"size of the list "<<templist.size();
			freqmap.insert(std::make_pair(hashid,freqreq));
		}
		count++;
	}
	infile.close();

	map<long,RequestFreq>::iterator it;
	multimap<long,RequestFreq> orderdmap;
	outfile.open("ouputFile.txt");
	for (it=freqmap.begin();it!=freqmap.end();it++){
		//cout <<"HASHCODE: " <<it->first;
		RequestFreq frq=it->second;
		//cout<<"FREQ :"<< frq.getFreq();
		std::list<long> itreq;
		itreq=frq.getReqlist();
		orderdmap.insert(std::make_pair(frq.getFreq(),it->second));
      	}
	multimap<long,RequestFreq>::iterator orderitr;
	for(orderitr=orderdmap.begin();orderitr!=orderdmap.end();orderitr++){
		RequestFreq frq=orderitr->second;
         cout<<"Freq:"<<frq.getFreq()<<"::Size"<<frq.getSize()<<": HASH CODE "<<frq.getHashid()<<endl;
	}

	cout << "Number of requests: " << count << endl;
	cout <<"Map size is :" <<freqmap.size();
	return 0;



}


