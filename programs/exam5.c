#include <stdio.h>
#include <stdlib.h>

int main() {
    //we open the files where is the image
    FILE *input = fopen("input.bmp", "rb");
    FILE *output = fopen("output.bmp", "wb");
    //we check if the files can open or not
    if (!input || !output) {
        return 1;
    }
    //we create the array we need for the image's header
    unsigned char header[54];
    if (!fread(header, sizeof(unsigned char), 54, input)) {
        return 1;
    }
    //we check if in the two first positions of the array there the character 'B' and 'M' respectively
    if (!(header[0]=='B' || header[1]=='M')) {
        return 1;
    }
    unsigned int color=(int)header[28];
    if (color!=24) {
        return 1;
    }
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int newWidth = height;
    int newHeight = width;
    *(int*)&header[18] = newWidth;
    *(int*)&header[22] = newHeight;
    fseek(input, 0, SEEK_END);
    long filesize = ftell(input);
    fseek(input, 0, SEEK_SET);
    if (filesize < 54) {
        return 1;
    }
    fseek(input, 54, SEEK_SET);
    fwrite(header, sizeof(unsigned char), 54, output);
    int imagesize = 3 * width * height;
    unsigned char *pixel = (unsigned char*)malloc(imagesize);
    if (!fread(pixel, sizeof(unsigned char), imagesize, input)) {
        return 1;
    }
    //we rotate the image 90 degrees to right
    int j;
    for (int i=0 ; i<width ; i++) {
        for (j=0 ; j<height ; j++) {
            fwrite(&pixel[3 * (j * width + (width-1-i))], sizeof(unsigned char), 3, output);
        }
    }
    //we release the memory from the array with the pixels
    free(pixel);
    //we close the files we had open 
    fclose(input);
    fclose(output);
    return 0;
}