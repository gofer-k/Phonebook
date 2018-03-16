#ifndef PHONEBOOK_INTERFACE_ADDRESS
#define PHONEBOOK_INTERFACE_ADDRESS

#include <string>

namespace Phonebook
{

/**
  Class representing an address in a phonebook.
  Object of this class should support the following operations:
  1. Store information about the following address pieces:
  - house number
  - street name
  - city
  - country
  - postal code
  2. Default initialization of its members
  3. Initialization with passed values
  4. Copy address object
  5. Move address object
  6. Equality comparison
*/
class Address
{
public:
  Address() = default;

  virtual ~Address() = default;
  
private:
};

}
#endif