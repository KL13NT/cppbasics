# Module-6
> Functions are parts of code with specific names that allow you to run that code whenever you like by "calling" them. In this module, we learn all about functions, revisit namespaces and some meaty switch hacks.

## Introduction
Ever felt that loops weren't doing it for you? Want your code to be executed whenever you want? Want more control over your loops? Think loops look ugly? Say no more! Functions are here, and we're ready to take off with em!
> A **function** is a reusable sequence of statements designed to do a particular job.
You already know that every program must have a function named main (which is where the program starts execution when it is run). However, as programs start to get longer and longer, putting all the code inside the main function becomes increasingly hard to manage. Functions provide a way for us to split our programs into small, reusable chunks. Most programs use many functions. The C++ standard library comes with plenty of functions and you can write your own functions as well.

## Types of functions 
There are two types of functions: 
1. Return Functions 
2. Void Functions


## Declaration & Definition
To declare a function you basically follow this: `return_type function_name(parameters){...}`. Let's explain each part of that declaration. For the sake of feasibility we'll use this mathematical equation:  `F(x) = 2x + 1, x ∈ Z+`

#### Return Type
Let's remember some Maths. In our equation, function `F(x)` would take an integer `x`, put it through that equation and then return the value as an integer as well. This is exactly what we mean. Return type is the `type` of `value` that the function will return. They're the same types as the ones we mentioned in Module-1. A function with any return type but `void` is called a `Return Function`.

#### Parameters
This is the variables that we want our function to work on. Normally, functions can work without any parameters, but conveniently, we usually want the function to calculate some result based on a set of passed parameters and return that result. The way to specify and use parameters is the same as normal variables: 
```cpp
...

int square(int x){ //you declare the type and name of the parameter.
  return x * x; //you use it like a normal variable
}

...
```
## Calling a function
The normal flow of any program is that it executes statements top-down. But when it encounters a function call it pauses execution of the current context, goes to the function and executes it, and then when the function's job is completed, the program continues running the code where it stopped before the call. Any function can call any other function, including itself (this is called recursion and will be explained in later modules). The syntax is: `functionName(parameter values);`

## Passing parameters and arguments by value
You can pass the values stored inside variables to functions by typing the variable name in the function call. This is called pass by value. Consider the following: 
```cpp
...

int passedVariable = 5; 

void printInteger(int variableToPrint){
  cout << printInteger;
}
...

printInteger(passedVariable);

...
```
Notice that the actual variable name is different than the parameter name? That's normal. The name of the parameter is only available to the function, and when you pass in the `passedVariable` the program assigns the *value* of that variable to the parameter so you can use that value by referring to the parameter name. A parameter value is called argument when passed to the function call.

Example: 
```cpp
...

int first = 5; 
int second = 5; 
int add(int x, int y){
  return x + y;
}
...

cout << add(first, second); //This will print 10

...
```
## Modifying variables not in local scope using functions
Our functions so far use values that are local to them, they don't modify external values. What if we want the function to modify a variable that's not inside of its local scope? There are two possible cases. 
1. The variable is available in the global scope
2. The variable is available in another local scope that the function doesn't have access to
   
For the first case, consider:
```cpp
...

int first = 5;  
int modifyFirst(){
  first++;
  return first;
}
...

cout << modifyFirst(); //This will set "first" to 6 and return 6

...
```
in this example, the global "first" is available to the functions as its available in the global scope, thus allowing the function to edit its value by referencing the variable name. 

As for the second case, that would be called passing by reference. We'll discuss this in module-7, pointers. As for now, let's go over some function usage examples. 
```cpp
...


int multiply(int x, int y){
  int result = x * y;
  return result;
}
int add(int x, int y){
  int result = x + y;
  return result;
}
...

cout << add(multiply(5,5), 5);  

...
```
Here we have two functions, one that multiplies two integers and returns the result, and the other adds two integers. Note that even though parameter names are the same, their values are actually different. This is because they're declared in local scope, so after a function terminates the variables declared within (in this case x, y, and result) will be deleted from the memory as well. In the `cout` statement we call the function `add` with the result of running the function `multiply` over 5 and 5. You can do that for as many levels of depth as you want, but it's usually recommended to only do it for a maximum of 3 levels. 

## Another way to define functions
In the previous ways we defined the function and its body in the same block. We could do something called "prototype definition" or "Forward declarations" which is as follows: 
```cpp
...

int add(int x, int y); //We tell the compiler that there will be a function called add
int main(){...}
int add(int x, int y){...} //We define what add does

...
```
This way is useful for when you want to organise your code in a different way. But what if we want to call a function that calls the function we're calling it from? This wouldn't be possible as one of them would be declared after the other, thus not being available in the global scope yet for the first function. Consider:
```cpp
...

void firstFunction(){
  secondFunction(); //This call is invalid because the function secondFunction is not declared yet
}
void secondFunction(){
  firstFunction();
}

...
```
A new problem arises with this, as this declaration might be essential to our program. To solve this, we can use header files, which will be explained later.
## Notes
It's best practice to always return a value from return functions. 

#### When and how to effectively use functions 
1. If you code has repeated logic. 
2. When a function becomes too long, too complicated, or hard to understand, it can be split into multiple sub-functions. 
3. Code that has a well-defined set of inputs and outputs is a good candidate for a function, particularly if it is complicated. For example, if we have a list of items that we want to sort, the code to do the sorting would make a great function,even if it’s only done once. The input is the unsorted list, and the output is the sorted list.
4. Once a function is written, it can be called multiple times from within the program. This avoids duplicated code (complying with DRY principle) and minimizes the probability of copy/paste errors.
5. When we need to extend our program to handle a case it didn’t handle before, functions allow us to make the change in one place and have that change take effect every time the function is called. 
6. In order to use a function, you only need to know its name, inputs, outputs, and where it lives. You don’t need to know how it works, or what other code it’s dependent upon to use it. 

#### Functions can't be nested in other functions. Only their calls can, but not the declaration of the function. This is invalid: 
```cpp
...

void outerFunction(){
  void innerFunction(){...}
}

...
```  