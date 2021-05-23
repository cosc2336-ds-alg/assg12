/** @file HashDictionary.cpp
 * @brief Implementation file with implementations of concrte HashDictionary member functions
 *   of the Dictionary container abstraction
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * Assignment Dictionaries and Hashing.  Implement member functions
 * for a HashDictionary class for an open hashing scheme with a
 * quadratic probe sequence.  This implementation file contains the
 * implementations of the HashDictionary methods for the Dictionary
 * API abstraction.  You need to add the implementations for the
 * member functions for this assignment to this file.
 */
#include <sstream>
#include "HashDictionary.hpp"
#include "DictionaryException.hpp"
#include "Employee.hpp"
using namespace std;


/** grow dictionary
 * Private member method that will increase the memory allocation if
 * the hash table is currently above 50% capacity.  To do this, we double the
 * current allocation, copy all of the values from the original block
 * of memory to the new block of memory, then delete the old block
 * that is no longer needed.  This method is called by methods that
 * need to grow the queue, to ensure we have enough allocated capacity
 * to accommodate the growth.  NOTE: this method has to not only
 * allocate a new block of memory, but all of the old key/value pairs
 * must be rehashed into the new table.
 */
template <class Key, class Value>
void HashDictionary<Key, Value>::growHashDictionaryIfNeeded()
{
  // if size is still less than 50% of the allocated size, then we don't need
  // to grow the size yet, just keep inserting until we reach 50% capacity
  if (Dictionary<Key, Value>::size < allocationSize / 2)
  {
    return;
  }

  // otherwise size is equal to our allocation, double the size of our allocation
  // to accommodate future growth, or make size 10 initially by default if
  // an empty container is being grown
  int newAllocationSize;
  if (allocationSize == 0)
  {
    newAllocationSize = INITIAL_ALLOCATION_SIZE;
  }
  else
  {
    newAllocationSize = 2 * allocationSize;
  }

  // dynamically allocate a new block of key/value pair items of the new allocation size
  KeyValuePair<Key, Value>* newHashTable = new KeyValuePair<Key, Value>[newAllocationSize];

  // We need to switch over to the new hash table, so we can reuse the insert()
  // member method to insert the existing key/value records into the new table
  KeyValuePair<Key, Value>* oldHashTable = hashTable;
  int oldAllocationSize = allocationSize;
  hashTable = newHashTable;
  allocationSize = newAllocationSize;

  // new table is empty until we reinsert values
  Dictionary<Key, Value>::size = 0;

  // reinsert all key/value pairs from current hash table into new hash table
  // we need to start by making sure the key of all entries is the empty key
  for (int index = 0; index < allocationSize; index++)
  {
    hashTable[index].setEmpty();
  }

  // now we can safely call insert on values in the old table to put them
  // into our new table
  for (int index = 0; index < oldAllocationSize; index++)
  {
    // any key that is not empty we want to insert into the new table
    if (not oldHashTable[index].isEmpty())
    {
      //insert(oldHashTable[index].getKey(), oldHashTable[index].getValue());
    }
  }

  // make sure we free up the old hash table back to the heap
  delete[] oldHashTable;
}


/** constructor
 * Standard constructor for the HashDictionary
 *
 * @param allocationSize The size of the hash table that should be
 *   generated for internal use by this dictionary for hasing.
 */
template <class Key, class Value>
HashDictionary<Key, Value>::HashDictionary(int allocationSize)
{
  // use initial indicated allocation size for this hash table,
  // and initial size of the container is empty
  this->allocationSize = allocationSize;
  Dictionary<Key, Value>::size = 0;

  // allocate an array/table of the indicated initial size
  hashTable = new KeyValuePair<Key, Value>[allocationSize];

  // initialize the hash table so all slots are initially empty
  for (int index = 0; index < allocationSize; index++)
  {
    hashTable[index].setEmpty();
  }
}


/** array based constructor
 * Construct a new hash dictionary from a given set of parallel
 * arrays of the intiial key/value pairs for the dictionary.
 *
 * @param size The size of the Key and Value arrays given with
 *   the initial key/value pairs to be inserted into the new
 *   hash dictionary.
 * @param keys An array of length size of the keys to be inserted
 *   into this new hash dictionary.
 * @param values An array of length size of the corresponding
 *   values to be inserted into this new hash dictionary.
 */
template <class Key, class Value>
HashDictionary<Key, Value>::HashDictionary(int size, const Key keys[], const Value values[])
{
  // create a hash table that is initially double the size of the values we are
  // asked to initialize it with
  this->allocationSize = 2 * size;
  Dictionary<Key, Value>::size = size;

  // allocate an array/table of the indicated initial size
  hashTable = new KeyValuePair<Key, Value>[allocationSize];

  // initialize the hash table so all slots are initially empty
  for (int index = 0; index < allocationSize; index++)
  {
    hashTable[index].setEmpty();
  }

  // insert the key/value pairs given in the parallel arrays into the dictionary
  for (int index = 0; index < size; index++)
  {
    //insert(keys[index], values[index]);
  }
}


/** destructor
 * Standard destructor for the HashDictionary.  Be good memory managers and
 * free up the dynamically allocated array of memory pointed to by hashTable.
 */
template <class Key, class Value>
HashDictionary<Key, Value>::~HashDictionary()
{
  // call clear to do actual work to deallocate any allocation beforw
  // we destruct
  clear();
}


/** get current allocation
 * Accessor method to get the current memory allocation of this hash
 * dictionary implementation.
 *
 * @returns int Returns the current memory allocation size of this hash
 *   dictionary instance.
 */
template <class Key, class Value>
int HashDictionary<Key, Value>::getAllocationSize() const
{
  return allocationSize;
}


/** HashDictionary to string
 * We normally wouldn't have
 * something like this for a Dictionary or HashTable, but for testing
 * and learning purposes, we want to be able to display the contents of
 * each slot in the hash table of a HashDictionary container.
 */
template <class Key, class Value>
string HashDictionary<Key, Value>::str() const
{
  ostringstream out;

  out << "<HashDictionary> size: " << Dictionary<Key, Value>::size << endl;
  for (int slot = 0; slot < allocationSize; slot++)
  {
    out << "Slot: " << slot << endl;
    // if slot is empty, display empty status
    if (hashTable[slot].isEmpty())
    {
      out << "     Key  : EMPTY" << endl;
      out << "     Value:" << endl;
    }
    // could also be missing, show that unique status as well
    else if (hashTable[slot].isMissing())
    {
      out << "     Key  : MISSING" << endl;
      out << "     Value:" << endl;
    }
    // otherwise display the key/value information of the slot
    else
    {
      out << "     Key  : " << hashTable[slot].getKey() << endl;
      out << "     Value: " << hashTable[slot].getValue() << endl;
    }
  }

  return out.str();
}


/** clear out hash dictionary
 * Clear or empty out the hash dictionary.  Return the hash table back
 * to an empty dictionary.
 */
template <class Key, class Value>
void HashDictionary<Key, Value>::clear()
{
  // if hash table is not null, it points to a dynamic block of memory, so
  // delete that block.
  if (hashTable != nullptr)
  {
    delete[] hashTable;
    hashTable = nullptr;
  }

  // make sure size and allocation are both reading as 0 now
  Dictionary<Key, Value>::size = 0;
  allocationSize = 0;
}


/** overload indexing operator[]
 * Overload indexing operator[] to provide direct access
 * to hash table.  This is not normally part of the Dictionary
 * API/abstraction, but included here for testing.
 *
 * @param index An integer index.  The index should be in the range 0 - tablesize-1.
 *
 * @returns KeyValuePair<> Returns a KeyValuePair object if the index into the
 *   internal hash table is a valid index.  This method throws an exception if
 *   the index is not a valid slot of the hash table.
 *
 * @throws DictionaryMemoryBoundsException is thrown if an attempt is made to
 *   access the hash table using this indexing operator beyond the bounds
 *   of its memory allocation/index.
 */
template <class Key, class Value>
KeyValuePair<Key, Value>& HashDictionary<Key, Value>::operator[](int index)
{
  if (index < 0 or index >= allocationSize)
  {
    ostringstream out;
    out << "Error: <HashDictionary::operator[] illegal bounds access: "
        << index << " table allocation size is currently: "
        << allocationSize << endl;
    throw DictionaryMemoryBoundsException(out.str());
  }

  return hashTable[index];
}


/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * HashDictionary<needed_key_type, needed_value_type> here of any types
 * we are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class HashDictionary<int, int>;
template class HashDictionary<int, Employee>;
//template class HashDictionary<string, double>;