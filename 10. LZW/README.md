# LZW (Lempel–Ziv–Welch) Compression technique

The LZW algorithm is a lossless data compression algorithm created by **Terry Welch** in **1984**. 
This algorithm represents an improved version of the LZ78 algorithm created by Abraham Lempel and Jacob Ziv in 1978.

The idea of the compression algorithm is the following: as the input data is being processed, a dictionary keeps a correspondence between the longest encountered words and a list of code values. 
The words are replaced by their corresponding codes and so the input file is compressed. Therefore, the efficiency of the algorithm increases as the number of long, repetitive words in the input data increases.
<p align="center">
  <img src="https://www.dspguide.com/graphics/F_27_6.gif">
</p>
Either when using the compression or the decompression methods, the elements of the input array must be of type unsigned char, which is also the type of the resulting array's elements.

The following example generates a sample array of N random letters (from A to Z) and compresses it. 
The compressed array is then decompressed to see if the sample array is identical to the uncompressed array. 
The size of the compressed array is also displayed, to prove the efficiency of the LZW algorithm.
