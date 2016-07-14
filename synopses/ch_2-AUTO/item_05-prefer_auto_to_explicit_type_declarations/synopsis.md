Prefer auto to explicit type declarations
=========================================

Common
------

The advantages of auto:
- avoidance of uninitialized variables;
- verbose variable declarations;
- ability to directly hold closures;

std::function object can refer to any callable object.

The "std::function" approach is generally bigger and slower than
the "auto" approach.