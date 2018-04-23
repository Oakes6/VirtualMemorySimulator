// Tanner Oakes
// 4/18/18
// OS Project 4 - Virtual MemorDriver

#ifndef Driver_h
#define Driver_h

#include <bitset>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class Driver {
public:
   vector<unsigned int> loadAddresses(string filename);
   unsigned char extractPageNumber(unsigned int logicalAddress);
   unsigned char extractOffset(unsigned int logicalAddress);

   typedef struct {
      unsigned int physicalAddress;
      unsigned char value;
   } address_value_pair;

private:
   vector<unsigned int> logicalAddresses;

};

#endif
