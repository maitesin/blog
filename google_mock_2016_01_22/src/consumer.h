#ifndef _CONSUMER_H_
#define _CONSUMER_H_

#include <string>
#include <algorithm>
#include "producer.h"

class Consumer {
public:
	Consumer(Producer * p): producer(p){}
	int countLevelOfDomain(const std::string & url) const {
		std::string domain = producer->getDomainFromUrl(url);
		return std::count(domain.begin(), domain.end(), '.') + 1;
	}
private:
	Producer * producer;
};

#endif /*_CONSUMER_H_*/
