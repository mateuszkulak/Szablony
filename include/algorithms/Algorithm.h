#pragma once

/**
 * Abstract base class for algorithms.
 */
class Algorithm
{
public:
    /**
     * Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Algorithm() = default;

    /**
     * Runs the algorithm.
     */
    virtual void run();

    /**
     * Describes the algorithm.
     */
    virtual const char *describe() const;
};