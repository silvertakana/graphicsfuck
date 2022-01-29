# graphicsfuck

graphicsfuck is a coding language similar to brainfuck. Basicly graphics smashed with brainfuck! 

## how does it work?

everything apply in brainfuck apply to graphicsfuck aswell.

there are atleast `196,613` bytes of memory `196,608` bytes for image buffer, `2` bytes for the postion teleport location (note that the postion is read from left to right), `1` byte for the teleport button, `1` byte for the render button, `1` byte for the settings count, 

#### layout:
`[image buffer][postion teleport location][teleport button][render button][settings count][additional memory for computing]`
#### attributes:
| name | byte counts |
| ---- | ----------- |
| image buffer | `196,608` |
| postion teleport location | `2` |
| teleport button | `1` |
| render button | `1` |
| settings count | `1` |
#### meaning:
setting count : the amount of bytes between settings count to the image buffer. 
render button : used to tell the window when to render data on the image buffer 
teleport button : used to teleport the pointer to the according pixel in the imageBuffer based on the  postion teleport location
postion teleport location : the xy coordinate on the screen used to teleport the pointer (note that the postion is read from left to right)
