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
const long memorybound=10737418240;

std::map<long, RequestFreq> readAndConstructMap(string filename,long &count) {
	long time, hashid, size;
	ifstream infile;
		infile.open("cache.07.01.tr");
	std::map<long, RequestFreq> freqmap;
	while (infile >> time >> hashid >> size) {
		if (freqmap.find(hashid) != freqmap.end()) {
			/*	std::list<long> reqlist1=freqmap[hashid].getReqlist();
			    Request req1=Request(time,hashid,size);
			 	std::list<long> reqlist2;
			 	reqlist2.push_back(time);
			 	reqlist1.merge(reqlist2);
			 	freqmap[hashid].setReqlist(reqlist1);*/
			freqmap[hashid].setFreq(freqmap[hashid].getFreq() + 1);
		} else {
			/*	std::list<long> reqlist;
				reqlist.push_back(time);*/
			RequestFreq freqreq = RequestFreq();
			freqreq.setFreq(1);
			//	freqreq.setReqlist(reqlist);
			freqreq.setSize(size);
			freqreq.setHashid(hashid);
			//std::list<long> templist=freqreq.getReqlist();
			freqmap.insert(std::make_pair(hashid, freqreq));
		}
		count++;
	}
	infile.close();
	return freqmap;
}

multimap<long, RequestFreq> constructOrderdMap(
		std::map<long, RequestFreq>& freqmap,long count) {
	map<long, RequestFreq>::iterator it;
	multimap<long, RequestFreq> orderdmap;
	long max, min, mean = 0;
	it = freqmap.begin();
	max = ((RequestFreq) (it->second)).getSize();
	min = ((RequestFreq) (it->second)).getSize();
	;
	for (it = freqmap.begin(); it != freqmap.end(); it++) {
		RequestFreq frq = it->second;
		//	std::list<long> itreq;
		//	itreq=frq.getReqlist();
		if (frq.getSize() > max)
			max = frq.getSize();
		else if (frq.getSize() < min)
			min = frq.getSize();

		mean = mean + frq.getSize();
		orderdmap.insert(std::make_pair(frq.getFreq(), it->second));
	}
	cout<<"Min:: "<<min<<endl;
	cout<<"Max:: "<<max<<endl;
	cout<<"Mean:: "<<mean/count<<endl;
	return orderdmap;
}

void findHitRatio( long count,
		multimap<long, RequestFreq>& orderdmap) {
	multimap<long, RequestFreq>::reverse_iterator orderitr;
	ofstream outfile;
	outfile.open("outputFile.txt");
	long sumofRequests = 0;
	long initailMemory = 0;
	outfile << "HASH CODE::" << "   " << "No Occurrence" << "  " << "Size \n";
	for (orderitr = orderdmap.rbegin(); orderitr != orderdmap.rend();
			orderitr++) {
		RequestFreq frq = orderitr->second;
		if (initailMemory < memorybound) {
			sumofRequests += frq.getFreq();
			initailMemory += frq.getSize();
		}
		outfile << " " << frq.getHashid() << " :" << frq.getFreq() << ": "
				<< frq.getSize() << "\n";
	}
	outfile << " Done with orderd map processing \n";
	cout << "Sum of Requests:: " << sumofRequests << endl;
	float sum_no;
	sum_no = (float) (sumofRequests) / count;
	cout << "sum of request/no of lines(Total number of requests)-Hit Ration:: " << sum_no
			<< endl;
	orderitr=orderdmap.rbegin();

		cout <<"Most popular object: with freq ::  "<<((RequestFreq)orderitr->second).getHashid()
				<<"::"<<((RequestFreq)orderitr->second).getFreq()<<endl;
}

void miscellaneousDetails(long count,
		const std::map<long, RequestFreq>& freqmap) {
	cout << "Number of requests: " << count << endl;
	cout << "Miscellaneous details :: map size is :" << freqmap.size();
}

int main (int argc, char* argv[])
{
	//const string traceFileName = argv[1];


	ofstream logfile;
	long count=0;
	logfile.open("LogFile.txt");
    string filename="cache.07.01.tr";

	logfile<<"Start of processing.. \n";
	std::map<long, RequestFreq> freqmap = readAndConstructMap(filename,count);
	logfile<<" Closing the file\n";
	multimap<long, RequestFreq> orderdmap = constructOrderdMap(freqmap,count);
	logfile<<" Done with map processing \n";
	findHitRatio(count, orderdmap);
	miscellaneousDetails(count, freqmap);
	return 0;

}


