CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = a3q5
OBJECTS = a3q5.o re.o regexp.o parser.o disjunction.o concatenation.o star.o word.o dot.o begin.o end.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
