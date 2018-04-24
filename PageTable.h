// Tanner Oakes
// 4/19/18
// OS Project 4 - Virtual Memory

#ifndef PageTable_h
#define PageTable_h

#include <bitset>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class PageTable {
public:
   PageTable() : page_table_t(PAGE_TABLE_SIZE), nextEmptyEntryIndex(0) {}

   // void initializePageTable();
   bool isValidPage(unsigned char pageNumber);
   bitset<8> returnFrameNumber(unsigned char pageNumber);
   void updatePageTable(unsigned char frameNumber);
   vector< bitset<9> > getPageTable();

private:
   const static int PAGE_TABLE_SIZE = 256;
   vector< bitset<9> > page_table_t;
   unsigned int nextEmptyEntryIndex;
};

#endif
