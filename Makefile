CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = run
OBJECTS = main2.o item.o potion.o gold.o character.o playerCharacter.o human.o orc.o elf.o dwarf.o decoratorPC.o boostAtk.o boostDef.o woundAtk.o woundDef.o enemy.o vampire.o werewolf.o goblin.o troll.o phoenix.o dragon.o merchant.o terrain.o wall.o space.o ground.o door.o passage.o stairs.o floor.o display.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

clear:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
