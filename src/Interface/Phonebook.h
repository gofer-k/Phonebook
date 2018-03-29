#ifndef PHONEBOOK_INTERFACE_PHONEBOOK
#define PHONEBOOK_INTERFACE_PHONEBOOK

#include "Contact.h"

#include <algorithm>
#include <string>

namespace Phonebook
{

class Phonebook
{
  using TContacts = std::vector<Contact>;

public:
  Phonebook() = default;
  ~Phonebook() = default;

  Phonebook(const Phonebook&) = delete;
  Phonebook& operator=(const Phonebook&) =  delete;

  const TContacts& GetContacts() const;

  void AddContact(Contact aContact);
  void RemoveContacts(const TContacts& aContactsToRemove);
  void UpdateContact(Contact aOldContact, Contact aNewContact);

  TContacts FindContacts(std::string aContactPiece) const;
  
private:
  TContacts iContacts;
};
}
#endif