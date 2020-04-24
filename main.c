#include <stdio.h>
#include "7bit_encoding.h"

#define BUFSIZE 128

int main(void) {
	char input[] = "abcdefg";
	char out_encode[BUFSIZE], out_decode[BUFSIZE];
	int encode, decode;

	if ((encode = text_7bit_encode(input, &out_encode)) > 0) {
		decode = text_7bit_decode(&out_encode, &out_decode);

        printf("Encoded string size: %d\n", encode);
        printf("Decoded string size: %d\n", decode);
	} else {
		printf("Error: Extended ASCII character detected!");
	}

	return 0;
}
