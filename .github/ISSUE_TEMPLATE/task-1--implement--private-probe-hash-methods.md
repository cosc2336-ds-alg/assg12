---
name: 'Task 1: Implement `HashDictionary` private `probe()` and `hash()` Methods'
about: Task 1 for Students
title: 'Task 1: Implement `HashDictionary` private `probe()` and `hash()` Methods'
labels: enhancement, good first issue
assignees: ''

---

**Description**

For task 1 implement private `probe()` and `hash()` methods as described.  This implement the basics of the quadratic probing sequence and the mid-square hash function, as described in our Shaffer textbook section 9.4.3.

**Suggested Solution**

The `probe()` function should be a simple calculation.  You should use `c1 = 1, c2 = 2, c3 = 2` as the parameters of the quadratic function that calculates the probe offset for the quadratic probing.

For the `hash()` function, perform the following steps:

1.  First of all, you should square the `key` value that is passed
    in. However do not use the `<cmath>` library function to square
    the key, since this will return back a `double` result.  Simply
    multiply the `key` by itself to square it.  **HINT**: since you
    should be passing this parameter in as a `const` reference, you
    might find the compiler complains if you try and assign a new
    value back into the `key` parameter you pass in.  You may need to
    make a local copy of the `key` to manipulate for your hash
    function here.
2. Then, assuming we are working with a 32 bit int, we want to only
   keep the middle 16 bits of the square of the key to use for our
   hash, which is the 'mid' part of the mid-square hashing.  There are
   many ways to work with and get the bits you need, but most likely
   you will want to use C bit-wise operators to do this.  For example,
   a simple method to get the middle 16 bits is to first mask out the
   upper 8 bits using the bit-wise & operator (e.g. `key & 0x00FFFFFF`)
   will mask out the high order 8 bits to 0).  Then once you have
   removed the upper most significant 8 bits, you can left shift the
   key by 8 bits, thus dropping out the lower least significant 8 bits
   (e.g. `key >> 8`).  Performing a mask of the upper 8 bits and
   shifting out the lower 8 bits will result in you only retaining the
   middle 16 bits.
3. Finally, after squaring your key and getting the middle bits of the
   key, you need to recast the resulting index into the range
   from 0 to the maximum size of the current hash table minus 1.
   For the `HashDictionary` instance, the member variable `allocationSize`
   keeps track of the current size of the hash table, so you will need
   to use modulus arithmetic to recast your result into the correct
   range to be a proper hash index.
4. Return this calculated hash index slot as the result from your
   `hash()` function.

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
  
