
#include "Address.h"
#include "Contact.h"

#include "gmock/gmock.h"

namespace Phonebook
{
namespace Test
{

namespace
{
  // Define your expectations here 
}

/**
 * Test class for a contact in a phonebook.
 * It tests at least the following cases:
 * 1. Valid and invalid Contact initialization (Check Contact type constrains).
 * 2. Verify copying of a Contact.
 * 3. Verify moving a Contact from instance to another
 * 4. Verify setting Contact properties.
 * 5. Verify equality/inequality of Contact objects
 * 6. Verify Contact objects ordering.
 */
class PhonebookContactTest : public ::testing::Test
{
public:
  //! Code here will be called immediately after the constructor (right before each test is executed).
  virtual void SetUp() override;
   
  //! Code here will be called immediately after each test 
  //! (at the end of each test and right before the destructor).
  virtual void TearDown() override;
   
};

void PhonebookContactTest::SetUp()
{}

void PhonebookContactTest::TearDown()
{}

// Below are test functions, one for each test case.
TEST_F(PhonebookContactTest, TestCase1 /* Replace name with appropriate one */)
{
}

}
}