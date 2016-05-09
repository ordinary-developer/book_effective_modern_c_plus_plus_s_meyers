alternatives to overloading on universal references
===================================================


abandon overloading
-------------------

you can avoid overloading on universal references by simply using
different names for the would-be overloads (this approach won't work
for constructors, because constructor names are fixed by the language)


pass by const T&
----------------

you can replace pass-by-universal-reference with 
pass-by-lvalue- reference-to-const;  
the drawback is that the design isn't as efficient as we'd prefer


pass by value
-------------

you can consider passing objects by value when you know you'll copy
them 


use tag dispatch
----------------

if the motivation for the use of a universal reference is perfect
forwarding, we have to use a universal reference

a universal reference parameter generally provides an exact match
for whatever's passed in, but if the universal reference is part
of a parameter list containing other parameters that are not
universal references, sufficiently poor matches on the non-universal
reference parameters can knock an overload with a universal
reference out of the running  
that's the basis behind the tag dispatch approach

a keystone of tag dispatch is the existence of a single (unoverloaded)
function as the client API; this single function dispatches the work
to be done to the implementation functions


constraining templates that take universal references
-----------------------------------------------------

if we have perferct-forwading overloaded constructors
the real problem is not that the compiler-generated functions
(i.e., copy and move constructors) sometimes bypass the tag dispatch
desigen, it's that they don't alwasy pass it by

by default, all templates are *enabled*, but a template using 
*std::enabled_if* is enabled only if he condition specified by
*std::enabled_if* is satisfied

we can enable *our class*'s perfect forwarding constructor only if the
being passed isn't *our class*; if the type being passed is 
*our class*, we want to disable the perfect forwarding constructor
(i.e., cause compilers to ignore it), becuase that will cause the
class's copy or move constructor to handle the call, which is what
we want when an *our class* object is initialized with another 
*out class* instance


summary
-------

- alternatives to the combination of universal references and
  overloading include the use of distinct function names, passing
  parameters by lvalue-reference-to-const, passing parameters by value,
  and using tag dispatch
- constraining templates via std::enable_if permits the use of
  universal references and overloading together, but it controls
  the conditions under which compilers may use the universal
  reference overloads
- universal reference parameters often have efficiency advantages,
  but they typically have usability disadvantages

