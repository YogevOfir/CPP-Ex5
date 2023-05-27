#include "MagicalContainer.hpp"
#include <math.h>

using namespace std;


// void MagicalContainer::fix()
// {
//     MagicalContainer::sortedElem = originalElem;
//     MagicalContainer::sortedElem.sort();

//     MagicalContainer::primeElem.clear();
//     for (int elem : originalElem)
//     {
//         if (isPrime(elem))
//         {
//             MagicalContainer::primeElem.push_back(elem);
//         }
//     }
// }

// bool isPrime(int elem)
// {
//     if (elem == 1)
//     {
//         return false;
//     }
//     else if (elem == 2)
//     {
//         return true;
//     }
//     else
//     {
//         for (int i = 2; i < sqrt(elem) + 1; i++)
//         {
//             if (elem % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// }

// ***************** MagicalContainer *****************
// ***************** MagicalContainer *****************
// ***************** MagicalContainer *****************

void MagicalContainer::addElement(int elem)
{
    // originalElem.push_back(elem);
    // MagicalContainer::fix();
}

void MagicalContainer::removeElement(int elem)
{

}

int MagicalContainer::size()
{
    return 0;
}





// ***************** AscendingIterator *****************
// ***************** AscendingIterator *****************
// ***************** AscendingIterator *****************


// Constructors

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), iter(container.sortedElem.begin()), pos(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), iter(other.iter), pos(other.pos) {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    iter = other.iter;
    pos = other.pos;
    return *this;
}

// Operators

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(iter == container.sortedElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    ++iter;
    ++pos;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*()
{
    if(iter == container.sortedElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    return *iter;
}

// Comparison operators

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos == other.pos;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos < other.pos;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos > other.pos;
}

// Getters

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin()
{
    iter = container.sortedElem.begin(); // iterates to the beginning of the container
    pos = 0;                             // sets the position to 0
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end()
{
    iter = container.sortedElem.end(); // iterates to the end of the container
    pos = container.sortedElem.size(); // sets the position to the size of the container
    return *this;
}


// ***************** SideCrossIterator *****************
// ***************** SideCrossIterator *****************
// ***************** SideCrossIterator *****************

// Constructors

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container), iter(container.crossElem.begin()), pos(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), iter(other.iter), pos(other.pos) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    iter = other.iter;
    pos = other.pos;
    return *this;
}
// Operators

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    if(iter == container.crossElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    ++iter;
    ++pos;
    return *this;
}

int& MagicalContainer::SideCrossIterator::operator*()
{
    if(iter == container.crossElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    return *iter;
}

// Comparison operators

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos == other.pos;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos < other.pos;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos > other.pos;
}

// Getters

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin()
{
    iter = container.crossElem.begin(); // iterates to the beginning of the container
    pos = 0;                             // sets the position to 0
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end()
{
    iter = container.crossElem.end(); // iterates to the end of the container
    pos = container.crossElem.size(); // sets the position to the size of the container
    return *this;
}


// ***************** PrimeIterator *****************
// ***************** PrimeIterator *****************
// ***************** PrimeIterator *****************

// Constructors

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container), iter(container.primeElem.begin()), pos(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), iter(other.iter), pos(other.pos) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    iter = other.iter;
    pos = other.pos;
    return *this;
}
// Operators

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if(iter == container.primeElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    ++iter;
    ++pos;
    return *this;
}

int& MagicalContainer::PrimeIterator::operator*()
{   
    if(iter == container.primeElem.end())
    {
        throw std::out_of_range("Out of range");
    }
    return *iter;
}

// Comparison operators

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos == other.pos;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos < other.pos;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    if(&container != &other.container) // if they are not the same container
    {
        throw std::invalid_argument("Invalid argument");
    }
    return pos > other.pos;
}

// Getters

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin()
{
    iter = container.primeElem.begin(); // iterates to the beginning of the container
    pos = 0;                             // sets the position to 0
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end()
{
    iter = container.primeElem.end(); // iterates to the end of the container
    pos = container.primeElem.size(); // sets the position to the size of the container
    return *this;
}




