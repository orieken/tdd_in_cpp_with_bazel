//
// Created by Rieken, Oscar (CORP) on 2019-02-03.
//

#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "src/Tweet/Tweet.h"

class RetweetCollection {
public:
    RetweetCollection()
            : empty_(true) {
    }

    bool isEmpty() const {
        return empty_;
    }

    void add(const Tweet& tweet) {
        empty_ = false;
    }

    unsigned int size() const {
        return isEmpty() ? 0 : 1;
    }

private:
    bool empty_;
};

#endif
