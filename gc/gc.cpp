#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

class DNA {
public:
	std::string name;
	std::string strand;
	double gc_content = -1;

	DNA(std::string name, std::string strand) : strand(strand), name(name) {
		calc_gc_content();
	}

	DNA(std::string strand) : DNA("", strand) {}

private:
	void calc_gc_content() {
		if ( gc_content < 0 ) {
			int count = 0;
			for ( auto& x : strand )
				if ( x == 'G' || x == 'C' )
					count++;
			gc_content = count / (double) strand.size() * 100.0;
		} 
	}

	friend bool operator< (const DNA& a, const DNA& b) {
		return a.gc_content < b.gc_content;
	}

	friend std::ostream& operator<< (std::ostream& out, const DNA& dna) {
		out << dna.name << '\n' << dna.gc_content;
		return out;
	}
};

void read_dna_dataset(std::ifstream& dataset, std::vector<DNA>& dnas) {
	std::string line;
	std::stringstream ss;

	std::string name, strand;

	bool first = true;

	while ( std::getline(dataset, line) ) {
		std::size_t pos = line.find(">");
		if ( pos != std::string::npos ) {
			if (!first) {
				strand = ss.str();
				std::stringstream().swap(ss);
				dnas.push_back(DNA(name, strand));
			}

			name = line.substr(pos+1);

			first = false;
		} else {
			ss << line;
		}
	}
	dnas.push_back(DNA(name, ss.str()));
}

int main(int argc, char* argv[]) {
	if ( argc != 2 )
		return -1;

	std::ifstream dataset(argv[1]);
	std::vector<DNA> dnas;

	if ( dataset.is_open() )
		read_dna_dataset( dataset, dnas );

	/* for ( auto& x : dnas )
		std::cout << x << '\n'; */

	std::vector<DNA>::iterator result = std::max_element( begin(dnas), end(dnas) );
	std::cout << *result << '\n';
}
