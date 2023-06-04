#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iterator>
#include <vector>
#include <list>
#include <set>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {

        private:
            vector<int> originalElem;
            vector<int*> sortedElem;
            vector<int*> crossElem;
            vector<int*> primeElem;

        public:
            void addElement(int elem);
            void removeElement(int elem);
            int size();
            void fixCross();
            void fixPrime();
            void fixSorted();
            void sortOriginalElem();

        class AscendingIterator
        {
            private:
                MagicalContainer& container;
                vector<int*>::iterator iter;
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
                vector<int*>::iterator iter;
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
                vector<int*>::iterator iter;
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
}

#endif