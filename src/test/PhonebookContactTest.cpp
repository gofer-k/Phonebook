
#include "Address.h"
#include "Contact.h"

#include "gmock/gmock.h"

#include <iostream>
#include <tuple>

namespace Phonebook
{
  void DumpAddress(const Address& aAddress, std::ostream* os)
  {
    *os << "Address: {" << aAddress.GetHouseNumber() << ", "
        << aAddress.GetStreetName() << ", "
        << aAddress.GetCity() << ", "
        << aAddress.GetCountry() << ", "
        << aAddress.GetPostalCode() << "}";
  }

  void DumpPhoneNumbers(const Contact::TPhoneNumbers& aPhoneNumbers, std::ostream* os)
  {
    for (const auto& phoneNumber : aPhoneNumbers)
    {
      *os << phoneNumber << " ";
    }
  }
  // For better message reporting of a Contact details, 
  // i.e if a Contact doesn't satisfy an expectation.
  void PrintTo(const Contact& aContact, std::ostream* os)
  {
    *os << "Contact:\nfirstName = " << aContact.GetFirstName()
        << "\tlastName = " << aContact.GetLastName()
        << "\t";
    DumpAddress(aContact.GetAddress(), os);

    *os << "\t";
    DumpPhoneNumbers(aContact.GetPhoneNumbers(), os);
    *os << std::endl;
  }
namespace Test
{
  using namespace ::testing;

  namespace
  {
    Address addr = {"16a", "Zielona", "Warszawa", "Poland", "01-234"};
    Contact::TPhoneNumbers phoneNumbers = {"42 2345 564", "555 777 999"};

    const std::tuple<std::string, std::string, Address, Contact::TPhoneNumbers> 
    expectedContact = std::make_tuple("Franek", "Kowalski", std::move(addr), std::move(phoneNumbers));
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
 * 7. Use matchers to improve output messages
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
TEST_F(PhonebookContactTest, CreateContactWithEmptyName_InvalidContact)
{
  Contact contact("");

  EXPECT_FALSE(contact.IsValid());
}

TEST_F(PhonebookContactTest, CreateContactWithName_ValidContact)
{
  std::string firstName;

  std::tie(firstName, std::ignore, std::ignore, std::ignore) = expectedContact;

  Contact contact(firstName);
  
  EXPECT_TRUE(contact.IsValid());
}

TEST_F(PhonebookContactTest, CopyContact)
{
  std::string firstName;
  std::string lastName;
  Address address;
  Contact::TPhoneNumbers phoneNumbers;

  std::tie(firstName, lastName, address, phoneNumbers) = expectedContact;

  Contact contact1 = {firstName, lastName, address, phoneNumbers};
  Contact contact2 = contact1;

  EXPECT_TRUE(contact1.IsValid());
  EXPECT_TRUE(contact2.IsValid());

  EXPECT_EQ(contact1, contact2);

  EXPECT_EQ(firstName, contact1.GetFirstName());
  EXPECT_EQ(lastName, contact1.GetLastName());
  EXPECT_EQ(address, contact1.GetAddress());
  EXPECT_EQ(phoneNumbers, contact1.GetPhoneNumbers());
}

TEST_F(PhonebookContactTest, MoveContact)
{
  std::string firstName;
  std::string lastName;
  Address address;
  Contact::TPhoneNumbers phoneNumbers;

  std::tie(firstName, lastName, address, phoneNumbers) = expectedContact;

  Contact contact1 = {firstName, lastName, address, phoneNumbers};
  Contact contact2(std::move(contact1));

  EXPECT_FALSE(contact1.IsValid());
  EXPECT_TRUE(contact2.IsValid());

  EXPECT_NE(contact1, contact2);

  EXPECT_EQ(firstName, contact2.GetFirstName());
  EXPECT_EQ(lastName, contact2.GetLastName());
  EXPECT_EQ(address, contact2.GetAddress());
  EXPECT_EQ(phoneNumbers, contact2.GetPhoneNumbers());
}

TEST_F(PhonebookContactTest, SetFirstName)
{
  std::string firstName;
  
  std::tie(firstName, std::ignore, std::ignore, std::ignore) = expectedContact;

  Contact contact = {firstName};
  
  EXPECT_TRUE(contact.IsValid());

  EXPECT_EQ(firstName, contact.GetFirstName());
  EXPECT_TRUE(contact.GetLastName().empty());
  EXPECT_EQ(Address(), contact.GetAddress());
  EXPECT_TRUE(contact.GetPhoneNumbers().empty());
}

TEST_F(PhonebookContactTest, SetLastName)
{
  std::string firstName;
  std::string lastName;
  
  std::tie(firstName, lastName, std::ignore, std::ignore) = expectedContact;

  Contact contact = {firstName, lastName};
  
  EXPECT_TRUE(contact.IsValid());

  EXPECT_EQ(firstName, contact.GetFirstName());
  EXPECT_EQ(lastName, contact.GetLastName());
  EXPECT_EQ(Address(), contact.GetAddress());
  EXPECT_TRUE(contact.GetPhoneNumbers().empty());
}

TEST_F(PhonebookContactTest, SetPhoneNumbers)
{
  std::string firstName;
  Contact::TPhoneNumbers phoneNumbers;

  std::tie(firstName, std::ignore, std::ignore, phoneNumbers) = expectedContact;

  Contact contact = {firstName, "", {}, phoneNumbers};
  
  EXPECT_TRUE(contact.IsValid());

  EXPECT_EQ(firstName, contact.GetFirstName());
  EXPECT_TRUE(contact.GetLastName().empty());

  // Use matcher here to improve error message
  EXPECT_EQ(Address(), contact.GetAddress());
  EXPECT_EQ(phoneNumbers, contact.GetPhoneNumbers());
  EXPECT_EQ(phoneNumbers.front(), contact.GetPrimaryPhoneNumber());
  EXPECT_EQ(phoneNumbers.back(), contact.GetSecondaryPhoneNumber());
}

TEST_F(PhonebookContactTest, SetAddress)
{
  std::string firstName;
  Address address;

  std::tie(firstName, std::ignore, address, std::ignore) = expectedContact;

  Contact contact = {firstName, "", address};
  
  EXPECT_TRUE(contact.IsValid());

  EXPECT_EQ(firstName, contact.GetFirstName());
  EXPECT_TRUE(contact.GetLastName().empty());

  // Use matcher here to improve error message
  EXPECT_EQ(address, contact.GetAddress());
  EXPECT_TRUE(contact.GetPhoneNumbers().empty());
}

TEST_F(PhonebookContactTest, OrderContacts)
{
  std::string firstName;
  std::string lastName;
  Address address;

  std::tie(firstName, lastName, address, std::ignore) = expectedContact;

  Contact contact1 = {firstName, "", address};

  // Check ordering contacts with different first name
  {
    Contact contact2 = {"Adam", "Nowak"};

    EXPECT_LT(contact2, contact1);
  }

  // Check ordering contacts with the same first name
  {
    Contact contact2 = {"Franek", "Nowak"};

    EXPECT_LT(contact1, contact2);
  }
}

}
}