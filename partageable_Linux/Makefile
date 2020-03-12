
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=.; \
	./main Composant1 3 4; \
	./main Composant2 3 4;

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
