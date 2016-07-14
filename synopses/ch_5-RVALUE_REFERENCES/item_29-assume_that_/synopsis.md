Assume that move operations are note prsent, not cheap, and not used
====================================================================

Base
----

Many types fail to support move semantics.
- For types in your
- For types in your applications where no modifications for C++11
  (only old C++98 code) have been made, the existence of move 
  support in your compilers is likely to do you little good.
  True, C++11 is willing to generate move operations for classes 
  that lack them, but that happens only for classes declaring
  no copy operations, move operations, or destructors.
- Data members or base classes of types that have disabled moving
  (e.g., by deleting the move operations) will also suppres
  compiler-generated move operations.
- For types without explicit support for moving and that don't
  qualify for compiler-generated move operations, there is no reason
  to expect C++11 to deliver andy kind of performance improvement
  over C++98

Data for a std::array's contents are stored directly in the 
std::array object. Thus moving from one std::array to another runs
in linear time because all elements must be moved

There are thus several scenarios in which C++11's move semantics 
do you no good:
- *No move operations:*   
  The object to be moved from fails to offer move operations.
  The move request therefore becomes a copy request.
- *Move not faster:*  
  The object to be moved from has move operations that are no faster
  than its copy operations.
- *Move not usable:*
  The context in which the moving would take place requies a move
  operations that emits no exception, but that operation isn't 
  declared noexcept.

It's worth mentioning, too, another scenario where move semantics
offers no efficiency gain:
- *Source object is lvalue:*  
  With very few exception only rvalues may be used as the source
  of a move operation.


Summary
-------

- Assume that move operations are not present, not cheap, 
  and not used.
- In code with known types or support for move semantics, there is
  no need for assumptions