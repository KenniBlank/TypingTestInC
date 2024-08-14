# Typing Test Program
This program is my approach to creating a **Typing Test**. It is implemented in pure C, utilizing only the standard library with minimal external dependencies. It has only **Paragrams** which I wanted. Also the program doesn't end without letting you complete the sentence (The extra time is used while calculating the WPM(Word Per Minute)).
VIDEO Visualization: [YT](https://youtu.be/9x4T1kilJW8)

# Installation Steps:
- On Linux:   
    - Install the typing_test.deb  
    - Open Terminal and type: ***typing_test*** to execute.  
- On windows: Open the typing_test.exe

## Why?
I was dissatisfied with how new sentences were displayed in various typing tests, so I decided to create my own version that suits my preferences. This program features a minimal Command-Line Interface (CLI) that I like, and I can modify it to meet my specific needs.

## Why C?
I wanted to demonstrate that the years I've spent learning C programming were not in vain. This project encompasses many core concepts I've learned over the years, such as memory allocation, `typedef` to define new data types, and other fundamental programming techniques.

## Process
I began the project by creating a `.c` file. My initial focus was on learning how to implement a timer in C. After that, I delved into basic memory allocation, ensuring that memory is properly allocated and freed during the program's execution. I then proceeded to implement the core functionality, focusing on presenting sentences, handling user input, and calculating typing speed and accuracy.

## How It Works
The program presents you with a random sentence that you need to type out. When you finish typing and hit enter, it provides a new sentence. The program uses standard C libraries to manage time tracking, memory allocation, and string manipulation. It calculates your Words Per Minute (WPM) and accuracy based on your input.

## Features
- **Random sentence generation:** Provides a new sentence every time you complete the previous one.
- **Real-time error detection:** Detects and highlights errors as you type.
- **Words per minute (WPM) calculation:** Measures your typing speed in WPM.
- **Accuracy calculation:** Tracks the accuracy of your typing in percentage.

## Credit
- **Learning Resources:** I gained a lot of the foundational knowledge for this program from [w3schools](https://www.w3schools.com/).
- **Compilation Steps:** The steps for compiling the program were guided by [GeeksforGeeks](https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/).
- **Debugging & Inquiries:** The community at [StackOverflow](https://stackoverflow.com/) provided invaluable help with debugging and other technical questions.
- **Sentence Generation:** Sentences used in the typing test were generated with the help of [ChatGPT](https://chatgpt.com/).

## Compilation
To compile the program, you need to have GCC (GNU Compiler Collection) installed on your system. If you don't have it installed yet, you can follow the instructions from the official GCC documentation:

- **GCC Installation Guide:** [Installing GCC](https://gcc.gnu.org/install/)

Once you have GCC installed, you can compile the program using the following commands in your terminal:

### Option 1: Using `gcc`
```bash
gcc -o typing_test typing_test.c
./typing_test
```
Optionally if you have makefile set up
```bash
make typing_test
./typing_test
```

> My Other Works: [Link](https://birajtiwari.com.np)
