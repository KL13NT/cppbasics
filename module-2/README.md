# Module-2
> In this module we learn how to store information throughout our program, using variables. 

## What are variables?
A computer memorises data in 2 ways, either by storing to the Hard Disk Drive (HDD) *which is not the way we're doing it here* or by storing them in the Random Access Memory (RAM) aka memory *which is used in this course*. Every RAM is split into tiny blocks called cells, each cell can store a specific amount of data. This is where our program is going to store all those integers and floats and characters. Variables on the other hand are our data, they are stored in the RAM in a specific way using specific names that we declare (known as variable declaration) and can be accessed by referencing that name. Every variables takes up a few memory cells, that's why you should watch out when declaring variables. Use the right size and type that you need for your variable to save computer resources.

## Main characteristics of variables
Variables can be declared, accessed, deleted and referenced in different ways. They have naming rules that if broken, the program will show an error (aka throwing errors). Those naming rules are different from a programming language to another but in C++ they are as follows:
1. Can contain only Alphanumerical letters and the underscore **_**
2. They can only start with letters, not numbers. And can also start with **_**
3. There are "Keywords" in the language such as "int" and "short" that you can't use for your own variables. Refer to the [Identifiers section here](http://www.cplusplus.com/doc/oldtutorial/variables/)
4. Variable names are case-sensitive. Meaning that "name" is not the same as "Name".



## How do you use variables?
Variables go through 3 stages normally. (This can change depending on how you structure your program): 
1. Declaration & initialisation
2. Assignment
3. Termination

## 1. Declaration
To declare a variable is to tell the computer that there's a new variable in your program, and initialise some space in the memory depending on the size and type of *that* variable. 

You can declare them in the following way: 
```cpp
int a;
char b;
double c;
```
If you run those instructions, the computer will give you the ability to use the value stored in those variables by referencing their names, just like how you'd call another human by their name. *Don't forget that variable names are case-sensitive.*

## 2. Assignment
Assignment is the stage in which we give the variable a specific value. It is done by using the assignment (**`=`**) operator. 
```cpp
a = 5;
b = 'A';
c = 2.52;
``` 
What the assignment operator does is store the right-hand side value in the left-hand side variable. Possible exceptions that will cause your program to **throw** an error OR cause confusion to you are:
1. If the variable you're trying to store the value into was not previously declared. (**will throw**)
2. If you're trying to store a different data type into it. (**could confuse**, this is type casting, next module.) `int a = 'A';` for instance.


## 3. Termination
After a variable has been used and its value is not needed anymore, it is removed from the computer memory to allow other variables to be stored. This happens every time your program is closed, you use the `delete` keyword, or the **scope** changes. We will talk about all of those in the upcoming modules.

## Extra
You can also do step 1 and 2 on the same line such as: 
```cpp
int a = 5; 
char b = 'A';
double c = 2.52;
```
This is known as 'initialising a variable'.

You can chain declaration of variables of the same type as well:
```cpp
int a, b, c, f;
char z, n, m;
```
This is equivalent to:
```cpp
int a;
int b; 
int c;
int f;
char z;
char n;
char m;
```
## Note
Initialising a variable is different than initialising memory as mentioned in section *1. Declaration*.

A computer automatically initialises memory for our variables, meaning that our variables now are free to use a specific amount of memory cells that no one else can access but that variable. Initialising a variable on the other hand is a manual process done by us if we want to combine steps 1 and 2.

## Up next
The basic structure of any C++ application, basic variable operations, scope, and naming conventions.
