#include <iostream>
#include <string>
#include <fstream>

int hamming_distance(const std::string& s, const std::string& t) {
	if ( s.size() != t.size() )
		return -1;

	int diff = 0;
	auto sit = begin(s);
	auto tit = begin(t);
	while ( sit != end(s) && tit != end(t) ) {
		if ( *sit != *tit )
			++diff;

		++sit;
		++tit;
	}

	return diff;
}

int main(int argc, char* argv[]) {
	if ( argc != 2 )
		return -1;

	std::ifstream dataset(argv[1]);
	if ( !dataset.is_open() )
		return -1;

	std::string s, t;
	std::getline(dataset, s);
	std::getline(dataset, t);

	std::cout << hamming_distance(s,t) << '\n';
}
