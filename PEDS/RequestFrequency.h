/*
 * RequestFrequency.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: sriharsha
 */
#include <iostream>
#include <list>
class Request{
private:
	long request_id;
	long hash_id;
	long request_size;
public:

	long getHashId() const;
	void setHashId(long hashId);
	long getRequestId() const;
	void setRequestId(long requestId);
	long getRequestSize() const;
	void setRequestSize(long requestSize);
	Request(long request_id, long hash_id , long request_size);
	Request();
};

class RequestFreq{
private:
	long hashid;
    std::list<Request> reqlist;
    long freq;
public:
    //std::list<Request> getFreq(long hashid);
    long getHashid();

	void setFreq(long freq) {
		this->freq = freq;
	}

	void setHashid(long hashid) {
		this->hashid = hashid;
	}

	const std::list<Request>& getReqlist() const {
		return reqlist;
	}

	void setReqlist(const std::list<Request>& reqlist) {
		this->reqlist = reqlist;
	}

	long getFreq() const {
		return freq;
	}

};

/*struct PointComarator{
bool operator()(const RequestFreq &first,const RequestFreq &second) const{
		if(first.getFreq()<second.getFreq()){
			return first.getFreq()<second.getFreq();
		}else{
			return second.getFreq()< first.getFreq();
		}
	}
};*/
/*std::list<Request> RequestFreq::getFreq(long hashid){
   this->reqlist;
}*/

Request::Request(long request_id, long hash_id , long request_size){
  this->request_id=request_id;
  this->hash_id=hash_id;
  this->request_size=request_size;
}

inline long Request::getHashId() const {
	return hash_id;
}

inline void Request::setHashId(long hashId) {
	hash_id = hashId;
}

inline long Request::getRequestId() const {
	return request_id;
}

inline void Request::setRequestId(long requestId) {
	request_id = requestId;
}

inline long Request::getRequestSize() const {
	return request_size;
}

inline void Request::setRequestSize(long requestSize) {
	request_size = requestSize;
}
