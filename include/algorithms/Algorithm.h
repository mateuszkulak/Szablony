#pragma once

class Algorithm {
public:
    virtual ~Algorithm() = default;
    virtual void run();
    virtual const char* describe() const;
};