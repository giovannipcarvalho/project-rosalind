#include <iostream>
#include <string>
#include <fstream>

void dna_to_rna(std::string& sequence) {
	for ( auto& x : sequence )
		if ( x == 'T' )
			x = 'U';
}

int main(int argc, char* argv[]) {
	if ( argc != 2 )
		return -1;

	std::ifstream dataset(argv[1]);

	std::string sequence;
	if ( dataset.is_open() )
		getline(dataset, sequence);

	dna_to_rna(sequence);
	std::cout << sequence << '\n';
}
