# 2017-May-10 https://github.com/moshahmed/cc

PY=c:/python27/python.exe
AB=addressbook
AR=address-read

all::
	make clean
	make pbc
	make business
	make addressbook
	make py

business::
	g++  out/business.pb.cc business.cpp -L/usr/local/lib -llibprotobuf -o out/business.exe
	cd out && ./business.exe
	protoc --decode_raw < out/company.bin
	protoc --decode=business.Employee business.proto  < out/company.bin

addressbook::
	g++  out/$(AB).pb.cc $(AB).cpp -L/usr/local/lib -llibprotobuf -o out/$(AB).exe
	g++  out/$(AB).pb.cc $(AR).cpp -L/usr/local/lib -llibprotobuf -o out/$(AR).exe
	 ./out/$(AB).exe out/$(AB).bin
	 ./out/$(AR).exe out/$(AB).bin
	
py::
	$(PY) $(AB).py out/$(AB).bin
	$(PY) $(AR).py out/$(AB).bin

pbc::
	touch out/__init__.py
	for i in *.proto ;do \
	  protoc --cpp_out=out/    $$i ;\
	  protoc --python_out=out/ $$i ;\
	  protoc --js_out=out/     $$i ;\
	done

clean::
	rm -rfv a.exe out
	mkdir -p out

demo::
	echo 'syntax = "proto3"; package demo; message demo { repeated int32 n=1; }' > demo.proto
	echo n : [1,2,3]  | protoc --encode=demo.demo demo.proto > out/demo.bin
	protoc --decode=demo.demo demo.proto < out/demo.bin
	protoc --decode_raw < out/demo.bin

