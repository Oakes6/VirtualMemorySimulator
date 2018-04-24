#include "PhysicalMemory.h"

unsigned char PhysicalMemory::loadFrame(unsigned char pageNumber) {
   pageNumber = (long) pageNumber;
   unsigned int index = pageNumber * FRAME_SIZE;
   unsigned char frameNumber = nextEmptyEntryIndex;

   ifstream readStream ("BACKING_STORE.bin", ios::binary);
   if (readStream.good()) {
      readStream.seekg(index);

      readStream.read(physical_memory_t[nextEmptyEntryIndex], 256);
      nextEmptyEntryIndex++;

      if (readStream)
         std::cout << "all characters read successfully." << endl;
      else
         std::cout << "error: only " << readStream.gcount() << " could be read";
      readStream.close();
   }
   else {
      cout << "*** INVALID FILE ***" << endl;
   }
   return frameNumber;
}

// returns a byte found in main memory from the supplied physical address (PA)
char PhysicalMemory::lookUp(unsigned char frameNumber, unsigned char offset) {
   return physical_memory_t[frameNumber][offset];
}
