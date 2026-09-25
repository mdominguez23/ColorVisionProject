Brightness checker

## Description

**version 1.0**

My program checks whether the colors in a palette, such as the color in a chart or graph, will
be easy to tell apart, especially for people with color blindness. The user enters how many colors they have
and each color's RGB value the program compares every colors brightness, and says wether eacher pair
is hard, okay or easy to tell apart. It finishes with a statements telling you it looks good and its easy
to tell apart or it warns you that the colors are hard to tell apart.


## Developer

Michael Dominguez

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
How many colors are in your palette (2-8): 2 
Color 1 - enter R G B: 204 0 0
Color 2 - enter R G B: 0 0 0
color 1 and 2... OKAY 

your palette looks good!
Every pair of colors has enough brightness difference to be told apart.

```