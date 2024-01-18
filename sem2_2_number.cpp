#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include "number.h"


Number::Number(int a)
{
    // Находим размер необходимой памяти под это число
    int temp = a;
    mCapacity = 0;
    while (temp != 0)
    {
        temp /= sBase;
        mCapacity += 1;
    }

    // Отдельно обрабатываем случай, когда число равно 0
    if (mCapacity == 0)
        mCapacity = 1;

    // Выделяем память и записывем число a в массив mData
    mData = new char[mCapacity];

    for (int i = 0; i < mCapacity; ++i)
    {
        mData[i] = a % sBase;
        a /= sBase;
    }

    // В данном случае размер будет равен вместимости
    mSize = mCapacity;
}

Number::~Number()
{
    delete[] mData;
}

Number::Number() : mSize(1), mCapacity(1), mData(new char[1]) {
    mData[0] = 0;
}

Number::Number(const Number& n) : mSize(n.mSize), mCapacity(n.mCapacity), mData(new char[n.mCapacity]) {
    std::copy(n.mData, n.mData + n.mSize, mData);
}

Number::Number(const char* str) {
    mSize = strlen(str);
    mCapacity = mSize;
    mData = new char[mCapacity];

    for (std::size_t i = 0; i < mSize; ++i) {
        mData[i] = str[mSize - i - 1] - '0';
    }
}

Number Number::operator=(const Number& right) {
    if (this != &right) {
        delete[] mData;
        mSize = right.mSize;
        mCapacity = right.mCapacity;
        mData = new char[mCapacity];
        std::copy(right.mData, right.mData + right.mSize, mData);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.mData[num.mSize - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.mSize - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.mData[num.mSize - 2 - i]);

    return stream;
}

Number Number::operator+(const Number& left, const Number& right) {
    Number result;

    int carry = 0;
    std::size_t maxSize = std::max(left.mSize, right.mSize);

    for (std::size_t i = 0; i < maxSize || carry; ++i) {
        int sum = carry + (i < left.mSize ? left.mData[i] : 0) + (i < right.mSize ? right.mData[i] : 0);
        result.mData[i] = sum % Number::sBase;
        carry = sum / Number::sBase;
        if (i == result.mSize) result.mSize++;
    }

    return result;
}

Number Number::operator+=(const Number& right) {
    *this = *this + right;
    return *this;
}

Number Number::fibonacci(int n) {
    Number a = 0, b = 1, temp;

    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

bool Number::isEven() const {
    return mData[0] % 2 == 0;
}

Number Number::factorial(int n) {
    Number result = 1;
    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}

bool operator>(const Number& left, const Number& right) {
    if (left.mSize != right.mSize) {
        return left.mSize > right.mSize;
    }

    for (std::size_t i = left.mSize; i-- > 0;) {
        if (left.mData[i] != right.mData[i]) {
            return left.mData[i] > right.mData[i];
        }
    }

    return false;
}

Number Number::divideByTwo() const {
    Number result(mSize, mCapacity, new char[mCapacity]);

    int carry = 0;
    for (std::size_t i = mSize; i-- > 0;) {
        int digit = mData[i] + carry * sBase;
        result.mData[i] = digit / 2;
        carry = digit % 2;
    }

    return result;
}
