# Module-1 
> In this module we learn the basic foundation of C++, data types. 

## What are data types?
Data types are how computers understand what we type. We as humans have the tendency to naturally recognise words and numbers separately just by looking at them, because our minds are that complex. But for computers, it's different. Computers work with *zero*s and *one*s, and thus they won't be able to distinguish words from numbers, and here comes the role of data types. Each data type gets translated to a specific set of zeros and ones, ordered in a very specific way that allows computers to comprehend them. And there are different categories of those.

## Main characteristics of data types
Data types have different lengths and ordering, some can be converted (cast) to other types while others can't. Some are longer than others, and we will illustrate that in a minute.

## Categories of data types
There are 2 categories, or 3. 
1. Primitive Types
2. Abstract/User-Defined
3. Modifiers (Not really data types but could be considered as such)


## 1. Primitive/Fundamental Data Types
These are the data types that every program needs. Without them, you won't be able to store a number in a computer, retrieve that number, store textual data, or any other kind of data that a computer could possibly work with. The most widely used ones are (Ordered by capability of casting): 
1. Characters (char)
2. Integers (int) -2,147,483,648 to 2,147,483,647
3. Boolean (bool)
4. Floating-Point (float)
5. Double Floating-Point (double)

Characters can be cast into integers using ASCII conversion, integers can be turned into booleans as (0 is false) and (1 is true) which is basic binary logic, and so forth. 

With a (char) you can store only one character. In C++, to store a single character you need to use single-quotes ' '

## 2. Abstract data types
Abstract data types are the ones that the user defines, they are not natively supported by the compiler until the very moment you define them yourself in your program. 

## 3. Modifiers
Modifiers are keywords used before Primitive types to extend their functionality. Such as using "short int" *-32,768 to 32,767* instead of "int" *-2,147,483,648 to 2,147,483,647* to represent a smaller integer value than what "int" can natively store. The most widely used ones are: 
1. Signed
2. Unsigned
3. Short
4. Long

You can also chain them! So you can say "long long int" *-(2^63) to (2^63)-1* to represent integers longer by billions!  
## Type Casting
Type casting is the process of converting (casting) a variable from a type to another type. It has a few casting operators which are used to cast variables using different methods from overriding constants type all the way to dynamic casting. But for the sake of simplicity I'll only explain the most basic form. 
```cpp
...

int integer = 65; //The ascii character for 65 is the letter 'A'
char charFromInteger = (int) integer; //The () act as the type casting operator in this case, and it awaits the type you want to convert to between the brackets.
float floatFromChar = (float) charFromInteger + 0.55;
double doubleFromFloat = (double) floatFromChar + 0.00005; 
int integerFromDouble = (int) doubleFromFloat; //This will round or floor the double to fit it into an integer. 
long long int integerFromInteger = integerFromDouble;
double doubleFromLongInteger = (double) integerFromInteger + 0.0005;

...
```
If we place a cout for each of those variables the output will be respectively the following: 
```cpp
65
A 
65.55
65.5501
65   
65   
65.0005  
``` 
