#pragma once
#include <iostream>
using namespace std;

class SupportAbility {
	public:
		char* getType() {
			return typeid(&this)->name();
		}
};
