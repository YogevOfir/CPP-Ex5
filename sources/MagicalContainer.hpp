#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iterator>
#include <list>
#include <set>

using namespace std;

class MagicalContainer
{

    private:
        list<int> originalElem;
        multiset<int> sortedElem;
        list<int> crossElem;
        list<int> primeElem;

    public:
        void addElement(int elem);
        void removeElement(int elem);
        int size();
        static void fixCross(MagicalContainer* container);


    // MagicalContainer() = default;  // Default constructor
    // MagicalContainer(const MagicalContainer&) = default;  // Copy constructor
    // MagicalContainer& operator=(const MagicalContainer&) = default;  // Copy assignment operator
    // MagicalContainer(MagicalContainer&&) = default;  // Move constructor
    // MagicalContainer& operator=(MagicalContainer&&) = default;  // Move assignment operator
    // ~MagicalContainer() = default;  // Destructor


    class AscendingIterator
    {
        private:
            MagicalContainer& container;
            multiset<int>::iterator iter;
            size_t pos;

        public:
            // Constructors
            AscendingIterator(MagicalContainer& container);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator() = default;
            AscendingIterator& operator=(const AscendingIterator& other); // Copy assignment operator
            AscendingIterator(AscendingIterator&& other) noexcept = default; // Move constructor
            AscendingIterator& operator=(AscendingIterator&& other) noexcept {return *this;} // Move assignment operator


            // Operators
            AscendingIterator& operator++(); 
            int operator*(); // dereference operator
            
            size_t getPos() const {return pos;}

            // Comparison operators
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;

            // Getters
            AscendingIterator &begin(); 
            AscendingIterator &end();
    };

    class SideCrossIterator
    {
        private:
            MagicalContainer& container;
            list<int>::iterator iter;
            size_t pos;

        public:
            // Constructors
            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator() = default;
            SideCrossIterator& operator=(const SideCrossIterator& other); // Copy assignment operator
            SideCrossIterator(SideCrossIterator&& other) noexcept = default; // Move constructor
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {return *this;} // Move assignment operator

            // Operators
            SideCrossIterator& operator++(); 
            int& operator*(); // dereference operator

            size_t getPos() const {return pos;}

            // Comparison operators
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;

            // Getters
            SideCrossIterator &begin(); 
            SideCrossIterator &end();
    };


    class PrimeIterator
    {
        private:
            MagicalContainer& container;
            list<int>::iterator iter;
            size_t pos;

        public:
            // Constructors
            PrimeIterator(MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator() = default;
            PrimeIterator& operator=(const PrimeIterator& other); // Copy assignment operator
            PrimeIterator(PrimeIterator&& other) noexcept = default; // Move constructor
            PrimeIterator& operator=(PrimeIterator&& other) noexcept {return *this;} // Move assignment operator

            // Operators
            PrimeIterator& operator++(); 
            int& operator*(); // dereference operator

            size_t getPos() const {return pos;}

            // Comparison operators
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;

            // Getters
            PrimeIterator &begin(); 
            PrimeIterator &end();
    };
        



};
#endif