#include <string>
#include "Direction.hpp"
#include <vector>
using namespace std;
using ariel::Direction;


namespace ariel{
    
    class Notebook{
        
        private:
            vector<vector<string>> page;

          public:

            void write(unsigned int page,unsigned int row,unsigned int col, Direction dir , string const &in);
            void erase(unsigned int page,unsigned int row,unsigned int col, Direction dir , int length); 
            string read(unsigned int page,unsigned int row,unsigned int col, Direction dir , int length);
            void show(unsigned int page);
            
            Notebook(){} //constructor 
            ~Notebook(){}
};

    }

    
  



