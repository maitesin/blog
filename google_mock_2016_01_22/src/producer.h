#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include <string>

class Producer {
public:
	virtual ~Producer(){}
	virtual std::string getDomainFromUrl(const std::string & url) const = 0;
};

#endif /*__PRODUCER_H__*/
