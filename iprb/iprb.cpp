#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

struct Organism {
	int dominance;

	double mate(const Organism& m) const {
		if (dominance == 1 || m.dominance == 1)
			return 1;
		if (dominance == 0 && m.dominance == 0)
			return 0.75;
		if ( (dominance == -1 && m.dominance == 0) || (dominance == 0 && m.dominance == -1) )
			return 0.5;
		if (dominance == -1 && m.dominance == -1)
			return 0;
		return 0;
	}
};

int main(int argc, char* argv[]) {

	if ( argc != 4 )
		return -1;

	int k, m, n;
	
	std::stringstream(argv[1]) >> k;
	std::stringstream(argv[2]) >> m;
	std::stringstream(argv[3]) >> n;

	std::vector<Organism> pool;

	for (int i = 0; i < k; ++i)
		pool.push_back(Organism{1});

	for (int i = 0; i < m; ++i)
		pool.push_back(Organism{0});
	
	for (int i = 0; i < n; ++i)
		pool.push_back(Organism{-1});

	std::vector<double> probs;
	for (int i = 0; i < pool.size(); ++i)
		for (int j = 0; j < pool.size(); ++j)
			if ( i != j )
				probs.push_back(pool.at(i).mate(pool.at(j)));

	double sum = std::accumulate(begin(probs), end(probs), 0.0);
	std::cout << sum / probs.size() << '\n';
}
