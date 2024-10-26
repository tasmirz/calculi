CXX := g++

SRC := cpp
TARGET := calculi/cpp_agents

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(TARGET)/%.o, $(SOURCES))

all: $(OBJECTS)

$(TARGET)/%.o: $(SRC)/%.cpp
	@mkdir -p $(TARGET)
	$(CXX) -c $< -o $@

clean:
	rm -rf $(TARGET)/*.o

.PHONY: all clean