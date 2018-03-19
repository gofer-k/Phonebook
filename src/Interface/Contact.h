#ifndef PHONEBOOK_INTERFACE_CONTACT_H
#define PHONEBOOK_INTERFACE_CONTACT_H

#include "Address.h"

#include <string>
#include <vector>

namespace Phonebook
{
/**
 * Class representing a contact in a phonebook. Class of this type should provide the following capabilities:
 * 1. Store at least the following properties:
 * - (first) name - mandatory, non empty field
 * - last name
 * - address
 * - up to 2 phone numbers
 * 2. Initialization with at least mandatory fields (first name)
 * 3. Validation of constraints (i.e. check for non empty contact name)
 * 4. Be copy constructible and assignable
 * 5. Be move constructible and assignable
 * 6. Be comparable in terms of equality
 * 7. Support sorting elements of Contact type
 */
class Contact final
{
public:
  using TPhoneNumbers = std::vector<std::string>;

  ~Contact() = default;

  Contact(std::string aFirstName, std::string aLastName = {}, Address aAddress = {}, 
          TPhoneNumbers aPhoneNumbers = {});

  Contact(const Contact& aOther);

  Contact& operator=(const Contact& aOther);

  Contact(Contact&& aOther);

  Contact& operator=(Contact&& aOther);

  bool operator==(const Contact& aOther) const;

  bool operator!=(const Contact& aOther) const;

  bool operator<(const Contact& aOther) const;

  void AddPhoneNumber(std::string aValue);
  void SetFirstName(std::string aValue);
  void SetLastName(std::string aValue);
  void SetAddress(Address aValue);
  
  const TPhoneNumbers& GetPhoneNumbers() const;
  std::string GetPrimaryPhoneNumber() const;
  std::string GetSecondaryPhoneNumber() const;
  const std::string& GetFirstName() const;
  const std::string& GetLastName() const;
  const Address& GetAddress() const;
  
  bool IsValid() const;

private:
  bool Validate() const;

private:
  TPhoneNumbers iPhoneNumbers;
  std::string iFirstName;
  std::string iLastName;
  Address iAddress;  
};
}
#endif