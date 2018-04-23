// main.cpp
// Tanner Oakes
// Project 4 - Virtual Driverory
// 4/19/18

#include <bitset>
#include <iostream>
#include "Driver.h"
#include "PageTable.h"
#include "PhysicalMemory.h"
#include "TLB.h"

// loads frame into main memory, updates page table, and updates TLB
void pageFaultHandler(unsigned char pageNumber, unsigned char &frameNumber, PhysicalMemory &mm, PageTable &pt, TLB &tlb) {
   frameNumber = mm.loadFrame();
   pt.updatePageTable(pageNumber);
   tlb.replaceLRU(pageNumber, frameNumber);

}

unsigned int createPhysicalAddress(unsigned char frameNumber, unsigned char offset) {
   string frameNumberStr = to_string(frameNumber);
   string offsetStr = to_string(offset);
   string physicalAddressStr = frameNumberStr + offsetStr;

   unsigned int physicalAddress = stoi(physicalAddressStr, nullptr);

   return physicalAddress;
}

int main(int argc, const char * argv[]) {
   // Vars: page number, frame number and offset
   unsigned char pageNumber;
   unsigned char frameNumber;
   unsigned char offset;

   //Addresses

   // The TLB and page table
   TLB tlb;
   PageTable pt;

   // Simulated Main Memory
   Driver driver;
   PhysicalMemory mm;

   // value and address-value list
   int value;
   vector<Driver::address_value_pair> address_value_list;

   // Boolean for TLB hit and page fault
   bool isTLBHit;
   bool isPageFault;

   // Input and output file names

   // Initialize the system
   tlb.initTLB();

   // Create a logical address list from the file
   // loads input addresses into vector
   vector<unsigned int> logicalAddresses = driver.loadAddresses("InputFile.txt");

   for (int i = 0; i < logicalAddresses.size(); i++) {
      // Get a logical address, its page number and offset
      pageNumber = driver.extractPageNumber(logicalAddresses[i]);
      offset = driver.extractOffset(logicalAddresses[i]);

      // Search the TLB
      // If a TLB hit occurs, return the frame number
      // else, go to the page table
      if (tlb.checkTLB(pageNumber) != -99) {
         // create physical address
         frameNumber = tlb.checkTLB(pageNumber);
      }
      // go to page table
      else {
         if (pt.isValidPage(pageNumber)) {
            isPageFault = false;
            frameNumber = (unsigned char)(pt.returnFrameNumber(pageNumber).to_ulong());
         }
         // page fault
         else {
            pageFaultHandler(pageNumber, frameNumber, mm, pt, tlb);

         }
      }
      // read one byte value from main memory
      value = mm.lookUp(frameNumber, offset);

      // Update the addres-value list
      Driver::address_value_pair pair;
      pair.physicalAddress = createPhysicalAddress(frameNumber, offset);
      pair.value = mm.lookUp(frameNumber, offset);
      address_value_list.push_back(pair);
   }

   mm.loadFrame();
   mm.loadFrame();

   cout << tlb.checkTLB(0) << endl;
   cout << tlb.checkTLB(1) << endl;

   return 0;
}
