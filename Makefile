CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = myvm
OBJECTS = main.o controller.o curseView.o position.o registerManager.o vm.o curseControl.o footprint.o model.o range.o subject.o fileManager.o basicMotion.o up.o down.o left.o right.o insertCommand.o insertMode.o insert.o writer.o write.o quitter.o quit.o writequit.o keys.o append.o prepend.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
