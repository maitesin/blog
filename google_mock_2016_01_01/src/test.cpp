#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "producer.h"
#include "consumer.h"

class ProducerMock : public Producer {
public:
	MOCK_CONST_METHOD1( getDomainFromUrl, std::string(const std::string & ) );
}

TEST(Consumer, EmptyString) {
	std::string url = "http://www.fantasticdomain.com/site/index.html";
	std::string domain = "fantasticdomain.com";
	ProducerMock mock;
	Consumer consumer(mock);
	EXPECT_CALL(mock //Mocked object
		    getDomainFromUrl(url) //Call with the parameter
		    .WillOnce(::testing::Return(std::string(domain))) //Returned );
	int domainLevel = consumer.countLevelOfDomain(url);
	EXPECT_EQ(analysis.size(), 2);
}

int main(int argc, char **argv) {
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
