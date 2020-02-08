// Sam Gass
// Operating Systems
// 2/7/2020
// Project Part 1
#include <stdio.h>

char memoryFile[] = "simulated_memory.bin";

unsigned short sector[32000];

void EraseAllSectors()
{
    for (int i = 0; i < 32000; i++)
    {
        sector[i] = 0xFF;
    }

    FILE *memoryPtr = fopen(memoryFile, "wb");

    for (int i = 0; i < 20; i++)
    {
        fwrite(&sector, sizeof(sector), 1, memoryPtr);
    }
    fclose(memoryPtr);
    return;
}

void EraseSector(int nSectorNr)
{
    FILE *memoryPtr = fopen(memoryFile, "rb+");
    if (memoryPtr == NULL)
    {
        EraseAllSectors();
    }

    for (int i = 0; i < 32000; i++)
    {
        sector[i] = 0xFFFF;
    }

    int offset = nSectorNr * sizeof(sector);

    fseek(memoryPtr, offset, SEEK_SET);

    fwrite(&sector, sizeof(sector), 1, memoryPtr);

    fclose(memoryPtr);
}

int main(void)
{
    //EraseAllSectors();
    //EraseSector(19);
    printf("done");
    return 0;
}