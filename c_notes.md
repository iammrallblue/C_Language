# C Programming Notes

## C Programming

---

### Before Learning C Language

---

### Format specifiers in C

| Format Specifier | Type                          | Format Specifier | Type                          |
| ---------------- | ----------------------------- | ---------------- | ----------------------------- |
| %c               | Character                     | %o               | Octal representation          |
| %d               | Signed integer                | %llu             | Unsigned long long            |
| %e or %E         | Scientific notation of floats | %lli or %lld     | Long long                     |
| %f               | Float values                  | %lu              | Unsigned int or unsigned long |
| %g or %G         | Similar as %e or %E           | %Lf              | Long double                   |
| %hi              | Signed integer (short)        | %x or %X         | Hexadecimal representation    |
| %hu              | Unsigned Integer (short)      | %n               | Prints nothing                |
| %i               | Unsigned integer              | %%               | Prints % character            |
| %lf              | Double                        | %l or %ld or %li | Long                          |
| %p               | Pointer                       | %u               | Unsigned int                  |
| %s               | String                        |

### GCC Compiler

- Pre-processing `*.i` file
  - using `-E` to preprocessor code file
  - `gcc -E demo.c -o demo.i` // `*.i file`

- Compiling `*.s` file
  - using `-s`, to stop compiler after assembling file compiled
  - `*.s` compiling file
  - `gcc -s demo.i -o demo.s` // `*.s file`

- Assembling `*.o` file
  - `-c`, compiling assembling file to machine code
  - `gcc -c demo.s -o demo.o` // `*.o file`

- Linking `bin` file (executable)
  - `-o` compile a executable file (bin file)
  - `gcc demo.o -o demo` // `bin file`

---

### return values in C `main() function`

- In C/C++ language, the `main()` function can be left without return value. By default, it will return zero.
- the standard defines **3 values** for returning that are strictly conforming, `0`, `EXIT_SUCCESS`, and `EXIT_FAILURE`.
- **<font color=orange>0 and EXIT_SUCCESS</font>** for a successful termination
- return **<font color=orange>1 and EXIT_FAILURE</font>** for an unsuccessful termination, **1**, it means that the program is returning an error.

- Any other values are non-standard and implementation defined.
  - e.g., "1"

### Comments in C

- "// is single line comment"
- "/\*this is a comment block. \*/

### Escape Sequence in C

| Escape sequence | Meaning                |
| --------------- | ---------------------- |
| `\\`            | Backslash              |
| `\'`            | Single quote           |
| `\"`            | Double quote           |
| `\?`            | Question mark          |
| `\a`            | Alert (bell) character |
| `\b`            | Backspace              |
| `\f`            | Form feed              |
| `\n`            | Newline (line feed)    |
| `\r`            | Carriage return        |
| `\t`            | Horizontal tab         |
| `\v`            | Vertical tab           |

### Declaration and Initialization of Variables

- Example, the source file `variables.c`,
- <font color=orange>Variables</font>, Allocated space in memory to store a value.
  // We refer to a variable's name to access the stored value.
  // That variable now behaves as if it was the value it contains
  // BUT we need to declare what type of data we are storing.

```c
int main()
{
    // integer type variables x and y

    int x;       // declaration
    x = 123;     // initialization
    int y = 321; // declaration + initialization


    int age = 21;
    // integer variable age

    float gpa = 2.05;
    // floating point number

    char grade = 'C';
    // single character

    char name[] = "Bro"; // array of characters
    // one format of string in C language

    printf("Hello %s \n", name); // print out with place holder
    printf("You are %d years old\n", age);
    printf("Your average grade is %c \n", grade);
    printf("Your gpa is %0.2f\n", gpa);

    return 0;
} // main
```

### Format Specifiers (Placeholders) in C

- Example, the source file `format_specifiers.c`

| Format Specifier | Data Type                              |
| ---------------- | -------------------------------------- |
| %c               | char                                   |
| %d               | int                                    |
| %e or %E         | float/double (scientific notation)     |
| %f               | float/double (decimal notation)        |
| %lf              | double (decimal notation)              |
| %g or %G         | float/double (shortest representation) |
| %i               | int                                    |
| %o               | octal                                  |
| %p               | pointer address                        |
| %s               | string                                 |
| %u               | unsigned int                           |
| %x or %X         | hexadecimal                            |
| %0.1             | decimal precision                      |
| %1               | minimum field width                    |
| %-               | left align                             |

### Datatypes in C

- Example, the source file `datatypes.c`
- `boolean` variable uses placeholder `%d`, result **1** is **True**, **0** is **False**

- Here is a table of the sizes of C language data types:

  | Data Type     | Size (in bytes) | Size (in bits) |
  | ------------- | --------------- | -------------- |
  | char          | 1               | 8              |
  | short int     | 2               | 16             |
  | int           | 4               | 32             |
  | long int      | 8               | 64             |
  | long long int | 8               | 64             |
  | float         | 4               | 32             |
  | double        | 8               | 64             |
  | long double   | 16              | 128            |

### Constants in C

- Example, the source file `constants.c`

- a `constant` is a value that cannot be modified during the execution of a program
- `Constants` are used to represent fixed values that remain unchanged throughout the program's execution

1. **Integer Constants**: Whole numbers without fractional or decimal parts, expressed in decimal, octal, or hexadecimal notation (e.g., 10, 020, 0xA).

2. **Floating-point Constants**: Real numbers with fractional parts, written in decimal notation with optional decimal point and exponent (e.g., 3.14, 2.0, 1.23e-4).

3. **Character Constants**: Individual characters enclosed in single quotes, including regular characters and escape sequences (e.g., 'A', 'x', '\n').

4. **String Constants**: A sequence of characters enclosed in double quotes, treated as an array of characters (e.g., "Hello, World!").

5. <font color=orange>Symbolic Constants</font>: Identifiers representing constant values, usually defined using `#define` or `const` keyword (e.g., `#define PI 3.14159`).

   ```c
   #define PI 3.14159
   ```

   - Example using `const`:

     ```c
     const int MAX_VALUE = 100;
     ```

6. **Enumeration Constants**: The `enum` keyword is used to define a list of named values representing a set of related constants.

- Example:

  ```c
  enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
  };
  ```

#### const and #define

- `const` is used to define constants. A constant is a variable that cannot be modified once it is declared in the program.
- The big advantage of `const` over `#define` is type checking.
- `#define`s can’t be type checked, so this can cause problems when trying to determine the data type.

- Data defined by the `#define` macro definition are preprocessed, so that your entire code can use it. This can free up space and increase compilation times.

### Arithmetic Operators in C

### Augmented Assignment Operators in C

- Example, the source file `augmented_assignment_operators.c`

### User Input functions in C

- Example, the source file `user_input.c`
- `scanf()` function, to read input from user, the input can be different data types.

- **<font color=orange>&</font>**, operator is used to get the address of a variable.

  ```c
  #include <stdio.h>
  int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered: %d", num);
    return 0;
  }
  ```

- `fgets()` function, to read a string from the input stream argument,

  ```c
  #include <stdio.h>
  int main() {
    char str[50];
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    printf("You entered: %s", str);
    return 0;
  }
  ```

- `gets()` function, to read a string from the input stream argument and store in a string variable

  ```c
  #include <stdio.h>
  int main() {
    char str[50];
    printf("Enter a string: ");
    gets(str);
    printf("You entered: %s", str);
    return 0;
  }
  ```

### Math Functions in C

- Example, the source file `math_functions.c`

- `sqrt(9)` function, Calculates the square root of 9
- `pow(2, 4)` function, Calculates 2 raised to the power of 4
- `round(3.24)` function, Rounds 3.24 to the nearest integer
- `ceil(3.99)` function, Rounds 3.99 up to the nearest integer
- `floor(3.99)` function, Rounds 3.99 down to the nearest integer
- `fabs(-100)` function, Calculates the absolute value of -100
- `log(3)` function, Calculates the natural logarithm of 3
- `sin(45)` function, Calculates the sine of 45 degrees
- `cos(45)` function, Calculates the cosine of 45 degrees
- `tan(45)` function, Calculates the tangent of 45 degrees

### If and Switch Statement in C

- Example, the source file `if_statements.c`, `switch_statement.c`

- if statement:

  - The if statement is used to execute a block of code if a condition is true.
  - It supports only one condition and one code block.
  - It provides flexibility for complex conditions by using logical operators (&&, ||).
  - It is suitable for situations where there are multiple possible conditions and different code blocks need to be executed for each condition.

- else if statement:

  - The else if statement is an extension of the if statement and allows for multiple conditions to be evaluated.
  - It is used when there are multiple conditions to be checked, and each condition has a different code block to be executed.
  - It is an alternative to using nested if statements for multiple condition checks.
  - It provides more organized code structure when dealing with multiple conditions.

- switch statement:

  - The switch statement is used to perform different actions based on different values of a variable or expression.
  - It provides a concise way to handle multiple conditions by using case labels.
  - It is often used when there are multiple mutually exclusive conditions, and each condition corresponds to a specific action or code block.
  - It improves code readability and maintainability when dealing with a large number of conditions or cases.
  - It supports only equality-based comparisons, and each case must be distinct (no overlapping values).

### Logical Operators in C

- Example, the source file `logical_operators.c`

- In C programming for decision-making, we use logical operators. We have 3 major logical operators in the C language:

  - Logical AND <font color=orange>&&</font>
  - Logical OR <font color=orange>||</font>
  - Logical NOT <font color=orange>!</font>

- Logical operators in C are used to combine multiple conditions/constraints.
- Logical operators return either 0 or 1, depending on the expression result true or false.

- Here is a table that shows all the logical operators supported by C language:

  | Operator | Description |
  | -------- | ----------- |
  | &&       | Logical AND |
  | \|\|     | Logical OR  |
  | !        | Logical NOT |

### Functions in C

- Example, the source file `functions.c`
- A <font color=orange>function</font> is a set of statements enclosed within curly brackets ({}) that take inputs, do the computation, and provide the resultant output.
- Functions can be called multiple times, thereby allowing reusability and modularity in C programming.

#### Two types of functions

- <font color=orange>Library Function</font>: also referred to as a <font color=orange>“built-in function”</font>. A compiler package already exists that contains these functions.
- <font color=orange>User Defined Function</font>: A user-defined function is a function that is created by the user at the time of writing the program².

### Function and Arguments

- Example, the source file `function_arguments.c`

- <font color=orange>Function Arguments</font> aka <font color=orange>Function Parameters</font> are the data that is passed to a function.
- Functions can be called either with or without arguments and might return values.

#### Arguments can be passed in two ways

- <font color=orange>Call by Value</font>: In call by value, the arguments we pass are copied to the function parameters. The changes made to the parameters inside the function have no effect on the arguments¹.
- <font color=orange>Call by Reference</font>: In call by reference, the address of the arguments is passed to the function parameters. The changes made to the parameters inside the function have an effect on the arguments¹.

### Return Statements in C

- Example, the source file `return_statements.c`

- The return statement is used to return a value from a function.
- The return statement terminates the execution of a function and returns control to the calling function.

  ```c
  #include <stdio.h>

  int add(int x, int y) {
    int sum = x + y;
    return sum;
  }

  int main() {
    int a = 10;
    int b = 20;
    int result = add(a, b);
    printf("The sum of %d and %d is %d\n", a, b, result);
    return 0;
  }
  ```

- In this example, we define a function called `add` that takes two integer arguments and returns their sum. We then call this function from the `main` function and print the result.

### Ternary Operator in C

Sure! In C programming language, the ternary operator is a shorthand way of writing an if-else statement. It is also known as the conditional operator.

Here is an example of how to use the ternary operator in C:

```c
#include <stdio.h>

int main() {
   int a = 10;
   int b = 20;
   int max = (a > b) ? a : b;
   printf("The maximum of %d and %d is %d\n", a, b, max);
   return 0;
}
```

- In this example, we define two integer variables `a` and `b`. We then use the ternary operator to find the maximum of these two numbers and store it in another variable called `max`. Finally, we print the result.

### Function Prototype in C

- Example, the source file `function_prototypes.c`

- <font color=orange>Function prototype</font> is used to provide function declaration.
- It defines the function's name, return types, and parameters.
- The return types are the data types that the function returns after execution.
- If a function returns an integer, the return type is int. When a function returns a float value, the return type is also a float.

- A function prototype is a declaration in the code that instructs the compiler about the data type of the function, arguments and parameter list.
- It is one of the most important features of C programming which originated from C++.

### String Function in C

- Example, the source file `string_function.c`

- must add `#include <string.h>` header file in your program.

- the most commonly used <font color=orange>built-in function</font> string functions in C:

  - <font color=orange>strlen()</font> - returns the length of a string.
  - <font color=orange>strcpy()</font> - copies a string to another.
  - <font color=orange>strcat()</font> - concatenates two strings.
  - <font color=orange>strcmp()</font> - compares two strings.
  - <font color=orange>strchr()</font> - searches for a character in a string.
  - <font color=orange>strstr()</font> - searches for a substring in a string.
  - <font color=orange>strlwr()</font> - converts a given string into lowercase.

### Loops in C

- <font color=orange>Three types of loops: for loop, while loop, do...while loop.</font>

#### For Loop in C

- Example, the source file `for_loop.c`

- For loop is used to repeat a block of code until the specified condition is met.

- For Loop in C Language provides a functionality/feature to recall a set of conditions for a defined number of times,
- moreover, this methodology of calling checked conditions automatically is known as for loop.
- For loop is in itself a form of an entry-controlled loop. It is mainly used to traverse arrays, vectors, and other data structures².

- The general syntax to use the for loop is shown below:

  ```c
  for (initialize; check_condition; update) {
      //do this
  }
  ```

  - initialize is the initialization statement – the loop control variable is initialized here.
  - check_condition is the condition that determines if the looping should continue.
  - update is the statement that updates the value of the loop control variable³.

### While Loop in C

- Example, the source file `while_loop.c`

- The `while` loop is used to execute a block of code repeatedly as long as the specified condition is true.

- The working of the `while` loop can be understood by looking at the following flowchart:

  ```c
  while (test condition)
  {
      // code to be executed repeatedly
  }
  ```

- `name[strlen(name) - 1] = '\0';` is used to remove the newline character (`\n`) that is added to the end of the string when the user presses Enter after entering their name using `fgets()`.

- The `strlen()` function is used to determine the length of a string by counting the number of characters in the string before the null character (`\0`) ².

- In C programming, a string is an array of characters that ends with a null character (`\0`). The `strlen()` function is used to determine the length of a string by counting the number of characters in the string before the null character³.

### Do While Loop in C

Sure! Here's a short and concise explanation of the do-while loop in C programming language:

The do-while loop is similar to the while loop, but the condition is checked at the end of the loop instead of at the beginning. This means that the statements inside the loop will always execute at least once, even if the condition is false from the start¹.

Here's an example of how to use a do-while loop in C:

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);
```

- This code will print out the numbers 0 through 4 because the statements inside the loop will execute at least once before checking if `i < 5` is true

---

$\frac{2}{4}+\frac{5}{10}$
