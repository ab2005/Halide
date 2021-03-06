#ifndef HALIDE_UTIL_H
#define HALIDE_UTIL_H

#include <string>
#include <vector>
#include "MLVal.h"

// TODO: move most of these symbols to an internal-only Util lib
namespace Halide {
    // Generate a unique name
    std::string uniqueName(char prefix);

    // Make sure a name has no invalid characters
    std::string sanitizeName(const std::string &name);

    void warn(const char* msg, ...);
    
    // Make ML lists
    MLVal makeList();
    MLVal addToList(const MLVal &list, const MLVal &item);

    MLVal makePair(const MLVal &a, const MLVal &b);
    MLVal makeTriple(const MLVal &a, const MLVal &b, const MLVal &c);

    MLVal listHead(const MLVal &l);
    MLVal listTail(const MLVal &l);
    MLVal listEmpty(const MLVal &l);
    MLVal listLength(const MLVal &l);

    std::string int_to_str(int);          // Connelly: workaround function for ostringstream << int failing in Python binding

    // Make small vectors
    template<typename T>
    std::vector<T> vec(T a) {
        std::vector<T> v(1);
        v[0] = a;
        return v;
    }

    template<typename T>
    std::vector<T> vec(T a, T b) {
        std::vector<T> v(2);
        v[0] = a;
        v[1] = b;
        return v;
    }

    template<typename T>
    std::vector<T> vec(T a, T b, T c) {
        std::vector<T> v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;
        return v;
    }

    template<typename T>
    std::vector<T> vec(T a, T b, T c, T d) {
        std::vector<T> v(4);
        v[0] = a;        
        v[1] = b;
        v[2] = c;
        v[3] = d;
        return v;
    }

    template<typename T>
    std::vector<T> vec(T a, T b, T c, T d, T e) {
        std::vector<T> v(5);
        v[0] = a;        
        v[1] = b;
        v[2] = c;
        v[3] = d;
        v[4] = e;
        return v;
    }

    template<typename T>
    std::vector<T> vec(T a, T b, T c, T d, T e, T f) {
        std::vector<T> v(6);
        v[0] = a;        
        v[1] = b;
        v[2] = c;
        v[3] = d;
        v[4] = e;
        v[5] = f;
        return v;
    }


    template<typename T>
    bool set_contains(const std::vector<T> &a, const T &b) {
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == b) return true;
        }
        return false;
    }

    // is b a subset of a? n^2 FTW!
    template<typename T>
    bool set_subset(const std::vector<T> &a, const std::vector<T> &b) {
        for (size_t i = 0; i < b.size(); i++) {
            if (!set_contains(a, b[i])) return false;
        }
        return true;
    }

    template<typename T>
    void set_add(std::vector<T> &a, const T &b) {
        if (set_contains(a, b)) return;
        a.push_back(b);
    }

    template<typename T>
    void set_union(std::vector<T> &a, const std::vector<T> &b) {
        for (size_t i = 0; i < b.size(); i++) {
            set_add(a, b[i]);
        }
    }
}

#endif
