/** @file Employee.hpp
 * @brief Basic example user defined class to hold Employee record.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Dictionaries and Hashing
 * @date   June 1, 2021
 *
 * @description Simple example of an Employee record/class
 *   we can use to demonstrate  key/value pair
 *   management.
 */
#include <string>
#include <iostream>
using namespace std;


#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP


// This should really be a class constant, however this
// global constant represents a flag that is used to
// indicate empty slots and/or failed search.
//const int EMPTY_EMPLOYEE_ID = 0;
//const int MISSING_EMPLOYEE_ID = -1;

/** Employee
 * A simple Employee class/record to demonstrate/test
 * our hashing dictionary assignment.
 * NOTE: we are using 0 as a flag to represent an unused
 * slot or an invalid/empty employee.  This is used/assumed
 * by our dictionary class to determine if a slot is empty
 * and/or to give a failure result for a failed search.
 */
class Employee
{
private:
  /// @brief The key/index of this Employee record
  int id;

  /// @brief The full name of the Employee.  In a real database
  ///   record we would need multiple fields, e.g. first, last, title, etc.
  string name;

  /// @brief The employee's address.  In a real database this would most likely
  ///   need to be a separate class with fields like street1, street2, state,
  ///   zipcode, etc.
  string address;

  /// @brief The employee's current salary information.  Represents other types of
  ///   information we might need to organized and work with employees in a database.
  float salary;

public:
  // constructors and desctuctors
  Employee();
  Employee(int id, string name, string address, float salary);

  // accessor and information methods
  int getId() const;
  string getName() const;
  string str() const;

  // class friend function and friend overloaded operators
  friend ostream& operator<<(ostream& out, Employee& employee);
};

#endif // EMPLOYEE_HPP