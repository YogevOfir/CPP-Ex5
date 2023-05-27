#include "doctest.h"
#include "MagicalContainer.hpp"
#include <stdexcept>

TEST_CASE("MagicContainer functions")
{
    MagicalContainer container;

    CHECK(container.size() == 0);

    container.addElement(19);
    container.addElement(7);
    container.addElement(35);
    container.addElement(10);
    container.addElement(4);
    container.addElement(2);

    CHECK(container.size() == 6); // maybe 8 idk

    container.removeElement(7);

    CHECK(container.size() == 5); // maybe 8 idk

    CHECK_THROWS_AS(container.removeElement(7), std::runtime_error);

    container.removeElement(19);

    CHECK(container.size() == 4); // maybe 8 idk

    container.removeElement(35);
    container.removeElement(10);
    container.removeElement(4);
    container.removeElement(2);

    CHECK(container.size() == 0); // maybe 8 idk
}


TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    MagicalContainer container2;

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(container2);
    MagicalContainer::AscendingIterator ascIter3(ascIter2);

    CHECK(ascIter.begin() == ascIter.end()); // empty container
    CHECK(ascIter2.begin() == ascIter2.end()); // empty container

    container.addElement(19);
    container.addElement(7);
    container.addElement(35);
    container.addElement(10);
    container.addElement(4);

    container2.addElement(9);
    container2.addElement(3);
    container2.addElement(25);
    container2.addElement(2);
    container2.addElement(17);

    CHECK(*ascIter.begin() == 4);
    CHECK(*ascIter2.begin() == 2);
    CHECK(*ascIter3.begin() == 2); // same as ascIter2 - copy constructor


    // Operators check

    // CHECK different containers
    CHECK_THROWS_AS(ascIter.operator==(ascIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(ascIter.operator!=(ascIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(ascIter.operator>(ascIter2),  std::invalid_argument); // different containers
    CHECK_THROWS_AS(ascIter.operator<(ascIter2),  std::invalid_argument); // different containers


    // CHECK same containers
    CHECK(ascIter2 == ascIter3); // same position
    ++ascIter3;
    CHECK(*ascIter3 == 3);
    CHECK(ascIter2 != ascIter3); // different position
    CHECK(ascIter2 < ascIter3); // different position
    CHECK(ascIter3 > ascIter2); // different position

    
    // Check Order of elements
    // container: 4 7 10 19 35
    CHECK(*ascIter.begin() == 4);
    CHECK(*(++ascIter) == 7);
    CHECK(*(++ascIter) == 10);
    CHECK(*(++ascIter) == 19);
    CHECK(*(++ascIter) == 35);
    CHECK(++ascIter == ascIter.end());
    CHECK_THROWS_AS(*ascIter, std::out_of_range); // prIter is at the end

    container.addElement(13);

    // container: 4 7 10 13 19 35
    CHECK(*ascIter.begin() == 4);
    CHECK(*(++ascIter) == 7);
    CHECK(*(++ascIter) == 10);
    CHECK(*(++ascIter) == 13);
    CHECK(*(++ascIter) == 19);
    CHECK(*(++ascIter) == 35);
    CHECK(++ascIter == ascIter.end());

    container2.removeElement(2);
    container2.removeElement(17);

    // container2: 3 9 25

    CHECK(*ascIter2.begin() == 3);
    CHECK(*(++ascIter2) == 9);
    CHECK(*(++ascIter2) == 25);
    CHECK(++ascIter2 == ascIter2.end());

}


TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    MagicalContainer container2;

    MagicalContainer::SideCrossIterator scIter(container);
    MagicalContainer::SideCrossIterator scIter2(container2);
    MagicalContainer::SideCrossIterator scIter3(scIter2);

    CHECK(scIter.begin() == scIter.end()); // empty container
    CHECK(scIter2.begin() == scIter2.end()); // empty container

    container.addElement(19);
    container.addElement(7);
    container.addElement(35);
    container.addElement(10);
    container.addElement(4);

    container2.addElement(9);
    container2.addElement(3);
    container2.addElement(25);
    container2.addElement(2);
    container2.addElement(17);

    CHECK(*scIter.begin() == 19);
    CHECK(*scIter2.begin() == 9);
    CHECK(*scIter3.begin() == 9); // same as scIter2 - copy constructor


    // Operators check

    // CHECK different containers
    CHECK_THROWS_AS(scIter.operator==(scIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(scIter.operator!=(scIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(scIter.operator>(scIter2),  std::invalid_argument); // different containers
    CHECK_THROWS_AS(scIter.operator<(scIter2),  std::invalid_argument); // different containers


    // CHECK same containers
    CHECK(scIter2 == scIter3); // same position
    ++scIter3;
    CHECK(*scIter3 == 17); 
    CHECK(scIter2 != scIter3); // different position
    CHECK(scIter2 < scIter3); // different position
    CHECK(scIter3 > scIter2); // different position

    // // after ++ for both iterators scIter3 position should be less than scIter2
    // ++scIter3;
    // ++scIter2;

    // CHECK(*scIter3 == 3);
    // CHECK(*scIter2 == 25); 

    // CHECK(scIter2 != scIter3); // different position
    // CHECK(scIter2 > scIter3); // different position
    // CHECK(scIter3 < scIter2); // different position

    
    // Check Order of elements
    // container: 19 4 7 10 35

    CHECK(*scIter.begin() == 19);
    CHECK(*(++scIter) == 4);
    CHECK(*(++scIter) == 7);
    CHECK(*(++scIter) == 10);
    CHECK(*(++scIter) == 35);
    CHECK(++scIter == scIter.end());
    CHECK_THROWS_AS(*scIter, std::out_of_range); // prIter is at the end

    container.addElement(13);

    // container: 19 13 7 4 35 10

    CHECK(*scIter.begin() == 19);
    CHECK(*(++scIter) == 13);
    CHECK(*(++scIter) == 7);
    CHECK(*(++scIter) == 4);
    CHECK(*(++scIter) == 35);
    CHECK(*(++scIter) == 10);
    CHECK(++scIter == scIter.end());
    

    container2.removeElement(2);
    container2.removeElement(17);

    // container: 9 25 3

    CHECK(*scIter2.begin() == 9);
    CHECK(*(++scIter2) == 25);
    CHECK(*(++scIter2) == 3);
    CHECK(++scIter2 == scIter2.end());

}


TEST_CASE("PrimeIterator")
{

    MagicalContainer container;
    MagicalContainer container2;

    MagicalContainer::PrimeIterator prIter(container);
    MagicalContainer::PrimeIterator prIter2(container2);
    MagicalContainer::PrimeIterator prIter3(prIter2);

    CHECK(prIter.begin() == prIter.end()); // empty container
    CHECK(prIter2.begin() == prIter2.end()); // empty container

    // should add to primeElem : 19 7
    container.addElement(19);
    container.addElement(7);
    container.addElement(35);
    container.addElement(10);
    container.addElement(4);

    // should add to primeElem : 3 2 17
    container2.addElement(9);
    container2.addElement(3);
    container2.addElement(25);
    container2.addElement(2);
    container2.addElement(17);

    CHECK(*prIter.begin() == 19);
    CHECK(*prIter2.begin() == 3);
    CHECK(*prIter3.begin() == 3); // same as prIter2 - copy constructor


    // Operators check

    // CHECK different containers
    CHECK_THROWS_AS(prIter.operator==(prIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(prIter.operator!=(prIter2), std::invalid_argument); // different containers
    CHECK_THROWS_AS(prIter.operator>(prIter2),  std::invalid_argument); // different containers
    CHECK_THROWS_AS(prIter.operator<(prIter2),  std::invalid_argument); // different containers


    // CHECK same containers
    CHECK(prIter2 == prIter3); // same position
    ++prIter3;
    CHECK(*prIter3 == 2); 
    CHECK(prIter2 != prIter3); // different position
    CHECK(prIter2 < prIter3); // different position
    CHECK(prIter3 > prIter2); // different position

    
    // Check Order of elements
    // container: 19 7

    CHECK(*prIter.begin() == 19);
    CHECK(*(++prIter) == 7);
    CHECK(++prIter == prIter.end());
    CHECK_THROWS_AS(*prIter, std::out_of_range); // prIter is at the end

    container.addElement(13);

    // container: 19 7 13

    CHECK(*prIter.begin() == 19);
    CHECK(*(++prIter) == 7);
    CHECK(*(++prIter) == 13);
    CHECK(++prIter == prIter.end());

    container2.removeElement(2);

    // container2: 3 17

    CHECK(*prIter2.begin() == 3);
    CHECK(*(++prIter2) == 17);
    CHECK(++prIter2 == prIter2.end());

}