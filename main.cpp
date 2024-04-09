#include <iostream>

int CountSimilarBytes(long long int byte);
//one more thing
void SwapBytes(unsigned short* b);

unsigned char GetMaxByte(const unsigned int* ar, size_t size);

//ok what the hell is wrong with my git shit
int main()
{

    return 0;
}


int CountSimilarBytes(long long int byte)
{
    int maxCount = 0;
    int currentCount = 0;
    int prevByte = -1;

    for (int i = 0; i < sizeof(long long int); ++i) {
        int currentByte = (byte >> (8 * i)) & 0xFF;
        if (currentByte != 0xFF && currentByte != 0x00) {
            if (currentByte == prevByte) {
                currentCount++;
            } else {
                currentCount = 1;
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        prevByte = currentByte;
    }

    return maxCount;
}

void SwapBytes(unsigned short* b)
{
    unsigned short bf = (*b << 4*6 >> 4*6);
    *b = *b + ~bf + 1;
    *b = (*b >> 4*2);
    *b = *b + (bf << 4*2);
}

unsigned char GetMaxByte(const unsigned int* ar, size_t size)
{
    unsigned char maxByte = 0;
    for (size_t i = 0; i < size; ++i) {
        const unsigned char* bytePtr = reinterpret_cast<const unsigned char*>(&ar[i]);
        for (size_t j = 0; j < sizeof(unsigned int); ++j) {
            if (bytePtr[j] > maxByte) {
                maxByte = bytePtr[j];
            }
        }
    }
    return maxByte;
}
