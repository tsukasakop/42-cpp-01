#include "Zombie.hpp"

int main(void) {
	// ヒープ割り当て: 関数スコープを超えて使用可能
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	
	// スタック割り当て: 関数内で即座に使用・破棄
	randomChump("StackZombie");
	
	// ヒープに割り当てたゾンビは明示的に削除する必要がある
	delete heapZombie;
	
	return 0;
}
