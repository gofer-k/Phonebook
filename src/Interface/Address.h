#ifndef PHONEBOOK_INTERFACE_ADDRESS
#define PHONEBOOK_INTERFACE_ADDRESS

#include <string>

namespace Phonebook
{

class Address
{
public:
  Address() = default;

  Address(std::string aHouseNumber, std::string aStreetName, std::string aCity, std::string aCountry,
          std::string aPostalCode);

  Address(const Address& aOther);
  Address& operator=(const Address& aOther);
  Address(Address&& aOther);  
  Address& operator=(Address&& aOther);

  bool operator==(const Address& aOther) const;

  bool operator!=(const Address& aOther) const;
  
  ~Address() = default;

  void SetHouseNumber(std::string aValue);
  void SetStreetName(std::string aValue);
  void SetCity(std::string aValue);
  void SetCountry(std::string aValue);
  void SetPostalCode(std::string aValue);

  const std::string& GetHouseNumber() const;
  const std::string& GetStreetName() const;
  const std::string& GetCity() const;
  const std::string& GetCountry() const;
  const std::string& GetPostalCode() const;

private:
  std::string iHouseNumber;
  std::string iStreetName;
  std::string iCity;
  std::string iCountry;
  std::string iPostalCode;
};
}
#endif