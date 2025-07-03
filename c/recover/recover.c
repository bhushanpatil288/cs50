#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // accenpting 1 command-line argument only
    if (argc != 2)
    {
        printf("usage ./recover [forensic-image]\n");
        return 1;
    }

    // opening memory card
    FILE *fImage = fopen(argv[1], "r");
    if (fImage == NULL)
    {
        printf("Cannot open the file : %s\n", argv[1]);
        return 1;
    }

    // buffer for block of data
    uint8_t buffer[BLOCK_SIZE];

    // pointer for recovered jpegs
    FILE *img = NULL;

    // store filename
    char filename[8];

    // counter
    int count = 0;

    // while there's still data left to read
    while (fread(buffer, 1, BLOCK_SIZE, fImage) == BLOCK_SIZE)
    {
        // check if it's the start of new jpeg

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if already writing jpeg close it
            if (img != NULL)
            {
                fclose(img);
            }

            // create new filename and open new file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");

            count++;
        }

        // if jpeg found write to the file
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(fImage);
}
