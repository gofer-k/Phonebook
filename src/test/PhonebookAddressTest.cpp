#include "Address.h"

#include "gmock/gmock.h"

#include <tuple>

namespace Phonebook
{
namespace Test
{

namespace
{
  std::tuple<std::string, std::string, std::string, std::string, std::string> 
  expectedAddress = std::make_tuple("16a", "Zielona", "Warszawa", "Poland", "01-234");
}

using ::testing::Matcher;
using ::testing::MatchesRegex;
using ::testing::Property;
using ::testing::Values;

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

TEST_F(PhonebookAddressTest, DefaultInitAddress)
{
  Address addr;

  EXPECT_TRUE(addr.GetHouseNumber().empty());
  EXPECT_TRUE(addr.GetStreetName().empty());
  EXPECT_TRUE(addr.GetCity().empty());
  EXPECT_TRUE(addr.GetCountry().empty());
  EXPECT_TRUE(addr.GetPostalCode().empty());
}

TEST_F(PhonebookAddressTest, InitWithArguments)
{
  std::string houseNumber;
  std::string streetName;
  std::string city;
  std::string country;
  std::string postalCode;

  std::tie(houseNumber, streetName, city, country, postalCode) = expectedAddress;
  
  Address addr = {houseNumber, streetName, city, country, postalCode};

  EXPECT_EQ(houseNumber, addr.GetHouseNumber());
  EXPECT_EQ(streetName, addr.GetStreetName());
  EXPECT_EQ(city, addr.GetCity());
  EXPECT_EQ(country, addr.GetCountry());
  EXPECT_EQ(postalCode, addr.GetPostalCode());
}

TEST_F(PhonebookAddressTest, CopyAddress)
{
  std::string houseNumber;
  std::string streetName;
  std::string city;
  std::string country;
  std::string postalCode;

  std::tie(houseNumber, streetName, city, country, postalCode) = expectedAddress;
  
  Address addr1 = {houseNumber, streetName, city, country, postalCode};
  Address addr2 = addr1;

  EXPECT_EQ(addr1, addr2);
}

TEST_F(PhonebookAddressTest, MoveAddress)
{
  std::string houseNumber;
  std::string streetName;
  std::string city;
  std::string country;
  std::string postalCode;

  std::tie(houseNumber, streetName, city, country, postalCode) = expectedAddress;
  
  Address addr1 = {houseNumber, streetName, city, country, postalCode};
  Address addr2 = std::move(addr1);

  EXPECT_NE(addr1, addr2);

  EXPECT_EQ(houseNumber, addr2.GetHouseNumber());
  EXPECT_EQ(streetName, addr2.GetStreetName());
  EXPECT_EQ(city, addr2.GetCity());
  EXPECT_EQ(country, addr2.GetCountry());
  EXPECT_EQ(postalCode, addr2.GetPostalCode());
}

TEST_F(PhonebookAddressTest, SetHouseNumber)
{
  std::string houseNumber;
  
  std::tie(houseNumber, std::ignore, std::ignore, std::ignore, std::ignore) = expectedAddress;

  Address addr;
  addr.SetHouseNumber(houseNumber);
  EXPECT_EQ(houseNumber, addr.GetHouseNumber());
}

TEST_F(PhonebookAddressTest, SetStreetName)
{
  std::string streetName;
  
  std::tie(std::ignore, streetName, std::ignore, std::ignore, std::ignore) = expectedAddress;

  Address addr;
  addr.SetStreetName(streetName);
  EXPECT_EQ(streetName, addr.GetStreetName());
}

TEST_F(PhonebookAddressTest, SetCity)
{
  std::string city;
  
  std::tie(std::ignore, std::ignore, city, std::ignore, std::ignore) = expectedAddress;

  Address addr;
  addr.SetCity(city);
  EXPECT_EQ(city, addr.GetCity());
}

TEST_F(PhonebookAddressTest, SetCountry)
{
  std::string country;
  
  std::tie(std::ignore, std::ignore, std::ignore, country, std::ignore) = expectedAddress;

  Address addr;
  addr.SetCountry(country);
  EXPECT_EQ(country, addr.GetCountry());
}
TEST_F(PhonebookAddressTest, SetPostalCode)
{
  std::string postalCode;
  
  std::tie(std::ignore, std::ignore, std::ignore, std::ignore, postalCode) = expectedAddress;

  Address addr;
  addr.SetPostalCode(postalCode);
  EXPECT_EQ(postalCode, addr.GetPostalCode());
}

class PostalCodeValidationTest : 
  public PhonebookAddressTest, public ::testing::WithParamInterface<std::string>
{};

TEST_P(PostalCodeValidationTest, Validate)
{ 
  // Matcher to validate given postal code as string (tested value)
  const Matcher<const std::string&> postalCodeMatcher = MatchesRegex("[0-9]{2}-[0-9]{3}");

  // Matcher to validate postal code format stored in Address
  const Matcher<const Address&> addressPostalCodeMatcher = 
    Property(&Address::GetPostalCode, postalCodeMatcher);

  const auto& inputPostalCode = GetParam();

  Address addr;
  addr.SetPostalCode(inputPostalCode);

  EXPECT_EQ(addressPostalCodeMatcher.Matches(addr), postalCodeMatcher.Matches(inputPostalCode));
}

INSTANTIATE_TEST_CASE_P(PostalCodeFormat,
                        PostalCodeValidationTest,
                        Values("01-234", "1-123", "11-22", "12-3435", "33 432", "21343"));

}
}