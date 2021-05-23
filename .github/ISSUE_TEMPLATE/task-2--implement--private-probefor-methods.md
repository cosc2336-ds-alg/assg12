---
name: 'Task 2: Implement `HashDictionary` private `probeForAvailableSlot()` and `probeForKeySlot()` Methods'
about: Task 2 for Students
title: 'Task 2: Implement `HashDictionary` private `probeForAvailableSlot()` and `probeForKeySlot()` Methods'
labels: enhancement
assignees: ''

---

**Description**

For task 2 implement private helper functions `probeForAvailableSlot()` and `probeForKeySlot()` private member methods.  These methods are almost identical, the algorithm only differs in the test you make to stop the probing sequence.  Both methods implement the closed hashing probing method.  Both methods use the previous `hash()` and `probe()` methods to implement the hash table probeing.

The purpose of `probeForAvailableSlot()` is to implement a probe sequence for a given `key` and return the first slot along the probe sequence that is "available".  A slot is "available" if it is either currently `empty` or it is `missing`.  Slots go missing when the are removed from the collection using the `remove()` API.

The `probeForKeySlot()` implements a hash probe sequence to search for a given `key`.  It should return the slot where the `key` is found, or if during the probe sequence an `empty` slot is encountered, this indicates a failed search, and the  `empty` slot will be returned to indicate this failed search.

**Suggested Solution**

The general algorithm for both private probe implementations is as follows:

1. Determine the home slot for the key using the `hash()` function.
2. Start at probe index 0
3. While not done
   - Calculate the probe slot by adding the home slot has and the probe
     offset calculated from `probe()` for the current probe index
   - test the resulting probe slot, if it is `empty` or `missing` then
     you are done, and you want to return this calculated probe slot
	 as your result of the location of the first missing or empty
	 slot along the probe sequence for this key.
   - otherwise keep searching by incrementing the probe index and returning
     back to the top of this loop task 3.


The only difference between the two is the test for when the probe sequence is done.  When searching for a `key` instead of the next available slot, you instead should test if the slot is either `empty` or contains the `key` that you are searching for, and return the slot in the probe sequence where either of those two conditions is detected.


**Additional Requirements**


- Both of these functions must be declared as `private` member
  functions of the `HashDictionary` class.
- Both of these functions are `const` member functions, they need to
  be declared as such.  They do not modify the hash table or instance
  in any way, they simply perform helper tasks for implementing the
  hashing algorithms of this class.
- All key and value parameters passed in to member functions in this
  class are required to be be declared as `const` reference
  parameters.
- Both of these function must make use of the `hash()` and `probe()`
  member methods to correctly implement the probeing sequence.
