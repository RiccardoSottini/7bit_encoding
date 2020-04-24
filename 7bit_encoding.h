#include <stdint.h>
#include <math.h>

/*
 * Function: text_7bit_encode
 * --------------------------
 * Encode a String where every character is saved using 8bit
 * to a String where each character is represented by only using 7bit
 * (Using the shift of the bits, the result is one bit saved for each character)
 *
 * const char* txt_in - pointer of the String to encode
 * char* txt_out      - pointer of the String encoded
 *
 * return  size of the String that results from the encoding
 *         -1 in the case the txt_in contains a character from the Extended ASCII version
 */

int32_t text_7bit_encode(const char* txt_in, char* txt_out) {
	int counter = 0;                //counter used in the shift of bits
	int nchar = strlen(txt_in) + 1;	//number of characters + string terminator
	char* pchar = txt_out;          //pointer used to move around the String

	for (int c = 0; c < nchar; c++, pchar++) {
		if ((txt_in[c] >> 7) & 1) return -1;	//check the highest bit of the character - check if the characters is from the Extended ASCII version

		counter = (counter % 7) + 1;			//counter increment
		int mask = pow(2, counter) - 1;			//bit mask used

		//calculate the value of the current character (considering the current character byte and the next one)
		int next = ((c + 1) != nchar) ? (txt_in[c + 1] >> (8 - counter - 1)) & mask : 0;
		*(pchar) = ((txt_in[c] << counter) & ~mask) | next;
		if (counter == 7) c++;
	}

	return pchar - txt_out;			//return the size of the output String
}

/*
 * Function: text_7bit_decode
 * --------------------------
 * Decode a String where every character is saved using 7bit
 * to a String where each character is represented by the full 8bit character
 *
 * const char* txt_in - pointer of the String to decode (the string must be in the 7bit encode format)
 * char* txt_out      - pointer of the String decoded
 *
 * return  size of the String that results from the decoding
 */

int32_t text_7bit_decode(const char* txt_in, char* txt_out) {
	int counter = 0;                //counter used in the shift of bits
	char* pchar = txt_out;          //pointer used to move around the String

	for (int c = 0; !c || *(pchar - 1) != 0; c++, pchar++) {
		counter = (counter % 8) + 1;        //counter increment
		int mask = pow(2, 8 - counter) - 1; //bit mask used

		//calculate the value of the current character (considering the previous character byte and the current one)
		int previous = (counter != 1) ? (txt_in[c - 1] << (8 - counter)) & 0x7F : 0;
		*(pchar) = ((txt_in[c] >> counter) & mask) | previous;
		if (counter == 8) c--;
	}

	return pchar - txt_out;			//return the size of the output String
}
