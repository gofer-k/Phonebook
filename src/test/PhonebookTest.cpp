
#include "Phonebook.h"

#include "gmock/gmock.h"

namespace Phonebook
{
namespace Test
{

class PhonebookTest : public ::testing::Test
{
public:
  //! Code here will be called immediately after the constructor (right before each test is executed).
  virtual void SetUp() override;
   
  //! Code here will be called immediately after each test 
  //! (at the end of each test and right before the destructor).
  virtual void TearDown() override;
   
};

void PhonebookTest::SetUp()
{}

void PhonebookTest::TearDown()
{}

// Below are test functions, one for each test case.

TEST_F(PhonebookTest, InitPhonebook)
{
  // Put test case implemnentation here
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, AddContact)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, RemoveContact)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, UpdateContact)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, ListContacts)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, FindContactsMatchingName)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, FindContactsMatchingPhoneNumber)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, FindContactsMatchingAddressPiece)
{
  ASSERT_TRUE(false);
}

TEST_F(PhonebookTest, FindContactsMatchingMultipleFields)
{
  ASSERT_TRUE(false);
}
}
}