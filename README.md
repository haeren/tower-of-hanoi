# Tower of Hanoi

The game contains three rods and a certain number of discs in different sizes. It starts by placing discs in ascending order of size (smallest at top) on initial rod. The goal of the game is moving discs to the target rod within the rules.

These rules are:
- Only one disc may be moved at a time.
- Each move consists of taking the upper disc from one of the rods and sliding it onto another rod.
- No disc may be placed on top of a smaller disc.

![steps.jpg](https://github.com/haeren/tower-of-hanoi/blob/main/readme-images/steps.jpg?raw=true)
|:--:|
|*Steps of Tower of Hanoi for 3 discs*|

## Recursive Algorithm

When we have two discs to move, solving the problem is pretty easy:
- Move the small disc from source rod to spare rod
- Move the large disc from source rod to destination rod
- Move the small disc from spare rod to destination rod

Now consider we have n discs, take all discs except big one at bottom then move them onto spare rod. So we have nth disc on source rod and n-1 discs on spare rod. Then move nth disc onto destination rod and move n-1 discs onto destination rod. These steps are:
- Move n-1 discs from source rod to spare rod
- Move nth disc from source rod to destination rod
- Move n-1 discs from spare rod to destination rod

![recursive.png](https://github.com/haeren/tower-of-hanoi/blob/main/readme-images/recursive.png?raw=true)
|:--:|
|*The functions we need to call for 3 discs*|

The stacks and count numbers are associated with the rods as follows:
- yiginA and aGuncel: Rod A (source)
- yiginB and bGuncel: Rod B (spare)
- yiginC and cGuncel: Rod C (destination)

## Functions
| Function | Comment |
| ------ | ------ |
| yiginiHazirla | It provides the initial state. Values which represents discs are assigned to yiginA. These values are assigned in descending order (smaller value = smaller disc). |
| yiginlariGoster | It shows status of the rods and discs. |
| diskiTasi | It moves discs by calling the functions yigindanCikar and yiginaEkle, also shows status of the rods on each step with the function yiginlariGoster. |
| yigindanCikar | The moving disc is removed from the rod and value of it returns as integer to the caller. |
| yiginaEkle | The removed disc is added to destination rod by using the value returned by yigindanCikar. |

## Output
![output.jpg](https://github.com/haeren/tower-of-hanoi/blob/main/readme-images/output.jpg?raw=true)
|:--:|
|*An example output of Tower of Hanoi with 3 discs*|
