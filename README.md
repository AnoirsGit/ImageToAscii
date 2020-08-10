# ImageToAscii
Application to create Ascii picture from image
This work was done with C++ language, Open CV 4.12 library that was integrated with CMake - 3.16 on Visual Studio code, Windows 10 operational system . 

When I looked for the Internet about the solution of this project on C++ mostly I saw that they are did this from Open CV library or they wrote own library to read images that based on image type that they wrote. I don't have enough knowledge or experience to wrote own library to work with images, so I settled on the idea to make it on Open CV. Firstly I wanted to make this project on Manjaro KDE 18.13 Linux, on the GCC 9.2 , but I had a lot of troubles with the integration of Open CV library.  I am tried to integrate this library on the Manjaro Linux two weeks, about hour a day. May be this version of Open CV can't correct work with the GCC 9.2 or I did something wrong with the guides that I read or watched to install this library. So I looked for the solution of this problem and I saw that mostly they work with Open CV on Windows 10. I didn't want to change my work space to solve this problem, but I had deadline and I didn't start to code that. I had to install Windows 10 and search the installation Open CV. Some guys in Hindi show the installation of Open CV older version on the Visual Studio Community with CMAKE. I tried to repeat his actions, but I had problems with the version of Visual Studio Community. Then I looked for fresh installation of Open CV library on C++, then after several days find the installation with CMAKE on Visual Studio code. After several tries Open CV was integrated on Visual Studio code.

This approach handles each pixel of area of pixels as single dot. The idea is to compute the average gray scale intensity of this dot and then replace it with character with close enough intensity to the computed one. For that we need some list of usable characters each with precomputed intensity that I choose by fingering list of ASCII elements. 

 Firstly I wanted to make project (just working )without any implementing the various topics of programming abstractions. 
 1) I upload the image and make it grayscale image to compute his intensity. 
Then resize it to make comfortable to view . There are we have problem that ASCII symbols are not square and we have ratio about 1:2 . Our program works with each pixel and we have a situation where txt file can contain about 2^20 character and I did integer scale that will compute optimal size of output image.


2) So we have usable characters and their intensities. We need to find intensity closest to the pixel. Sometimes for simplicity the characters can be handled as linearly distributed causing slight gamma distortion usually unseen in the result unless you know what to look for.
Intensity based conversion is great also for gray-scale images (not just black and white). If you select the pixel the result gets large (1 pixel -> single character) so for larger images an area (multiply of font size) is selected instead to preserve aspect ratio and do not enlarge too much.
When we choose pixel from grayscale image it will give us integer from 0 to 255. It is intensity of the pixel that you choose, there are brightness starts from 255(white) and 0(black)
As character you can use any characters but the result gets better if the character has pixels dispersed evenly along the character area. 
I'm used this set of characters (   . ^ + / 7 & M @ ).
I wrote function that takes integer and outputs the characters that I wrote before. It chooses needed character with (if and else if) condition.
I make txt file where I will write ASCII art of image.
So, I wrote the square loop (by x dimension and y dimension) to iterate over all the pixels in the image and get their intensity in integer. So its call function that outputs character from integer of intensity and write it on txt file. After row of characters it is starts new line.
