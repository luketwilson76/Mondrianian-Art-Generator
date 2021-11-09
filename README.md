# L6: Recursive Art

## Use randomness, recursion, and turtles to create art in the style of Piet Mondrian.
### Starter files have been provided for you in C++

### Author(s):
- Author of this program: *Luke Wilson*
- Author of lab and stubs: Jan Pearce, Berea College
- Author of the [C-Turtle](https://github.com/walkerje/C-Turtle) library: Jesse Walker-Schadler

# Implementation Prompts due with Milestone 2:

1. **SPLITTING**
*How many units wide or tall did you consider a
rectangle too small to split?*

*I made the base case  <= 15 for both width and height using a or statement*

2. **NUMBER CALLS**
*While filling out the above rectangle in the Mondrian style
using the series of steps above,
is there anything you noticed that will change how many times the
recursive function gets called? Explain*

*messing with the min and max of what a random value can be returned messes with how many squares are returned*

3. **EXTRA STEPS**
*Most design choices have advantages as well as disadvantages.
Given the above series of steps, are there any steps you 
felt were unnecessary given what other steps perform?*

*I'm sure there are many unneccessary steps in my code I have overlooked'*

4. **DISADVANTAGE**
*Describe and explain at least one disadvantage of using recursion to
generate Mondrian art.*

I think a disadvantage to recursion is how changing some type of rule to reach your
your base case can change your code drastically.

5. **CHALLENGES IN BASIC ALGORITHM**
I'm still struggling created the recursive algorithm. I'm still trying to get it to split correctly.

# Customization Prompts due with Final Milestone:

6. **REQUIRED CUSTOMIZATIONS**
*What customizations did you make Mondrian art, and why did you choose it.*

*I made it to where the color was generated randomly using three random objects using a roll method.*

7. **PROCESS SUMMARY**
*Briefly summarize your design and implementation process,
including how much your initial design plan evolved,
the final results you achieved, and the amount of time you spent
as a programmer or programmers in accomplishing these results.
This should be one or at most two paragraphs.*

*I wanted a method to first start a screen then split that screen randomly into four quadrants. I planeed for a 
recursive method to populate each quadrant using adjusted values due to x, y coordinate difference. The quadrants would
be filled randomly based on their relative size. I spent probaly 24hrs on this projects. I some-what got the
result I was looking for with some errors.*

8. **DESIGN CHALLENGES**
*Describe the primary conceptual challenges that you encountered
in trying to complete this lab and what might have made the
lab easier for you.*

*The hardest challenge was for the program to recursive remember what the max/new sizes were for next recursive step. 
Another hard part was making the turtle move correctly to the bigger sector of a square. I think giving sample code
of the quadrants being seperated evenly would have helped a lot.*

9. **BIG O ANALYSIS**
*Please analyze the Big O of all of the methods of the MondrianArt class,
including constructors.
Hint: Given the random nature of this lab,
be sure you write about the worst case.*

*
Square: O(1)
draw_screen: O(1)
set_frame: O(1)
recursive_draw: best case O(1), worst case O(logn)
'*

10. **TESTING**
*Please briefly describe your testing process.
Here you should be careful to select representative input cases,
including both representative typical cases as well as extreme cases.*

*I used incremental testing. I slowly tested each part of the code until an expectation was met. If
an error were to show up, I would know whre it be coming from since I tested just about every line 
indivdually*

11. **ERRORS**
*List in bulleted form of all known errors
and deficiencies with a very brief explanation.*

- *program will sometimes overlap squares when a quadrant is bigger in width and height*
- *sometimes the program may act weird when a line is revisted by a turtle.*

12. **LEARNING AND REACTION**
*A paragraph or so of your own comments
on what you learned and your reactions to this lab.*

*I learned that recursive algorithms are the hardest part of the three rules of recursive It's easy to create a
base case and call the function back to itself but narrowing down the parameters to reach a base case is quite
difficult. I learned that incremental testing is a neccessary when working with recursion. Recursion is very 
unpredictable sometimes when one value is changed. It's like a line of dominoes.*

13. **INTEGRITY STATEMENT**
*INTEGRITY STATEMENT: Please briefly describe ALL help you 
received and all help you gave to others in completing this lab.
Also list all other references. 
If you worked in a pair you must also attested to only 
having worked together as a pair, not separately.*


*n/a*

## References:
- This repo contains code by Jan Pearce and Jesse Walker-Schadler as described above.
- The linked lab heavily leverages nifty.stanford.edu/2018/stephenson-mondrian-art/
- *FIXME*
