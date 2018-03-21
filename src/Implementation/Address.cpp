#include "Address.h"

#include <regex>

namespace Phonebook
{
  Address::Address(std::string aHouseNumber, std::string aStreetName, std::string aCity, 
                   std::string aCountry, std::string aPostalCode)
  : iHouseNumber(std::move(aHouseNumber))
  , iStreetName(std::move(aStreetName))
  , iCity(std::move(aCity))
  , iCountry(std::move(aCountry))
  , iPostalCode(std::move(aPostalCode))
  {}

  Address::Address(const Address& aOther)
  : iHouseNumber(aOther.iHouseNumber)
  , iStreetName(aOther.iStreetName)
  , iCity(aOther.iCity)
  , iCountry(aOther.iCountry)
  , iPostalCode(aOther.iPostalCode)
  {}

  Address& Address::operator=(const Address& aOther)
  {
    iHouseNumber = aOther.iHouseNumber;
    iStreetName = aOther.iStreetName;
    iCity = aOther.iCity;
    iCountry = aOther.iCountry;
    iPostalCode = aOther.iPostalCode;

    return *this;
  }

  Address::Address(Address&& aOther)
  : iHouseNumber(std::move(aOther.iHouseNumber))
  , iStreetName(std::move(aOther.iStreetName))
  , iCity(std::move(aOther.iCity))
  , iCountry(std::move(aOther.iCountry))
  , iPostalCode(std::move(aOther.iPostalCode))
  {}

  Address& Address::operator=(Address&& aOther)
  {
    if (this != &aOther)
    {
      iHouseNumber = std::move(aOther.iHouseNumber);
      iStreetName = std::move(aOther.iStreetName);
      iCity = std::move(aOther.iCity);
      iCountry = std::move(aOther.iCountry);
      iPostalCode = std::move(aOther.iPostalCode);
    }

    return *this;
  }

  bool Address::operator==(const Address& aOther) const
  {
    return !(*this != aOther);
  }

  bool Address::operator!=(const Address& aOther) const
  {
    return (iHouseNumber != aOther.iHouseNumber ||
            iStreetName != aOther.iStreetName ||
            iCity != aOther.iCity ||
            iCountry != aOther.iCountry ||
            iPostalCode != aOther.iPostalCode);
  }
  void Address::SetHouseNumber(std::string aValue)
  {
    iHouseNumber = std::move(aValue);
  }

  void Address::SetStreetName(std::string aValue)
  {
    iStreetName = std::move(aValue);
  }

  void Address::SetCity(std::string aValue)
  {
    iCity = std::move(aValue);
  }

  void Address::SetCountry(std::string aValue)
  {
    iCountry = std::move(aValue);
  }

  void Address::SetPostalCode(std::string aValue)
  {
    static std::regex regexString("[0-9]{2}-[0-9]{3}"); // postal code format valid in Poland
    std::smatch match;

    if (std::regex_match(aValue, match, regexString))
    {
      iPostalCode = std::move(aValue);
    }
    
  }

  const std::string& Address::GetHouseNumber() const
  {
    return iHouseNumber;
  }

  const std::string& Address::GetStreetName() const
  {
    return iStreetName;
  }

  const std::string& Address::GetCity() const
  {
    return iCity;    
  }

  const std::string& Address::GetCountry() const
  {
    return iCountry;
  }

  const std::string& Address::GetPostalCode() const
  {
    return iPostalCode;
  }
}