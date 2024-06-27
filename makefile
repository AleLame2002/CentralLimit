LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.cpp RandomGen.h FunzioneBase.h Funzioni.h
	g++ main.cpp -o main ${INCS} ${LIBS}

clean:
	rm -i main
