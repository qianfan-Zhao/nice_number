nice number
===========

There has a version code in [stackoverflow](http://stackoverflow.com/questions/8506881/nice-label-algorithm-for-charts-with-minimum-ticks),
it was wrote by JAVA, So i write anthor version of C.


> When creating a graph by computer, it is desirable to label the x and y axes with "nice" numbers: simple decimal numbers. For example, if the data range is 105 to 543, we'd probably want to plot the range from 100 to 600 and put tick marks every 100 units. Or if the data range is 2.04 to 2.16, we'd probably plot a range from 2.00 to 2.20 with a tick spacing of 0.05. Humans are good at choosing such "nice" numbers, but simplistic algorithms are not. The naïve label-selection algorithm takes the data range and divides it into n equal intervals, but this usually results in ugly tick labels. We here describe a simple method for generating nice graph labels.
>
> <br>
> The primary observation is that the "nicest" numbers in decimal are 1, 2, and 5, and all power-of-ten multiples of these numbers. We will use only such numbers for the tick spacing, and place tick marks at multiples of the tick spacing...

## BUILD, TEST

	$ gcc nice_number.c -o nice_number -lm
	$ ./nice_number -0.085 0.173 10
	num: 0.050000, min: -0.100000, max: 0.200000
	-0.100000 | -0.050000 | 0.000000 | 0.050000 | 0.100000 | 0.150000 | 0.200000 |

## LICENSE

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

