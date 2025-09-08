# A sample Makefile for building Google Test and using it in user tests.
GTEST_DIR=$(_GOOGLETEST_PATH)/googletest

# Where to find user code.
USER_DIR = ../..
SRC_DIR = ../../src
TEST_INCLUDE_DIR = ../include

# Where to find the unit test code
UNITTEST_DIR = .

# Flags passed to the preprocessor.
# $(USER_DIR)/src is used by xxx_unittest.cpp
CPPFLAGS += -I$(GTEST_DIR)/include
CPPFLAGS += -I$(USER_DIR)/src
CPPFLAGS += -I$(USER_DIR)/include

# Flags passed to the C++ compiler.
CXX = g++-13
CXXFLAGS = -std=c++20 -I/usr/local/include
LDFLAGS = -L/usr/local/lib 

# All Google Test headers.  Usually you shouldn't change this definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# symbolic name for this problem-solving code
EGO = NeedleInHayStack
UTILS = utils
TESTS = ${EGO}_unittest

# House-keeping build targets.
all : clean $(TESTS)

clean :
	rm -f $(TESTS) *.a *.o

# Usually you shouldn't tweak such internal variables, indicated by a trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
#
# the tab in head of 2nd line is necessary, it is valid separator
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

# below == "ar rcs gtest.a gtest-all.o" here "ar" is archiver, "rcs" are ARFLAGS
# r for insert into archive, c for create archive, s for write an index to archive
gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main() function.
# -c: compile and assemble source file without link.
# the ultimate output is .o file for each source file
# $@: own name of the target
# $^: names of the dependencies
#
$(UTILS).o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ${SRC_DIR}/${UTILS}.cpp

${EGO}.o: $(GTEST_HEADERS) ${UTILS}.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/${EGO}.cpp

${TESTS}.o : $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(UNITTEST_DIR)/${TESTS}.cpp -I ${TEST_INCLUDE_DIR}

${TESTS} : ${EGO}.o ${TESTS}.o gtest_main.a ${UTILS}.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -pthread $^ -o $@
