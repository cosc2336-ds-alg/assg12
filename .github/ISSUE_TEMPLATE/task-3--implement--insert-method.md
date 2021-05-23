---
name: 'Task 3: Implement `HashDictionary` public `insert() API Method'
about: Task 3 for Students
title: 'Task 3: Implement `HashDictionary` public `insert() API Method'
labels: enhancement
assignees: ''

---

**Description**

Implement the missing `insert()` public API method for this concrete implementation of the `Dictionary` abstraction.  The purpose of the `insert()` method is to insert a new key/value pair into the dictionary collection.  Thus it takes two parameters, a `key` and a `value`, both of which are `const` reference parameters.  The function is a `void` function, it doesn't return an explicit result.  However, if an attempt is made to insert a `key` that already exists in the collection, a `DictionaryDuplicateKeyInsertionException` should be thrown.

**Suggested Solution**

The implementation of the `insert()` API should be relatively simple as most all of the hard work has already been done in the private helper methods.  To implement `insert()` perform the following steps:

1. First determine if an attempt is being made to insert a duplicate key.  For
   the dictionary collections we don't allow duplicate keys in the dictionary,
   each key must be unique.  So use the `probeForKeySlot()` method to
   first search for the key being inserted.  This function returns a slot
   in the hash table.  If the returned slot is not empty, or equivalently
   if the key in the returned slot is the same as the key that is trying to
   be inserted, then we need to throw an exception to inform the caller
   that they are trying to do something bad.  Throw a
   `DictionaryDuplicateKeyInsertionException` if you detect an attempt
   to insert a duplicate key into the collection.
2. If the key is not a duplicate, this means we will be inserting the new
   key/value pair into the dictionary.  Call the `growHashDictionaryIfNeeded()`
   method before doing the actual insert, to ensure that the hash table is
   currently of adequate size to insert the new key/value (or to grow to a
   bigger size if needed before you do the insert).
3. After calling the grow function, you are ensured the hash table is of
   adequate size now to perform the insertion.  Call the `probeForAvailableSlot()`
   for the `key` to determine the correct slot along the probe sequence where
   the new key/value pair should be inserted.
4. Insert the key/value pair into the table at the indicated available slot.
   You need to create a new instance of a `KeyValuePair<Key, Value>` with
   the input `key` and `value` parameters, and assign this into the `hashTable`
   slot.
5. Finally your hash table has grown in `size` by 1 with the insertion.  Don't
   forget to increment the `size` member variable, which is defined in the
   `Dictionary` base class.

**Additional Requirements**

- This function must correctly not grow the hash table if an invalid
  duplicate is key is attempted to be inserted.
- This function must reuse both `probeForKeySlot()` and `probeForAvailableSlot()`
  in order to be implemented.
- This function must detect an attempt to insert a duplicate key and throw
  the `DictionaryDuplicateKeyInsertionException` when that happens.
