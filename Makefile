CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g -O3
EXEC = myvm
OBJECTS = main.o controller.o curseView.o position.o registerManager.o vm.o curseControl.o model.o range.o subject.o fileManager.o basicMotion.o up.o down.o left.o right.o insertCommand.o insertMode.o insert.o writer.o write.o quitter.o quit.o writequit.o keys.o append.o prepend.o newlineInsert.o appendToLine.o enterReplaceMode.o scrollDown.o scrollUp.o footprint.o insertFootprint.o deleteFootprint.o replaceFootprint.o undo.o commandInfo.o delete.o deleteCommand.o writeRegisterCommand.o yank.o paste.o cursorManager.o motionCommand.o wordForward.o wordBack.o scrollForward.o scrollBackward.o findForward.o findBack.o coloredBuffer.o lineBegin.o lineEnd.o lineJump.o jumpToMatch.o searchForward.o searchBack.o replaceChar.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
