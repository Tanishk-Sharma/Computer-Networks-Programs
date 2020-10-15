# Hamming Code generation

In telecommunication, a Hamming code is a linear error-correcting code named after its inventor, Richard Hamming. 
Hamming codes can detect up to two simultaneous bit errors, and correct single-bit errors; thus, reliable communication is possible when the Hamming distance between the transmitted and received bit patterns is less than or equal to one. 
By contrast, the simple parity code cannot correct errors, and can only detect an odd number of errors.
<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20200424184419/hamming_code.png">
</p>
## Steps

The key to the Hamming Code is the use of extra parity bits to allow the identification of a single error.
Create the code word as follows:

**1.** Mark all bits positions that are powers of two as parity bits (eg. 1, 2, 4, 8, ...)

**2.** All other bit positions are for the data to be encoded (eg. 3, 5, 7, 9, ...)

**3.** Each parity bit calculates the parity for some of the bits in the code word.

The position of the parity bit determines the sequence of bits that it alternatively checks and skips:

**Position 1**: check 1 bit, skip 1 bit (1, 3, 5, 7, 9, ...)

**Position 2**: check 2 bits, skip 2 bits (2, 3, 6, 7, 10, 11, ...)

**Position 4**: check 4 bits, skip 4 bits (4, 5, 6, 7, 12, 13, 14, 15, ...)

etc.

**4.** Set a Parity Bit to 1 if the total number of ones in the positions it checks is odd; if even, set Parity Bit to 0.
