#pragma once

template <class T>
class Misc {
public:
    static bool Contains(std::vector<T> tmp, T element) {
        return (std::find(std::begin(tmp), std::end(tmp), element) != std::end(tmp));
    }
};

