car : doors.hpp perf.hpp perf.cpp car.hpp car.cpp
	g++ --std=c++20 doors.hpp perf.hpp perf.cpp car.hpp car.cpp -o car

clean:
	rm car