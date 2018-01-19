#include "gtest/gtest.h"

namespace SampleGTest
{

class SampleGTest : public ::testing::Test
{
public:
  //! Code here will be called immediately after the constructor (right before each test is executed).
  virtual void SetUp() override;
   
  //! Code here will be called immediately after each test 
  //! (at the end of each test and right before the destructor).
  virtual void TearDown() override;
   
};

void SampleGTest::SetUp()
{}

void SampleGTest::TearDown()
{}

// Below are test functions, one for each test case.

TEST_F(SampleGTest, TestCase1)
{
  // Put test case implemnentation here
  ASSERT_TRUE(false);
}

}