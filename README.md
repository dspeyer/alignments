alignments
==========

Test code for a (sometimes) more efficient DNA alignment algorithm

The usual approach to DNA alignment is quadratic-time dynamic programming.  This algorithm examines only relevant DNA for approximately linear time over similar sequences, at the cost of much higher overhead for dissimilar sequences.  This repository contains both the new algorithm and a simple test harness.

For more information, see explanation.pdf
