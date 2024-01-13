# source files in this project 
PROJECT_NAME=assg12

assg_src  = Dictionary.cpp \
	    DictionaryException.cpp \
	    Employee.cpp \
	    HashDictionary.cpp \
	    KeyValuePair.cpp

test_src  = ${PROJECT_NAME}-HashDictionary-tests.cpp \
	    ${assg_src}

sim_src   = ${PROJECT_NAME}-sim.cpp \
	    ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include include/Makefile.inc

# assignment header file specific dependencies
${OBJ_DIR}/Dictionary.o: ${SRC_DIR}/Dictionary.cpp ${INC_DIR}/Dictionary.hpp
${OBJ_DIR}/DictionaryException.o: ${SRC_DIR}/DictionaryException.cpp ${INC_DIR}/DictionaryException.hpp
${OBJ_DIR}/Employee.o: ${SRC_DIR}/Employee.cpp ${INC_DIR}/Employee.hpp
${OBJ_DIR}/HashDictionary.o: ${SRC_DIR}/HashDictionary.cpp ${INC_DIR}/HashDictionary.hpp
${OBJ_DIR}/KeyValuePair.o: ${SRC_DIR}/KeyValuePair.cpp ${INC_DIR}/KeyValuePair.hpp
${OBJ_DIR}/${PROJECT_NAME}-HashDictionary-tests.o: ${SRC_DIR}/${PROJECT_NAME}-HashDictionary-tests.cpp ${INC_DIR}/DictionaryException.hpp ${INC_DIR}/HashDictionary.hpp ${INC_DIR}/Employee.hpp
${OBJ_DIR}/${PROJECT_NAME}-sim.o: ${SRC_DIR}/${PROJECT_NAME}-sim.cpp ${INC_DIR}/HashDictionary.hpp
