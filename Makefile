ifeq ($(OS),Windows_NT)
	make -f MakefileWindows
else
	make -f MakefileUnix
endif
