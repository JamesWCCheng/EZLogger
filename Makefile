TARGETS := main
CXXFLAGS += -g -Wall -std=c++11

all: ./EZLogger/$(TARGETS)

clean:
	@rm -rf ./EZLogger/$(TARGETS)