all:
	g++ -o bat battery.cc
	g++ -o temp cpu_temp.cc
	g++ -o freq cpu_frequency.cc
clean:
	rm bat temp freq
