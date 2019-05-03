# Module-8 [WIP]
> We've seen how we can declare, initialise, use, point, and pass variables around our code. But what if we want to group a some variables together? This is why structs [short for data structures] were made. 

## Introduction
Let's imagine a road. You see a car on that road, and think to yourself. That car has 4 wheels, 5 seats, an engine at the front, a large trunk, and is a 4Wheel-Drive vehicle. All those aspects are `members` of the `struct` car. This is exactly how structs work. 

## Declaration & initialisation
Let's translate what we learned about that car to C++ structures. 
```cpp
...

//First, we'll start by defining those aspects in a blueprint
struct carBlueprint{
  int wheels;
  int driveMode;
  int seats;
  string engineLocation;
  string trunkSize;
  void move(){
    cout << "The car is moving!\n";
  }
}; //Notice the semicolon after the brackets!

//Now let's create a car based on that blueprint
carBlueprint car = {4, 4, 5, "front", "large"}; //Looks similar to arrays doesn't it?
car.move(); //calls the method (when a function is inside a struct/object it's called method) and prints "The car is moving!"

...
```
## Accessing values of structs
We now have a car struct that has all those aspects. Let's imagine a car dealer creating an advertisement based on that car struct we created. How'd he be able to get those values? 
```cpp
...

cout << car.wheels; //outputs 4
cout << car.engineLocation; //outputs "front"

...
```
## There's another (uglier) way of declaring structs
```cpp
...

struct carBlueprint{
  int wheels;
  int driveMode;
  int seats;
  string engineLocation;
  string trunkSize;
} car;
//And then you start assigning values by accessing and assigning like so
car.wheels = 4; 
//If you don't do this, those values will be filled with garbage, so just go with the first way to ease your mind
...
```

## Nesting structs
Imagine a company (a struct) with employees (structs as well). 
```cpp
...

struct Employee
{
    short id;
    int age;
    double wage;
};
 
struct Company
{
    Employee CEO; // Employee is a struct within the Company struct
    int numberOfEmployees;
};

...
```

## Structure size
Typically, the size of a struct is the sum of the size of all its members, but that's not always the case! Sometimes the compiler will add gaps into structure memory size (called padding) for performance optimisation reasons. If you want to learn more [click here](https://en.wikipedia.org/wiki/Data_structure_alignment). This is optional to understand and won't help you understand how to use structures. But more knowledge is good.

## Note
Natively, you can't iterate over structures, but some **very** complex libraries can do it. For the scope of this tutorial, I'm not going to mention them. :P 