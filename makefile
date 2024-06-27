LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.cpp ../Esercizio_10.0/RandomGen.h ../Esercizio_10.0/FunzioneBase.h Funzioni.h
	g++ main.cpp -o main ${INCS} ${LIBS}

clean:
	rm -i main