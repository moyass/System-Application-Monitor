all:
	g++ -o sysmon --std=c++11 main.cc get-proc-info.cc

clean:
	rm sysmon