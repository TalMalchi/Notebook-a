#include "doctest.h"
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;
using namespace ariel; 



TEST_CASE("write"){

Notebook notebook_test;

CHECK_NOTHROW(notebook_test.write(2,3,6,Direction::Horizontal, "hiii"));
CHECK_NOTHROW(notebook_test.write(4,5,5,Direction::Horizontal, "aa"));
CHECK_NOTHROW(notebook_test.write(7,7,6,Direction::Horizontal, "home"));
CHECK_NOTHROW(notebook_test.write(2,5,20,Direction::Horizontal, "hiii"));
CHECK_NOTHROW(notebook_test.write(9,5,3,Direction::Horizontal, "fun"));
CHECK_NOTHROW(notebook_test.write(13,7,9,Direction::Vertical, "sky"));
CHECK_NOTHROW(notebook_test.write(6,8,6,Direction::Vertical, "aaaa"));
CHECK_NOTHROW(notebook_test.write(2,9,10,Direction::Vertical, "xyz"));
CHECK_NOTHROW(notebook_test.write(2,5,3,Direction::Vertical, "hiii"));
CHECK_THROWS(notebook_test.write(1,0,95,Direction::Vertical, "aaaaaa"));

}


TEST_CASE("read"){
Notebook notebook_test;
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 4)== "hiii");
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 1)== "h");
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 2)=="hii");
CHECK(notebook_test.read(4,5,5,Direction::Horizontal, 2)=="aa");
CHECK(notebook_test.read(7,7,6,Direction::Horizontal, 4)== "home");
CHECK(notebook_test.read(13,7,9,Direction::Horizontal,5)=="sky__");
CHECK_THROWS(notebook_test.read(1,0,95,Direction::Vertical, 101));


}

TEST_CASE("erase"){

Notebook notebook_test;
//read or write string and then erase it 
CHECK(notebook_test.read(2,5,20,Direction::Horizontal,6)=="tal___");
CHECK_NOTHROW(notebook_test.erase(2,5,20,Direction::Horizontal, 5));
CHECK_NOTHROW(notebook_test.write(2,5,3,Direction::Vertical, "hiii"));
CHECK_NOTHROW(notebook_test.erase(2,5,3,Direction::Horizontal, 7));
CHECK_NOTHROW(notebook_test.erase(7,7,6,Direction::Horizontal, 4));
CHECK_THROWS(notebook_test.erase(2,1,3,Direction::Horizontal, 104));
CHECK_THROWS(notebook_test.erase(9,5,98,Direction::Horizontal, 5));
}
