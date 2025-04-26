CXX = g++
CXXFLAGS = -Wall -Wextra

OBJS = main.o Memory.o Array.o String.o Math.o Sys.o BinaryOp.o Screen.o Output.o
TARGET = os_sim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
