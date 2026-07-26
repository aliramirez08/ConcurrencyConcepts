# Concurrency Concepts

This project was developed to strengthen my understanding of threads and concurrency APIs in Java and C++. Both programs create separate threads that count upward and downward, then use `join()` to wait for each thread to finish.

The implementations demonstrate how Java and C++ manage thread creation and coordination using different language-specific APIs while producing the same behavior.

## Features

- Implements threading examples in Java and C++
- Creates separate counting-up and counting-down threads
- Counts upward from 0 to 20
- Counts downward from 20 to 0
- Coordinates thread completion using `join()`
- Uses `std::mutex` and `std::lock_guard` in C++
- Displays thread activity in the terminal
- Includes pseudocode for both implementations

## Concepts Demonstrated

- Thread creation
- Thread lifecycle
- Thread execution
- Thread coordination
- Waiting for threads with `join()`
- Lambda expressions in Java
- Mutexes in C++
- Resource Acquisition Is Initialization (RAII) with `std::lock_guard`
- Java Virtual Machine (JVM) thread management
- C++ Standard Library thread management
- Interrupted thread handling in Java

## Technologies Used

- Java
- C++
- Java Development Kit (JDK)
- C++ Standard Library
- Visual Studio Code
- Git
- GitHub
- Terminal / Command Line

## Project Structure

```text
ConcurrencyConcepts/
├── Screenshots/
├── ConcurrencyDemo.java
├── main.cpp
├── PseudocodeJava.txt
├── PseudocodeC++.txt
├── README.md
└── .gitignore
```

- `ConcurrencyDemo.java` – Java thread implementation
- `main.cpp` – C++ thread and mutex implementation
- `PseudocodeJava.txt` – Pseudocode for the Java program
- `PseudocodeC++.txt` – Pseudocode for the C++ program
- `Screenshots/` – Program output, pseudocode, and repository screenshots
- `.gitignore` – Excludes generated files and editor settings

## How to Run

### Prerequisites

- Java Development Kit (JDK 11 or later)
- A C++ compiler with C++11 support, such as `g++`
- Git

Verify that the required tools are installed:

```bash
java -version
javac -version
g++ --version
git --version
```

### Steps

1. Clone the repository:

```bash
git clone https://github.com/aliramirez08/ConcurrencyConcepts.git
```

2. Navigate to the project directory:

```bash
cd ConcurrencyConcepts
```

### Run the Java Program

1. Compile the Java source file:

```bash
javac ConcurrencyDemo.java
```

2. Run the compiled program:

```bash
java ConcurrencyDemo
```

### Run the C++ Program

1. Compile the C++ source file:

```bash
g++ -std=c++11 -pthread main.cpp -o cpp_runner
```

2. Run the compiled program:

```bash
./cpp_runner
```

## Code Examples

### Java Thread Creation

```java
Thread upThread = new Thread(() -> {
    for (int i = 0; i <= 20; i++) {
        System.out.println("Counting Up: " + i);
    }
});

upThread.start();
upThread.join();
```

The lambda expression defines the work performed by the thread. The `start()` method begins its execution, and `join()` makes the main thread wait for it to finish.

### C++ Thread Creation

```cpp
std::thread thread1(countUp);
thread1.join();
```

Creating the `std::thread` starts the `countUp()` function on a new thread. Calling `join()` makes the main thread wait for it to complete.

### C++ Mutex Protection

```cpp
std::lock_guard<std::mutex> lock(outputMutex);
std::cout << "Counting Up: " << i << std::endl;
```

The lock guard acquires the mutex before writing to the console and automatically releases it when the current scope ends.

## Example Output

```text
Starting Concurrency Example...
Counting Up: 0
Counting Up: 1
...
Counting Up: 20
Counting Down: 20
Counting Down: 19
...
Counting Down: 0
Both threads have finished.
```

Because each thread is joined before the next thread starts, the upward count finishes before the downward count begins.

## What I Learned

This project strengthened my understanding of how threads are created, started, and joined in Java and C++. I learned that both languages support the same fundamental threading concepts but provide different APIs for implementing them.

I also learned how `join()` affects execution order, how Java handles interrupted threads with `InterruptedException`, and how C++ uses mutexes and RAII-based lock guards to protect shared resources.

## Future Improvements

- Start both threads before joining them to demonstrate concurrent execution
- Update the Java version to handle concurrent console output
- Compare sequential and concurrent execution
- Demonstrate race conditions and their solutions
- Add deadlock examples and prevention techniques
- Implement semaphores and condition variables
- Add a producer-consumer example
- Include performance benchmarks
- Add automated tests
- Build a graphical visualization of thread execution

## Screenshots

### Java Program Output

![Java Program Output](Screenshots/JavaOutput.png)

### C++ Program Output

![C++ Program Output](Screenshots/C++Output.png)

### Java Pseudocode

![Java Pseudocode](Screenshots/PseudocodeJava.png)

### C++ Pseudocode

![C++ Pseudocode](Screenshots/PseudocodeC++.png)

### GitHub Repository

![GitHub Repository](Screenshots/Github.png)
