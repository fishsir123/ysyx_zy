BUILD_DIR = ./build

VFLAGS = -cc -trace --exe --build -j 8

VSRC=./vsrc/add.sv
CSRC=./csrc/main.cpp

build:
	@verilator $(VFLAGS) \
	--top-module top \
	--Mdir $(BUILD_DIR) \
	-sv \
	$(VSRC) $(CSRC) \

run:
	$(BUILD_DIR)/Vtop

all:
	@echo "Write this Makefile by your self."

clean:
	rm -rf ./build