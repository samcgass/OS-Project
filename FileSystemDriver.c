/*  Sam Gass, Henry Paek, Haden Stuart
    Operating Systems
    2/8/2020
    Project Part 1 - File System Driver */

#include <stdio.h>

// String for the name of the memory file to be created/modified
char memoryFile[] = "simulated_memory.bin";

/*  An unsigned short is 2 bytes (a word) so 32000 ushorts is 64KB,
    the size of a sector. Now we can use sizeof(sector) to get 64KB.
    Its initalized to all zeros but the Erase methods make every bit a 1.   */
unsigned short sector[32000];

/*  If the file with name memoryFile does not exist, it creates a file with
    20 sectors, each sector with size 64KB for a total of 1.28MB with every bit being 1.
    If the file does exist, it replaces it with a file of all 1's   */
void EraseAllSectors()
{
    //  sets all bits in the sector array to 1. 0xFFFF is the max value of an ushort.
    for (int i = 0; i < 32000; i++)
    {
        sector[i] = 0xFFFF;
    }

    //  opens or creates the file with name memoryFile in the mode for writing bits.
    FILE *memoryPtr = fopen(memoryFile, "wb");

    //  For 20 sectors, writes 64KB of 1's to the file pointed to by memoryPtr
    for (int i = 0; i < 20; i++)
    {
        fwrite(&sector, sizeof(sector), 1, memoryPtr);
    }

    //  close file.
    fclose(memoryPtr);

    return;
}

/*  If the file with name memoryFile does not exist, calls EraseAllSectors() to create a file.
    If the file does exist, it replaces all bits at sector nSectorNr  with 1's   */
void EraseSector(int nSectorNr)
{
    // opens the file at memoryFile for reading and writing bits.
    FILE *memoryPtr = fopen(memoryFile, "rb+");
    // if the file does not exist, calls on EraseAllSectors() to create one.
    if (memoryPtr == NULL)
    {
        EraseAllSectors();
        return;
    }

    //  sets all bits in the sector array to 1. 0xFFFF is the max value of an ushort.
    for (int i = 0; i < 32000; i++)
    {
        sector[i] = 0xFFFF;
    }

    //  moves memoryPtr to sector to be erased
    int offset = nSectorNr * sizeof(sector);
    fseek(memoryPtr, offset, SEEK_SET);
    //  for the sector pointed to be memoryPtr, all bits are set to 1.
    fwrite(&sector, sizeof(sector), 1, memoryPtr);
    //  close file.
    fclose(memoryPtr);
}

void readWord(int nAddress)
{
    return;
}

void writeWord(int nAddress, unsigned short nWord)
{
    return;
}

int main(void)
{
    //EraseAllSectors();
    //EraseSector(19);
    printf("done");
    return 0;
}