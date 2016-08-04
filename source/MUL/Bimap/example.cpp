/*#include "Bimap/Bimap.hpp"
#include <iostream>

template<class Left, class Right>
using Bimap = mul::bimap::Bimap<Left,Right>;

struct Id1 { using tagged_type = int; };
struct Id2 { using tagged_type = int; };

int main()
{
	Bimap<Id1,Id2> b({
		{1,2},
		{3,4},
		{5,6},
		{7,8},
		{9,10}
	});

	std::cout << b.get<Id1>(6) << std::endl;
	std::cout << b.fromRight(4) << std::endl;

	b.insert({11,12});
	b.insert(13,14);

	for(auto e : b)
		std::cout << "key : " << e.first << "  , value : " << *e.second << std::endl;

	b.remove({5,6});
	b.remove(11,12);

	std::cout << b.fromRight(12) << std::endl;

	std::cout << std::endl;

	for(auto e : b)
		std::cout << "key : " << e.first << "  , value : " << *e.second << std::endl;

    return 0;
}*/
