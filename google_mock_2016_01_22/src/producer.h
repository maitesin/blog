#ifndef _PRODUCER_H_
#define _PRODUCER_H_

#include <string>

class Producer {
public:
	virtual ~Producer(){}
	virtual std::string getDomainFromUrl(const std::string & url) const = 0;
};

#endif /*_PRODUCER_H_*/
