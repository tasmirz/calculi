CXX := g++

SRC := cpp
TARGET := calculi/cpp_agents

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(TARGET)/%.out, $(SOURCES))

all: $(OBJECTS)

$(TARGET)/%.out: $(SRC)/%.cpp
	@mkdir -p $(TARGET)
	$(CXX) $< -o $@

clean:
	rm -rf $(TARGET)/*.out
run:
	python3 calculi/__init__.py
.PHONY: all clean