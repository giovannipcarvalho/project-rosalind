#include <iostream>
#include <array>
#include <sstream>

int main(int argc, char* argv[]) {
	if ( argc != 3 )
		return -1;

	int n = 5;
	int k = 3;
	
	std::istringstream(argv[1]) >> n;
	std::istringstream(argv[2]) >> k;

	if ( n > 40 || k > 5 )
		return -1;
	
	std::array<long, 2> buf = {1, 0};

	for ( int i = 0; i < n; ++i ) {
		long aux = buf[1] * k;
		buf[1] += buf[0];
		buf[0] = aux;
	}

	std::cout << buf[1] << '\n';
}
