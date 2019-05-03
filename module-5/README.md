# Module-5
> Loops and conditionals help us control the flow of our programs. In this module, we'll learn how to jump around, repeat stuff while applying DRY*. 

## DRY (Don't Repeat Yourself)
Programming is not just throwing statements at the editor and running them, it's an art that you have to master. One of the main principles in programming is Don't Repeat Yourself. What this principle tells you is that languages offer you loops, conditions, and functions (to be explained later). Repeating your code will get others lost in it,will make files bigger, and logic harder to understand. That's why it's essential you make sure your code is NOT repetitive. 


## Conditionals
Conditions in programming languages take a somewhat arbitrary syntax than our normal maths conditions. For instance, if you want to compare to values for equality you use `==` instead of `=` since `=` is reserved for assignment. If you want to use multiple conditions that all must evaluate to true to execute a certain command you use the `&&` signs and if you want to use logical OR you go with `||`. Comparison operators include: 
1. Equality `==`
2. Smaller than or equal to `<=`
3. Bigger than or equal to `>=`
4. Smaller than `<`
5. Bigger than `>`

#### Declaring conditionals
There are a few ways of declaring conditionals, and they're all at our disposal. Those include: 
1. if... else if...else
2. Switch statements
3. Ternary operators

We're going to go over all of them, when to use one and not the other, when to combine them, the proper ways of chaining them, and how to chain multiple conditions in a single condition.

#### if conditionals
If is a natural human statement that tells us some information about the start of some process. For instance, *if* you study, you *pass*. This is especially useful inside loops but let's not get ahead of ourselves. 
The syntax to create an if conditional is pretty straightforward: `if(condition/s) code_to_execute;`. This way doesn't allow you to use multiple code statements to execute, it'll only execute the following statement coming right after it, and anything after the `;` will be executed in the normal flow without the condition. To solve this we can spread it across multiple lines using curly brackets (to declare them as a block). Notice that using this syntax, the semicolon `;` is placed inside the curly brackets `{}` after every statement like normal code and not after the whole condition block. 

Correct:
```cpp
...

if(condition/s) {
  statement_to_execute;
  another_statement_to_execute;
}

...
```
Wrong:
```cpp
...

if(condition/s) {
  statement_to_execute
  another_statement_to_execute
};

...
```
Also wrong:
```cpp
...

if(condition/s) {
  statement_to_execute;
  another_statement_to_execute;
};

...
```
#### If...else if
What if you want to chain multiple conditions based on each other? For instance, if you want to succeed, you should work for it, else you'll fail. The "else" part here wraps up all other possible events that will NOT make the first if condition true. Consider the following: 
```cpp
...

int randomValue = 5; 

if(randomValue == 5) cout << "Random value is 5";
else if(randomValue == 6) cout << "Random value is 6";

...
```
In this case, we check if random is equal to 5, if it is then we'll say it is. If it's not and INSTEAD is equal to 6, we'll say it's 6. These are two specific conditions with different results. 
#### If ... else
Now that we've seen how we can chain two or more conditions using `if..else if`, what if we want to handle every possible case? Do we have to write hundreds of if conditions to do that? Not at all! Using the `else` statement, you'll handle all other possible cases without the need to actually know all of them. All you have to do is: 
```cpp
...

int randomValue = 5; 

if(randomValue == 5) cout << "Random value is 5";
else cout << "Random value is NOT 5";

...
```
This time we checked IF random is equal to five, then we'll print that it is. But if that specific condition is not met (aka doesn't evaluate to true) then we'll tell the user that it's not equal to 5. This is handy in situations where you need to handle errors gracefully. You can also chain it with `else if` like so: 
```cpp
...

int randomValue = 5; 

if(randomValue == 5) cout << "Random value is 5";
else if(randomValue == 6) cout << "Random value is 6";
else cout << "Random value is not equal to 5 nor 6!";
...
```
#### Switch statements
Switch is used to evaluate more than 3 cases with ease. It's syntax is:
```cpp
...

switch(randomValue){
  case case_value: 
    code_to_execute; 
    break;
  case default: 
    do_something_if_no_case_evaluate_to_true;
}

...
```
This feels different than a normal if condition, but certainly it looks better than chaining tens of if conditions and is less repetitive. The only down-side to this way is that it only checks for integers. Now, what does `case`, `default`, and `break` do? 

`case` defines an equality comparison with the `variable_to_check`. So if we type `case 5: do something;` this is equivalent to `if(variable_to_check == 5){do something;}`. `default` is like `else`, it is the block to be executed if no other condition is met. Now onto `break`. 

Consider the following:
```cpp
...

switch(randomValue){
  case 1: 
    code_to_execute; 
  
  case 2:
    another_code_to_execute;
  
  case 3:
    another_code_to_execute;

  case default: 
    do_something_if_no_case_evaluate_to_true;
}

...
```
If randomValue is equal to 1, and there are no `break` statements added to that case, something known as "fall through" will happen. This means that if the first case is true the code in case 1, case 2, case 3 and default will all execute, regardless of the conditions in them. That's why we use the `break` statement. What it does is stop the execution of the following cases if a specific one evaluates to true. So if we add break to every case (with the exception of default because it's already the last one) and case 1 evaluates to true, only that case will be executed. 
#### Ternary operators
Ternary operators `condition? execute_this: else execute_this;` are used in place of complex if conditionals mostly in declarations and tiny modifications to your code. Consider the following: 
```cpp
...

int original = 5; 
bool originalTrue = original == 5? true: false; //returns true

...
```
What this does is check if `original` is equal to 5, if so, then the value of `originalTrue` will be equal to `true`. If it's not then the value will be `false`. You can also chain ternary operators like so: `condition? do_something: other_condition? do_something_else: else;` but this can be relatively hard to read and understand, so it's not advised. 

# Loops
Loops are blocks of code that are repeated for as many times as we like. There are different types of loops that can be either **conditional** or **unconditional** including: 
1. for
2. while
3. do/while

#### conditional for
For loops work on a variable and a condition as `for(initialise loop variable here; condition to work; optional incrementation){...}`. Consider: 
```cpp
...

for(int i = 0; i < 10; i ++){
  cout << i << endl; 
}

...
```
What this is does is it initialises `i` with value of 0, and if `i` is less than 10,it will increment `i` by 1 and execute the `cout` statement. This is the most basic form of a for loop and the most popular one you'll see. You can also initialise `i` outside the for loop like so: `int i = 0; for(; i < 10; i ++){...}`
#### conditional while and do/while
For loops run `n` times, unlike while loops which run only when the condition evaluates to true. Consider the following:
```cpp
...

int i = 5;
while(i < 10){
  cout << i << endl;
  i++;
}

...
```
This shows that a while loop will only run if the condition `i < 10` is initially met. What if we want our loop to run at least 1 time before checking the condition? This can easily be done using a do/while loop which executes the block of code once before checking the condition. 
```cpp
...

int i = 4;

do{
  cout << i << endl;
  i++; 
}
while(i < 10);

...
``` 
# Nesting
All of those can be nested! Nested? Yes. You can put an if conditional inside other if conditionals, for loops inside for loops, and so on! What could such things be used for? Arrays of arrays! If we have an array of arrays like the following, if we want to fill each element of each inner array we would need a loop that runs iterates the outer array and another that iterates every inner array. Consider the following:
```cpp
...

int arrOfArrays[5][5]; //This is how you declare an array of arrays. You can also go with arrOfArray[5][5][5] to declare arrays 3 levels down and that will need 3 nested loops. 

for(int i = 0; i < 5; i ++ ){
    for(int j = 0; j < 5; j++){
        arrOfArrays[i][j] = j; //arrOfArrays[i] when `i` equals 0 will be the first inner array. So lets consider that arrOfArrays[i] is int innerArr[5];
        //arrOfArrays[i][j] will be the first element of the inner array equivalent to our innerArr[5].
    }
}

...
```
# The "break" and "continue" statement
The `break` statement terminates a loop the same way it terminates a switch case. If `break` is encountered inside a loop, the loop will forcefully stop and will no longer execute. On the other hand, continue ensures that the loop continues when a conditions is met. Consider:
```cpp
...

int i = 5; 
while(i < 10){
  if(i == 8){
    break;
  }
  else{
    continue;
  }
}

...
```
# Unconditional loops
Unconditional loops are `infinite` loops that run without a specific condition either until the program is forcefully terminated or a `break` statement is encountered.
```cpp
...

for(;;){ //This weird for loop ensures that there's no condition, and no variable to base the loop on, causing it to become an infinite loop. 
  int i = 0; 
  cin >> i;
  if(i == 5){
    break;
  }
  else{
    continue;
  }
}

...
```
In this example, you infinitely take input from the user and check its value, if it's equal to 5 then the infinite loop will stop and the program will continue normally to execute any code that lies beyond that loop. This is one of the most common ways of using break. 

# Note
You can forcefully terminate a command-line program by pressing the key combination (`CTRL` + `C`).

You'll find the basic structure of our game in the `module-5.cpp` file.
# Up next
Revisiting namespaces, more best practices and all about functions. 