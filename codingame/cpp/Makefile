CXX = g++-13
CXXFLAGS = -std=c++20 -ltbb -I/usr/local/include
LDFLAGS = -L/usr/local/lib 

#SUB_DIR=
SINGLE_FILE=BytePairEncoding

SRC = ./src/$(SINGLE_FILE).cpp
OBJ = $(SRC:.cpp=.o)
EXEC = ./target/$(SINGLE_FILE)

all: clean $(EXEC)

build: $(EXEC)

$(EXEC): $(OBJ)
	mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)%
