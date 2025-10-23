#!/bin/sh

#cleanup
rm -rf obj_dir
rm -f sigdelay.vcd

#run verialtor to translate verilog into C++, including C++ testbench
verilator  -Wall --cc --trace sigdelay.sv --exe sigdelay_tb.cpp

#build C++ project via make automatically genrated by verilator
make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay

#run executable simulation file
obj_dir/Vsigdelay