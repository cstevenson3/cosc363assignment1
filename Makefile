MAKE_COMMAND := 
MAKEFILE_NAME := 

ifeq ($(OS),Windows_NT)
	MAKE_COMMAND += mingw32-make
	MAKEFILE_NAME += MakefileWindows
else
	MAKE_COMMAND += make
	MAKEFILE_NAME += MakefileUnix
endif

dummy.recipe:
	$(MAKE_COMMAND) -f $(MAKEFILE_NAME)
