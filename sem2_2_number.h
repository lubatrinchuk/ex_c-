#pragma once

class Number
{
private:
    static const int sBase = 100;
    std::size_t mSize;
    std::size_t mCapacity;
    char* mData;

public:

    Number(int a);
    ~Number();

    // Default Constructor
    Number();

    // Copy Constructor
    Number(const Number& n);

    // Constructor from string
    Number(const char* str);

    // Assignment Operator
    Number operator=(const Number& right);

    // Addition Operators
    friend Number operator+(const Number& left, const Number& right);
    Number operator+=(const Number& right);

    // Multiplication Operator
    Number operator*(const Number& right) const;

    // Fibonacci numbers
    static Number fibonacci(int n);

    // Parity Check
    bool isEven() const;

    // Factorial
    static Number factorial(int n);

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);

private:
    // Helper methods
    Number(int size, int capacity, char* data) : mSize(size), mCapacity(capacity), mData(data) {}

    // Comparison Operator
    friend bool operator>(const Number& left, const Number& right);

    // Division by 2
    Number divideByTwo() const;
};
