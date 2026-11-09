Brightness checker

## Description

**version 1.0**

MY program uses a palette in hex that the user can choose from. The user also gets a menu from different types
of colorblindess'. This menu can be used so that the user can choose their type of blindness so that
the compiler can determine the difference of the brightness of certain colors more accurately. This is so 
the user can save themselves from colors that are harder to distinguish depending on their colorblidness.


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
How many colors are in your palette (2-10): 3
Choose a vision type:
1. Protanopia (red-blind)
2. Deuteranopia (green-blind)
3. Tritanopia (blue-blind)
4. Normal vision
Choice: 1
Color 1 - enter hex code (like #FF8000): #0000FF
Color 2 - enter hex code (like #FF8000): #FF00FF
Color 3 - enter hex code (like #FF8000): #FFFF00
Color 1 and 2: Hard to tell apart.
Color 1 and 3... EASY
Color 2 and 3... EASY

Warning: Some colors in your palette are too similar.
People with color blindness may not be able to tell them apart.

```