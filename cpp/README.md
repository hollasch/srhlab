Index of C++ Programs
====================================================================================================

Floating Point
---------------
- `constants.cpp` -- various C++ constant values and their literal decimal representation
- `float.cpp` -- float values, zero, NaN, infinity
- `float-close.cpp` -- the pitfall of using std::...epsilon() to determine closeness
- `floatEpsilonDiffTest.cpp` -- testing abs(a-b) < epsilon
- `fpsum.cpp` -- preserving precision when summing floats
- `rgbclamp.cpp` -- testing [0,1] clamping

Variables
----------
- `expr-vars.cpp` -- playing with comma-operator variable declarations
- `initialization.cpp` -- testing member variable initialization
- `scope-for.cpp` -- testing scope of variables declared in for-loops
- `scope-if.cpp` -- testing scope of variables declared in if-blocks

Std Library
------------
- `ignore.cpp`  -- Illustrate usage & effects of `std::ignore` for suppressing unused param warnings
- `istream.cpp` -- `std::istream `test (reads `istream-test.txt`)
- `ostream.cpp` -- `std::ostream` experiments

Std Containers
---------------
- `pair.cpp` -- playing with std::pair<>
- `sharedPtr.cpp` -- experiments with `std::shared_ptr`, `std::weak_ptr`
- `string.cpp` -- experiments with `std::string`
- `unordered_set.cpp` -- experiments with `std::unordered_set`

Language Features
------------------
- `partvirt.cpp` -- (crash) declaring non-virtual base dtor, plus virtual derived dtor
- `std-move-class.cpp` -- a class with `std::move` semantics
- `template-values.cpp` -- using templates to declare specialized value constants
- `variadic.cpp` -- experiments with variadic functions

Types
------
- `enum-bitfield` -- pitfalls of `enum`-based bitfields
- `type-collision.cpp` -- illustrates that new types via `using` are mere type aliases
