# Module-3
>In this module we learn the basic structure of any C++ console app, basic operations, constants, naming conventions, and scopes.

## The basic structure
Every console application programmed with C++ will most-likely look like this: 
```cpp

//This is a single-line comment!
/*
This is a multiline
Comment!
*/
#include <iostream>

using namespace std;

int main(){
  cout << "Hello, world!";
}

```
## Comments
Comments are lines of code that are not interpreted by your program, they are solely textual flavour for you as a developer to leave notes or explain why you used a certain function in a certain way. 

## #include \<iostream\>
C++ in its basic form is a stripped language. It doesn't support many things out of the box, but rather through what's known as **libraries**. Libraries are also called header files, and some end with **.h** in their name. What those libraries do is bring more functionality to the language such as the ability to print to the console or erase something from it. 

## using namespace std;
Let's imagine a kids playground, we will call this `std` (short for standard). You are a parent, and all the kids are playing in the playground. You're currently standing outside behind a wall, and are unable to see what's inside of there without passing through the main gate. Once you pass, you can see those kids. This is exactly how C++ handles its variables. Variables in C++ are declared in something called `namespace`. All the the extra functionalities that the library we `#include`d previously brought will be available in a specific namespace (referred to previously as playground). To access those functionalities we need to specify the namespace we're using in order to reach the functionalities. `\<iostream\>` uses `std` for all its functionalities, so we need to use that as our namespace to be able to reach the variables within it. This is what `using namespace std` allows us to do as it sets the default namespace as `std`.

## int main(){...}
This is the main engine that's going to start and will have all our `statements` that are going to be executed once our program runs. Without it the program won't even start. So we really need it. This is the main `function`, and we'll explain what a function is later on. 

## cout << "Hello, world!;"
All executable commands are called `statements`. This is one of them. In our case, we want to print something onto our console, and to do that we have to use something called `cout`. This allows us to print the value of a variable or a stream of text to the console. It prints everything to the right of the `<<` signs. This is also available in the `std` namespace, and without the `using namespace std;` line we would have to use it as follows:
```cpp
...

std::cout << "Hello, world!";

...
```
This is how we reference variables in different namespaces if we didn't use the namespace line. 

Every `statement` in C++ ends with a `;` semicolon. 

## Constants
These are a special type of variables. Their value can never be changed across the whole program. Only set. If you try to modify it the program will **throw** an error. 
```cpp
...

const int a = 5;

...
```
Or by using #define
```cpp
...

#define a 5

...
```
Note that we did not add a semicolon ; to the end of our statement using #define. Anything starting with # is a preprocessor attribute and shouldn't be allowed to be ended with a semicolon. Explained further in the tutorial.

## Basic operations and operators
Programming languages allow us to do all kinds of operations, and C++ is not different. Operators are: 
#### Assignment: 
```cpp
... 

int a = 5; 

...
```
#### Arithmetic operators
```cpp
...

int b = 5;
int a = ((5 * b + b - 5) / 5 ) & 2;

...
```
#### Compound assignment
```cpp
...

int a = 5; 
a = a + 5; //a is now 10

...
```
is equivalent to:
```cpp
...

int a = 5; 
a += 5; //a is now 10

...
```
There are other compound operators. For a full list visit this [page](http://www.cplusplus.com/doc/oldtutorial/operators/). 
#### Increment & decrement (x++, x--)
```cpp
...

int a = 5; 
cout << a++; //will print 5, but increase a by 1 after.
cout << a; //will print 6

...
```
on the other hand 
```cpp
...

int a = 5;
cout << ++a; //will increase a by 1 before printing the updated value which is 6
cout << a; //will print 6

...
```
## Naming conventions
When variables are named as `b`, `a` or any other gibberish letter, they become hard to understand and will often require more attention than needed, tiring whoever is reading your code and possibly causing you to lose marks if you're a student. It's considered best practice to use meaningful variable names and proper **casing** in order to make your code easy to understand. Doing so will almost always eliminate the need for comments. Some case styles are: 
1. camelCase (this is the most famous one)
2. snake_case
3. kebab-case also known as hyphen-case
4. PascalCase
5. UPPER_CASE_SNAKE_CASE
6. lowercase

Some good practices include:
1. Files should be named using kebab-case, snake-case or lower-case
2. Constants should be UPPER_CASE_SNAKE_CASE
3. Class names should be PascalCase
4. Other variables and functions are any other type, preferably snake_case or camelCase

## Scope
All the variables that we intend to use in a program must have been declared with its type specifier in an earlier point in the code, like we did in the previous code at the beginning of the body of the function main when we declared that a, b, and result were of type int.

A variable can be either of global or local scope. A global variable is a variable declared in the main body of the source code, outside all functions, while a local variable is one declared within the body of a function or a block.

![A simple illustration. Source: cplusplus.com](http://www.cplusplus.com/doc/oldtutorial/variables/scope_of_variables.gif)

Global variables can be referred from anywhere in the code, even inside functions, whenever it is after its declaration.

The scope of local variables is limited to the block enclosed in braces ({}) where they are declared. For example, if they are declared at the beginning of the body of a function (like in function main) their scope is between its declaration point and the end of that function. In the example above, this means that if another function existed in addition to main, the local variables declared in main could not be accessed from the other function and vice versa.

## Note
It is not recommended to always use `using namespace std;` because of possible conflicts, but for the sake of simplicity, we will be using it.

## Extra
You can run the module-3.cpp file supplied with this module to check how main() and cout work. 
>You can use [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler) to run C++ code in the browser if you don't have a compiler on your machine. You can also use Visual Studio, CodeBlocks, JetBrains CLion, or any other [IDE](https://en.wikipedia.org/wiki/Integrated_development_environment). 

## Up next
Arrays, handling user input (using cin), Strings
