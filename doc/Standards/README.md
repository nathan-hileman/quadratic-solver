Author: Xavier Gray

Compiler options:
	I have looked into C compiler options and have decided on the following
	-Wall -pedantic
		These are on for the reasons mentioned in class. They will help us to write standard C.
	-std=c99
		We will use c99 because of it's IEEE floating point support (see https://en.wikipedia.org/wiki/C99#IEEE_754_floating_point_support)
	for debugging: -DDEBUG -g
		This will allow us to debug using gdb, since the app will be running on linux

	In this directory is a sample makefile with these flags set

Programming Standard:
	Looking at different C coding standards, the one that makes the most sense is the GNU c programming standard. (https://www.gnu.org/prep/standards/html_node/Writing-C.html)
	Feel free to skim it. 

