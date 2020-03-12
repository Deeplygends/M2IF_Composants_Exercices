ifdef PARAM
	OPERATION=${PARAM}
else
	OPERATION="Composant1"
endif
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main ${OPERATION}

install:
	cd main && ${MAKE} install PARAM=${OPERATION}

clean:
	cd main && ${MAKE} clean
