#pragma once

/** Vector class.
    Has +, -, *, =, == , !=, [] operators, Copy Constructor and checking for Zero vector */

template <unsigned int Dim>
class Vector
{
public:
    Vector();
    Vector(int *ValueArray);
    Vector(const Vector<Dim> &vector);
    ~Vector() {}
    int& operator[](unsigned int index);
    Vector<Dim> operator+(const Vector<Dim> &operand);
    Vector<Dim> operator-(const Vector<Dim> &operand);
    Vector<Dim> operator=(const Vector<Dim> &vector);
    int operator*(const Vector<Dim> &operand);
    bool operator==(const Vector<Dim> &vector);
    bool operator!=(const Vector<Dim> &vector);
    bool isZero();
private:
    int array[Dim];
};

template <unsigned int Dim>
Vector<Dim>::Vector()
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        array[i] = 0;
    }
}

template <unsigned int Dim>
Vector<Dim>::Vector(int *ValueArray)
{
    for (int i = 0; i < Dim; i++)
    {
        array[i] = ValueArray[i];
    }
}

template <unsigned int Dim>
Vector<Dim>::Vector(const Vector<Dim> &vector)
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        array[i] = vector.array[i];
    }
}

template <unsigned int Dim>
int &Vector<Dim>::operator[](unsigned int index)
{
    return array[index];
}

template <unsigned int Dim>
Vector<Dim> Vector<Dim>::operator+(const Vector<Dim> &operand)
{
    Vector<Dim> result;
    for (unsigned int i = 0; i < Dim; i++)
    {
         result.array[i] = array[i] + operand.array[i];
    }
    return result;
}

template <unsigned int Dim>
Vector<Dim> Vector<Dim>::operator-(const Vector<Dim> &operand)
{
    Vector<Dim> result;
    for (unsigned int i = 0; i < Dim; i++)
    {
        result.array[i] = array[i] - operand.array[i];
    }
    return result;
}

template <unsigned int Dim>
Vector<Dim> Vector<Dim>::operator=(const Vector<Dim> &vector)
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        array[i] = vector.array[i];
    }
    return *this;
}

template <unsigned int Dim>
int Vector<Dim>::operator*(const Vector<Dim> &operand)
{
    int result = 0;
    for (unsigned int i = 0; i < Dim; i++)
    {
        result += array[i] * operand.array[i];
    }
    return result;
}

template <unsigned int Dim>
bool Vector<Dim>::operator==(const Vector<Dim> &vector)
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        if (array[i] != vector.array[i])
        {
            return false;
        }
    }
    return true;
}

template <unsigned int Dim>
bool Vector<Dim>::operator!=(const Vector<Dim> &vector)
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        if (array[i] != vector.array[i])
        {
            return true;
        }
    }
    return false;
}

template <unsigned int Dim>
bool Vector<Dim>::isZero()
{
    for (unsigned int i = 0; i < Dim; i++)
    {
        if (array[i] != 0)
        {
            return false;
        }
    }
    return true;
}
