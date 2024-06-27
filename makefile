myLibs=RandomGen.o FunzioneBase.o 
myDeps=RandomGen.h FunzioneBase.h Funzioni.h
RFlags:=`root-config --libs` `root-config --cflags`

main: main.cpp ${myLibs} 
	g++ -Wall -o $@ $^ ${RFlags}

%.o: %.cpp %.h ${myDeps}
	g++ -Wall -c $< 

clean:
	rm -i *.o main
