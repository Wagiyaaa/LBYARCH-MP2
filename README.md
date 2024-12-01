# MP2
MADE BY:
Baniqued, Lourenz Jhay G. And
De Guzman, Joaquin Nicholas C.


## Overview
The program is written in **C** and **x86-64 Assembly**, with functionality to process pixel values and convert them using Assembly Function.

---

## Execution Time and Performance Analysis

The execution time of the Assembly Function was measured for 10 * 10, 100 * 100, 1000 * 1000. The test is run 30 times to get the average execution time. Below are the results for the ASM function:

| Method          | Average Execution Time (seconds) |
|-----------------|--------------------------|
| 10*10 | 0.008033333333       |
|  100*100  | 0.5066    |
|  1000*1000  | 33.36216667    |

Below are the results for the C function:
| Method          | Average Execution Time (seconds) |
|-----------------|--------------------------|
| 10*10 | 0.01006666667       |
|  100*100  | 0.4885    |
|  1000*1000  | 33.29783333    |

Link of tests: https://docs.google.com/spreadsheets/d/1iV-V2P77U_uW7-nzBrkqMWuYemiLZkOcvrB35FCf-VA/edit?usp=sharing

### Analysis:
Based from each of the test cases ran, it seems that the C equivalent function executed faster than the one implemented in Assembly. The only time Assembly was faster was when the size of the image was 10 pixels by 10 pixels. However, the difference in running times were not so great in the 100 x 100 and 1000 x 1000 trials. Morever, in some instances, the assembly function ran faster than the C function. This shows that perhaps some improvements can be made to the assembly code such that it requires less instructions to execute. However, going back to the fact that the average of all the trials were very close in execution time, one can conclude that at the very least the assembly equivalent function is nearly equal to that of the one implemented in C.

---

## Program Output and Correctness Check
### 10 * 10
![Program Output 10*10](images/10x10_output.JPG)
### 100 * 100
![Program Output 100*100](images/100x100_output.JPG)
### 1000 * 1000
![Program Output 1000*1000](images/1000x1000_output.JPG)



---

## Short Videos

---
[Demo Video](https://drive.google.com/file/d/1GLSPLI_hfYSpWvvjMgyHeOSh72mTszT2/view?usp=sharing)
