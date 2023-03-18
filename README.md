# ZFX - Simple Graphics Library
Better version of this project - https://www3.nd.edu/~dthain/courses/cse20211/fall2013/gfx/, that was used at my university at first semester for the Programming 1 practice course. 
Here is my team semestrial project that was made with it - https://github.com/MatveyM11/Programming-I-Semester-Project.

My main issue with a GFX library is that it's not simple at all, in compare to even more level libraries like a SDL2 or pure OpenGL/Vulkan.
GFX is a terribly designed piece of [DATA EXPUNGED], worst part of it comes when you need to make an animation, cause it's not using double buffer.
And because of it you're going to have such pleasant video effects as flickering and tearing.
Also it has no text support, so in our project we have implemented our own font, besides of the fact that there's no support for the images drawing so we've implement our own sprites storage as 2d c-arrays and pixel by pixel render for them.

This early version of this wrapper, isn't wrapper at all, it's just a singular file for now, but it's already has a double buffering implemented, text render and drawing of the primitives such as polygons, circles, rectangles. 
Even more, ZFX also supports sprite in format of the .xmp images and animations as a series of the .xmp images. 


* DISCLAIMER!
This X11 wrapper is a joke, don't use it for any non-pet projects and even for them look better at SDL, RayLib or anything else.
