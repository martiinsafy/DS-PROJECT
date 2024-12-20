#ifndef XCEPT_H
#define XCEPT_H

#include <new>      // For std::set_new_handler
#include <stdexcept> // For standard exception classes

// Bad initializers
class BadInitializers : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad initializers";
    }
};

// Insufficient memory
class NoMem : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient memory";
    }
};

// Change new to throw NoMem instead of std::bad_alloc
void my_new_handler() {
    throw NoMem();
}

// Set the new handler
std::new_handler old_handler = std::set_new_handler(my_new_handler);

// Improper array, find, insert, or delete index
// Or deletion from empty structure
class OutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Index out of bounds";
    }
};

// Use when operands should have matching size
class SizeMismatch : public std::exception {
public:
    const char* what() const noexcept override {
        return "Size mismatch";
    }
};

// Use when zero was expected
class MustBeZero : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value must be zero";
    }
};

// Use when bad input was detected
class BadInput : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad input detected";
    }
};

#endif // XCEPT_H
