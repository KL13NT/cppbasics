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

Given that the problem of sorting an array is a common one amongst the members of Valarium, it has been decided that we shall post solutions to that problem. 
There are numerous algorithms of sorting an array, but we'll mention one of the most popular and novice-friendly one known as "Bubble sorting".

The algorithm is fairly simple, you take each element and compare it against the whole array, swapping it with whichever element bigger/smaller (depending on whether you're ascending or descending) than the one we're holding. 

```cpp
void BubbleSort(){
    int arr[5] = {1,5,2,3,4};
    int temp;
    for(int i = 0; i < 5; i++){
      for (int j = 0; j < 4; j++){ //walks over all elements of the array to compare values
           if (arr[j+1] > arr[j]){ //compares the current with the following
                int temp = arr[j]; //temp to save the value for swapping
                arr[j] = arr[j+1]; //swapping
                arr[j+1] = temp;
           }
        }
    }
}
```
Tracing first pass: {1,5,2,3,4}
1. 5 > 1, Swap 1,5 {5,1,2,3,4}
2. 2 > 1, Swap 1,2 {5,2,1,3,4}
3. 3 > 1, Swap 1,3 {5,2,3,1,4}
4. 4 > 1, Swap 1,4 {5,2,3,4,1}

Tracing second pass: {5,2,3,4,1}
1. 5 > 2, don't swap
2. 3 > 2, Swap 3,2 {5,3,2,4,1}
3. 4 > 2, Swap 2,4 {5,3,4,2,1}
4. 2 > 1, don't swap

Tracing third pass: {5,3,4,2,1}
1. 5 > 3, don't swap
2. 4 > 3, Swap 3,4 {5,4,3,2,1}
3. 3 > 2, don't swap
4. 2 > 1, don't swap

End.

Resulting array is {5,4,3,2,1}

## EXTRA EXAMPLES ON STRUCTS
Imagine you're standing on a side-walk, people all around. Each person is a struct. 
```cpp
...

struct personDescription{ //defining personnel attributes and descriptions
  string name;
  int age;
  int height;
  int weight;
};

//Using the created struct blueprint
personDescription person1 = {"John", 19, 185, 72}; 
personDescription person2 = {"Doe", 26, 155, 56};
personDescription person3 = {"AnaWadGamedGedan", 13, 130, 50};
personDescription person4 = {"AnaBanota7elwaAwy", 14, 120, 45};

struct personDescription arrayOfPersonnel[4] = {person1, person2, person3, person4}; ///declaring an array of people

for(int i = 0; i < 4; i ++){
  cout << "Name: " << arrayOfPersonnel[i].name << endl;
  cout << "Age: " << arrayOfPersonnel[i].age << endl;
  cout << "Height: " << arrayOfPersonnel[i].height << endl;
  cout << "Weight: " << arrayOfPersonnel[i].weight << endl;
  cout << "\n\n";
}

...
```

This time you're in an airport, planes all around. 
```cpp
...

struct plane{ //defining aeroplane attributes and descriptions
  string name;
  int passengerCount;
  int weight;
  int flights;
};

struct plane arrayOfPlanes[4] = {
  {"Airbus A380", 200, 50, 15},
  {"Boeing 747", 300, 50, 17},
  {"Boeing 777", 400, 35, 9},
  {"Airbus A340", 350, 70, 2}
};

for(int i = 0; i < 4; i ++){
  cout << "Airplane Model: " << arrayOfPlanes[i].name << endl;
  cout << "Passenger count: " << arrayOfPlanes[i].passengerCount << endl;
  cout << "Weight: " << arrayOfPlanes[i].weight << endl;
  cout << "Flight count: " << arrayOfPlanes[i].flights << endl;
  cout << "\n\n";
}

...
```
You're in a library, containing books of course!
```cpp
...

struct book{ //defining book attributes and descriptions
  string name;
  string author;
  int pages;
};

struct book Library[4] = {
  {"Cantu Torres", "Pitts", 327},
  {"Marjorie Rodriguez", "Perkins", 70},
  {"Cross Randolph", "Foster", 398},
  {"Shannon Keller", "Kinney", 418}
};

for(int i = 0; i < 4; i ++){
  cout << "Book name: " << Library[i].name << endl;
  cout << "Book author" << Library[i].author << endl;
  cout << "Book pages: " << Library[i].pages << endl;
  cout << "\n\n";
}

...
```