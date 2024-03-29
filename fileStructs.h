// Struct types for all files
#include <stdint.h>

// globally define MAX_BLOCK_SIZE for random functions
#define MAX_BLOCK_SIZE 3

// assigns type uint8_t to type BYTE for better readability
typedef uint8_t BYTE;

// struct for storing data from an ebf file
typedef struct 
{
    unsigned char magicNumber[2];
    int width, height;
    long numBytes;
    unsigned int **imageData;
    unsigned int *dataBlock;
} 
ebfData;

// struct for storing data from an ebu file
typedef struct
{
    unsigned char magicNumber[2];
    int width, height;
    long numBytes;
    BYTE **imageData;
    BYTE *dataBlock;
}
ebuData;

// struct for storing data from an ebc file
typedef struct
{
    unsigned char magicNumber[2];
    int width, height;
    long numBytesUncompressed;
    long numBytesCompressed;
    BYTE *dataBlockCompressed;
    BYTE *dataBlockUncompressed;
}
ebcData;


// struct for storing block data according to the top left pixel index
typedef struct
{
    int rowNum;
    int columnNum;
    int rowSize;
    int columnSize;
    int numPixelsInBlock;
    int totalValueOfBlock;
    int averageValueOfBlock;
    BYTE blockImage[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE];
    BYTE dataBlock[MAX_BLOCK_SIZE * MAX_BLOCK_SIZE];
}
block;


// struct for storing data from an ebcc file
typedef struct
{
    unsigned char magicNumber[2];
    int width, height;
    int noBlocksByWidth, noBlocksByHeight;
    long numBytes;
    long numBlocksUncompressed;         // variables for finding how many bytes 
    long numBlocksCompressed;           // are needed for these arrays
    BYTE *blocksCompressed;
    BYTE *blocksUncompressed;
    BYTE **imageDataUncompressed;
    BYTE *dataBlockUncompressed;
    block *blocksInImage;
}
ebcBlockData;


// struct for storing data from an ebcc random block file
typedef struct 
{
    unsigned char magicNumber[2];
    int width, height;
    int numParadigmBlocksUncompressed;
    int numParadigmBlocksCompressed;
    long sizeOfParadigmBlockArrayUncompressed;
    long sizeOfParadigmBlockArrayCompressed;
    int numBitsCompressed;
    long numBlocksUncompressed;         // variables for finding how many bytes 
    long numBlocksCompressed;           // are needed for these arrays
    int *paradigmBlocksIndex;
    BYTE *compressedParadigmBlocks;         // stores the values for the paradigm blocks being used in the program
    BYTE *uncompressedParadigmBlocks;           // ^
    BYTE *dataBlockCompressed;          // stores the location for the paradigm blocks being used in the image
    BYTE *dataBlockUncompressed;        // ^ 
}
ebcRandomBlockData;






