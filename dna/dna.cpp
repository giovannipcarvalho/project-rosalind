#include <iostream>
#include <array>
#include <string>
#include <fstream>

std::array<int, 4> dna_count(const std::string& sequence)
{

	std::array<int, 4> counts{0, 0, 0, 0};

	auto counter = [=] (char c) mutable {
		switch ( c ) {
			case 'A': ++counts[0]; break;
			case 'C': ++counts[1]; break;
			case 'G': ++counts[2]; break;
			case 'T': ++counts[3]; break;
		}
	};

	for ( auto x : sequence )
		counter( x );

	return counts;
}

int main(int argc, char* argv[]) {
	if ( argc != 2 )
		return -1;

	std::ifstream dataset{argv[1]};

	std::string sequence;
	if (dataset.is_open())
		getline(dataset, sequence);

	std::array<int, 4> counts = dna_count(sequence);

	for (auto x : counts)
		std::cout << x << " ";
}
