#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

void reverse_complement ( std::string& sequence ) {
	for ( auto& x : sequence )
		switch ( x ) {
			case 'A': x = 'T'; break;
			case 'C': x = 'G'; break;
			case 'G': x = 'C'; break;
			case 'T': x = 'A'; break;
		}
	std::reverse( sequence.begin(), sequence.end() );
}

int main(int argc, char* argv[]) {
	if ( argc != 2 )
		return -1;

	std::ifstream dataset(argv[1]);

	std::string sequence;

	if ( dataset.is_open() )
		getline( dataset, sequence );

	reverse_complement( sequence );
	std::cout << sequence << '\n';
}
