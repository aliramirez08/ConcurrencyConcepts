# Concurrency Concepts Project

## Overview

This project demonstrates concurrency concepts in both **C++** and **Java**. In each program, two threads are used to simulate counters:

- The first thread counts upward from 0 to 20.
- Once the first thread completes, the second thread counts downward from 20 to 0.
- Both programs ensure thread coordination using appropriate mechanisms (`join()`), preventing race conditions and maintaining predictable execution.

---

## C++ Implementation

The C++ program uses the `<thread>` and `<mutex>` libraries. The counting is divided into two functions:

- **countUp()** handles incrementing from 0 to 20.
- **countDown()** handles decrementing from 20 to 0.
- A mutex is used to ensure safe and orderly access to the console output.

This version demonstrates how concurrency is handled at the system level, with explicit control over thread creation and synchronization.

---

## Java Implementation

The Java program uses the `Thread` class and lambda expressions. The logic is similar:

- One thread counts upward to 20.
- Once it completes, another thread begins counting downward to 0.
- The `join()` method is used to ensure that threads run in sequence rather than overlapping.

This implementation highlights Java’s concurrency model, which is built on top of the JVM, providing portability and memory safety.

---

## Summary

Both implementations successfully demonstrate the same concurrency concept while highlighting key differences between languages:

- **C++** provides more direct control over threads and requires careful handling of synchronization to avoid race conditions.
- **Java** abstracts many low-level details, offering a safer and more portable concurrency model at the cost of some performance overhead.

These examples illustrate the trade-offs between **performance and control in C++** versus **safety and simplicity in Java**.
