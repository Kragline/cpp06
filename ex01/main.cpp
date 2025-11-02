#include "Serializer.hpp"

int	main()
{
	Data	*original = new Data();
	original->id = 0;
	original->name = "some name";

	std::cout << "Original -> " << original << std::endl;
	std::cout << "Original (id) -> " << original->id << std::endl;
	std::cout << "Original (name) -> " << original->name << std::endl;

	// Serialize
	uintptr_t	raw = Serializer::serialize(original);
	std::cout << "Serialized -> " << raw << std::endl;

	// Deserialize
	Data	*restored = Serializer::deserialize(raw);
	std::cout << "Restored -> " << restored << std::endl;
	std::cout << "Restored (id) -> " << restored->id << std::endl;
	std::cout << "Restored (name) -> " << restored->name << std::endl;

	// Verify
	std::cout << "Addressed are " << (restored == original ? "equal!" : "not equal :(") << std::endl;

	delete original;
	return (0);
}
