---
name: 'Task 4: Implement `HashDictionary` public `find()` API Method'
about: Task 4 for Students
title: 'Task 4: Implement `HashDictionary` public `find()` API Method'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement the public `find()` api method.  This method should be a simple implementation as it mostly reuses the helper functions to perform its task.  The `find()` method is a basic search of the dictionary collection.  Given a `Key` as a `const` reference parameter, this method searches the collection and returns the `Value` associated with the `Key` if it is found.  This method will throw a `DictionaryKeyNotFoundException` if asked to search for a `key` that is not in the dictionary.

**Suggested Solution**

The steps to implement the `find()` method are as follows:

1. Use the `probeForKeySlot()` method to search for the slot for the
   given input `key`.
2. Test the returned hash table slot.  If the slot is empty it means the
   search for the `key` failed and you should throw the
   `DictionaryKeyNotFoundException`.
3. Otherwise you found the key, so you can simply retrieve and return the
   value from the hash table slot that contains that key/value pair.


**Additional Requirements**

- This function must reuse `probeForKeySlot()` to perform its work.
- This function must detect a failed search and throw a `DictionaryKeyNotFoundException`
  if it fails to find the asked for `key` in the collection.


