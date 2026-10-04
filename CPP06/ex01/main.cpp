#include "Serializer.hpp"
#include <iostream>
#include <limits>

static bool	testRoundTrip(Data& original)
{
	uintptr_t	raw = Serializer::serialize(&original);
	Data*		restored = Serializer::deserialize(raw);
	bool		passed = restored == &original;

	if (passed)
		passed = restored->id == original.id && restored->name == original.name && Serializer::serialize(restored) == raw;
	std::cout << "Round trip (id " << original.id << ", name length " << original.name.size() << "): " << std::boolalpha << passed << std::endl;
	return passed;
}

int	main()
{
	Data		original = {42, "Chud"};
	uintptr_t	raw = Serializer::serialize(&original);
	Data*		restored = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &original << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Restored pointer: " << restored << std::endl;
	std::cout << "Same pointer: " << std::boolalpha << (restored == &original) << std::endl;
	if (restored != &original)
		return 1;
	std::cout << "Data: " << restored->id << ", " << restored->name << std::endl;

	restored->id = 67;
	std::cout << "Original id after modifying restored: " << original.id << std::endl;
	bool	passed = original.id == 67;
	Data	cases[] = {
		{0, ""},
		{std::numeric_limits<int>::min(), "negative"},
		{std::numeric_limits<int>::max(), std::string(1024, 'x')}
	};

	for (unsigned int i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
		passed = testRoundTrip(cases[i]) && passed;

	Data*	heap = new Data;
	heap->id = -42;
	heap->name = "heap object";
	passed = testRoundTrip(*heap) && passed;
	delete heap;
	return passed ? 0 : 1;
}
