# Makefile for bitmap_project

all:	bitmap

bitmap:	bitmap_project.cpp bitmap_variables.h 
	clang++ -I .. -I /opt/X11/include bitmap_project.cpp -L /opt/X11/lib -lX11 -o bitmap

clean:
	rm -f Colours.txt
	rm -f resized.bmp
	rm -f blurry.bmp
	rm -f blackandwhite.bmp
	rm -f sharpness.bmp
	rm -f *.o bitmap
	

