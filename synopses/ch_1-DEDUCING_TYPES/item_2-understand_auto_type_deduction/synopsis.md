understand auto type deduction
==============================


common
------

```c++
template <typename T> 
void f(ParamType parameter); 

f(expr); 
```

when a variable is declared using "auto", 
"auto" plays the role of "T" in the template,
and the type specifier for the variable acts as "ParamType"

so the next snippets are "equal"

```c++
auto x = 27;

// and
template <typename T>
void f_for_x(T param);

f_for_x(27);
```

```c++
const auto cx = x;

// and
template <typename T>
void f_for_cx(const T param);

f_for_cx(x);
```

```c++
const auto& rx = x;

// and
template <typename T>
void f_for_rx(const T& param);

f_for_rx(x);
```

and rules for template type deducing can be applied


auxiliary
---------

- "auto" type deduction assumes that a braced initializer 
  represents a "std::initializer_list",
  and template type deduction doesn't
- "auto" in a function return type or a lambda parameter
  implies template type deduction, not "auto" type deduction

