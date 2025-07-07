// cache.hpp
#ifndef CACHE_HPP
#define CACHE_HPP

#include <unordered_map>
#include <string>
#include <mutex>

class Cache {
private:
    std::unordered_map<std::string, std::string> storage;
    std::mutex mtx;

public:
    bool exists(const std::string& url) {
        std::lock_guard<std::mutex> lock(mtx);
        return storage.find(url) != storage.end();
    }

    std::string get(const std::string& url) {
        std::lock_guard<std::mutex> lock(mtx);
        return storage[url];
    }

    void store(const std::string& url, const std::string& data) {
        std::lock_guard<std::mutex> lock(mtx);
        storage[url] = data;
    }
};

#endif // CACHE_HPP