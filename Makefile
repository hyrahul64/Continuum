INCPATH=/home/ubuntu/rahuls/prgs/Continuum/

stl:stl.cpp student.h
	g++ -o stl -I$(INCPATH) stl.cpp

clean:
	rm stl
