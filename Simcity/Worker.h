#pragma once
// Worker class represents an individual worker in the simulation, tracking their availability

class Worker {
private:
	bool isAvail;// Flag to indicate if the worker is currently available
public:
	Worker() { isAvail = true; }

	bool assign() {  // Assigns the worker to a task if they are available, marking them as unavailable
		if (!isAvail)return false;

		isAvail = false;
		return true;
	}
    // Checks if the worker is currently available

	bool isAvailable() { return isAvail; }
};
