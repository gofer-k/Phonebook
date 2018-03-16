#include "gmock/gmock.h"
#include "Address.h"

#include <tuple>

namespace Phonebook
{
namespace Test
{

/**
 * Unit test for Address class from Phonebook library. It should cover all Address type capabilities
 * listed in Address class header.
 */ 
class PhonebookAddressTest : public ::testing::Test
{
public:
  //! Code here will be called immediately after the constructor (right before each test is executed).
  virtual void SetUp() override;
   
  //! Code here will be called immediately after each test 
  //! (at the end of each test and right before the destructor).
  virtual void TearDown() override;
   
};

void PhonebookAddressTest::SetUp()
{}

void PhonebookAddressTest::TearDown()
{}

// Below are test functions, one for each test case.
TEST_F(PhonebookAddressTest, TestCase1 /* Change name accordingly to the implementation*/)
{
  ASSERT_TRUE(false);
}

}
}