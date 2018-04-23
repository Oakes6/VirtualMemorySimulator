virtual_memory: Driver.cpp main.cpp PageTable.cpp PhysicalMemory.cpp TLB.cpp
	g++ -o virtual_memory Driver.cpp main.cpp PageTable.cpp PhysicalMemory.cpp TLB.cpp

# virtual_memory: Driver.o TLB.o PageTable.o main.o
# 	g++ -o virtual_memory Driver.o TLB.o PageTable.o main.o

# Driver.o: Driver.cpp Driver.h
# 	g++ Driver.cpp Driver.h
#
# TLB.o: TLB.cpp TLB.h
# 	g++ TLB.cpp TLB.h
#
# PageTable.o: PageTable.cpp PageTable.h
# 	g++ PageTable.cpp PageTable.h
#
# main.o: main.cpp
# 	g++ main.cpp
