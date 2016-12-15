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

std::map<long, RequestFreq> readAndConstructMap(const char* filename,long &count) {
	long time, hashid, size;
	ifstream infile;
		infile.open(filename);
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
	outfile.open("outputFile1.txt");
	long sumofRequests = 0;
	long initailMemory = 0;
	outfile << "HASH CODE" << " " << "Occurrence" << " " << "Size\n";
	for (orderitr = orderdmap.rbegin(); orderitr != orderdmap.rend();
			orderitr++) {
		RequestFreq frq = orderitr->second;
		if (initailMemory < memorybound) {
			sumofRequests += frq.getFreq();
			initailMemory += frq.getSize();
		}
		outfile << "" << frq.getHashid() << " " << frq.getFreq() << " "
				<< frq.getSize()<<"\n";
	}
//	outfile << " Done with orderd map processing \n";
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
     int i;
	cout<<"Choose Options: 1.Calculating data for popularity and other graphs  2.Construct Data for Plotting \n";
	cin>>i;
switch(i){
case 1: {
	 // cout<<"Value is "<<i;
	  ifstream infile1, infile2,infile3,infile4,infile5,infile6,infile7;
	  string str,str1;
	  long hashid,freq,size,hashid1,freq1,size1,hashid2,freq2,size2,hashid3,freq3,size3,hashid4,freq4,size4,hashid5,freq5,size5,
	  hashid6,freq6,size6;
	  map<long,long> map1;
	  map<long,long> map2;
	  map<long, long>::iterator it;
	  map<long, long>::iterator it1;
	/*Have to format and move to separate file to read the files-Generalize*/
	  infile1.open("cache.07.01.tr");
	  infile2.open("cache.07.02.tr");
	  infile3.open("cache.07.03.tr");
	  infile4.open("cache.07.04.tr");
	  infile5.open("cache.07.05.tr");
	  infile6.open("cache.07.06.tr");
	  infile7.open("cache.07.07.tr");
	  /*TO skip the header*/
	  getline(infile1,str);
	  getline(infile2,str1);
	  getline(infile3,str1);
	  getline(infile4,str1);
	  getline(infile5,str1);
	  getline(infile6,str1);
	  getline(infile7,str1);
	  long i=0,j=0,k=0;
	  ofstream outfile1,outfile2,popularity;
	  outfile1.open("Day1.txt");
	  outfile2.open("Day2.txt");
	  popularity.open("ObjectSize.txt");
	  popularity<<"Day1"<<" "<<"Day2"<<" "<<"Day3"<<" "<<"Day4"<<" "<<"Day5"<<" "<<"Day6"<<" "<<"Day7"<<endl;
	  while ((infile1 >> hashid >> freq >> size) && (infile2 >> hashid1 >> freq1 >> size1)
			  && (infile3 >> hashid2 >> freq2 >> size2) && (infile4 >> hashid3 >> freq3 >> size3)
			  && (infile5 >> hashid4 >> freq4 >> size4) &&(infile6 >> hashid5 >> freq5 >> size5)
			  && (infile7 >> hashid6 >> freq6 >> size6)) {
		  //cout<<"\n Hash ID"<< hashid;
		  i++;
		  if(i<=100){
			  //cout<<i<<" "<<"Hash ID "<< hashid<<endl;
			  map1.insert(std::make_pair(hashid, freq));

		  }
		  outfile1<<i<<" "<<freq<<endl;
		  popularity<<size<<" "<<size1<<" "<<size2<<" "<<size3<<" "<<size4<<" "<<size5<<" "<<size6<<endl;
	  }
	  //cout<<"MAp 2\n";
	 outfile2<<"Popularity"<<" "<<"Times"<<endl;
	  while (infile2 >> hashid >> freq >> size) {
		  j++;

		  		  if(j<=100){
		  			 //cout<<j<<" "<<" Hash ID "<< hashid<<endl;
		  			map2.insert(std::make_pair(hashid, freq));
		  		  }
		  	outfile2<<j<<" "<<freq<<endl;
	  	  }
	    for(it=map1.begin() ;it!=map1.end(); it++){
	    	if(map2.find(it->first)!=map2.end()){
	    		k++;
	    	}
	    }
      cout<<"Value of Popularity"<< k;
      outfile2.close();
      outfile1.close();
      break;
}

case 2: {
	ofstream logfile;
	long count=0;
	logfile.open("LogFile.txt");
    char *filename="/home/sriharsha/Downloads/Traces/cache.07.01.tr";

	logfile<<"Start of processing.. \n";
	std::map<long, RequestFreq> freqmap = readAndConstructMap(filename,count);
	logfile<<" Closing the file\n";
	multimap<long, RequestFreq> orderdmap = constructOrderdMap(freqmap,count);
	logfile<<" Done with map processing \n";
	findHitRatio(count, orderdmap);
	miscellaneousDetails(count, freqmap);
	break;
}
}
	return 0;

}


