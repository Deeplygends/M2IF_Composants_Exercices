
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main

install:
	ifdef PARAM
		cd main && ${MAKE} install COMPONENT=PARAM
	else
		cd main && ${MAKE} install COMPONENT=NaiveHashComponent
	endif
clean:
	cd main && ${MAKE} clean COMPONENT="NaiveHashComponent sha3Component sha256Component"
