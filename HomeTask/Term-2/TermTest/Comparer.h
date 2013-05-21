#pragma once

/** Comparer template class.
    Comparers two element and return 1, 0 or -1.
    Has specialization for char* */

template <typename T>
class Comparer
{
public:
    static int compare(T elem1, T elem2)
    {
        if (elem1 == elem2)
            return 0;
        else if (elem1 > elem2)
            return 1;
        else
            return -1;
    }
};

template <>
class Comparer<char*>
{
public:
    static int compare(const char* elem1, const char* elem2)
    {
        int i = 0;
        while (elem1[i] != '\0' && elem2[i] != '\0')
        {
            if (Comparer<char>::compare(elem1[i], elem2[i]) == 1)
            {
                return 1;
            }
            else if (Comparer<char>::compare(elem1[i], elem2[i]) == -1)
            {
                return -1;
            }
            i++;
        }
        if (elem1[i] == '\0' && elem2[i] == '\0')
        {
            return 0;
        }
        else if (elem1[i] != '\0')
        {
            return 1;
        }
        else
            return -1;
    }
};
