#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "producer.h"
#include "consumer.h"

class ProducerMock : public Producer {
public:
	MOCK_CONST_METHOD1( getDomainFromUrl, std::string(const std::string & ) );
};

TEST(Consumer, EmptyString) {
	std::string url = "http://www.fantasticdomain.com/site/index.html";
	std::string domain = "fantasticdomain.com";
	ProducerMock mock;
	Consumer consumer(mock);
	EXPECT_CALL(mock, getDomainFromUrl(url))
		    .WillOnce(::testing::Return(std::string(domain)));
	int domainLevel = consumer.countLevelOfDomain(url);
	EXPECT_EQ(domainLevel, 2);
}

int main(int argc, char **argv) {
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
