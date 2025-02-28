#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Modifies the volume of an audio file

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    uint8_t buffer[44];
    // TODO: Copy header from input file to output file
    fread(buffer, sizeof(uint8_t), 44, input);
    fwrite(buffer, sizeof(uint8_t), 44, output);

    int16_t sample;
    // TODO: Read samples from input file and write updated data to output file
    while(fread(&sample, sizeof(int16_t), 1, input))
    {
        sample *= factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
