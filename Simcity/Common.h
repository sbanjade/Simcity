#pragma once
class Common // Common class: An abstract base class providing a shared interface for city elements
{
public:
// Pure virtual function to get a list of available workers
    // Must be implemented by any derived class
    virtual std::vector <Worker*> getAvailWorkers() = 0;
    // Pure virtual function to get a list of goods available for sale
    // Must be implemented by any derived class
    virtual std::vector <Good*> getSoldableGoods() = 0;
};

