# 7bit String Encoding - Decoding
The purpose of the program is to Encode a string where every single byte is used entirely to represent a character to a string where each character is represented by only using 7 bits (the highest bit is not counted), by doing so the encode function saves 1 bit for each character.  
The Encoding is done by shifting to the left the character byte, starting from a shift of only 1 bit and increase the shift each time to a maximum of 7 bits, then the module operator is used to reset the shift counter to the initial 1 bit.  
The Decoding is done by shifting to the right the character byte, by doing so the highest bit (8th bit) will always be 0, that will only make possible the encoding/decoding of Standard ASCII characters and exclude the Extended ASCII characters set.  
Some bitwise operations are done to make the Encoding and Decoding of a string possible.  

### Encoding example of a String
*- input string 'abcdefg\0' (size of 8 bytes):*
| a (0x61) | b (0x62) | c (0x63) | d (0x64) | e (0x65) | f (0x66) | g (0x67) | \0 (0x00)|
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | 
| 01100001 | 01100010 | 01100011 | 01100100 | 01100101 | 01100110 | 01100111 | 00000000 |

*- output string (size of 7 bytes):*
| 0xc3     | 0x8b     | 0x1e     | 0x4c     | 0xb9     | 0xb3     | 0x80     |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | 
| 11000011 | 10001011 | 00011110 | 01001100 | 10111001 | 10110011 | 10000000 |