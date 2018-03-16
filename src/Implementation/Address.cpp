#include "../Interface/Address.h"

#include <iostream>

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
  {
    std::cout << "copy ctor\n";
  }

  Address& Address::operator=(const Address& aOther)
  {
    std::cout << "assignment operator\n";

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
  {
    std::cout << " move c-tor\n";
  }

  Address& Address::operator=(Address&& aOther)
  {
    std::cout << "move assignment operator\n";
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
    iPostalCode = std::move(aValue);
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