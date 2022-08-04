<h3 align="center"> 42 São Paulo - Get Next Line </h3>


<p align="center">
	<b><i>Reading a line on a fd is way too tedious 😮‍💨 </i></b><br>
</p>


## 💡 About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
	This project consists of coding a function that returns one line at a time from a text file.

## Grade and Badge 
![image](https://user-images.githubusercontent.com/85964972/132257264-f92eb828-0168-46d7-aa10-15a6bf44ef6e.png)
![image](https://user-images.githubusercontent.com/85964972/132258308-4a7ceea0-b212-4a51-a300-88c9bd1706ef.png)


## Skills
* Rigor
* Unix
* Algorithms & AI 

## Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

## 🧭 Usage

Clone the repository and access it with `cd`.

**1. Using it in your code**

To use the function in your code, simply include its header:

```
#include "get_next_line.h"
```


## 📋 Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test othe cases.
Then simply run this command (change "xx" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=XX get_next_line.c get_next_line_utils.c && ./a.out
```

or

Use the following command :
```
make
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
