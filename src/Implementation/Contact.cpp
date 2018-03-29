#include "Contact.h"

namespace Phonebook
{
  Contact::Contact(std::string aFirstName, std::string aLastName, Address aAddress, 
                   TPhoneNumbers aPhoneNumbers)
  : iFirstName(std::move(aFirstName))
  , iLastName(std::move(aLastName))
  , iAddress(std::move(aAddress))
  , iPhoneNumbers(std::move(aPhoneNumbers))
  {}

  Contact::Contact(const Contact& aOther)
  : iFirstName(aOther.iFirstName)
  , iLastName(aOther.iLastName)
  , iAddress(aOther.iAddress)
  , iPhoneNumbers(aOther.iPhoneNumbers)
  {}

  Contact& Contact::operator=(const Contact& aOther)
  {
    iFirstName = aOther.iFirstName;
    iLastName = aOther.iLastName;
    iAddress = aOther.iAddress;
    iPhoneNumbers = aOther.iPhoneNumbers;
    return *this;
  }

  Contact::Contact(Contact&& aOther)
  : iFirstName(std::move(aOther.iFirstName))
  , iLastName(std::move(aOther.iLastName))
  , iAddress(std::move(aOther.iAddress))
  , iPhoneNumbers(std::move(aOther.iPhoneNumbers))
  {}

  Contact& Contact::operator=(Contact&& aOther)
  {
    if (this != &aOther)
    {      
      iFirstName = std::move(aOther.iFirstName);
      iLastName = std::move(aOther.iLastName);
      iAddress = std::move(aOther.iAddress);
      iPhoneNumbers = std::move(aOther.iPhoneNumbers);
    }
    return *this;
  }

  bool Contact::operator==(const Contact& aOther) const
  {
    return !(*this != aOther);
  }

  bool Contact::operator!=(const Contact& aOther) const
  {
    return (iFirstName != aOther.iFirstName || 
            iLastName != aOther.iLastName ||
            iAddress != aOther.iAddress ||
            iPhoneNumbers != aOther.iPhoneNumbers);
  }

  bool Contact::operator<(const Contact& aOther) const
  {
    int result = iFirstName.compare(aOther.iFirstName);

    if (result < 0)
    {
      return true;
    }
    else if (result == 0)
    {
      return iLastName < aOther.iLastName;
    }
    return false;
  }

  void Contact::AddPhoneNumber(std::string aValue)
  {
    iPhoneNumbers.emplace_back(std::move(aValue));
  }
  void Contact::SetFirstName(std::string aValue)
  {
    iFirstName = std::move(aValue);
  }
  void Contact::SetLastName(std::string aValue)
  {
    iLastName = std::move(aValue);
  }
  void Contact::SetAddress(Address aValue)
  {
    iAddress = std::move(aValue);
  }
  
  const Contact::TPhoneNumbers& Contact::GetPhoneNumbers() const
  {
    return iPhoneNumbers;
  }
  std::string Contact::GetPrimaryPhoneNumber() const
  {
    return iPhoneNumbers.empty() ? "" : iPhoneNumbers.front();
  }
  std::string Contact::GetSecondaryPhoneNumber() const
  {
    return (iPhoneNumbers.size() < 2) ? "" : iPhoneNumbers.back();
  }
  const std::string& Contact::GetFirstName() const
  {
    return iFirstName;
  }
  const std::string& Contact::GetLastName() const
  {
    return iLastName;
  }
  const Address& Contact::GetAddress() const
  {
    return iAddress;
  }
  bool Contact::IsValid() const
  {
    return Validate();
  }
  bool Contact::Validate() const
  {
    return !iFirstName.empty();
  }
}