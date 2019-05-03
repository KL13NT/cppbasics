# Module-4
>In this module we learn basic array operations, strings, cin, and cout.

## The basic structure
Every console application programmed with C++ will most-likely contain cin and cout, they are used to take input and push output as follows: 
```cpp
...

int userInput;
cin >> userInput; //user inputs number 2 for instance
cout << userInput << endl; //output "2"
cout << "This is called standard output using COUT\n";
cout << "The \\n characters in the last sentence have special meaning.\n"; 
cout  << "As you might have already guessed, they make the output go onto a new line\n";
cout << "The slash in them is called an escaping character, more on that later.\n";

...
```

## Arrays
Arrays are a collection of things of the same type, they can be integers, characters, floats, any basic data type of the ones that we mentioned is available at your disposal to create an array with. 

#### Creating arrays
The syntax to create an array is pretty straightforward: `data_type array_name[array_size] = {initialisation values}`
```cpp
...

int myArray[5] = {1,2,3,4,5};
int mySecondArray[5] = {1,2,3};
int myThirdArray[5];

...
```
Arrays are static, meaning that when you set its size, you can't change that size. Looking at the example, we have created 3 arrays with the size of 5 elements. The first one had all five elements initialised with its declaration. The second one on the other hand had only 3 elements when initialised, this tells the program to set the first 3 elements to the values we provided, and fill the rest with zeros or just plain dummy data, depending on the type of array you're creating and the compiler used. 

#### Filling specific positions
Array elements can be accessed using the square bracket notation `[]` where the index of the element goes between the brackets. The first element of the array has an index of 0 and the last has an index equivalent to `size_of_array - 1`.
```cpp
...

int mySpecificallyFilledArray[5];
mySpecificallyFilledArray[0] = 2;
mySpecificallyFilledArray[3] = 3;
mySpecificallyFilledArray[1] = 1;

...
```
In this example, we fill the first element with index [0] with the integer value 2, the fourth element [3] with value 3 and the second element [1] with value 1. This is how you can fill specific positions of the array, and you can as well retrieve those values the same way you set them! Working on the previously declared array, see:
```cpp
...

cout << mySpecificallyFilledArray[0] << endl; //prints 2
cout << mySpecificallyFilledArray[3] << endl; //prints 3

...
```
#### Arrays of characters (aka strings)
This way of filling is especially powerful when combined with loops and conditionals, things we're going to learn together in the next modules.
Arrays can also contain characters just like anything else! And this is the primitive way of creating what's known as a "string": *a set of characters in a specific order*. Try the following: 
```cpp
...

char arrayOfCharacters[13] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
cout << arrayOfCharacters; //prints "Hello, World!"

...
```
This is useful when you want to take an input from a user that has spaces in it such as their full name, given that the normal `cin >>` syntax stops at the first space. Let's consider this: 
```cpp
...

char arrayOfCharacters[256]; //this is an empty array of characters, we'll call it string *for now*.
cin >> arrayOfCharacters; //Try inputting "Hello, World!"
cout << arrayOfCharacters; //Output only "Hello,"

...
```
To fix this, we need to use `cin.getline(name_of_array_of_characters, size_of_array)` check the following example: 
```cpp
...

char arrayOfCharacters[256];
cin.getline(arrayOfCharacters, 256); //Try inputting anything with and without spaces up to 256 characters and getline will store them all in the array. 

...
```
## Strings
We have seen what creating an array of characters (also sometimes called string) is like, but there's a different way as well. By including the `standard string library` we can we can create strings seamlessly. This way, our string is dynamic, meaning that its size can change according to the size of the text being input into them. Consider the following: 
```cpp
...

#include <string>

string myFullname = "Nabil Tharwat"; 
string arrayOfStrings[2] = {"Nabil", "Tharwat"};
cout << arrayOfStrings[0] << endl; //print "Nabil"
cout << arrayOfStrings[1] << endl; //prints "Tharwat"

...
```
That's it! You have just created a string, easy enough? Now, remember how we used square bracket notation to reference values in an array of characters? We can do that with strings as well! There are slight changes to our code when using strings, so for instance, sinec our strings are now dynamic, we don't need to pass a specific size to getline, so instead of typing `cin.getline(...)` we can just type `getline(cin, string_name)`! We will continue on with strings across the tutorial. You now have the foundation to jumpstart your app with strings and arrays! 

## Notes
It's not recommended to use `cin.getline(...)` in conjunction with `cin >>` in the same file because they can cause conflicts with each other. To better understand this, we need to understand what a stream buffer is and the way `cin` works. 

#### Buffer 
The buffer is a block of memory which belongs to a stream and is used to hold stream data temporarily. When cin is called the stream of text is input and a buffer is obtained. Characters that are written to a stream are normally accumulated in the buffer, instead of appearing as soon as they are output by the application program. This is done to increase efficiency, as file and console I/O is slow in comparison to memory operations.

#### How cin works
`cin` works by going over the currently stored buffer of input text till the very first space character `\s`, newline character `\n` or string terminator `\0` appears. Meaning that if you input "Hello world" the value that's going to get stored is the "Hello" only, because it was followed by a space character. What happens then, is that it leaves the rest of the string which is " world" in the buffer, and if you run `cin.getline(...)` or `getline(...)` after that cin, getline will take the remaining part of the string, ignoring the *new* *needed* input. 

#### Solving the conflict
There's something called `cin.ignore(amount_of_characters_to_skip_in_buffer, delimiter`. What this basically does is walk over the buffer by the specified amount and then place an end to the old buffered text, causing it to ignore what's leftover from `cin` in the buffer. Consider the following example:
```cpp
...

  char arrayOfCharacters[256];
  cin >> arrayOfCharacters;
  cout << arrayOfCharacters << endl; //prints "Hello,", leaving the rest in the buffer
  cin.getline(arrayOfCharacters, 256); //automatically takes what's left in the buffer and doesn't allow the user to input something new for getline
  cout << arrayOfCharacters << endl; //prints " World", the leftovers

...
```
Now consider with the fix: 
```cpp
...

  char arrayOfCharacters[256];
  cin >> arrayOfCharacters;
  cin.ignore(1000, '\n'); //Skips 1000 characters in the buffer, and places a newline, forcing the cin.getline to not see the data
  cout << arrayOfCharacters << endl; //prints "Hello," that's stored in the variable. 
  cin.getline(arrayOfCharacters, 256); //Prompts the user again for input 
  cout << arrayOfCharacters << endl; //Prints the new input taken in the previous line

...
```
After applying the fix, the buffer gets ignored and the user is prompted to enter an input a second time at the getline. 

## Extra
You can run the module-4.cpp file supplied with this module to check how arrays of characters, string, and arrays of string work. 

>You can use [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler) to run C++ code in the browser if you don't have a compiler on your machine. You can also use Visual Studio, CodeBlocks, JetBrains CLion, or any other [IDE](https://en.wikipedia.org/wiki/Integrated_development_environment). 

## Up next
Conditionals, loops, and others.
