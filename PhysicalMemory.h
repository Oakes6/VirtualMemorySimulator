// Tanner Oakes
// 4/20/18
// OS Project 4 - Virtual Memory

#ifndef PhysicalMemory_h
#define PhysicalMemory_h

#include <bitset>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class PhysicalMemory {
public:
   PhysicalMemory() : nextEmptyEntryIndex(0) {}

   char lookUp(unsigned char frameNumber,unsigned char offset);
   unsigned char loadFrame();

private:
   const static int PHYS_MEM_SIZE = 256;
   const static long FRAME_SIZE = 256;
   char physical_memory_t[256][256];
   long nextEmptyEntryIndex;
};

#endif
