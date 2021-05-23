---
name: 'Task 5: Implement `HashDictionary` public `remove()` API Method'
about: Task 5 for Students
title: 'Task 5: Implement `HashDictionary` public `remove()` API Method'
labels: enhancement
assignees: ''

---

**Description**

The fifth task is to implement the `remove()` API method, which is almost identical to the `find()` you just completed.  The `remove()` function will perform the same search and return the `value` it finds associated with the `key` it is asked to remove.  But if it finds the key/value pair, it will remove it from the collection before returning the `value`.  A value is removed from the table by setting it to be in the `missing` state.


**Suggested Solution**

The steps to implement the `remove()` method are mostly the same as the previous `find()`:

1. Use the `probeForKeySlot()` method to search for the slot for the
   given input `key`.
2. Test the returned hash table slot.  If the slot is empty it means the
   search for the `key` failed and you should throw the
   `DictionaryKeyNotFoundException`.
3. Otherwise you found the key, so you retrieve and return the
   value from the hash table slot that contains that key/value pair and also
   mark the slot as `missing` to remove it from the hash table.
   
Be careful when marking the slot as `missing`, this causes the `key` and `value` to be reset.  So you will need to make a copy of the `value` you need to return before setting the slot to be `missing`.

**Additional Requirements**

- This function must reuse `probeForKeySlot()` to perform its work.
- This function must detect a failed search and throw a `DictionaryKeyNotFoundException`
  if it fails to find the asked for `key` in the collection.
