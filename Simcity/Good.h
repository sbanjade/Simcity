#pragma once
// Good class: Represents a commercial good in the simulation, which can be sold
class Good {
private:
	bool is_soldable; // Tracks whether the good is available for sale
public: // Constructor: Initializes a Good object with its sale status set to available
	Good() { is_soldable = true; }
// sell method: Marks the good as sold if it is available
    // Returns true if the sale was successful, false otherwise
	bool sell() {
		if (!isSoldable())return false;

		is_soldable = false;
		return true;
	}
// isSoldable method: Checks if the good is available for sale
	bool isSoldable() { return is_soldable; }
};


