# graphicsfuck

graphicsfuck is a coding language similar to brainfuck. Basicly graphics smashed with brainfuck! 

here is an introduction:  
https://www.youtube.com/watch?v=GsIUcM05eXU


## install

first you must download the repository down  
you can use the terminal:

```batch
git clone https://github.com/silvertakana/graphicsfuck.git
```
or you can use the download zip button:

![alt text](https://helpdeskgeek.com/wp-content/pictures/2021/06/11CodeButtonDownloadZip.png)


after dowloaded the repository, navigate to the `generateProject.bat` file, and click it. this should appear on the terminal.  
```
your ProjectEditor:
```
type in the project editor you are using and click enter.
example for visual studio 2019:
```
your ProjectEditor: vs2019
```
now write your code here.
```
auto programCode = R"(

	write your code here

)";
```
example program:
```
    +[<<<<+[<+[+>>+ +>-->+ |<<<<<]>+]|<<+|]
```
## how does it work?

everything apply in brainfuck apply to graphicsfuck aswell.

there are atleast `196,613` bytes of memory `196,608` bytes for image buffer, `2` bytes for the postion teleport location (note that the postion is read from left to right), `1` byte for the teleport button, `1` byte for the render button, `1` byte for the settings count, 

#### layout:
`[image buffer][postion teleport location][teleport button][render button][settings count][additional memory for computing]`
#### attributes:
| name | byte counts | meaning |
| ---- | ----------- | ------- |
| image buffer | `196,608` | the buffer where you draw things to. |
| postion teleport location | `2` | the xy coordinate on the screen used to teleport the pointer (note that the postion is read from left to right) |
| teleport button | `1` | used to teleport the pointer to the according pixel in the imageBuffer based on the  postion teleport location. |
| render button | `1` | used to tell the window when to render data on the image buffer. |
| settings count | `1` | the amount of bytes between settings count to the image buffer. |
