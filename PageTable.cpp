// Tanner Oakes
// 4/20/18
// OS Project 4 - Virtual Memory

#include "PageTable.h"

bool PageTable::isValidPage(unsigned char pageNumber) {

   bitset<9> page = page_table_t[pageNumber];
   //check the valid bit (MSB)
   return page.test(8);
}

void PageTable::updatePageTable(unsigned char frameNumber) {
   //next empty entry
   bitset<9> entry (frameNumber);
   entry.set(8);

   page_table_t[nextEmptyEntryIndex] = entry;
   nextEmptyEntryIndex++;
}

bitset<8> PageTable::returnFrameNumber(unsigned char pageNumber) {
   bitset<9> pte = page_table_t[pageNumber];
   string frameNumberStr = pte.to_string();
   frameNumberStr = frameNumberStr.substr(1,9);
   bitset<8> frameNumber (frameNumberStr);
   return frameNumber;
}

// returns the page table
vector< bitset<9> > PageTable::getPageTable() {
   return page_table_t;
}
