#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>

class Producer {
public:
	virtual ~Producer(){}
	virtual std::string getDomainFromUrl(const std::string & url) const = 0;
};

#endif /*PRODUCER_H*/
