#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include <string>
#include "producer.h"

class Consumer {
public:
	Consumer(const Producer &p): producer(p){}
	int countLevelOfDomain(const std::string & url) const {
		//Another awesome code goes here
		return int();
	}
private:
	Producer producer;
};

#endif /*__CONSUMER_H__*/
