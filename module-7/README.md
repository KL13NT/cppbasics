# Module-7
> In this module, we learn about pointers, their benefits, use cases, when and when not to point, and dynamic memory 


## Pointers are royal servants
Imagine this scene with me. A king has just written a message and wants that "original" message delivered to another king without modification. What he'd normally do is give it to a messenger and order that messenger to deliver this specific message on this specific piece of paper to the other king and to tell that other king the address of who sent the message. This is exactly what a pointer does, deliver a message content (in this case, this is the value of a variable) and sender location (the memory address of that variable) to another. 

> A pointer in itself is a variable that has a memory address and value, contains the address of the variable pointed to, and allows us to access the original value and modify it as we please.  

## How to declare and use a pointer
Pointers can be confusing at first, but once you get a grasp of the concept and get some hands-on experience using them, which you will, they'll turn out to be really easy. 
#### Declaration
```cpp
...

int* pointerName;

...
```
This creates a non-initialised pointer, that points to absolute garbage the compiler generated just like it does with arrays. Pointers are specific in that you have to specify the type of variable you're going to be pointing to, so you add the type and the name just like any normal variable but with the exception of the asterisk `*`. The asterisk `*` will be used later in another way, but for now let's call it the declaration asterisk.
#### Initialisation and referencing other variables
```cpp
...

int normalInteger = 5; 
int* integerPointer = &normalInteger;

...
```
This pointer `integerPointer` now points to the memory address of `normalInteger`. The and `&` sign grabs the memory address of the following variable (in this case `normalInteger`) and assigns it to the integerPointer. We can now pass this pointer around and whenever we use it we'll be able to access the original variable `normalInteger` (with some minor exceptions depending on scope and whether the variable pointer to still exists in the memory). You're probably asking yourself now, what would knowing the address of a variable benefit me? 
#### The de-reference operator
Let's imagine a room filled with boxes, each box labelled with a name and contains some toy. A person goes into the room with a list in his hand with all box labels and their contents. He picks one off the list and opens the corresponding box to allow himself to **see** the toy inside. 
```cpp
...

int normalInteger = 5; 
int* integerPointer = &normalInteger; //integerPointer now has address of normalInteger
int anotherNormalInteger = *integerPointer; //anotherNormalInteger now equals 5

...
```
This is it. The room is your RAM and the boxes are memory cells that each one of them has a specific address. The person looking around is the program and in his hand is the `*`. After a pointer has been declared and assigned an address of another variable, we can access that pointed-to variable value by using the asterisk `*`. 
## Benefits of using pointers
Before going into how to operate a pointer, let's learn some facts first. It's impossible as you know to declare a function inside another one, pass a function as a parameter to another function (aka callback), create a dynamic array, or pass variables around while being able to reference the original one. Pointers come to solve all of these problems. With pointers we can: 
1. Iterate through an array (as an alternative to array indices)
2. Dynamically allocate memory. This is by far the most common use case for pointers
3. Pass a large amount of data to a function in a way that doesn’t involve copying the data, making your program more efficient
4. Pass a function as a parameter to another function
5. They can be used to have one struct/class point at another struct/class, to form a chain. This is useful in some more advanced data structures.
## Basic operations using pointers
These are the most basic operations you can do with a pointer, and they're the foundation of your usage of them. 
```cpp
...

int normalInteger = 5; 
int* integerPointer = &normalInteger;
int anotherNormalInteger = *integerPointer; //anotherNormalInteger now equals 5
*integerPointer = 6; //sets normalInteger to 6
cout << normalInteger; //prints 6


...
```
## Intermediate points 
This is called *passing by reference*.
```cpp
...

#include <iostream>

using namespace std;

void firstFunction(int* pointerToOriginalVariable){ //declares parameter as pointer to receive the passed pointer
  int differentVariable = *pointerToOriginalVariable; //assigns value of variableToChange to differentVariable
  differentVariable = 9; //sets differentVariable to 9, notice it doesn't change the original variableToChange
  cout << differentVariable << endl; //prints 9
  *pointerToOriginalVariable = 10;  //sets variableToChange to 10
  cout << *pointerToOriginalVariable << endl; //prints 10
  cout << differentVariable << endl; //prints 9, notice that changing the original pointed-to variable doesn't change this one 
}
void secondFunction(){
  int variableToChange = 4; 
  int* toChangePointer = &variableToChange; //points to variableToChange
  firstFunction(toChangePointer); //passes the pointer
  cout << variableToChange << endl; //notice the changed value!
}
int main(){
    secondFunction();
}

...
```
This example demonstrates one of the most common use-cases for pointers. Normally, if we didn't pass a pointer, the `variableToChange` wouldn't change in `secondFunction()`'s cout.

## Passing arrays by reference
Arrays by nature are stored in memory in the same order you write them. So if you type {1,2,3} in an array variable of size 3, the second element will exist in the memory address following the one where the first element is located and so on. When you create a pointer to an array, it points to the first element of **that** array and given the fact they're stacked next to each other in our memory gives us the possibility of reaching all the elements by just adding `1` to the address. 
```cpp
...

int name[2] = {2,3};
int* namePtr = name; //This points to the first element of the array
cout << namePtr; //Output the memory address of the first element. On my machine this yields the following address: 0x7ffe12b021e0
cout << namePtr + 1; //yields 0x7ffe12b021e4, this is the address of the second element
cout << *namePtr; //yields 2
cout << *(namePtr + 1); //yields 3

...
```
This allows us to pass arrays to functions the same way we would pass a normal array, but with the benefit of being able to modify the original array.

## A breif into to dynamic memory allocation 
There are three ways to declare variables and assign memory to them. 
1. Static
2. Automatic
3. Dynamic

We've seen the first two ways in things like `int array[5];` and locally scoped variables. But what about dynamic? C++ allows us to specify the amount of memory we want for a specific variable, instead of just letting it automatically do the work for us. This is possible using the `new` and `delete` operators. This way has its own downfalls, and most people don't recommend it because of the issues that could arise because of it. But, nonetheless, if we're careful enough and are good enough, hopefully we won't waste any memory or crash our program! Consider the following:
```cpp
...

char name[25]; // let's hope their name is less than 25 chars!

...
```
This is all fun and games till the user inputs something bigger than 25 letters for their name, and it all goes haywire. This is where dynamic memory allocation becomes useful. Consider the following instead:
```cpp
...

int *ptr = new int; // dynamically allocate an integer and assign the address to ptr so we can access it later

...
```
Why do we use pointers here? In C++, we add the type of the variable before its name, so if we do `int integer = new int;` this will return an error because `new int` returns a pointer. That's why we need to assign it to a pointer variable. 

## Dangling pointers 
We learned how we can create variables dynamically using pointers and we know that variables get terminated when the scope they're declared in is terminated. Consider: 
```cpp
...

void functionOne(){
  int i = 5;
  cout << i; //prints 5 and terminates function
}
...
in main(){
  functionOne();
  cout << i; //undefined! because the variable has been terminated with the function
}

...
```
This is not the case with dynamic variables. Variables declared with `new` need to be deleted using `delete` because their allocated memory stays allocated until it is explicitly deallocated (using `delete`) or until the program ends. Many programmers don't realise this or forget it, leading to to memory leaks. But another problems comes to existence when you delete a variable pointed to by a pointer. The pointer now points to nothing. This is called a `dangling` pointer. When you delete a pointer, if that pointer is not going out of scope immediately afterward, set the pointer to 0. Consider:
```cpp
...

void doSomething(){
    int *ptr = new int;
}

...
```
This function creates a variable pointed to by *ptr. The pointer gets terminated with the termination of the function, but the allocated memory doesn't free up, leading to a memory leak. Memory leaks can occur if a pointer holding the address of the dynamically allocated memory is assigned another value as well.

## Dynamic arrays
```cpp
...

int *array = new int[numberOfElements]; //This number could be any integer, variable or user input. As long as it represents a number.
array[0] = 5; // set element 0 to value 5
delete[] array; // use array delete to deallocate array. This is a special delete for arrays.

...
```
This way is different from the static way however, because as we've learned, variables created with `new` return pointers and not actual types normally. The downside here is that things like `sizeof()` won't be available for dynamically allocated arrays because originally they're pointers and thus they don't know the exact length of the array pointed to. It's your responsibility of knowing how long an array is if you're going this way. 

## Extra
The size of a pointer depends on the processor architecture. If you're running a 32bit processor (and assuming your OS is the same) then all pointers in your code are going to be 32bit in size, regardless of the actual data size being pointed to.
 
## Note
Using `new` doesn't guarantee that it will be successful. The host machine could be running low on memory, and therefore there will be no available memory for your program, causing the `new` operator to fail.


