
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main

install:
	ifdef COMPONENT
		cd main && ${MAKE} install COMPONENT
	else
		cd main && ${MAKE} install COMPONENT=NaiveHashComponent

clean:
	cd main && ${MAKE} clean
