TARGETS := main
CXXFLAGS += -g -Wall -std=c++14

all: ./EZLogger/$(TARGETS)

clean:
	@rm -rf $(TARGETS)