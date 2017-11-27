libs  = -lX11 -lpthread
incs  = -I/usr/X11R6/include
flags =  -pedantic -Wextra -Wall

all:
	gcc -o k_panel main.c $(libs) $(incs) $(flags)
