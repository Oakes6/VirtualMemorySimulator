#include "PhysicalMemory.h"

// loads a frame and returns the frame number index it was loaded to 
unsigned char PhysicalMemory::loadFrame() {
   // pageNumber = (long) pageNumber;
   unsigned int index = nextEmptyEntryIndex * FRAME_SIZE;
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
   // cout << "(0,0): " << physical_memory_t[0][0] << endl;
   // cout << "(0,255): " << physical_memory_t[0][255] << endl;
   // cout << "(1,0): " << physical_memory_t[1][0] << endl;
   // cout << "(1,255): " << physical_memory_t[1][255] << endl;
   return frameNumber;
}

// returns a byte found in main memory from the supplied physical address (PA)
char PhysicalMemory::lookUp(unsigned char frameNumber, unsigned char offset) {
   return physical_memory_t[frameNumber][offset];
}
